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
} // namespace A
