/*
 * FSR-example_1: force 0.0/0.0 to set invalid FP exception and show FSR/fenv
 * Observe TEM, cexc, aexc (FSR) changes via printed values (and via Renode register view)
 */

#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "FSR EXAMPLE 1";

rtems_task Init(
  rtems_task_argument ignored
)
{
  (void) ignored;
  TEST_BEGIN();

  volatile double a = 0.0;
  volatile double b = 1.0;
  volatile double c = 0.0;

  volatile double res_invalid = a / c;
  volatile double res_zero = b / c;

  printf("res_invalid: %f\n", res_invalid);
  printf("res_zero: %f\n", res_zero);

  TEST_END();
  exit(0);
}
