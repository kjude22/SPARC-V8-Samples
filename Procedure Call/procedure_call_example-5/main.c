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

const char rtems_test_name[] = "PROCEDURE CALL EXAMPLE 5";
volatile int res;

int PrintNum(int x)
{
  printf("PrintNum: %d\n", x);
  return 0;
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  res = PrintNum(5);

  TEST_END();
  exit(0);
}
