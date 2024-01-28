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

