#include <iostream>
#include <list>

void printList(std::list<int> read) {
  for (auto& item : read) {
    std::cout << item;
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> A{3, 2, 1, 0};
  std::list<int> B{4, 5, 6};

  // std::list<int> resultAB;

  A.splice(A.begin(), B);

  printList(A);

  std::list<int> C{3, 2, 1, 0};
  std::list<int> D{4, 5, 6};

  C.splice(C.begin(), D);

  // std::list<int> resultCD;

  printList(C);

  return 0;
}