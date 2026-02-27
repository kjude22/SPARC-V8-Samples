#include <rtems.h>
#include <rtems/test.h>
#include <rtems/test-info.h>
#include <stdlib.h>
#include <buffer_test_io.h>
#include <stdio.h>
#include <float.h>
#include <fenv.h>
#include <signal.h>
#include <math.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

const char rtems_test_name[] = "FSR FTT EXAMPLE";

/* SPARC V8 FSR bit fields */
#define FSR_TEM_SHIFT 23
#define FSR_TEM_MASK (0x3fu << FSR_TEM_SHIFT)

rtems_task Init(rtems_task_argument ignored)
{
    (void)ignored;
    TEST_BEGIN();

    /*
     * Floating-point compare in C.
     * With -O0 and volatile, the compiler should emit an FP compare+branch.
     */
    volatile float a = 1.5;
    volatile float b = 2.5;
    volatile int taken = 0;

    if (a >= b)
    {
        taken = 0;
    }
    else
    {
        taken = 1;
    }

    /* Prevent optimization away; inspect 'taken' in gdb if needed. */
    if (taken == 12345)
    {
        printf("impossible\n");
    }

    TEST_END();
    exit(0);
}
