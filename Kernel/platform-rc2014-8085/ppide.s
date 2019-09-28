#include "../kernel-8080.def"
!
!	First draft on an 8085 PPIDE driver.
!
!	Does not yet include swap support.
!

#define PPIDE_PPI_BUS_READ	0x92
#define PPIDE_PPI_BUS_WRITE	0x80

#define PPIDE_PPI_WR_LINE	0x20
#define PPIDE_PPI_RD_LINE	0x40

#define IDE_REG_STATUS		0x0F
#define IDE_REG_DATA		0x08

#define BLKPARAM_ADDR_OFFSET	0
#define BLKPARAM_IS_USER_OFFSET	2

	.sect .discard

	.define _ppide_init

!
!	Initialize PPIDE. This consists of setting up the registers
!	for read state
!
_ppide_init:
	mvi a,PPIDE_PPI_BUS_READ
	out 0x23
	mvi a,IDE_REG_STATUS
	out 0x22
	ret

	.sect .text

	.define _ppide_readb
!
!	Read a byte from an IDE register and hand it back to the C code
!
_ppide_readb:
	ldsi 2
	ldax d
	out 0x22
	mov b,a
	ori 0x80
	out 0x22
	in 0x20
	mov e,a
	mov a,b
	out 0x22
	mvi d,0
	ret

	.define _ppide_writeb
!
!	Write a byte to an IDE register for C code
!
_ppide_writeb:
	ldsi 2
	lhlx
	ldsi 4

	mvi a,PPIDE_PPI_BUS_WRITE
	out 0x23
	ldax d
	out 0x22
	mov a,l
	out 0x20
	mov a,h
	out 0x21
	ldax d
	mov b,a
	ori PPIDE_WR_LINE
	out 0x22
	mov a,b
	out 0x22
	mvi a,PPIDE_PPI_BUS_READ
	out 0x23
	ret

	.sect .common

	.define _ppide_read_data
!
!	Perform the data block transfer when reading. blk_op holds all the
!	parameter information we need
!
_ppide_read_data:
	! Point at the data register
	mvi a,IDE_REG_DATA
	out 0x22
	! Get the destination buffer
	lhld _blk_op + BLKPARAM_ADDR_OFFSET
	! Set d and e up as fast copies of the values we need to out
	mov d,a
	ori PPIDE_RD_LINE
	mov e,a
	! If we are doing a user transfer map the process
	! We don't yet support swap or buffer mappings (FIXME)
	lda _blk_op + BLKPARAM_IS_USER_OFFSET
	ora a
	push psw
	cnz map_process_always
	! 256 words per transfer
	mvi b,0
goread:
	! Write the register | RD
	mov a,e
	out 0x22
	! Read the byte back from the interface (no polling - it is faster
	! than we are)
	in 0x20
	! Save it
	mov m,a
	inx h
	! Repeat for second byte
	in 0x21
	mov m,a
	inx h
	! Drop RD
	mov a,d
	out 0x22
	! Check if done
	dcr b
	jnz goread
	! Fix up mappings
	pop psw
	rz
	jmp map_kernel

	.define _ppide_write_data

_ppide_write_data:
	! Point at the data register
	mvi a,ide_reg_data
	out 0x22
	! Switch the bus direction on the 82C55 for ports A and B
	mvi a,PPIDE_PPI_BUS_WRITE
	out 0x23
	! Get the source buffer
	lhld _blk_op + BLKPARAM_ADDR_OFFSET
	! Set up d and e as the register values we need to out
	mvi d,ide_reg_data
	mvi e,ide_reg_data | PPIDE_WR_LINE
	! Map the user space if needed
	! Need to do swap and buffer mappings properly
	lda _blk_op + BLKPARAM_IS_USER_OFFSET
	ora a
	push psw
	cnz map_process_always
gowrite:
	! Write bit off
	mov a,d
	out 0x22
	! Now put the data value on the bus (the register is already set)
	mov a,m
	inx h
	out 0x20
	mov a,m
	inx h
	out 0x21
	! Strobe write with data pending and settled
	mov a,e
	out 0x22
	! Check if we are done
	dcr b
	jnz gowrite
	! Drop the write bit
	mov a,d
	out 0x22
	! Put the bus back in the read direction as all other code expects
	mvi a,PPIDE_PPI_BUS_READ
	out 0x23
	! Recover the mappings
	pop psw
	rz
	jmp map_kernel