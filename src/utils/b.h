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
