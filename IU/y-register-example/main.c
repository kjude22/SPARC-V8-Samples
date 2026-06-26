/*
 * Multiply/Divide example for observing Y register effects
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

const char rtems_test_name[] = "MULDIV TEST";

volatile unsigned int u1;
volatile unsigned int u2;
volatile int s1;
volatile int s2;

volatile int num = 2147483647;
volatile int a = 256;
volatile int b = -1024;

void Multiple(void)
{
  volatile int res_s = s1 * s2;
  volatile unsigned int res_u = u1 * u2;
  printf("%d*%d = %d\n", s1, s2, res_s);
  printf("%u*%u = %u\n", u1, u2, res_u);
}

void Divide(void)
{
  volatile int res_s = s1 / s2;
  volatile unsigned int res_u = u1 / u2;
  printf("%d/%d = %d\n", s1, s2, res_s);
  printf("%u/%u = %u\n", u1, u2, res_u);
}

// example: Mul
void Mul(void)
{
  volatile int res_a = num * a;
  volatile int res_b = num * b;
  printf("%d/%d = %d\n", num, a, res_a);
  printf("%u/%u = %u\n", num, b, res_b);
}

rtems_task Init(
    rtems_task_argument ignored)
{
  (void)ignored;
  TEST_BEGIN();

  u1 = 123u;
  u2 = 7u;
  s1 = 2147483647;
  s2 = 8192;

  Multiple();
  Divide();
  Mul();
  TEST_END();
  exit(0);
}
