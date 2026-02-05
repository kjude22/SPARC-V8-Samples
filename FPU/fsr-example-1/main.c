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

const char rtems_test_name[] = "ARITH EXAMPLE";

static inline void sparc_set_fsr(unsigned int fsr)
{
    __asm__ __volatile__("ld %0, %%fsr" : : "m"(fsr));
}

static inline unsigned int sparc_get_fsr(void)
{
    unsigned int fsr;
    __asm__ __volatile__("st %%fsr, %0" : "=m"(fsr));
    return fsr;
}

static inline void sparc_set_rounding_mode(unsigned int rd)
{
    unsigned int fsr = sparc_get_fsr();
    fsr = (fsr & ~(0x3u << 30)) | ((rd & 0x3u) << 30);
    sparc_set_fsr(fsr);
}

rtems_task Init(rtems_task_argument ignored)
{
    (void)ignored;
    TEST_BEGIN();

    /* Round-to-nearest even (default) */
    // sparc_set_rounding_mode(0);
    volatile float a = 1.5;
    volatile float b = -2.5;
    volatile float r1 = nearbyint(a);
    volatile float r2 = nearbyint(b);

    /* Round-toward-zero */
    sparc_set_rounding_mode(1);
    volatile float r3 = nearbyint(a);
    volatile float r4 = nearbyint(b);

    TEST_END();
    exit(0);
}
