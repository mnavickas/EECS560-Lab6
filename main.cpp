#include "heap.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "BST/BinarySearchTree.hpp"

using namespace std;

int main()
{

  Tree::BinarySearchTree tree;
  tree.levelorder();
  tree.remove(1);
  tree.levelorder();


}