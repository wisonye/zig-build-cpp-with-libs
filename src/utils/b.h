// -------------------------------------------------------------------------
// C++ API
// -------------------------------------------------------------------------
#ifdef __cplusplus
namespace B {

///
///
///
class Result {
  float invisible_float;

public:
  Result(float init_float);
  ~Result();
  float get_float_value();
};

///
///
///
void print(Result &result);
}
#endif

// -------------------------------------------------------------------------
// C API
// -------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

void *BResult_init(float init_float);
void BResult_free(void *self);
float BResult_get_float_value(void *self);
void BResult_print(void *self);

#ifdef __cplusplus
}
#endif
