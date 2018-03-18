// File:      main.cpp
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 7
// Date:      4/21/2016

// Demo program
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void visitFunction(int& value)
{
   cout << value << ' ';
}

int main()
{
   bSearchTreeType<int> tree;
   int num;
   cout << "Enter numbers ending with 0." << endl;
   cin >> num;
   while (num != 0)
   {
      tree.insert(num);
      cin >> num;
   }
   cout << "inorder traversal: ";
   tree.inorderTraversal(visitFunction);
   cout << endl;

   num = 999;
   tree.insert(999);
   if (tree.search(num))
      cout << num << " is in the tree at level " << tree.level(num) << endl;
   else
      cout << num << " is NOT in the tree\n";
   if (tree.binaryTreeType<int>::search(num))
      cout << num << " is in the tree at level " << tree.level(num) << endl;
   else
      cout << num << " is NOT in the tree\n";
   tree.deleteNode(num);
   if (tree.search(num))
      cout << num << " is in the tree\n";
   else
      cout << num << " is NOT in the tree\n";
   if (tree.binaryTreeType<int>::search(num))
      cout << num << " is in the tree at level " << tree.level(num) << endl;
   else
      cout << num << " is NOT in the tree\n";

   cout << "47 is at level " << tree.level(47) << endl;
   cout << "47 is at level " << tree.binaryTreeType<int>::level(47) << endl;

   cout << "tree height = " << tree.treeHeight() << endl;
   cout << "nodes: " << tree.treeNodeCount() << endl;
   cout << "leaves: " << tree.treeLeavesCount() << endl;
   cout << "non leaves: " << tree.nonLeavesCount() << endl;
   cout << "one child: " << tree.oneChildCount() << endl;
   cout << "two children: " << tree.twoChildrenCount() << endl;

   if (tree.balanced())
      cout << "the tree is balanced\n";
   else
      cout << "the tree is NOT balanced\n";

   cout << "breadth first traversal: ";
   tree.breadthFirstTraversal(visitFunction);
   cout << endl;


// Bonus
   cout << "BONUS: path from 47 to root: ";
   tree.path(47);
// Bonus
   int num1=77,num2=90;
   cout << "BONUS: siblings: ";
   if (tree.siblings(num1,num2))
      cout << num1 << " and " << num2 << " are siblings\n";
   else
      cout << num1 << " and " << num2 << " are NOT siblings\n";
   cout << "BONUS: siblings: ";
   if (tree.siblings(num2,num1))
      cout << num2 << " and " << num1 << " are siblings\n";
   else
      cout << num2 << " and " << num1 << " are NOT siblings\n";
   

// Bonus
   cout << "BONUS: ";
   if (tree.full())
      cout << "the tree is full\n";
   else
      cout << "the tree is NOT full\n";
// Bonus
   cout << "BONUS: generation of 90: ";
   tree.generation(90);
   

/*
   cout << "BONUS: ";
// Bonus
   if (tree.complete())
      cout << "the tree is complete\n";
   else
      cout << "the tree is NOT complete\n";
*/
   return 0;
}
