#include "a.h"

#include <iostream>

// -------------------------------------------------------------------------
// C++ API
// -------------------------------------------------------------------------

///
///
///
A::Result::Result(int init_value, bool success)
    : invisible_value(init_value), invisible_success(success){};

///
///
///
A::Result::~Result() { std::cout << ">>> A::Result destroyed." << std::endl; }

///
///
///
int A::Result::get_value() { return invisible_value; }

///
///
///
bool A::Result::is_success() { return invisible_success; }

///
///
///
void A::print(A::Result &result) {
    const char *is_success = result.is_success() ? "true" : "false";
    std::cout << ">>> [ A - Result ] {" << std::endl
              << "{" << std::endl
              << "\t invisible_value: " << result.get_value() << std::endl
              << "\t is_success: " << is_success << std::endl
              << "}" << std::endl;
}

// -------------------------------------------------------------------------
// C API
// -------------------------------------------------------------------------

///
///
///
void *AResult_init(int init_value, bool success) {
    return (void *)new A::Result(init_value, success);
}

///
///
///
void AResult_free(void *self) {
    if (self != NULL) {
        delete (A::Result *)self;
    }
}

///
///
///
int AResult_get_value(void *self) { return ((A::Result *)self)->get_value(); }

///
///
///
bool AResult_is_success(void *self) {
    return ((A::Result *)self)->is_success();
}

///
///
///
void AResult_print(void *self) { A::print(*((A::Result *)self)); }
