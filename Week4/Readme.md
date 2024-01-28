# Sky130 RTL Synthesis for RISC-V 

## Overview:

This repository provides an overview of the synthesis process for RTL (Register-Transfer Level) code using the SkyWater 130nm (Sky130) process and the Yosys tool for RISC-V designs.

## Steps:

### 1. RTL Design:

- Begin with RTL code written in a hardware description language (HDL) like Verilog or VHDL.
- Describe digital logic and behavior at the register-transfer level.

### 2. Synthesis Tool (Yosys):

- Use Yosys, an open-source synthesis tool, to generate a gate-level netlist from the RTL code.
- The netlist represents the design using basic logic gates, flip-flops, and standard cells.

### 3. Technology Mapping:

- Yosys performs technology mapping, mapping the netlist to specific library cells available in the Sky130 process.
- Choose appropriate standard cells matching RTL functionality.

### 4. Cell Library (Libraries):

- Utilize the Sky130 standard cell library, which includes logic gates, flip-flops, and other cells.
- Yosys maps RTL logic to specific cells using this library.

### 5. Timing Constraints:

- Specify timing constraints (clock frequency, setup/hold times) to ensure the design meets performance requirements.
- Yosys considers these constraints during synthesis.

### 6. Netlist Optimization:

- Yosys optimizes the netlist to enhance performance, reduce power consumption, and minimize area utilization.
- Optimization includes logic restructuring and removal of redundant elements.

### 7. Post-Synthesis Simulation:

- Conduct post-synthesis simulation to verify that the synthesized netlist behaves as expected.
- Identify and address any issues introduced during synthesis.

### 8. Formal Verification:

- Employ formal verification tools to ensure the synthesized netlist adheres to original design specifications and meets specific properties.

### 9. Place and Route:

- After synthesis and verification, perform place and route using tools like OpenROAD.
- Determine the physical placement of cells and routing of interconnections on the chip.

### 10. GDSII Generation:

- Generate the GDSII file, the layout description of the chip, for fabrication.

### 11. Foundry Submission:

- Submit the GDSII file to the foundry for fabrication.
- The foundry uses the GDSII file to create masks for manufacturing the chip.

## Usage:

- Clone this repository for a detailed guide on synthesizing RTL code using Sky130 and Yosys for RISC-V designs.

- Follow the step-by-step instructions provided in the documentation.



# Installing Yosys on the VSDWorkshop VM

## Overview:

This guide explains how to install Yosys on the VSDWorkshop VM. Note that Yosys is pre-installed on the VSDWorkshop VM, so you don't need to perform any additional installations.

To verify if Yosys is installed, you can open a terminal on the VSDWorkshop VM and run the following command:

```bash
yosys -h

```

## Gate Level Synthesis - GLS
-- Comment out the data & instruction memory modules in processor.v and ensure writing_inst_done=1 for uart verification OR writing_inst_done=0 to bypass uart for simulation.\
-- All required ```sky130``` libs are kept in the current working directory, and proper instantiation name is used for **SRAM** from sky130 libs.\

### Use the following yosys commands to synthesize gate-level netlist
```
yosys
```
--  make sure you have latest version of yosys 
![image](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/91d27273-68d3-435e-8872-c7faede5b003)

-- Read liberty file to import sky130 cells
```
read_liberty -lib sky130_fd_sc_hd__tt_025C_1v80_256.lib
```
-- Read your verilog file and generate RTLIL\
NOTE : RTLIL of sky130 sram cell should be generated as it is not part of module design.
```
read_verilog gpio_syn.v
```
![image](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/cb569ac4-363c-4555-91bc-595371c80118)

-- Synthesis of top module (wrapper)
```
synth -top wrapper
```
![Screenshot 2024-01-28 000756](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/62219721-2b8f-4670-ae95-5334ca2d6804)

-- Mapping yosys standard cell to sky130 lib logic cells
```
abc -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
```
![image](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/36fa5ee3-4074-4840-a09f-12065d25bfd4)

-- Mapping sky130 lib flip-flop cells
```
dfflibmap -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
```
![image](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/edd62d16-149f-4d3a-b033-a34c2b19e4c0)

-- Synthesis dumping output
```
write_verilog synth_gpio.v
```
-- Generating Graphviz representation of design
```
show wrapper
```
![image](https://github.com/AbrarShaikh/RISC-V-Design/assets/34272376/68fbbf48-24b7-46ec-90e2-dacb437e4068)
