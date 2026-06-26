#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

const char rtems_test_name[] = "FPU EXAMPLE 1";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void)ignored;
  TEST_BEGIN();

    volatile float f1 = 1.0f;
    volatile float f2 = 2.0f;
    volatile double d1 = 1.0;
    volatile double d2 = 2.0;

    volatile float f_sum = f1 + f2;
    volatile double d_sum = d1 + d2;

  TEST_END();
  exit(0);
}
