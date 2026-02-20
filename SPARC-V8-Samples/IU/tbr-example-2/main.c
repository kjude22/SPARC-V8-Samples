/*
 * Simple addition / subtraction example
 * hello-world/hello.c 를 참고하여 기본적인 사칙 연산(덧셈/뺄셈)만 출력하는 샘플입니다.
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

const char rtems_test_name[] = "ARITH EXAMPLE";

rtems_task Init(rtems_task_argument ignored)
{
    (void)ignored;
    TEST_BEGIN();
    volatile int a = 3;
    volatile int zero = 0;
    volatile int result;
    result = a / zero;
    TEST_END();
    exit(0);
}
