// -------------------------------------------------------------------------
// C++ API
// -------------------------------------------------------------------------
#ifdef __cplusplus
namespace A {

///
///
///
class Result {
    int invisible_value;
    bool invisible_success;

   public:
    Result(int init_value, bool success);
    ~Result();
    int get_value();
    bool is_success();
};

///
///
///
void print(Result &result);
}  // namespace A
#endif

// -------------------------------------------------------------------------
// C API
// -------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
#include <stdbool.h>
#endif

void *AResult_init(int init_value, bool success);
void AResult_free(void *self);
int AResult_get_value(void *self);
bool AResult_is_success(void *self);
void AResult_print(void *self);

#ifdef __cplusplus
}
#endif
