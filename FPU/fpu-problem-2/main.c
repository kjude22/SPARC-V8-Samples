#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

const char rtems_test_name[] = "FPU PROBLEM 2";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void)ignored;
  TEST_BEGIN();

    volatile float f1 = 1.0/0.0;
    volatile float f2 = log(0.0);
    volatile float f3 = f2 + 1;

  TEST_END();
  exit(0);
}
