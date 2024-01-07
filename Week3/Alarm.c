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