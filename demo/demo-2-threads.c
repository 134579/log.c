#include <logc/log.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t MUTEX_LOG;
void log_lock(bool lock, void *udata) {
  pthread_mutex_t *LOCK = (pthread_mutex_t *)(udata);
  if (lock)
    pthread_mutex_lock(LOCK);
  else
    pthread_mutex_unlock(LOCK);
}

void *DoLog(void *arg) {
  const char *msg = "Hello World";
  log_trace("Trace Message:%s", msg);
  usleep(100);
  log_debug("Debug Message:%s", msg);
  usleep(100);
  log_info("Info Message:%s", msg);
  usleep(100);
  log_warn("Warn Message:%s", msg);
  usleep(100);
  log_error("Error Message:%s", msg);
  usleep(100);
  log_fatal("Fatal Message:%s", msg);
  usleep(100);
  getchar();
  return NULL;
}

#define N 3
int main(int argc, const char **argv) {

  pthread_t threads[N];

  pthread_mutex_init(&MUTEX_LOG, NULL);
  log_set_lock(log_lock, &MUTEX_LOG);

  for (size_t i = 0; i < N; i++) {
    pthread_create(&threads[i], NULL, DoLog, NULL);
  }

  for (size_t i = 0; i < N; i++) {
    pthread_join(threads[i], NULL);
  }


  return 0;
}