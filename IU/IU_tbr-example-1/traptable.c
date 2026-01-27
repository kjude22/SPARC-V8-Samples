/*
 * TBR (Trap Base Register) 예제
 * gdb에서도, 실행 로그에서도 쉽게 확인하도록 출력 포함.
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

const char rtems_test_name[] = "TBR TRAP TABLE TEST";

/* 링커가 제공하는 실제 Trap Table 심볼 */
extern char trap_table[];

/* gdb에서 바로 확인할 수 있도록 전역에 저장 */
volatile unsigned int tbr;
volatile unsigned int tba;
volatile unsigned int trap_table_addr;

/* TBR 레지스터 읽기 */
__attribute__((noinline, used))
static unsigned int read_tbr(void)
{
  unsigned int result;
  __asm__("rd %%tbr, %0" : "=r"(result));
  return result;
}

rtems_task Init(rtems_task_argument ignored)
{
  (void) ignored;

  TEST_BEGIN();

  /* TBR 읽기 및 TBA(31~11비트) 추출 */
  tbr = read_tbr();
  tba = tbr & 0xFFFFF000;

  /* trap_table 심볼 주소 */
  trap_table_addr = (unsigned int)trap_table;

  if (tba == trap_table_addr) {
    printf("Trap Table Address, Correct!\n");
  } else {
    printf("Mismatch!\n");
  }

  TEST_END();
  exit(0);
}
