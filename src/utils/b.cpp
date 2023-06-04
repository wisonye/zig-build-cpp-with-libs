#include "b.h"
#include <iomanip>
#include <iostream>

namespace B {

///
///
///
Result::Result(float init_float) : invisible_float(init_float){};

///
///
///
Result::~Result() { std::cout << ">>> B::Result destroyed." << std::endl; }

///
///
///
float Result::get_float_value() { return invisible_float; }

///
///
///
void print(Result &result) {
  std::cout << ">>> [ B - Result ]" << std::endl
            << "{" << std::endl
            << "\t invisible_float: " << std::fixed << std::setprecision(3)
            << result.get_float_value() << std::endl
            << "}" << std::endl;
}
} // namespace B
