#include "test.h"

TEST(ListTest, CreateList) {
  s21::list::list a;
  std::vector<int> b;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
