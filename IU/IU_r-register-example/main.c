/*
 * Simple IU arithmetic sample (add/sub only)
 */
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_UNLIMITED_OBJECTS
#define CONFIGURE_UNIFIED_WORK_AREAS

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT

#include <rtems/confdefs.h>
#include <rtems.h>
#include <stdio.h>
#include <stdlib.h>

static volatile int compute_add_sub(int a, int b, int c)
{
  volatile int r1 = a + b;
  if (r1 < a)
  { /* unsigned overflow 가능성 체크 */
    r1 = 0;
  }

  volatile int r2 = r1 - c;
  if (r2 > r1)
  { /* unsigned borrow */
    r2 = 0;
  }

  return r2;
}

rtems_task Init(
    rtems_task_argument ignored)
{
  (void)ignored;
  volatile int a = 10;
  volatile int b = 3;
  volatile int c = 4;
  volatile int result = compute_add_sub(a, b, c);

  printf("IU add/sub result = %d\n", result);
  exit(0);
}
