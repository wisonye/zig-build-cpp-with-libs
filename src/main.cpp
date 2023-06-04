#include "a.h"
#include "b.h"
#include <iostream>

int main() {
  std::cout << "\n>>> Simple zig build CPP demo." << std::endl;
  A::Result a_result = A::Result(28, true);
  A::print(a_result);
  B::Result b_result = B::Result(88.456);
  B::print(b_result);
}
