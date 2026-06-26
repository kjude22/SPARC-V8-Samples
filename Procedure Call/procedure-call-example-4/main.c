/*
 * Minimal procedure call example:
 * same function called twice in sequence with argument reuse.
 */
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "PROC CALL SIMPLE REUSE";
volatile int final_res;

int Mult(int x, int y);
int Func3(int base);

int Mult(int x, int y)
{
  return x * y;
}

int Func3(int base)
{
  volatile int first, second;
  first = Mult(base, 2);
  second = Mult(base, 3);

  return first + second;
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  volatile int res = Func3(10);
  printf("%d\n", res);

  TEST_END();
  exit(0);
}
