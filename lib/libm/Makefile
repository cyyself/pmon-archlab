#	$Id: Makefile,v 1.1.1.1 2006/09/14 01:59:06 root Exp $ */
#
#
# Copyright (c) 2001 Opsycon AB  (www.opsycon.se)
# Copyright (c) 2002 Patrik Lindergren  (www.lindergren.com)
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#	This product includes software developed by Opsycon AB, Sweden.
#	This product includes software developed by Patrik Lindergren.
# 4. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
#

LIB=m
NOPIC=

MACHINE=	${XMACHINE}
MACHINE_ARCH=	${XMACHINE_ARCH}
CURDIR=$(shell pwd)

M=	${CURDIR}/arch/${MACHINE_ARCH}

CPPFLAGS=	-I$M ${MLIBCPPFLAGS} -U_KERNEL

VPATH+=	${M} ${MLIBDIR}
 
include ${M}/Makefile.inc

# Files to clean up
CLEANFILES+= ${OBJDIR}/lib${LIB}.a

include ${PMONDIR}/tools/scripts/pmon.lib.gmk

${OBJDIR}/lib${LIB}.a: ${OBJS}
	@echo building standard ${LIB} library
	@rm -f $@
	@${AR} rcs $@ ${OBJS}
#	${RANLIB} $@

# DO NOT DELETE

gunzip.o: /home/cyy/Downloads/pmon_archlab/include/zlib.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/include/stdlib.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
gunzip.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/ubi_uboot.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/div64.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/ubifs_pmon.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/stddef.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/linux/types.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/crc32.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/list.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/stddef.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/poison.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/rbtree.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/string.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/mtd.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/mtd-abi.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/compat.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/mtd/mtd.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/linux/types.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/mtd/compatmac.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/module.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/param.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/simplelock.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/syslimits.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/signal.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/signal.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cpu.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/psl.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/siginfo.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/time.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/time.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/param.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/limits.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/sys/syslog.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/pio.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/intr.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/dev/pci/pcivar.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/bus.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/dev/pci/pcireg.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/pci/pci_machdep.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/target/pmon_target.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/target/fcr.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/nand.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/pmon.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/pmon_arch.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/progress.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/ubi.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/ubi-user.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/onenand_uboot.h
rbtree.o: /home/cyy/Downloads/pmon_archlab/include/linux/mtd/errno.h
ctype.o: /home/cyy/Downloads/pmon_archlab/include/linux/ctype.h
cfun.o: /home/cyy/Downloads/pmon_archlab/include/linux/ctype.h
cfun.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
cfun.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
cfun.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
cfun.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
cfun.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
cfun.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
cfun.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/linux/lzo.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/byteorder.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/unaligned.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/linux/unaligned/le_byteshift.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/linux/unaligned/be_byteshift.h
lzo1x_decompress.o: /home/cyy/Downloads/pmon_archlab/include/linux/unaligned/generic.h
lzo1x_decompress.o: lzodefs.h
div64.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
div64.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
div64.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
div64.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
div64.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
div64.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
div64.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_acos.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_asin.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_atan.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_ceil.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_cos.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_exp.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_expm1.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_fabs.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_floor.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_frexp.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_log.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_log.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_log10.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_modf.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_pow.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_sin.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
w_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_tan.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_tanh.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_scalbn.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
s_copysign.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_acos.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_asin.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_atan2.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
k_cos.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_cosh.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_exp.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_fmod.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_log.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_log.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_log.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_log.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_log10.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_pow.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
k_sin.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_sinh.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_sqrt.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
k_tan.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
e_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/include/math.h math_private.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/types.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/types.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/cdefs.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/cdefs.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/ansi.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/Targets/LS1B/compile/ls1b/machine/endian.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/sys/endian.h
k_rem_pio2.o: /home/cyy/Downloads/pmon_archlab/sys/arch/mips/include/endian.h
