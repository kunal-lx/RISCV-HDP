.section .data
flag: .word 0
flame: .word 0
buzzer: .word 0
buzzer_reg: .word 0
led: .word 0
led_reg: .word 0
mask: .word 0xFFFFFFF3

.section .text
.globl _start
_start:
    and x30, x30, mask
    or x30, x30, buzzer_reg
    or x30, x30, led_reg

while_loop:
    andi t0, x30, 1
    sw t0, flag
    bnez t0, if_block
    j while_loop

if_block:
    andi t1, x30, 2
    sw t1, flame
    beqz t1, else_block

    li t2, 0
    sw t2, buzzer
    sw t2, led
    j update_registers

else_block:
    li t3, 1
    sw t3, buzzer
    sw t3, led

update_registers:
    lw t4, buzzer
    slli t4, t4, 2
    sw t4, buzzer_reg

    lw t5, led
    slli t5, t5, 3
    sw t5, led_reg

    and x30, x30, mask
    or x30, x30, buzzer_reg
    or x30, x30, led_reg

    j while_loop