#include <a.h>
#include <b.h>
#include <stdio.h>

///
///
///
int main(void) {
    printf("\n>>> Calling C++ lib function in C:)\n");

    void *a_result = AResult_init(38, true);
    printf("\n>>> a_result value: %d", AResult_get_value(a_result));
    printf("\n>>> a_result is_success: %s\n",
           AResult_is_success(a_result) ? "true" : "false");
    AResult_print(a_result);
    AResult_free(a_result);

    void *b_result = BResult_init(123.789);
    printf("\n>>> b_result value: %.3f\n", BResult_get_float_value(b_result));
    BResult_print(b_result);
    BResult_free(b_result);
}
