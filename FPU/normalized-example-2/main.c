#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <stdlib.h>

const char rtems_test_name[] = "NORMALIZED EXAMPLE 2";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void)ignored;
  TEST_BEGIN();

  volatile int i = 128;
  volatile float f = 128.0f;
  volatile double d = 128.0;

  printf("i = %d\n", i);
  printf("f = %.1f\n", f);
  printf("d = %.1f\n", d);

  TEST_END();
  exit(0);
}
