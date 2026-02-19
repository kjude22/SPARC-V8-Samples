
#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <math.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
const char rtems_test_name[] = "UNION EXAMPLE";
union MyUnion {
    int i;
    char c[4];
};
rtems_task Init(rtems_task_argument ignored)
{
(void) ignored;
TEST_BEGIN();
volatile union MyUnion u;
u.c[0] = 'A';
u.c[1] = 'B';
u.c[2] = 'C';
u.c[3] = 'D';
u.i = 0x12345678;
TEST_END();
exit(0);
}
