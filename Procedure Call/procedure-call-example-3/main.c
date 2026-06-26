/*
 * Procedure call example with 8 arguments for stack inspection
 */
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

volatile int final_res;
const char rtems_test_name[] = "PROC CALL 8 ARGS";

static void Func2(int a1, int a2, int a3, int a4,
                 int a5, int a6, int a7, int a8)
{
  volatile int mix = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
  printf("%d\n", mix);
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();
  Func2(1, 2, 3, 4, 5, 6, 7, 8);
  TEST_END();
  exit(0);
}
