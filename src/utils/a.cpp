#include "a.h"
#include <iostream>

namespace A {

///
///
///
Result::Result(int init_value, bool success)
    : invisible_value(init_value), invisible_success(success){};

///
///
///
Result::~Result() { std::cout << ">>> A::Result destroyed." << std::endl; }

///
///
///
int Result::get_value() { return invisible_value; }

///
///
///
bool Result::is_success() { return invisible_success; }

///
///
///
void print(Result &result) {
  const char *is_success = result.is_success() ? "true" : "false";
  std::cout << ">>> [ A - Result ] {" << std::endl
            << "{" << std::endl
            << "\t invisible_value: " << result.get_value() << std::endl
            << "\t is_success: " << is_success << std::endl
            << "}" << std::endl;
}
} // namespace A
