#include <logc/log.h>
#include <stdio.h>
int main(int argc, const char **argv) {
  log_add_fp(fopen("demo.log", "wa"), LOG_INFO);
  const char *msg = "Hello World";
  log_trace("Trace Message:%s", msg);
  log_debug("Debug Message:%s", msg);
  log_info("Info Message:%s", msg);
  log_warn("Warn Message:%s", msg);
  log_error("Error Message:%s", msg);
  log_fatal("Fatal Message:%s", msg);

  return 0;
}