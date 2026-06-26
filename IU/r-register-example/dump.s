
	.text

	.global _memcfg1, _memcfg2, _memcfg3, _sdmemcfg1,  _memcaddr, _uart, _dsuuart, _scaler,  _uaddr, _gptaddr, _irqmpaddr, _dsuuart_addr, _iserc32, _agga4, _doedac, _doft, _clean_ram0, _clean_ram0_size, _clean_ram1, _clean_ram1_size, _ddrspa_cfg1, _ddr2spa_cfg1, _ddr2spa_cfg3, _ddr2spa_cfg4, _dsustart, _dsutrace, _nopnp, _isddr, _pnp, _mp, _sdctrl_sdcfg, _spimcfg, _dsuctrl 

	.global _uartnr, _sparcleon0, _mpstart, freqkhz

	.global _mpirqsel0, _mpirqsel1, ftsdctrl64_pwr, ftsdctrl64_cfg, ftsdctrl64_edac, ftahbram_cfg

	.global ramsize, _stack, _entry
	.global freq, configmsg, bmsg, noinit
freq:
	.word	50
freqkhz:
	.word	50000
bmsg:
	.word	1
_iserc32:
	.word	0
_agga4:
	.word	0
_doedac:
	.word	0
_doft:
	.word	0
_sparcleon0:
	.word	1
_mpstart:
	.word	0
_mpirqsel0:
	.word	0x00000000
_mpirqsel1:
	.word	0x00000000
_dsustart:
	.word	0x90000000
_dsutrace:
	.word	0
_nopnp:
	.word	0
_isddr:
	.word	0
_pnp:
	.word	-2048
_mp:
	.word	0
_dsuctrl:
	.word	0xcf
_memcfg1:
	.word	0x803c0ff
_memcfg2:
	.word	0x8200020
_sdmemcfg1:
	.word	0x8200020
ftsdctrl64_cfg:
	.word	0x0
ftsdctrl64_pwr:
	.word	0x0
ftsdctrl64_edac:
	.word	0x0
ftahbram_cfg:
	.word	0x0
_ddr2spa_cfg1:
	.word	0x91a082bc
_ddr2spa_cfg3:
	.word	0x02290000
_ddr2spa_cfg4:
	.word	0x00000000
_ddrspa_cfg1:
	.word	0xa1a082bc
_sdctrl_sdcfg:
	.word	0x00000000
_spimcfg:
	.word	0x00000000
_uart:
	.word	0x00000145
_uaddr:
	.word	0xff900000
_uartnr:
	.word	 1
_dsuuart:
	.word	0
_memcfg3:
	.word	0x8000000
noinit:
	.word	0
_clean_ram0:
	.word	0x0
_clean_ram0_size:
	.word	0x0
_clean_ram1:
	.word	0x0
_clean_ram1_size:
	.word	0x0
_entry:
	.word	0xffffffff
ramsize:
	.word	0x0
_stack:
	.word	0xfffff00
_memcaddr:
	.word	0x80000000
_gptaddr:
	.word	0x80000300
_irqmpaddr:
	.word	0x80000200
_dsuuart_addr:
	.word	0x80000700
configmsg:
	.string	"  system clock   : 50.0 MHz\n\r  baud rate      : 19171 baud\n\r  prom           : 512 K, (2/2) ws (r/w)\n\r  sram           : 0 K, 1 bank(s), 0/0 ws (r/w)\n\r"

	.align 32

	.text

	.global filename
filename:
	.string	"app.exe"

	.align 32
	.global sections
sections:
	.word	0
	.word	0
