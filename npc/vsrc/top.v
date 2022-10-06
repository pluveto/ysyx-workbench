module top(
  input [7:0] sw,
  output [15:0] ledr
);
  assign ledr[0] = sw[0];
  assign ledr[1] = sw[1];
  assign ledr[2] = sw[0] ^ sw[1];
endmodule
