#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <fenv.h>
#include <stdint.h>

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  volatile double x = 1.0;
  volatile double y = 3.0;

  volatile double res_no_trap = x / y;

  // 1.set $fsr = 0x80000으로 초기화
  // 2.set $fsr = $fsr | (1<<23)로 inexact 예외 활성화 후 실행
  volatile double res_trap = x / y;

  printf("res_no_trap: %f\n", res_no_trap);
  printf("res_trap: %f\n", res_trap);
  exit(0);
}
