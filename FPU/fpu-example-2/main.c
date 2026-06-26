#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>
#include <float.h>

const char rtems_test_name[] = "FPU EXAMPLE 2";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void)ignored;
  TEST_BEGIN();

  volatile float f = FLT_MAX;
  volatile double d = DBL_MAX;

  volatile float tf = (float)d;
  volatile double td = (double)f;

  TEST_END();
  exit(0);
}
