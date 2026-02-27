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

const char rtems_test_name[] = "PROC CALL SIMPLE";
volatile int final_res;

int Sum(int x);
int Mult(int x, int y, int z);    

int Sum(int x)
{
  volatile int res = 0;
  res = Mult(x, 2, 3); 
  return res + 5;
}

int Mult(int x, int y, int z)
{
  return x*y*z;
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  final_res = Sum(10);

  TEST_END();
  exit(0);
}
