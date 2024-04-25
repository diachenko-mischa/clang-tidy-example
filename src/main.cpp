#include <gtest/gtest.h>
#include <array>
#include <iostream>
#include "table.h"

struct Foobar {
 public:
  explicit Foobar(int value) : mhelloField(value) {}

  [[nodiscard]] int value() const { return mhelloField; }

 private:
  int mhelloField;
};

TEST(Foobar, goodTest) {
  using ::testing::Eq;
  constexpr auto EXPECTED_VALUE = 10;
  const auto foobar = Foobar{EXPECTED_VALUE};
  EXPECT_EQ(foobar.value(), EXPECTED_VALUE);
}