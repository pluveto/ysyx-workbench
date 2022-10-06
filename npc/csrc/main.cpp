#include <nvboard.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#include <cassert>
#include <cstdio>
#include <cstdlib>

#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top);

int main(int argc, char const* argv[]) {
  Verilated::traceEverOn(true);
  // VerilatedVcdC tfp;

  Vtop top;
  nvboard_bind_all_pins(&top);
  nvboard_init();

  // top.trace(&tfp, 99);
  // tfp.open("obj_dir/simx.vcd");
  for (; ;) {
    nvboard_update();
    top.eval();
    usleep(1000);
    // printf("a = %d, b = %d, f = %d\n", a, b, top.f);
    // assert(top.f == (a ^ b));
    // tfp.dump(contextp.time());
  }
  // tfp.close();

  nvboard_quit();
  return 0;
}
