
uart.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <UART0_Send_String>:
   0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   4:	e28db000 	add	fp, sp, #0
   8:	e24dd00c 	sub	sp, sp, #12
   c:	e50b0008 	str	r0, [fp, #-8]
  10:	ea000006 	b	30 <UART0_Send_String+0x30>
  14:	e59f3030 	ldr	r3, [pc, #48]	; 4c <UART0_Send_String+0x4c>
  18:	e51b2008 	ldr	r2, [fp, #-8]
  1c:	e5d22000 	ldrb	r2, [r2]
  20:	e5832000 	str	r2, [r3]
  24:	e51b3008 	ldr	r3, [fp, #-8]
  28:	e2833001 	add	r3, r3, #1
  2c:	e50b3008 	str	r3, [fp, #-8]
  30:	e51b3008 	ldr	r3, [fp, #-8]
  34:	e5d33000 	ldrb	r3, [r3]
  38:	e3530000 	cmp	r3, #0
  3c:	1afffff4 	bne	14 <UART0_Send_String+0x14>
  40:	e28bd000 	add	sp, fp, #0
  44:	e8bd0800 	ldmfd	sp!, {fp}
  48:	e12fff1e 	bx	lr
  4c:	101f1000 	andsne	r1, pc, r0

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000058 	andeq	r0, r0, r8, asr r0
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000000e 	andeq	r0, r0, lr
  10:	00002301 	andeq	r2, r0, r1, lsl #6
  14:	00003c00 	andeq	r3, r0, r0, lsl #24
  18:	00000000 	andeq	r0, r0, r0
  1c:	00005000 	andeq	r5, r0, r0
  20:	00000000 	andeq	r0, r0, r0
  24:	2a010200 	bcs	40808 <UART0_Send_String+0x40808>
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000105 	andeq	r0, r0, r5, lsl #2
  30:	00500000 	subseq	r0, r0, r0
  34:	00000000 	andeq	r0, r0, r0
  38:	4e010000 	cdpmi	0, 0, cr0, cr1, cr0, {0}
  3c:	03000000 	movweq	r0, #0
  40:	0000001a 	andeq	r0, r0, sl, lsl r0
  44:	004e0501 	subeq	r0, lr, r1, lsl #10
  48:	91020000 	mrsls	r0, (UNDEF: 2)
  4c:	04040074 	streq	r0, [r4], #-116	; 0x74
  50:	00000054 	andeq	r0, r0, r4, asr r0
  54:	00080105 	andeq	r0, r8, r5, lsl #2
  58:	00000000 	andeq	r0, r0, r0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f012e 	ldfeqs	f0, [pc], #-184	; ffffff64 <UART0_Send_String+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <UART0_Send_String+0xe8382c>
  1c:	0c270b3b 	stceq	11, cr0, [r7], #-236	; 0xffffff14
  20:	01120111 	tsteq	r2, r1, lsl r1
  24:	42970640 	addsmi	r0, r7, #64, 12	; 0x4000000
  28:	0013010c 	andseq	r0, r3, ip, lsl #2
  2c:	00050300 	andeq	r0, r5, r0, lsl #6
  30:	0b3a0e03 	bleq	e83844 <UART0_Send_String+0xe83844>
  34:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  38:	00000a02 	andeq	r0, r0, r2, lsl #20
  3c:	0b000f04 	bleq	3c54 <UART0_Send_String+0x3c54>
  40:	0013490b 	andseq	r4, r3, fp, lsl #18
  44:	00240500 	eoreq	r0, r4, r0, lsl #10
  48:	0b3e0b0b 	bleq	f82c7c <UART0_Send_String+0xf82c7c>
  4c:	00000e03 	andeq	r0, r0, r3, lsl #28
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	047d0002 	ldrbteq	r0, [sp], #-2
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000050 	andeq	r0, r0, r0, asr r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000039 	andeq	r0, r0, r9, lsr r0
   4:	001d0002 	andseq	r0, sp, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	74726175 	ldrbtvc	r6, [r2], #-373	; 0x175
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	00000000 	andeq	r0, r0, r0
  28:	00000205 	andeq	r0, r0, r5, lsl #4
  2c:	83170000 	tsthi	r7, #0
  30:	02008330 	andeq	r8, r0, #48, 6	; 0xc0000000
  34:	87630104 	strbhi	r0, [r3, -r4, lsl #2]!
  38:	01000802 	tsteq	r0, r2, lsl #16
  3c:	Address 0x0000003c is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	4e470072 	mcrmi	0, 2, r0, cr7, cr2, {3}
  10:	20432055 	subcs	r2, r3, r5, asr r0
  14:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  18:	5f500032 	svcpl	0x00500032
  1c:	535f5854 	cmppl	pc, #84, 16	; 0x540000
  20:	75007274 	strvc	r7, [r0, #-628]	; 0x274
  24:	2e747261 	cdpcs	2, 7, cr7, cr4, cr1, {3}
  28:	41550063 	cmpmi	r5, r3, rrx
  2c:	5f305452 	svcpl	0x00305452
  30:	646e6553 	strbtvs	r6, [lr], #-1363	; 0x553
  34:	7274535f 	rsbsvc	r5, r4, #2080374785	; 0x7c000001
  38:	00676e69 	rsbeq	r6, r7, r9, ror #28
  3c:	4b5c3a46 	blmi	170e95c <UART0_Send_String+0x170e95c>
  40:	6c697279 	sfmvs	f7, 2, [r9], #-484	; 0xfffffe1c
  44:	20736f6c 	rsbscs	r6, r3, ip, ror #30
  48:	6e656853 	mcrvs	8, 3, r6, cr5, cr3, {2}
  4c:	6164756f 	cmnvs	r4, pc, ror #10
  50:	624d4520 	subvs	r4, sp, #32, 10	; 0x8000000
  54:	65646465 	strbvs	r6, [r4, #-1125]!	; 0x465
  58:	65525c64 	ldrbvs	r5, [r2, #-3172]	; 0xc64
  5c:	4d5c6f70 	ldclmi	15, cr6, [ip, #-448]	; 0xfffffe40
  60:	65747361 	ldrbvs	r7, [r4, #-865]!	; 0x361
  64:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  68:	626d452d 	rsbvs	r4, sp, #188743680	; 0xb400000
  6c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0x465
  70:	79532d64 	ldmdbvc	r3, {r2, r5, r6, r8, sl, fp, sp}^
  74:	6d657473 	cfstrdvs	mvd7, [r5, #-460]!	; 0xfffffe34
  78:	6e555c73 	mrcvs	12, 2, r5, cr5, cr3, {3}
  7c:	335f7469 	cmpcc	pc, #1761607680	; 0x69000000
  80:	626d4520 	rsbvs	r4, sp, #32, 10	; 0x8000000
  84:	65646465 	strbvs	r6, [r4, #-1125]!	; 0x465
  88:	5c432064 	mcrrpl	0, 6, r2, r3, cr4
  8c:	202d2032 	eorcs	r2, sp, r2, lsr r0
  90:	7373654c 	cmnvc	r3, #76, 10	; 0x13000000
  94:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  98:	62614c5c 	rsbvs	r4, r1, #92, 24	; 0x5c00
  9c:	Address 0x0000009c is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000014 	andeq	r0, r0, r4, lsl r0
	...
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	8b040e42 	blhi	103930 <UART0_Send_String+0x103930>
  24:	0b0d4201 	bleq	350830 <UART0_Send_String+0x350830>
