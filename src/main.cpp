#include <gtest/gtest.h>
#include <array>
#include <iostream>
#include "table.h"

struct Foobar {
 public:
  explicit Foobar(int value) : _helloField(value) {}

  [[nodiscard]] int value() const { return _helloField; }

 private:
  int _helloField;
};

TEST(Foobar, goodTest) {
  using ::testing::Eq;
  constexpr auto EXPECTED_VALUE = 10;
  const auto foobar = Foobar{EXPECTED_VALUE};
  EXPECT_EQ(foobar.value(), EXPECTED_VALUE);
}