`include "FourBitALU.v"

module tb();

  // Inputs
  reg [3:0] A_init;
  reg [3:0] B_init;
  reg [2:0] OP_init;

  // Instantiate the FourBitALU module
  FourBitALU uut (
    .A(A_init),
    .B(B_init),
    .OP(OP_init),
    .Result() // Output of the ALU
  );

  // Clock generation (not used in this example)
  reg clk = 0;
  always #5 clk = ~clk;

  initial begin
    $display("Time\tA\tB\tOP\tResult");
    $display("--------------------------------");

    // Test Case 1: Addition
    A_init = 4'b0010;
    B_init = 4'b0101;
    OP_init = 3'b000;

    $monitor("%t\t%b\t%b\t%b\t%b", $time, A_init, B_init, OP_init, uut.Result);
    #10;

    // Test Case 2: Subtraction
    A_init = 4'b0101;
    B_init = 4'b0010;
    OP_init = 3'b001;

    $monitor("%t\t%b\t%b\t%b\t%b", $time, A_init, B_init, OP_init, uut.Result);
    #10;

    // Test Case 3: Bitwise AND
    A_init = 4'b1100;
    B_init = 4'b1010;
    OP_init = 3'b010;

    $monitor("%t\t%b\t%b\t%b\t%b", $time, A_init, B_init, OP_init, uut.Result);
    #10;

    // Test Case 4: Bitwise OR
    A_init = 4'b1100;
    B_init = 4'b1010;
    OP_init = 3'b011;

    $monitor("%t\t%b\t%b\t%b\t%b", $time, A_init, B_init, OP_init, uut.Result);
    #10;

    // Test Case 5: Bitwise XOR
    A_init = 4'b1100;
    B_init = 4'b1010;
    OP_init = 3'b100;

    $monitor("%t\t%b\t%b\t%b\t%b", $time, A_init, B_init, OP_init, uut.Result);
    #10;

    // Additional test cases can be added here

    $finish; // End the simulation
  end

  initial begin
    $dumpvars; // Dump all variables
    $dumpfile("dump.vcd");
  end

endmodule
