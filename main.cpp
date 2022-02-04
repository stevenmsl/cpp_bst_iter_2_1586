#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1586;

Node *testFixture1()
{
  auto tree = new Node(7);
  tree->left = new Node(3);
  tree->right = new Node(15);
  tree->right->left = new Node(9);
  tree->right->right = new Node(20);
  return tree;
}

void test1()
{
  auto tree = testFixture1();
  auto iter = BTSIterator(tree);
  cout << "next should be 3: " << iter.next() << endl;
  cout << "next should be 7: " << iter.next() << endl;
  cout << "prev should be 3: " << iter.prev() << endl;
  cout << "next should be 7: " << iter.next() << endl;
  cout << "has next should be 1: " << iter.hasNext() << endl;
  cout << "next should be 9: " << iter.next() << endl;
  cout << "next should be 15: " << iter.next() << endl;
  cout << "next should be 20: " << iter.next() << endl;
  cout << "has next should be 0: " << iter.hasNext() << endl;
  cout << "has prev should be 1: " << iter.hasPrev() << endl;
  cout << "prev should be 15: " << iter.prev() << endl;
  cout << "prev should be 9: " << iter.prev() << endl;
}

main()
{
  test1();

  return 0;
}