#include "test.h"

TEST(ListTest, CreateList) {
  s21::list<int> a;
  std::vector<int> b;

  s21::list<int> i(5);
  std::vector<int> j(5);

  s21::list<int> k = {5, 4, 3, 2, 1};
  std::vector<int> m = {5, 4, 3, 2, 1};
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(i.size(), j.size());
  EXPECT_EQ(k.size(), m.size());
}

TEST(ListTest, IteratorList) {
  s21::list<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {1, 2, 3, 4, 5};

  size_t i = 0;
  for (const auto& item : a) {
    EXPECT_EQ(item, b[i++]);
  }
}

TEST(ListTest, PushBack) {
  s21::list<int> a;
  a.push_back(1);
  a.push_back(2);
  EXPECT_EQ(a.size(), 2);

  auto it = a.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}