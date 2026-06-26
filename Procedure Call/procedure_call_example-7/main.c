#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "PROCEDURE CALL EXAMPLE 7";
volatile int res;

int Sum(int x)
{
  volatile int arr[5];
  arr[0] = x;
  arr[1] = x - 10;
  arr[2] = x - 20;
  arr[3] = x - 30;
  arr[4] = x - 40;

  int result = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
  return result;
}

rtems_task Init(rtems_task_argument ignored)
{
  (void) ignored;
  TEST_BEGIN();

  res = Sum(40);
  printf("%d\n", res);

  TEST_END();
  exit(0);
}
