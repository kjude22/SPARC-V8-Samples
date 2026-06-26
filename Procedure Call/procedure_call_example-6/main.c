/*
 * Simple procedure call example for stack inspection
 */
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "PROCEDURE CALL EXAMPLE 6";
volatile int res;

int MakeArr(int x)
{
  volatile int arr[3];
  arr[0] = x;
  arr[1] = x + 1;
  arr[2] = arr[0] + arr[1];

  return arr[2];
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  res = MakeArr(25);

  TEST_END();
  exit(0);
}
