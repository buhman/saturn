/*                                                              */
/*    �A�v���P�[�V�����������v���O�����T���v��                  */
/*                              V1.10  '94.11.11  S.U and T.S   */
/*                                                              */
/*    ����^�C�~���O�Ƌ@�\�ɂ��āF                            */
/*       ���C�Z���X��ʕ\�����ɁA�s��ɂȂ��Ă���e��f�o�C�X   */
/*       ��Ԃ�A���̃������̃N���A�Ȃǂ��s�Ȃ��܂��B           */
/*       �����̏��v���Ԃ́A0.1 �b���x������܂��B               */
/*       �I����A��ǂ݂��Ă������v���O�����̎��s�Ɉڂ�܂��B   */
/*       ���̎��s�J�n�A�h���X�� APP_ENTRY �ɒ�`���Ă��������B  */
/*                                                              */
/*    �����P�[�W�ɂ��āF                                      */
/*       �h�o�� sys_init.obj �̒���Ƀ����N���Ă��������B       */
/*       �v���O���������̂܂܎g�p�����ꍇ�A��R�U�O�g�o�C�g��   */
/*       �Ȃ�A�h�o�T�C�Y�͂P�O�O�O�g���z���܂��̂Œ��ӂ���     */
/*       ���������B                                             */
/*                                                              */
/*    �v���O�����ύX���̒��ӁF                                  */
/*       main() �̑O�Ɏ��s�����܂ފ֐���ǉ����Ȃ��ł��������B  */
/*                                                              */

#include "sega_sys.h"

/* ��ǂ݂����v���O�����̎��s�J�n�A�h���X�i���C������������ɃW�����v�j*/
#define	APP_ENTRY	(0x06003000)

/* �f�o�C�X�����������郋�[�`�� */
static void vd1Comfil(void);		 /* �u�c�o�P �N���b�s���O������    */
static void vd2Ramfil(void);		 /* �u�c�o�Q �u�q�`�l�N���A        */
static void colRamfil(void);		 /* �J���[�q�`�l�N���A             */
static void sndRamfil(Sint32);		 /* �T�E���h�q�`�l�N���A           */
static void scuDspInit(void);		 /* �r�b�t �c�r�o ������           */
static void msh2PeriInit(void);		 /* �}�X�^�r�g���Ӄ��W���[�������� */
static void sndDspInit(void);		 /* �T�E���h�c�r�o�N���A           */

/* ���̑��T�u���[�`�� */
static void vbIrtn(void);		 /* �u�a-�h�� �����ݏ���           */
static void vbOrtn(void);		 /* �u�a-�n���� �����ݏ���         */
static void syncVbI(void);		 /* �u�a-�h�� ���������p           */

#ifndef __GNUC__
static void memset_w(Sint16 *, Sint16, Sint32); /* ���[�h ������������ */
static void memcpy_w(Sint16 *, Sint16 *, Sint32); /* ���[�h ������������ */
static Sint16 *blkmfil_w(Sint16 *, Sint16, Sint32);
                                         /* ���[�h�E�u���b�N�������� */
static Sint32 *blkmfil_l(Sint32 *, Sint32, Sint32);
                                         /* �����O���[�h�E�u���b�N�������� */
#else
static void memset_w(volatile Sint16 *, Sint16, Sint32);
static void memcpy_w(volatile Sint16 *, Sint16 *, Sint32);
static void blkmfil_w(volatile Sint16 *, Sint16, Sint32);
                                         /* ���[�h�E�u���b�N�������� */
static void blkmfil_l(volatile Sint32 *, Sint32, Sint32);
                                         /* �����O���[�h�E�u���b�N�������� */
#endif

/* �����_��(���C�Z���X��ʕ\����)��ʃT�C�Y�Ɋւ����� */
#define	XRES			(320)	 /* ���C�Z���X��ʂ̐����T�C�Y     */
#define	SCLIP_UX		(XRES-1) /*             �V                 */
#define	SCLIP_UY_N		(224-1)	 /*   �V   (�m�s�r�b�̏ꍇ)        */
#define	SCLIP_UY_P		(256-1)	 /*   �V   (�o�`�k�̏ꍇ)          */

/* �����Ώۃf�o�C�X�̃x�[�X�A�h���X */
#define	SND_RAM			((volatile Sint32 *)0x25a00000)
#define	VD1_VRAM		((volatile Sint16 *)0x25c00000)
#define	VD1_REG			((volatile Sint16 *)0x25d00000)
          /* VD2_VRAM �́A���C�Z���X�\���Ŏg�p���̂u�q�`�l�̈������    */
#define	VD2_VRAM		((volatile Sint32 *)0x25e08004)
          /* COL_RAM �́A���C�Z���X�\���Ŏg�p���̃J���[�q�`�l�̈������ */
#define	COL_RAM			((volatile Sint16 *)0x25f00020)
#define	VD2_REG			((volatile Sint16 *)0x25f80000)
#define SCSP_DSP_RAM		((volatile Sint16 *)0x25b00800)

/* �r�l�o�b���W�X�^ */
#define	SMPC_REG(ofs)		(*(volatile Uint8  *)(0x20100000+ofs))

/* �r�b�t���W�X�^ */
#define DSP_PGM_CTRL_PORT	(*(volatile Sint32 *)0x25fe0080)
#define DSP_PGM_RAM_PORT	(*(volatile Sint32 *)0x25fe0084)
#define DSP_DATA_RAM_ADRS_PORT	(*(volatile Sint32 *)0x25fe0088)
#define DSP_DATA_RAM_DATA_PORT	(*(volatile Sint32 *)0x25fe008c)

/* �r�b�r�o �T�E���h�q�`�l�T�C�Y���W�X�^ */
#define SCSP_SNDRAMSZ		(*(volatile Sint8 *)0x25b00400)

/* �r�g�Q���Ӄ��W���[�����W�X�^ */
#define MSH2_DMAC_SAR(ofs)	(*(volatile Sint32 *)(0xffffff80 + ofs))
#define MSH2_DMAC_DAR(ofs)	(*(volatile Sint32 *)(0xffffff84 + ofs))
#define MSH2_DMAC_TCR(ofs)	(*(volatile Sint32 *)(0xffffff88 + ofs))
#define MSH2_DMAC_CHCR(ofs)	(*(volatile Sint32 *)(0xffffff8c + ofs))
#define MSH2_DMAC_DRCR(sel)	(*(volatile Sint8  *)(0xfffffe71 + sel))
#define MSH2_DMAC_DMAOR		(*(volatile Sint32 *)(0xffffffb0))
#define MSH2_DIVU_CONT		(*(volatile Sint32 *)(0xffffffb8))

/* ���C���̏����Ɋւ����� */
 	  /* ���݃��C�Z���X�\�����A�P�U�r�b�g�P�O�Q�S�F���[�h���g�p */
 	  /* �u�c�o�Q�̂u�q�`�l�ƃJ���[�q�`�l�͂S��ɕ����ăN���A   */
	  /* �u�q�`�l�͂P��� �Q�O�O�O�O�g �o�C�g(�\��������������) */
 	  /* �J���[�q�`�l�͂P��� �Q�O�O�g �o�C�g(�\��������������) */
#define	MSETDIV			(4)
#define BLKMSK_VD2_VRAM		(0x1fffc)
#define BLKMSK_COL_RAM		(0x001fe)
	  /* �T�E���h�q�`�l�͂R�菇�ŃN���A */
#define M68000_VECTBLSZ		(0x00400/sizeof(Sint32))
#define BLKMSK_SND_RAM		(0x003fc)
	  /* �T�E���h�c�r�o �q�`�l�T�C�Y */
#define SCSP_DSP_RAMSZ		(0x00400)

	  /* �����ݏ����Ɋւ����� */
#define	VBI_NUM			(0x40)   /* �u�a�C�������ݔԍ�        */
#define	VBO_NUM			(0x41)   /* �u�a�A�E�g�����ݔԍ�      */
#define	VB_MASK			(0x0003) /* �r�b�t�����݃}�X�N�Q��  */

	  /* �X�^�e�B�b�N�ϐ� */
static Sint16	yBottom, ewBotRight;
static Sint16	vdp1cmds[48];
#ifndef __GNUC__
/* static Sint16	vbIcnt = 0, sequence = 0; */
static Sint16	vbIcnt = 0, sequence = 0;
static Sint32	*vramptr = VD2_VRAM;
static Sint16	*cramptr = COL_RAM;
#else
static volatile Sint16	vbIcnt = 0, sequence = 0;
static volatile Sint32	*vramptr = VD2_VRAM;
static volatile Sint16	*cramptr = COL_RAM;
#endif

/* ���C������ */
void main(void)
{
	/* ���ӁFAUTO �ϐ����Ƃ�ƁAAPP_ENTRY �̃v���O������ */
        /*       ���䂪�ڂ�Ƃ��A�X�^�b�N���኱���ʂɂȂ�    */

	yBottom  = (VD2_REG[2]&1)? SCLIP_UY_P: SCLIP_UY_N;
	ewBotRight = ((XRES/8)<<9)+(yBottom);
	  /* ��ʏc����� �Q�Q�R(�m�s�r�b) or �Q�T�T(�o�`�k) */

	SYS_SETUINT(VBI_NUM, vbIrtn); /* �u�a�C�������o�^    */
	SYS_SETUINT(VBO_NUM, vbOrtn); /* �u�a�A�E�g  �V      */
	SYS_CHGSCUIM( ~VB_MASK, 0);   /* �u�a�����݂Q����  */

	vd1Comfil();                  /* �u�c�o�P������      */
	for (sequence = 0; sequence < MSETDIV; sequence++)
	{
		syncVbI();   /* �J���[�q�`�l�N���A�̂��ߓ��� */
		colRamfil();	     /* �J���[�q�`�l�N���A   */
		vd2Ramfil();	     /* �u�c�o�Q�q�`�l�N���A */
		sndRamfil(sequence); /* �T�E���h�q�`�l�N���A */
	}

	scuDspInit();                /* �r�b�t�̂c�r�o������ */
	msh2PeriInit();              /* �r�g���Ӄ��W���[���V */
	sndDspInit();                /* �T�E���h�c�r�o �V    */

	SYS_CHGSCUIM( -1, VB_MASK);  /* �u�a�����݂Q�֎~   */
	SYS_SETUINT(VBI_NUM, (void(*)())0 ); /* �t�b�N       */
	SYS_SETUINT(VBO_NUM, (void(*)())0 ); /*   �ď�����   */

	((void(*)())APP_ENTRY)();    /* ���̎��s�J�n�A�h���X */
}

#ifndef __GNUC__
static void memset_w(Sint16 *buf, Sint16 pattern, Sint32 size)
#else
static void memset_w(volatile Sint16 *buf, Sint16 pattern, Sint32 size)
#endif
{
	register Sint32	i;

	for (i = 0; i < size; i+= sizeof(Sint16)) {
		*buf++ = pattern;
	}
}

#ifndef __GNUC__
static void memcpy_w(Sint16 *dst, Sint16 *src, Sint32 size)
#else
static void memcpy_w(volatile Sint16 *dst, Sint16 *src, Sint32 size)
#endif
{
	register Sint32	i;

	for (i = 0; i < size; i+= sizeof(Sint16)) {
		*dst++ = *src++;
	}
}

/* ���������������́A��؂�̂����A�h���X�͈͂�������������������� */
#ifndef __GNUC__
static Sint16 *blkmfil_w(Sint16 *buf, Sint16 pattern, Sint32 brkmsk)
#else
static void blkmfil_w(volatile Sint16 *buf, Sint16 pattern, Sint32 brkmsk)
#endif
{
	register Sint32	i;

#ifndef __GNUC__
	i = (Sint32)buf & brkmsk;
#else
	i = (volatile Sint32)buf & brkmsk;
#endif
	for (; i <= brkmsk; i+= sizeof(Sint16)) {
		*buf++ = pattern;
	}
#ifndef __GNUC__
	return (buf);
#endif
}

#ifndef __GNUC__
static Sint32 *blkmfil_l(Sint32 *buf, Sint32 pattern, Sint32 brkmsk)
#else
static void blkmfil_l(volatile Sint32 *buf, Sint32 pattern, Sint32 brkmsk)
#endif
{
	register Sint32	i;

#ifndef __GNUC__
	i = (Sint32)buf & brkmsk;
#else
	i = (volatile Sint32)buf & brkmsk;
#endif
	for (; i <= brkmsk; i+= sizeof(Sint32)) {
		*buf++ = pattern;
	}
#ifndef __GNUC__
	return (buf);
#endif
}

/* �u�a�C���́A�����݂ŃX�^�e�B�b�N�ϐ����C���N�������g����̂� */
static void vbIrtn(void)
{
	vbIcnt++;
}

/* �u�a�A�E�g�́A�����݂łu�c�o�P���W�X�^���R���g���[������̂� */
static void vbOrtn(void)
{
#ifndef __GNUC__
	register Sint16	*vdp1r;
#else
	register volatile Sint16 *vdp1r;
#endif
                        /* �C���[�X���C�g�Ńt���[���o�b�t�@���N���A */
	vdp1r = VD1_REG;
	*vdp1r++ = 0x0;	/* �P�^�U�O�b�����`�惂�[�h */
	*vdp1r++ = 0x0;
	*vdp1r++ = 0x2;
	*vdp1r++ = 0x0;	/* �C���[�X���C�g�͓����F   */
	*vdp1r++ = 0x0;	        /*  �V   ������W   */
	*vdp1r   = ewBotRight;  /*  �V   �E�����W   */
}

/* �u�a�h�����́A�Ă΂��Ƒ҂��A�u�a�h����ɔ����Ė߂� */
static void syncVbI(void)
{
	register Sint32  cur_cnt_value;
                        /* �҂̂̓J���[�q�`�l�N���A�̂��� */
	cur_cnt_value = vbIcnt;
	while (cur_cnt_value == vbIcnt);
}

/* �u�c�o�P�ɁA�V�X�e���N���b�s���O�ƃ��[�J�����W��ǂ܂��� */
static void vd1Comfil(void)
{
	register Sint16	*cmdbuf;

	memset_w((cmdbuf=vdp1cmds), 0, sizeof(vdp1cmds));
	cmdbuf[0]  = 0x0009;
	cmdbuf[10] = SCLIP_UX;
	cmdbuf[11] = yBottom;
	cmdbuf[16] = 0x000a;
	cmdbuf[32] = 0x8000;
	memcpy_w(VD1_VRAM, vdp1cmds, sizeof(vdp1cmds));
}

/* �u�c�o�Q�̂q�`�l���A�P�^�S���N���A */
static void vd2Ramfil(void)
{
#ifndef __GNUC__
	vramptr = blkmfil_l(vramptr, 0, BLKMSK_VD2_VRAM);
#else
	blkmfil_l(vramptr, 0, BLKMSK_VD2_VRAM);
#endif
}

/* �J���[�q�`�l���A�P�^�S���N���A */
static void colRamfil(void)
{
#ifndef __GNUC__
	cramptr = blkmfil_w(cramptr, 0, BLKMSK_COL_RAM);
#else
	blkmfil_w(cramptr, 0, BLKMSK_COL_RAM);
#endif
}

/* �T�E���h�q�`�l���A�R�菇�ŃN���A */
static void sndRamfil(Sint32 initstep)
{
#ifndef __GNUC__
	register Sint32	*memptr;
#else
	register volatile Sint32 *memptr;
#endif

	switch (initstep) {
	case 0:
		SMPC_REG(31) = 7;	/* �l�U�W�O�O�O���~          */
		break;
	case 1:
		SCSP_SNDRAMSZ = 2;   	/* �T�E���h�q�`�l�T�C�Y�ݒ�    */
					/* �T�E���h�q�`�l�擪�S�O�O�g  */
		memptr = SND_RAM;	/* (�x�N�^)�ɂS�O�O�g���t�B��  */
		blkmfil_l(memptr, 0x400, BLKMSK_SND_RAM);
		*memptr = 0x0007fffc;	/* �r�o�����l���Z�b�g          */
		memptr += M68000_VECTBLSZ;
		*memptr = 0x4e7160fc;	/* �A�h���X�S�O�O�g�� �m�n�o�� */
					/* �a�q�` ���|�Q ���߂�������  */
		break;
	case 2:
		SMPC_REG(31) = 6;	/* �l�U�W�O�O�O�N��(�����҂�)  */
		break;
					/* ���l�F �P�C���g�̊Ԃ�����   */
	}                               /* ���߁A�r�l�o�b�X�e�[�^�X��  */
}                                       /* �Z�b�g�^�`�F�b�N���ȗ�      */

static void msh2PeriInit(void)
{
	register Sint32 i, ofs, dummy;

        ofs = 0;
	for(i = 0;i < 2; i++)
        {                               /* �c�l�`�b�e���W�X�^��������  */
		MSH2_DMAC_SAR(ofs)  = 0x00000000;
		MSH2_DMAC_DAR(ofs)  = 0x00000000;
		MSH2_DMAC_TCR(ofs)  = 0x00000001;
		dummy = MSH2_DMAC_CHCR(ofs);
		MSH2_DMAC_CHCR(ofs) = 0x00000000;
		MSH2_DMAC_DRCR(i)   = 0x00;
		ofs = 0x10;
	}
	dummy  = MSH2_DMAC_DMAOR;
	MSH2_DMAC_DMAOR = 0x00000000;
                                        /* �c�h�u�t�����݂�s����      */
	MSH2_DIVU_CONT =  0x00000000;
}

static void scuDspInit(void)
{
	register Sint32 i;

	DSP_PGM_CTRL_PORT = 0x0;              /* �c�r�o��~           */

	for(i = 0; i < 256; i++)
	  DSP_PGM_RAM_PORT = 0xf0000000;      /* �d�m�c���߃t�B��     */

	for(i = 0; i < 256; i++){             /* �c�r�o �q�`�l�N���A  */
		DSP_DATA_RAM_ADRS_PORT = i;
		DSP_DATA_RAM_DATA_PORT = 0x0;
	}
}

static void sndDspInit(void)
{
	memset_w(SCSP_DSP_RAM, 0, SCSP_DSP_RAMSZ);
					      /* �T�E���h�c�r�o       */
}					      /* �v���O�����̈�N���A */
