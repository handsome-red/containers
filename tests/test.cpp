#include "test.h"

TEST(ListTest, CreateList) {
  s21::list<int> list_int_cust;
  std::list<int> list_int_orig;
  EXPECT_EQ(list_int_cust.size(), list_int_orig.size());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}