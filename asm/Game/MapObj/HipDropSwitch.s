.include "macros.inc"

.text

.global func_801E5484
func_801E5484:
/* 801E5484 001E09C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5488 001E09C8  7C 08 02 A6 */	mflr r0
/* 801E548C 001E09CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5490 001E09D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5494 001E09D4  7C 7F 1B 78 */	mr r31, r3
/* 801E5498 001E09D8  4B F7 FD 6D */	bl func_80165204
/* 801E549C 001E09DC  3C 80 80 58 */	lis r4, lbl_80581574@ha
/* 801E54A0 001E09E0  38 00 00 00 */	li r0, 0
/* 801E54A4 001E09E4  38 84 15 74 */	addi r4, r4, lbl_80581574@l
/* 801E54A8 001E09E8  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 801E54AC 001E09EC  38 60 00 14 */	li r3, 0x14
/* 801E54B0 001E09F0  90 9F 00 00 */	stw r4, 0(r31)
/* 801E54B4 001E09F4  90 1F 00 94 */	stw r0, 0x94(r31)
/* 801E54B8 001E09F8  90 1F 00 98 */	stw r0, 0x98(r31)
/* 801E54BC 001E09FC  98 1F 00 CC */	stb r0, 0xcc(r31)
/* 801E54C0 001E0A00  98 1F 00 CD */	stb r0, 0xcd(r31)
/* 801E54C4 001E0A04  98 1F 00 CE */	stb r0, 0xce(r31)
/* 801E54C8 001E0A08  48 22 46 31 */	bl func_80409AF8
/* 801E54CC 001E0A0C  2C 03 00 00 */	cmpwi r3, 0
/* 801E54D0 001E0A10  41 82 00 08 */	beq lbl_801E54D8
/* 801E54D4 001E0A14  48 22 15 C9 */	bl func_80406A9C
lbl_801E54D8:
/* 801E54D8 001E0A18  90 7F 00 90 */	stw r3, 0x90(r31)
/* 801E54DC 001E0A1C  38 60 00 38 */	li r3, 0x38
/* 801E54E0 001E0A20  48 22 46 19 */	bl func_80409AF8
/* 801E54E4 001E0A24  2C 03 00 00 */	cmpwi r3, 0
/* 801E54E8 001E0A28  41 82 00 0C */	beq lbl_801E54F4
/* 801E54EC 001E0A2C  7F E4 FB 78 */	mr r4, r31
/* 801E54F0 001E0A30  48 01 2F 15 */	bl func_801F8404
lbl_801E54F4:
/* 801E54F4 001E0A34  C0 22 D5 D0 */	lfs f1, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E54F8 001E0A38  90 7F 00 94 */	stw r3, 0x94(r31)
/* 801E54FC 001E0A3C  FC 40 08 90 */	fmr f2, f1
/* 801E5500 001E0A40  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 801E5504 001E0A44  FC A0 08 90 */	fmr f5, f1
/* 801E5508 001E0A48  C0 62 D5 D4 */	lfs f3, lbl_806A8854-_SDA2_BASE_(r2)
/* 801E550C 001E0A4C  C0 82 D5 D8 */	lfs f4, lbl_806A8858-_SDA2_BASE_(r2)
/* 801E5510 001E0A50  48 22 15 C9 */	bl func_80406AD8
/* 801E5514 001E0A54  38 7F 00 9C */	addi r3, r31, 0x9c
/* 801E5518 001E0A58  4B E3 10 99 */	bl func_800165B0
/* 801E551C 001E0A5C  7F E3 FB 78 */	mr r3, r31
/* 801E5520 001E0A60  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5524 001E0A64  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5528 001E0A68  7C 08 03 A6 */	mtlr r0
/* 801E552C 001E0A6C  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5530 001E0A70  4E 80 00 20 */	blr 
/* 801E5534 001E0A74  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801E5538 001E0A78  7C 08 02 A6 */	mflr r0
/* 801E553C 001E0A7C  90 01 00 44 */	stw r0, 0x44(r1)
/* 801E5540 001E0A80  39 61 00 40 */	addi r11, r1, 0x40
/* 801E5544 001E0A84  48 33 1F F5 */	bl func_80517538
/* 801E5548 001E0A88  3F E0 80 58 */	lis r31, lbl_80581528@ha
/* 801E554C 001E0A8C  7C 7D 1B 78 */	mr r29, r3
/* 801E5550 001E0A90  7C 9E 23 78 */	mr r30, r4
/* 801E5554 001E0A94  3B FF 15 28 */	addi r31, r31, lbl_80581528@l
/* 801E5558 001E0A98  48 1F 45 25 */	bl func_803D9A7C
/* 801E555C 001E0A9C  7F A3 EB 78 */	mr r3, r29
/* 801E5560 001E0AA0  38 9F 00 00 */	addi r4, r31, 0
/* 801E5564 001E0AA4  38 A0 00 00 */	li r5, 0
/* 801E5568 001E0AA8  38 C0 00 00 */	li r6, 0
/* 801E556C 001E0AAC  4B F8 04 59 */	bl func_801659C4
/* 801E5570 001E0AB0  7F A3 EB 78 */	mr r3, r29
/* 801E5574 001E0AB4  48 20 9C 29 */	bl func_803EF19C
/* 801E5578 001E0AB8  7F A3 EB 78 */	mr r3, r29
/* 801E557C 001E0ABC  48 1F 6F 75 */	bl func_803DC4F0
/* 801E5580 001E0AC0  7F A3 EB 78 */	mr r3, r29
/* 801E5584 001E0AC4  38 80 00 04 */	li r4, 4
/* 801E5588 001E0AC8  38 A0 00 00 */	li r5, 0
/* 801E558C 001E0ACC  4B F8 07 31 */	bl func_80165CBC
/* 801E5590 001E0AD0  7F A3 EB 78 */	mr r3, r29
/* 801E5594 001E0AD4  38 80 00 02 */	li r4, 2
/* 801E5598 001E0AD8  4B F8 05 21 */	bl func_80165AB8
/* 801E559C 001E0ADC  C0 22 D5 D0 */	lfs f1, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E55A0 001E0AE0  38 61 00 20 */	addi r3, r1, 0x20
/* 801E55A4 001E0AE4  FC 40 08 90 */	fmr f2, f1
/* 801E55A8 001E0AE8  FC 60 08 90 */	fmr f3, f1
/* 801E55AC 001E0AEC  4B E3 36 19 */	bl func_80018BC4
/* 801E55B0 001E0AF0  C0 22 D5 D0 */	lfs f1, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E55B4 001E0AF4  7C 66 1B 78 */	mr r6, r3
/* 801E55B8 001E0AF8  7F A3 EB 78 */	mr r3, r29
/* 801E55BC 001E0AFC  38 9F 00 0E */	addi r4, r31, 0xe
/* 801E55C0 001E0B00  38 A0 00 10 */	li r5, 0x10
/* 801E55C4 001E0B04  48 1D C5 B1 */	bl func_803C1B74
/* 801E55C8 001E0B08  C0 22 D5 D0 */	lfs f1, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E55CC 001E0B0C  38 61 00 14 */	addi r3, r1, 0x14
/* 801E55D0 001E0B10  FC 40 08 90 */	fmr f2, f1
/* 801E55D4 001E0B14  FC 60 08 90 */	fmr f3, f1
/* 801E55D8 001E0B18  4B E3 35 ED */	bl func_80018BC4
/* 801E55DC 001E0B1C  C0 22 D5 D0 */	lfs f1, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E55E0 001E0B20  7C 66 1B 78 */	mr r6, r3
/* 801E55E4 001E0B24  7F A3 EB 78 */	mr r3, r29
/* 801E55E8 001E0B28  38 8D 88 18 */	addi r4, r13, lbl_8069D4B8-_SDA_BASE_
/* 801E55EC 001E0B2C  38 A0 00 10 */	li r5, 0x10
/* 801E55F0 001E0B30  48 1D C5 85 */	bl func_803C1B74
/* 801E55F4 001E0B34  C0 02 D5 D0 */	lfs f0, lbl_806A8850-_SDA2_BASE_(r2)
/* 801E55F8 001E0B38  7F A3 EB 78 */	mr r3, r29
/* 801E55FC 001E0B3C  C0 22 D5 DC */	lfs f1, lbl_806A885C-_SDA2_BASE_(r2)
/* 801E5600 001E0B40  38 81 00 08 */	addi r4, r1, 8
/* 801E5604 001E0B44  D0 01 00 08 */	stfs f0, 8(r1)
/* 801E5608 001E0B48  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 801E560C 001E0B4C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 801E5610 001E0B50  48 21 51 51 */	bl func_803FA760
/* 801E5614 001E0B54  7F A3 EB 78 */	mr r3, r29
/* 801E5618 001E0B58  38 9F 00 0E */	addi r4, r31, 0xe
/* 801E561C 001E0B5C  4B F8 02 59 */	bl func_80165874
/* 801E5620 001E0B60  7C 65 1B 78 */	mr r5, r3
/* 801E5624 001E0B64  7F A3 EB 78 */	mr r3, r29
/* 801E5628 001E0B68  38 9F 00 00 */	addi r4, r31, 0
/* 801E562C 001E0B6C  38 C0 00 00 */	li r6, 0
/* 801E5630 001E0B70  48 1F 8B 49 */	bl func_803DE178
/* 801E5634 001E0B74  7F A3 EB 78 */	mr r3, r29
/* 801E5638 001E0B78  38 8D 88 18 */	addi r4, r13, lbl_8069D4B8-_SDA_BASE_
/* 801E563C 001E0B7C  4B F8 02 39 */	bl func_80165874
/* 801E5640 001E0B80  7C 65 1B 78 */	mr r5, r3
/* 801E5644 001E0B84  7F A3 EB 78 */	mr r3, r29
/* 801E5648 001E0B88  38 9F 00 13 */	addi r4, r31, 0x13
/* 801E564C 001E0B8C  38 C0 00 02 */	li r6, 2
/* 801E5650 001E0B90  48 1F 8B 71 */	bl func_803DE1C0
/* 801E5654 001E0B94  90 7D 00 98 */	stw r3, 0x98(r29)
/* 801E5658 001E0B98  48 1F 90 95 */	bl func_803DE6EC
/* 801E565C 001E0B9C  7F A3 EB 78 */	mr r3, r29
/* 801E5660 001E0BA0  38 8D BB E8 */	addi r4, r13, lbl_806A0888-_SDA_BASE_
/* 801E5664 001E0BA4  4B F8 04 01 */	bl func_80165A64
/* 801E5668 001E0BA8  7F A3 EB 78 */	mr r3, r29
/* 801E566C 001E0BAC  7F C4 F3 78 */	mr r4, r30
/* 801E5670 001E0BB0  48 1E 13 A1 */	bl func_803C6A10
/* 801E5674 001E0BB4  7F A3 EB 78 */	mr r3, r29
/* 801E5678 001E0BB8  7F C4 F3 78 */	mr r4, r30
/* 801E567C 001E0BBC  48 1E 11 85 */	bl func_803C6800
/* 801E5680 001E0BC0  2C 03 00 00 */	cmpwi r3, 0
/* 801E5684 001E0BC4  41 82 00 24 */	beq lbl_801E56A8
/* 801E5688 001E0BC8  7F A3 EB 78 */	mr r3, r29
/* 801E568C 001E0BCC  48 1E 14 F9 */	bl func_803C6B84
/* 801E5690 001E0BD0  81 9D 00 00 */	lwz r12, 0(r29)
/* 801E5694 001E0BD4  7F A3 EB 78 */	mr r3, r29
/* 801E5698 001E0BD8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 801E569C 001E0BDC  7D 89 03 A6 */	mtctr r12
/* 801E56A0 001E0BE0  4E 80 04 21 */	bctrl 
/* 801E56A4 001E0BE4  48 00 00 18 */	b lbl_801E56BC
lbl_801E56A8:
/* 801E56A8 001E0BE8  81 9D 00 00 */	lwz r12, 0(r29)
/* 801E56AC 001E0BEC  7F A3 EB 78 */	mr r3, r29
/* 801E56B0 001E0BF0  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 801E56B4 001E0BF4  7D 89 03 A6 */	mtctr r12
/* 801E56B8 001E0BF8  4E 80 04 21 */	bctrl 
lbl_801E56BC:
/* 801E56BC 001E0BFC  39 61 00 40 */	addi r11, r1, 0x40
/* 801E56C0 001E0C00  48 33 1E C5 */	bl func_80517584
/* 801E56C4 001E0C04  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801E56C8 001E0C08  7C 08 03 A6 */	mtlr r0
/* 801E56CC 001E0C0C  38 21 00 40 */	addi r1, r1, 0x40
/* 801E56D0 001E0C10  4E 80 00 20 */	blr 
/* 801E56D4 001E0C14  80 63 00 94 */	lwz r3, 0x94(r3)
/* 801E56D8 001E0C18  48 01 2D 6C */	b func_801F8444
/* 801E56DC 001E0C1C  88 03 00 CE */	lbz r0, 0xce(r3)
/* 801E56E0 001E0C20  38 80 00 00 */	li r4, 0
/* 801E56E4 001E0C24  98 83 00 CC */	stb r4, 0xcc(r3)
/* 801E56E8 001E0C28  98 03 00 CD */	stb r0, 0xcd(r3)
/* 801E56EC 001E0C2C  98 83 00 CE */	stb r4, 0xce(r3)
/* 801E56F0 001E0C30  4E 80 00 20 */	blr 
/* 801E56F4 001E0C34  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 801E56F8 001E0C38  7C 08 02 A6 */	mflr r0
/* 801E56FC 001E0C3C  90 01 00 84 */	stw r0, 0x84(r1)
/* 801E5700 001E0C40  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 801E5704 001E0C44  F3 E1 00 78 */	psq_st f31, 120(r1), 0, 0
/* 801E5708 001E0C48  39 61 00 70 */	addi r11, r1, 0x70
/* 801E570C 001E0C4C  48 33 1E 2D */	bl func_80517538
/* 801E5710 001E0C50  7C 7D 1B 78 */	mr r29, r3
/* 801E5714 001E0C54  4B F7 FE 81 */	bl func_80165594
/* 801E5718 001E0C58  3C 80 80 58 */	lis r4, lbl_8058153B@ha
/* 801E571C 001E0C5C  7F A3 EB 78 */	mr r3, r29
/* 801E5720 001E0C60  38 84 15 3B */	addi r4, r4, lbl_8058153B@l
/* 801E5724 001E0C64  48 1E F9 91 */	bl func_803D50B4
/* 801E5728 001E0C68  E0 03 00 00 */	psq_l f0, 0(r3), 0, 0
/* 801E572C 001E0C6C  3B E1 00 2C */	addi r31, r1, 0x2c
/* 801E5730 001E0C70  E0 23 00 08 */	psq_l f1, 8(r3), 0, 0
/* 801E5734 001E0C74  7C 7E 1B 78 */	mr r30, r3
/* 801E5738 001E0C78  E0 63 00 10 */	psq_l f3, 16(r3), 0, 0
/* 801E573C 001E0C7C  E0 83 00 18 */	psq_l f4, 24(r3), 0, 0
/* 801E5740 001E0C80  E0 A3 00 20 */	psq_l f5, 32(r3), 0, 0
/* 801E5744 001E0C84  E0 C3 00 28 */	psq_l f6, 40(r3), 0, 0
/* 801E5748 001E0C88  C0 42 D5 E0 */	lfs f2, lbl_806A8860-_SDA2_BASE_(r2)
/* 801E574C 001E0C8C  F0 1F 00 00 */	psq_st f0, 0(r31), 0, 0
/* 801E5750 001E0C90  F0 3F 00 08 */	psq_st f1, 8(r31), 0, 0
/* 801E5754 001E0C94  F0 7F 00 10 */	psq_st f3, 16(r31), 0, 0
/* 801E5758 001E0C98  F0 9F 00 18 */	psq_st f4, 24(r31), 0, 0
/* 801E575C 001E0C9C  F0 BF 00 20 */	psq_st f5, 32(r31), 0, 0
/* 801E5760 001E0CA0  F0 DF 00 28 */	psq_st f6, 40(r31), 0, 0
/* 801E5764 001E0CA4  80 7D 00 90 */	lwz r3, 0x90(r29)
/* 801E5768 001E0CA8  C3 E3 00 04 */	lfs f31, 4(r3)
/* 801E576C 001E0CAC  FC 20 F8 90 */	fmr f1, f31
/* 801E5770 001E0CB0  48 20 01 C5 */	bl func_803E5934
/* 801E5774 001E0CB4  2C 03 00 00 */	cmpwi r3, 0
/* 801E5778 001E0CB8  40 82 00 94 */	bne lbl_801E580C
/* 801E577C 001E0CBC  C0 61 00 58 */	lfs f3, 0x58(r1)
/* 801E5780 001E0CC0  38 61 00 20 */	addi r3, r1, 0x20
/* 801E5784 001E0CC4  C0 41 00 48 */	lfs f2, 0x48(r1)
/* 801E5788 001E0CC8  C0 21 00 38 */	lfs f1, 0x38(r1)
/* 801E578C 001E0CCC  4B E3 17 F5 */	bl func_80016F80
/* 801E5790 001E0CD0  7F A4 EB 78 */	mr r4, r29
/* 801E5794 001E0CD4  38 61 00 14 */	addi r3, r1, 0x14
/* 801E5798 001E0CD8  48 1D 80 A9 */	bl func_803BD840
/* 801E579C 001E0CDC  E0 21 00 14 */	psq_l f1, 20(r1), 0, 0
/* 801E57A0 001E0CE0  7F E3 FB 78 */	mr r3, r31
/* 801E57A4 001E0CE4  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 801E57A8 001E0CE8  7F C4 F3 78 */	mr r4, r30
/* 801E57AC 001E0CEC  F0 21 00 08 */	psq_st f1, 8(r1), 0, 0
/* 801E57B0 001E0CF0  EC 00 07 F2 */	fmuls f0, f0, f31
/* 801E57B4 001E0CF4  E0 61 80 28 */	psq_l f3, 40(r1), 1, 0
/* 801E57B8 001E0CF8  C0 41 00 08 */	lfs f2, 8(r1)
/* 801E57BC 001E0CFC  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 801E57C0 001E0D00  EC 42 07 F2 */	fmuls f2, f2, f31
/* 801E57C4 001E0D04  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 801E57C8 001E0D08  EC 01 07 F2 */	fmuls f0, f1, f31
/* 801E57CC 001E0D0C  E0 81 00 20 */	psq_l f4, 32(r1), 0, 0
/* 801E57D0 001E0D10  E0 21 80 10 */	psq_l f1, 16(r1), 1, 0
/* 801E57D4 001E0D14  D0 41 00 08 */	stfs f2, 8(r1)
/* 801E57D8 001E0D18  10 23 08 2A */	ps_add f1, f3, f1
/* 801E57DC 001E0D1C  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 801E57E0 001E0D20  E0 01 00 08 */	psq_l f0, 8(r1), 0, 0
/* 801E57E4 001E0D24  F0 21 80 28 */	psq_st f1, 40(r1), 1, 0
/* 801E57E8 001E0D28  10 24 00 2A */	ps_add f1, f4, f0
/* 801E57EC 001E0D2C  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 801E57F0 001E0D30  F0 21 00 20 */	psq_st f1, 32(r1), 0, 0
/* 801E57F4 001E0D34  C0 41 00 20 */	lfs f2, 0x20(r1)
/* 801E57F8 001E0D38  C0 21 00 24 */	lfs f1, 0x24(r1)
/* 801E57FC 001E0D3C  D0 41 00 38 */	stfs f2, 0x38(r1)
/* 801E5800 001E0D40  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 801E5804 001E0D44  D0 01 00 58 */	stfs f0, 0x58(r1)
/* 801E5808 001E0D48  48 2D 07 01 */	bl func_804B5F08
lbl_801E580C:
/* 801E580C 001E0D4C  80 7D 00 98 */	lwz r3, 0x98(r29)
/* 801E5810 001E0D50  38 81 00 2C */	addi r4, r1, 0x2c
/* 801E5814 001E0D54  4B F9 05 15 */	bl func_80175D28
/* 801E5818 001E0D58  E3 E1 00 78 */	psq_l f31, 120(r1), 0, 0
/* 801E581C 001E0D5C  39 61 00 70 */	addi r11, r1, 0x70
/* 801E5820 001E0D60  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 801E5824 001E0D64  48 33 1D 61 */	bl func_80517584
/* 801E5828 001E0D68  80 01 00 84 */	lwz r0, 0x84(r1)
/* 801E582C 001E0D6C  7C 08 03 A6 */	mtlr r0
/* 801E5830 001E0D70  38 21 00 80 */	addi r1, r1, 0x80
/* 801E5834 001E0D74  4E 80 00 20 */	blr 
/* 801E5838 001E0D78  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E583C 001E0D7C  7C 08 02 A6 */	mflr r0
/* 801E5840 001E0D80  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5844 001E0D84  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5848 001E0D88  7C 7F 1B 78 */	mr r31, r3
/* 801E584C 001E0D8C  4B F7 FF 25 */	bl func_80165770
/* 801E5850 001E0D90  80 7F 00 94 */	lwz r3, 0x94(r31)
/* 801E5854 001E0D94  48 01 2D 8D */	bl func_801F85E0
/* 801E5858 001E0D98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E585C 001E0D9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5860 001E0DA0  7C 08 03 A6 */	mtlr r0
/* 801E5864 001E0DA4  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5868 001E0DA8  4E 80 00 20 */	blr 
/* 801E586C 001E0DAC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E5870 001E0DB0  7C 08 02 A6 */	mflr r0
/* 801E5874 001E0DB4  90 01 00 24 */	stw r0, 0x24(r1)
/* 801E5878 001E0DB8  39 61 00 20 */	addi r11, r1, 0x20
/* 801E587C 001E0DBC  48 33 1C BD */	bl func_80517538
/* 801E5880 001E0DC0  7C 9E 23 78 */	mr r30, r4
/* 801E5884 001E0DC4  7C 7D 1B 78 */	mr r29, r3
/* 801E5888 001E0DC8  7C DF 33 78 */	mr r31, r6
/* 801E588C 001E0DCC  7F C3 F3 78 */	mr r3, r30
/* 801E5890 001E0DD0  48 1D DF 69 */	bl func_803C37F8
/* 801E5894 001E0DD4  2C 03 00 00 */	cmpwi r3, 0
/* 801E5898 001E0DD8  41 82 00 14 */	beq lbl_801E58AC
/* 801E589C 001E0DDC  38 00 00 01 */	li r0, 1
/* 801E58A0 001E0DE0  38 60 00 01 */	li r3, 1
/* 801E58A4 001E0DE4  98 1D 00 CE */	stb r0, 0xce(r29)
/* 801E58A8 001E0DE8  48 00 00 44 */	b lbl_801E58EC
lbl_801E58AC:
/* 801E58AC 001E0DEC  7F C3 F3 78 */	mr r3, r30
/* 801E58B0 001E0DF0  48 1D DC 59 */	bl func_803C3508
/* 801E58B4 001E0DF4  2C 03 00 00 */	cmpwi r3, 0
/* 801E58B8 001E0DF8  41 82 00 30 */	beq lbl_801E58E8
/* 801E58BC 001E0DFC  80 7D 00 98 */	lwz r3, 0x98(r29)
/* 801E58C0 001E0E00  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 801E58C4 001E0E04  7C 00 F8 40 */	cmplw r0, r31
/* 801E58C8 001E0E08  40 82 00 20 */	bne lbl_801E58E8
/* 801E58CC 001E0E0C  88 1D 00 CC */	lbz r0, 0xcc(r29)
/* 801E58D0 001E0E10  2C 00 00 00 */	cmpwi r0, 0
/* 801E58D4 001E0E14  40 82 00 14 */	bne lbl_801E58E8
/* 801E58D8 001E0E18  38 00 00 01 */	li r0, 1
/* 801E58DC 001E0E1C  38 60 00 01 */	li r3, 1
/* 801E58E0 001E0E20  98 1D 00 CC */	stb r0, 0xcc(r29)
/* 801E58E4 001E0E24  48 00 00 08 */	b lbl_801E58EC
lbl_801E58E8:
/* 801E58E8 001E0E28  38 60 00 00 */	li r3, 0
lbl_801E58EC:
/* 801E58EC 001E0E2C  39 61 00 20 */	addi r11, r1, 0x20
/* 801E58F0 001E0E30  48 33 1C 95 */	bl func_80517584
/* 801E58F4 001E0E34  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801E58F8 001E0E38  7C 08 03 A6 */	mtlr r0
/* 801E58FC 001E0E3C  38 21 00 20 */	addi r1, r1, 0x20
/* 801E5900 001E0E40  4E 80 00 20 */	blr 
/* 801E5904 001E0E44  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5908 001E0E48  7C 08 02 A6 */	mflr r0
/* 801E590C 001E0E4C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5910 001E0E50  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5914 001E0E54  7C DF 33 78 */	mr r31, r6
/* 801E5918 001E0E58  93 C1 00 08 */	stw r30, 8(r1)
/* 801E591C 001E0E5C  7C 7E 1B 78 */	mr r30, r3
/* 801E5920 001E0E60  7C 83 23 78 */	mr r3, r4
/* 801E5924 001E0E64  48 1D DC C5 */	bl func_803C35E8
/* 801E5928 001E0E68  2C 03 00 00 */	cmpwi r3, 0
/* 801E592C 001E0E6C  41 82 00 2C */	beq lbl_801E5958
/* 801E5930 001E0E70  80 7E 00 98 */	lwz r3, 0x98(r30)
/* 801E5934 001E0E74  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 801E5938 001E0E78  7C 00 F8 40 */	cmplw r0, r31
/* 801E593C 001E0E7C  40 82 00 1C */	bne lbl_801E5958
/* 801E5940 001E0E80  88 1E 00 CD */	lbz r0, 0xcd(r30)
/* 801E5944 001E0E84  38 60 00 01 */	li r3, 1
/* 801E5948 001E0E88  98 7E 00 CE */	stb r3, 0xce(r30)
/* 801E594C 001E0E8C  7C 00 00 34 */	cntlzw r0, r0
/* 801E5950 001E0E90  54 03 D9 7E */	srwi r3, r0, 5
/* 801E5954 001E0E94  48 00 00 08 */	b lbl_801E595C
lbl_801E5958:
/* 801E5958 001E0E98  38 60 00 00 */	li r3, 0
lbl_801E595C:
/* 801E595C 001E0E9C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5960 001E0EA0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5964 001E0EA4  83 C1 00 08 */	lwz r30, 8(r1)
/* 801E5968 001E0EA8  7C 08 03 A6 */	mtlr r0
/* 801E596C 001E0EAC  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5970 001E0EB0  4E 80 00 20 */	blr 

.global func_801E5974
func_801E5974:
/* 801E5974 001E0EB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5978 001E0EB8  7C 08 02 A6 */	mflr r0
/* 801E597C 001E0EBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5980 001E0EC0  88 03 00 CC */	lbz r0, 0xcc(r3)
/* 801E5984 001E0EC4  2C 00 00 00 */	cmpwi r0, 0
/* 801E5988 001E0EC8  41 82 00 14 */	beq lbl_801E599C
/* 801E598C 001E0ECC  38 8D BB EC */	addi r4, r13, lbl_806A088C-_SDA_BASE_
/* 801E5990 001E0ED0  4B F7 FE 95 */	bl func_80165824
/* 801E5994 001E0ED4  38 60 00 01 */	li r3, 1
/* 801E5998 001E0ED8  48 00 00 08 */	b lbl_801E59A0
lbl_801E599C:
/* 801E599C 001E0EDC  38 60 00 00 */	li r3, 0
lbl_801E59A0:
/* 801E59A0 001E0EE0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E59A4 001E0EE4  7C 08 03 A6 */	mtlr r0
/* 801E59A8 001E0EE8  38 21 00 10 */	addi r1, r1, 0x10
/* 801E59AC 001E0EEC  4E 80 00 20 */	blr 

.global func_801E59B0
func_801E59B0:
/* 801E59B0 001E0EF0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E59B4 001E0EF4  7C 08 02 A6 */	mflr r0
/* 801E59B8 001E0EF8  38 80 00 00 */	li r4, 0
/* 801E59BC 001E0EFC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E59C0 001E0F00  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E59C4 001E0F04  7C 7F 1B 78 */	mr r31, r3
/* 801E59C8 001E0F08  48 1F 6D A9 */	bl func_803DC770
/* 801E59CC 001E0F0C  2C 03 00 00 */	cmpwi r3, 0
/* 801E59D0 001E0F10  41 82 00 28 */	beq lbl_801E59F8
/* 801E59D4 001E0F14  7F E3 FB 78 */	mr r3, r31
/* 801E59D8 001E0F18  48 1F 58 D9 */	bl func_803DB2B0
/* 801E59DC 001E0F1C  2C 03 00 00 */	cmpwi r3, 0
/* 801E59E0 001E0F20  41 82 00 18 */	beq lbl_801E59F8
/* 801E59E4 001E0F24  7F E3 FB 78 */	mr r3, r31
/* 801E59E8 001E0F28  38 8D BB F0 */	addi r4, r13, lbl_806A0890-_SDA_BASE_
/* 801E59EC 001E0F2C  4B F7 FE 39 */	bl func_80165824
/* 801E59F0 001E0F30  38 60 00 01 */	li r3, 1
/* 801E59F4 001E0F34  48 00 00 08 */	b lbl_801E59FC
lbl_801E59F8:
/* 801E59F8 001E0F38  38 60 00 00 */	li r3, 0
lbl_801E59FC:
/* 801E59FC 001E0F3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5A00 001E0F40  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5A04 001E0F44  7C 08 03 A6 */	mtlr r0
/* 801E5A08 001E0F48  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5A0C 001E0F4C  4E 80 00 20 */	blr 
lbl_801E5A10:
/* 801E5A10 001E0F50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5A14 001E0F54  7C 08 02 A6 */	mflr r0
/* 801E5A18 001E0F58  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5A1C 001E0F5C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5A20 001E0F60  7C 7F 1B 78 */	mr r31, r3
/* 801E5A24 001E0F64  48 1F 6C C9 */	bl func_803DC6EC
/* 801E5A28 001E0F68  2C 03 00 00 */	cmpwi r3, 0
/* 801E5A2C 001E0F6C  41 82 00 44 */	beq lbl_801E5A70
/* 801E5A30 001E0F70  38 00 00 00 */	li r0, 0
/* 801E5A34 001E0F74  7F E3 FB 78 */	mr r3, r31
/* 801E5A38 001E0F78  98 1F 00 CC */	stb r0, 0xcc(r31)
/* 801E5A3C 001E0F7C  48 1F 46 71 */	bl func_803DA0AC
/* 801E5A40 001E0F80  7F E3 FB 78 */	mr r3, r31
/* 801E5A44 001E0F84  48 1E 11 29 */	bl func_803C6B6C
/* 801E5A48 001E0F88  3C 80 80 58 */	lis r4, lbl_80581540@ha
/* 801E5A4C 001E0F8C  7F E3 FB 78 */	mr r3, r31
/* 801E5A50 001E0F90  38 84 15 40 */	addi r4, r4, lbl_80581540@l
/* 801E5A54 001E0F94  38 A0 00 00 */	li r5, 0
/* 801E5A58 001E0F98  48 1F 4F C1 */	bl func_803DAA18
/* 801E5A5C 001E0F9C  7F E3 FB 78 */	mr r3, r31
/* 801E5A60 001E0FA0  38 8D 88 1C */	addi r4, r13, lbl_8069D4BC-_SDA_BASE_
/* 801E5A64 001E0FA4  48 1F 5D 99 */	bl func_803DB7FC
/* 801E5A68 001E0FA8  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 801E5A6C 001E0FAC  4B FE 8C 51 */	bl func_801CE6BC
lbl_801E5A70:
/* 801E5A70 001E0FB0  7F E3 FB 78 */	mr r3, r31
/* 801E5A74 001E0FB4  38 8D 88 20 */	addi r4, r13, lbl_8069D4C0-_SDA_BASE_
/* 801E5A78 001E0FB8  38 A0 00 01 */	li r5, 1
/* 801E5A7C 001E0FBC  38 C0 00 00 */	li r6, 0
/* 801E5A80 001E0FC0  48 21 55 15 */	bl func_803FAF94
/* 801E5A84 001E0FC4  2C 03 00 00 */	cmpwi r3, 0
/* 801E5A88 001E0FC8  41 82 00 0C */	beq lbl_801E5A94
/* 801E5A8C 001E0FCC  38 00 00 01 */	li r0, 1
/* 801E5A90 001E0FD0  98 1F 00 CE */	stb r0, 0xce(r31)
lbl_801E5A94:
/* 801E5A94 001E0FD4  88 1F 00 CD */	lbz r0, 0xcd(r31)
/* 801E5A98 001E0FD8  2C 00 00 00 */	cmpwi r0, 0
/* 801E5A9C 001E0FDC  40 82 00 3C */	bne lbl_801E5AD8
/* 801E5AA0 001E0FE0  88 1F 00 CE */	lbz r0, 0xce(r31)
/* 801E5AA4 001E0FE4  2C 00 00 00 */	cmpwi r0, 0
/* 801E5AA8 001E0FE8  41 82 00 30 */	beq lbl_801E5AD8
/* 801E5AAC 001E0FEC  80 FF 00 90 */	lwz r7, 0x90(r31)
/* 801E5AB0 001E0FF0  3C 80 80 58 */	lis r4, lbl_80581545@ha
/* 801E5AB4 001E0FF4  C0 02 D5 E4 */	lfs f0, lbl_806A8864-_SDA2_BASE_(r2)
/* 801E5AB8 001E0FF8  7F E3 FB 78 */	mr r3, r31
/* 801E5ABC 001E0FFC  C0 27 00 10 */	lfs f1, 0x10(r7)
/* 801E5AC0 001E1000  38 84 15 45 */	addi r4, r4, lbl_80581545@l
/* 801E5AC4 001E1004  38 A0 FF FF */	li r5, -1
/* 801E5AC8 001E1008  38 C0 FF FF */	li r6, -1
/* 801E5ACC 001E100C  EC 01 00 2A */	fadds f0, f1, f0
/* 801E5AD0 001E1010  D0 07 00 10 */	stfs f0, 0x10(r7)
/* 801E5AD4 001E1014  48 21 2F 69 */	bl func_803F8A3C
lbl_801E5AD8:
/* 801E5AD8 001E1018  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 801E5ADC 001E101C  48 22 10 15 */	bl func_80406AF0
/* 801E5AE0 001E1020  7F E3 FB 78 */	mr r3, r31
/* 801E5AE4 001E1024  4B FF FE 91 */	bl func_801E5974
/* 801E5AE8 001E1028  2C 03 00 00 */	cmpwi r3, 0
/* 801E5AEC 001E102C  41 82 00 0C */	beq lbl_801E5AF8
/* 801E5AF0 001E1030  80 7F 00 90 */	lwz r3, 0x90(r31)
/* 801E5AF4 001E1034  4B FE 8B C9 */	bl func_801CE6BC
lbl_801E5AF8:
/* 801E5AF8 001E1038  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5AFC 001E103C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5B00 001E1040  7C 08 03 A6 */	mtlr r0
/* 801E5B04 001E1044  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5B08 001E1048  4E 80 00 20 */	blr 
lbl_801E5B0C:
/* 801E5B0C 001E104C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5B10 001E1050  7C 08 02 A6 */	mflr r0
/* 801E5B14 001E1054  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5B18 001E1058  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5B1C 001E105C  7C 7F 1B 78 */	mr r31, r3
/* 801E5B20 001E1060  48 1F 6B CD */	bl func_803DC6EC
/* 801E5B24 001E1064  2C 03 00 00 */	cmpwi r3, 0
/* 801E5B28 001E1068  41 82 00 0C */	beq lbl_801E5B34
/* 801E5B2C 001E106C  7F E3 FB 78 */	mr r3, r31
/* 801E5B30 001E1070  48 1F 45 C1 */	bl func_803DA0F0
lbl_801E5B34:
/* 801E5B34 001E1074  7F E3 FB 78 */	mr r3, r31
/* 801E5B38 001E1078  38 80 00 00 */	li r4, 0
/* 801E5B3C 001E107C  48 1F 6B 79 */	bl func_803DC6B4
/* 801E5B40 001E1080  2C 03 00 00 */	cmpwi r3, 0
/* 801E5B44 001E1084  41 82 00 20 */	beq lbl_801E5B64
/* 801E5B48 001E1088  7F E3 FB 78 */	mr r3, r31
/* 801E5B4C 001E108C  38 8D 88 23 */	addi r4, r13, lbl_8069D4C3-_SDA_BASE_
/* 801E5B50 001E1090  38 A0 00 00 */	li r5, 0
/* 801E5B54 001E1094  48 1F 4E C5 */	bl func_803DAA18
/* 801E5B58 001E1098  7F E3 FB 78 */	mr r3, r31
/* 801E5B5C 001E109C  38 8D 88 23 */	addi r4, r13, lbl_8069D4C3-_SDA_BASE_
/* 801E5B60 001E10A0  48 1F 5C 9D */	bl func_803DB7FC
lbl_801E5B64:
/* 801E5B64 001E10A4  7F E3 FB 78 */	mr r3, r31
/* 801E5B68 001E10A8  4B FF FE 49 */	bl func_801E59B0
/* 801E5B6C 001E10AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5B70 001E10B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5B74 001E10B4  7C 08 03 A6 */	mtlr r0
/* 801E5B78 001E10B8  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5B7C 001E10BC  4E 80 00 20 */	blr 
lbl_801E5B80:
/* 801E5B80 001E10C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5B84 001E10C4  7C 08 02 A6 */	mflr r0
/* 801E5B88 001E10C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5B8C 001E10CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5B90 001E10D0  7C 7F 1B 78 */	mr r31, r3
/* 801E5B94 001E10D4  48 1F 6B 59 */	bl func_803DC6EC
/* 801E5B98 001E10D8  2C 03 00 00 */	cmpwi r3, 0
/* 801E5B9C 001E10DC  41 82 00 30 */	beq lbl_801E5BCC
/* 801E5BA0 001E10E0  7F E3 FB 78 */	mr r3, r31
/* 801E5BA4 001E10E4  48 1F 45 09 */	bl func_803DA0AC
/* 801E5BA8 001E10E8  7F E3 FB 78 */	mr r3, r31
/* 801E5BAC 001E10EC  48 1E 0F A9 */	bl func_803C6B54
/* 801E5BB0 001E10F0  3C 80 80 58 */	lis r4, lbl_8058155C@ha
/* 801E5BB4 001E10F4  7F E3 FB 78 */	mr r3, r31
/* 801E5BB8 001E10F8  38 84 15 5C */	addi r4, r4, lbl_8058155C@l
/* 801E5BBC 001E10FC  38 A0 FF FF */	li r5, -1
/* 801E5BC0 001E1100  38 C0 FF FF */	li r6, -1
/* 801E5BC4 001E1104  48 21 2E 79 */	bl func_803F8A3C
/* 801E5BC8 001E1108  48 20 B8 41 */	bl func_803F1408
lbl_801E5BCC:
/* 801E5BCC 001E110C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5BD0 001E1110  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5BD4 001E1114  7C 08 03 A6 */	mtlr r0
/* 801E5BD8 001E1118  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5BDC 001E111C  4E 80 00 20 */	blr 
/* 801E5BE0 001E1120  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5BE4 001E1124  7C 08 02 A6 */	mflr r0
/* 801E5BE8 001E1128  2C 03 00 00 */	cmpwi r3, 0
/* 801E5BEC 001E112C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5BF0 001E1130  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801E5BF4 001E1134  7C 9F 23 78 */	mr r31, r4
/* 801E5BF8 001E1138  93 C1 00 08 */	stw r30, 8(r1)
/* 801E5BFC 001E113C  7C 7E 1B 78 */	mr r30, r3
/* 801E5C00 001E1140  41 82 00 20 */	beq lbl_801E5C20
/* 801E5C04 001E1144  41 82 00 0C */	beq lbl_801E5C10
/* 801E5C08 001E1148  38 80 00 00 */	li r4, 0
/* 801E5C0C 001E114C  48 07 B5 A9 */	bl func_802611B4
lbl_801E5C10:
/* 801E5C10 001E1150  2C 1F 00 00 */	cmpwi r31, 0
/* 801E5C14 001E1154  40 81 00 0C */	ble lbl_801E5C20
/* 801E5C18 001E1158  7F C3 F3 78 */	mr r3, r30
/* 801E5C1C 001E115C  48 22 3F 25 */	bl __dl__FPv
lbl_801E5C20:
/* 801E5C20 001E1160  7F C3 F3 78 */	mr r3, r30
/* 801E5C24 001E1164  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801E5C28 001E1168  83 C1 00 08 */	lwz r30, 8(r1)
/* 801E5C2C 001E116C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5C30 001E1170  7C 08 03 A6 */	mtlr r0
/* 801E5C34 001E1174  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5C38 001E1178  4E 80 00 20 */	blr 
/* 801E5C3C 001E117C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801E5C40 001E1180  7C 08 02 A6 */	mflr r0
/* 801E5C44 001E1184  38 6D BB E8 */	addi r3, r13, lbl_806A0888-_SDA_BASE_
/* 801E5C48 001E1188  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E5C4C 001E118C  48 00 00 25 */	bl func_801E5C70
/* 801E5C50 001E1190  38 6D BB EC */	addi r3, r13, lbl_806A088C-_SDA_BASE_
/* 801E5C54 001E1194  48 00 00 2D */	bl func_801E5C80
/* 801E5C58 001E1198  38 6D BB F0 */	addi r3, r13, lbl_806A0890-_SDA_BASE_
/* 801E5C5C 001E119C  48 00 00 35 */	bl func_801E5C90
/* 801E5C60 001E11A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801E5C64 001E11A4  7C 08 03 A6 */	mtlr r0
/* 801E5C68 001E11A8  38 21 00 10 */	addi r1, r1, 0x10
/* 801E5C6C 001E11AC  4E 80 00 20 */	blr 

.global func_801E5C70
func_801E5C70:
/* 801E5C70 001E11B0  3C 80 80 58 */	lis r4, lbl_8058160C@ha
/* 801E5C74 001E11B4  38 84 16 0C */	addi r4, r4, lbl_8058160C@l
/* 801E5C78 001E11B8  90 83 00 00 */	stw r4, 0(r3)
/* 801E5C7C 001E11BC  4E 80 00 20 */	blr 

.global func_801E5C80
func_801E5C80:
/* 801E5C80 001E11C0  3C 80 80 58 */	lis r4, lbl_805815FC@ha
/* 801E5C84 001E11C4  38 84 15 FC */	addi r4, r4, lbl_805815FC@l
/* 801E5C88 001E11C8  90 83 00 00 */	stw r4, 0(r3)
/* 801E5C8C 001E11CC  4E 80 00 20 */	blr 

.global func_801E5C90
func_801E5C90:
/* 801E5C90 001E11D0  3C 80 80 58 */	lis r4, lbl_805815EC@ha
/* 801E5C94 001E11D4  38 84 15 EC */	addi r4, r4, lbl_805815EC@l
/* 801E5C98 001E11D8  90 83 00 00 */	stw r4, 0(r3)
/* 801E5C9C 001E11DC  4E 80 00 20 */	blr 
/* 801E5CA0 001E11E0  80 64 00 00 */	lwz r3, 0(r4)
/* 801E5CA4 001E11E4  4B FF FE DC */	b lbl_801E5B80
/* 801E5CA8 001E11E8  80 64 00 00 */	lwz r3, 0(r4)
/* 801E5CAC 001E11EC  4B FF FE 60 */	b lbl_801E5B0C
/* 801E5CB0 001E11F0  80 64 00 00 */	lwz r3, 0(r4)
/* 801E5CB4 001E11F4  4B FF FD 5C */	b lbl_801E5A10
