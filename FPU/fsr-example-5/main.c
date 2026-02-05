#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>

const char rtems_test_name[] = "FSR EXAMPLE 3";

rtems_task Init(
  rtems_task_argument ignored
)
{
    (void) ignored;
    TEST_BEGIN();
    volatile double a = 1e308;
    volatile double b = 1e308;

    // 1.set $fsr = $fsr | (1<<26)
    // 2.set $fsr = $fsr | (1<<23)

    // 한 번의 곱셈에서 overflow + inexact가 동시에 발생
    volatile double res = a * b;
    TEST_END();
}
