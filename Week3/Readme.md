

![Alt Text](Assign.png) 


# Temperature-Activated Fire Alarm System

This project implements a simple temperature-activated fire alarm system using a custom RISC-V processor with I/O-mapped GPIO. The system reads temperature data from a sensor and activates an alarm (LED and buzzer) when the temperature exceeds a predefined threshold.

## Hardware Setup

- The RISC-V processor is configured with I/O-mapped GPIO addresses.
- A temperature sensor is connected to the system, and its data is read from the address `0x20000000`.
- The LED and buzzer are connected to GPIO pins, with their respective pin numbers defined in the code.

## Software Implementation

The main C code (`main.c`) continuously reads the temperature from the sensor and activates the fire alarm if the temperature exceeds a predefined threshold. The alarm is indicated by turning on an LED and a buzzer.

## Compilation and Execution

1. Compile the C code using a RISC-V toolchain. Example:

   riscv32-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tmain.ld main.c -o main.elf

C code:

```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int flag;
    int flame;
    int buzzer = 0;
    int buzzer_reg = buzzer * 4;
    int led = 0;
    int led_reg = led * 8;
    int mask = 0xFFFFFFF3;

    asm volatile(
        "and x30, x30, %2\n\t"
        "or x30, x30, %0\n\t"
        "or x30, x30, %1\n\t"
        :
        : "r"(buzzer_reg), "r"(led_reg), "r"(mask)
        : "x30"
    );

    while (1) {
        asm volatile(
            "andi %0, x30, 1\n\t"
            : "=r"(flag)
            :
            :
        );

        if (flag) {
            asm volatile(
                "andi %0, x30, 2\n\t"
                : "=r"(flame)
                :
                :
            );

            if (flame == 0) {
                buzzer = 1;
                led = 1;
            } else {
                buzzer = 0;
                led = 0;
            }

            buzzer_reg = buzzer * 4;
            led_reg = led * 8;

            asm volatile(
                "and x30, x30, %2\n\t"
                "or x30, x30, %0\n\t"
                "or x30, x30, %1\n\t"
                :
                : "r"(buzzer_reg), "r"(led_reg), "r"(mask)
                : "x30"
            );
        }
    }

    return 0;
}
```


Assembly Code:

```a
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

```