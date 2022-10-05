#include <verilated.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "Vtop.h"

int main(int argc, char const* argv[]) {
  static const int N = 10;
  VerilatedContext contextp;
  contextp.commandArgs(argc, argv);
  Vtop top(&contextp);
  for (int i = 0; i < N; i++) {
    int a = rand() & 1;
    int b = rand() & 1;
    top.a = a;
    top.b = b;
    top.eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top.f);
    assert(top.f == (a ^ b));
  }

  return 0;
}
