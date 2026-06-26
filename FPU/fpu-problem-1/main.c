#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

const char rtems_test_name[] = "FPU PROBLEM 1";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void)ignored;
  TEST_BEGIN();
  volatile float f = 2.5f;
  volatile double d = 2.75;
  exit(0);
}
