

![Alt Text](1A.png) 

__________________________________________

Verification with RISC-V Compiler and Spike Simulator
Counter Code (counter.c)

# Compilation
riscv64-unknown-elf-gcc -o counter counter.c

# Execution with Spike Simulator
spike counter
Result: The code compiles successfully, and the Spike simulator executes it without errors.

Matrix Multiplication Code (matmulti.c)
We have verified the matmulti.c code using the RISC-V GCC compiler and the Spike simulator. Here are the steps and results:


# Compilation
riscv64-unknown-elf-gcc -o matmulti matmulti.c

# Execution with Spike Simulator
spike matmulti
Result: The code compiles successfully, and the Spike simulator executes it without errors.

ALU Code (alu.c)
We have verified the alu.c code using the RISC-V GCC compiler and the Spike simulator. Here are the steps and results:


# Compilation
riscv64-unknown-elf-gcc -o alu alu.c

# Execution with Spike Simulator
spike alu
Result: The code compiles successfully, and the Spike simulator executes it without errors.

Performance Measurement with RISC-V Disassembler
We have measured the CPU performance of the programs mentioned above using the RISC-V disassembler. Here are the steps and results:

# Disassemble Counter Code
riscv64-unknown-elf-objdump -d -r counter > counter_disassembly.txt

# Disassemble Matrix Multiplication Code
riscv64-unknown-elf-objdump -d -r matmulti > matmulti_disassembly.txt

# Disassemble ALU Code
riscv64-unknown-elf-objdump -d -r alu > alu_disassembly.txt
Result: The disassembly files (counter_disassembly.txt, matmulti_disassembly.txt, alu_disassembly.txt) provide a detailed breakdown of the generated assembly code for further analysis.

# Performance Measurement Analysis for RISC-V CPU

In order to assess the CPU performance of the count32_noprintf.c code on different RISC-V CPUs, I have performed a detailed analysis using the RISC-V disassembler. 
The example below illustrates the analysis for two hypothetical CPUs: an idealized RISC-V CPU (IdealRV) and a specific RISC-V CPU model, the PicoRV32.

IdealRV CPU Analysis
Assuming an idealized scenario where the CPU executes one instruction per clock cycle (CPI = 1) and operates at a clock speed of 10 MHz, we can calculate the expected CPU time for one pass of the count32_noprintf.c 

code:

CPU time = CPI * Total instructions * Clock period
          = 1 * 292 * 0.1 microseconds
          = 29.2 microseconds


PicoRV32 CPU Analysis

Now, let's consider the PicoRV32 CPU, which has an average CPI of approximately 4. Given the same clock speed of 10 MHz, the expected CPU time for one pass of the count32_noprintf.c code on PicoRV32 would be:

CPU time = CPI * Total instructions * Clock period
          = 4 * 292 * 0.1 microseconds
          = 116.8 microseconds


Relative Performance Comparison
To compare the relative performance between IdealRV and PicoRV32, we calculate the CPU performance ratio:

CPU performance ratio = CPI of PicoRV32 / CPI of IdealRV
                      = 4 / 1
                      = 4
This indicates that, on average, the IdealRV is four times faster than the PicoRV32 CPU for the given code and clock speed.

Clock Speed Variation
If we hypothetically increase the clock speed of the PicoRV32 CPU to 100 MHz while keeping IdealRV at 10 MHz, the new performance ratio becomes:


CPU performance ratio = (CPI of PicoRV32 * Clock period PicoRV32) / (CPI of IdealRV * Clock period IdealRV)
= (4 * 0.01) / (1 * 0.1)
= 0.4


In this case, the IdealRV is 0.4 times slower, or the PicoRV32 is 2.5 times faster than IdealRV.

This analysis provides insights into the relative performance of different RISC-V CPUs for the specific code under consideration and varying clock speeds.

