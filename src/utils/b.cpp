#include "b.h"

#include <iomanip>
#include <iostream>

// -------------------------------------------------------------------------
// C++ API
// -------------------------------------------------------------------------

///
///
///
B::Result::Result(float init_float) : invisible_float(init_float){};

///
///
///
B::Result::~Result() { std::cout << ">>> B::Result destroyed." << std::endl; }

///
///
///
float B::Result::get_float_value() { return invisible_float; }

///
///
///
void B::print(B::Result &result) {
    std::cout << ">>> [ B - Result ]" << std::endl
              << "{" << std::endl
              << "\t invisible_float: " << std::fixed << std::setprecision(3)
              << result.get_float_value() << std::endl
              << "}" << std::endl;
}

// -------------------------------------------------------------------------
// C API
// -------------------------------------------------------------------------

///
///
///
void *BResult_init(float init_float) {
    return (void *)new B::Result(init_float);
}

///
///
///
void BResult_free(void *self) {
    if (self != NULL) {
        delete (B::Result *)self;
    }
}

///
///
///
float BResult_get_float_value(void *self) {
    return ((B::Result *)self)->get_float_value();
}

///
///
///
void BResult_print(void *self) { B::print(*((B::Result *)self)); }
