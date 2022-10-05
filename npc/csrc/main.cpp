#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>

#include "Vtop.h"

int main(int argc, char const* argv[]) {
  VerilatedContext contextp;
  contextp.commandArgs(argc, argv);
  Verilated::traceEverOn(true);
  VerilatedVcdC tfp;

  Vtop top(&contextp);
  top.trace(&tfp, 99);
  tfp.open("obj_dir/simx.vcd");
  int sim_time = 100;
  for (; contextp.time() < sim_time && !contextp.gotFinish();) {
    contextp.timeInc(1);

    int a = rand() & 1;
    int b = rand() & 1;
    top.a = a;
    top.b = b;
    top.eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top.f);
    assert(top.f == (a ^ b));
    tfp.dump(contextp.time());
  }
  tfp.close();

  return 0;
}
