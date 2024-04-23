#include <logc/log.h>

int main(int argc, const char **argv) {
  const char *msg = "Hello World";
  log_trace("Trace Message:%s", msg);
  log_debug("Debug Message:%s", msg);
  log_info("Info Message:%s", msg);
  log_warn("Warn Message:%s", msg);
  log_error("Error Message:%s", msg);
  log_fatal("Fatal Message:%s", msg);

  return 0;
}