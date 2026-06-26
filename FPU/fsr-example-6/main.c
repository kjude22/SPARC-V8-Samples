#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>
#include <float.h>

const char rtems_test_name[] = "FSR EXAMPLE 6";

rtems_task Init(
  rtems_task_argument ignored
)
{
    (void)ignored;
    TEST_BEGIN();
    volatile float f = FLT_MIN;
    volatile float res;

    res = f / 10.0f;
    TEST_END();
    exit(0);
}
