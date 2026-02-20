/*
 * Procedure call example with a single pointer argument for stack inspection
 */
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "PROC CALL PTR ARG";

static int Func(int *value)
{
  volatile int local_offset = 7;

  *value += local_offset;
  return *value;
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  int stack_value = 10;
  int res = Func(&stack_value);
  printf("%d\n", res);

  TEST_END();
  exit(0);
}
