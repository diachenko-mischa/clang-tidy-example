#include <array>
#include <iostream>

struct f__Foobar {
 private:
  int m_helloField;
};

int main(int argc, char** argv) {
  constexpr auto ARRAY_SIZE = 100;
  std::array<int, ARRAY_SIZE> array;
  std::cout << "Hello world" << std::endl;
  return 0;
}