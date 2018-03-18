// File:      binaryTree.h
// Name:      Binaya Bhattarai
// Class:     CSIS 352
// Program:   assignment 7
// Date:      4/21/2016

//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

//Definition of the Node
template <class elemType>
struct nodeType
{
	elemType			info;
	nodeType<elemType>  *llink;
	nodeType<elemType>  *rlink;
};
	
	//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
   	int level(const elemType& item) const;
	//Function to return the level of the tree where item is.
	//	The level is the number of branches from the root to the node.
	//	The root is at level 0.
	//Input: item to find the level where it's at
	//Output: level where item is
	//Precondition: item must be in the tree
	//Postcondition: Returns the level where item is
   bool full() const;
      //Input: none
      //Output: whether tree is full or not (bool)
      //Function to return whether the tree is full (by definition) or not
      //Precondition:  none
      //Postcondition: Returns true if tree is full, false otherwise
	void path(const elemType& item) const;
      //Function to output the path from the item to the root with each
      //     item separated with a blank
      //Input: item to find the path
      //Output: none
      //Precondition:  item must be in the tree
      //Postcondition: the path is output
	bool siblings(const elemType& item1, const elemType& item2) const;
	//Function to return whether the items are siblings or not
	//Input: two items of the type stored in the tree
	//Output: true if the items are siblings, false otherwise
	//Precondition: none
	//Postcondition: whether items are siblings is returned
	void breadthFirstTraversal(void (*visit) (elemType&)) const;
      //Function to do a breadth first traversal of the tree
      //Input: a pointer to a function to execute on each item
      //Output: none
      //Precondition:  none
      //Postcondition: the traversal visits each node
   bool balanced() const;
      //Function to return whether the tree is balanced (by definition) or not
      //Input: none
      //Output: whether tree is balanced or not (bool)
      //Precondition:  none
      //Postcondition: Returns true if tree is balanced, false otherwise
	int nonLeavesCount() const;
      //Function to return number of nodes that are not leaves
      //Input: none
      //Output: the number of nodes that are not leaves
      //Precondition:  none
      //Postcondition: Returns the number of nodes that are not leaves
	int twoChildrenCount() const;
      //Function to return number of nodes with two children
      //Input: none
      //Output: the number of nodes with two children
      //Precondition:  none
      //Postcondition: Returns the number of nodes with two children
	int oneChildCount() const;
      //Function to return number of nodes with one child
      //Input: none
      //Output: the number of nodes with one child
      //Precondition:  none
      //Postcondition: Returns the number of nodes with one child
	bool search(const elemType& searchItem) const;
      //Function to determine if searchItem is in the binary tree
      //Postcondition: Returns true if searchItem is found in the 
      //               binary tree; otherwise, returns false.	
    const binaryTreeType<elemType>& operator=
                 (const binaryTreeType<elemType>&); 
      //Overload the assignment operator.
    bool isEmpty() const;
      //Function to determine whether the binary tree
	  //is empty.
	  //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in inorder sequence.
    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in preorder sequence.
    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
	  //Postcondition: Nodes are printed in postorder sequence.

	void inorderTraversal(void (*visit) (elemType&)) const;
	  //Function to do an inorder traversal of the binary tree.
	  //The parameter visit, which is a function, specifies
	  //the action to be taken at each node.
	  //Postcondition: The action specified by the function visit
	  //               is applied to each node of the binary tree.

    int treeHeight() const;
      //Funtion to determine the height of a binary tree.
	  //Postcondition: Returns the height of the binary tree.
    int treeNodeCount() const;
      //Funtion to determine the number of nodes in a 
	  //binary tree.
      //Postcondition: Returns the number of nodes in the 
	  //               binary tree.
    int treeLeavesCount() const;
      //Funtion to determine the number of leaves in a 
	  //binary tree.
      //Postcondition: Returns the number of leaves in the 
	  //               binary tree.
    void destroyTree();
      //Function to destroy the binary tree.
	  //Postcondition: Memory space occupied by each node 
	  //               is deallocatd.
      //               root = NULL;

    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //copy constructor

    binaryTreeType();   
      //default constructor

    ~binaryTreeType();   
      //destructor

protected:
    nodeType<elemType>  *root;

private:
	void getPath(const elemType& item, nodeType<elemType>* p, 
				 stack<nodeType<elemType>*>& s) const;
      //Function to get the path from the item to p.
		// the path is returned as items in the stack s
      //Input: item to find the path to, root node of tree, stack for output
      //Output: none
      //Precondition:  item must be in the tree
      //Postcondition: the path is output as items in the stack s
	bool isBalanced(nodeType<elemType>* p, int diff) const;
	   //Function to return whether the tree to which p points
	   //is balanced (by definition) or not
      //Input: root node of the tree p 
	  // 	diff is the amount by which the left and right heights can differ
      //Output: whether tree is balanced or not (bool)
      //Precondition:  none
      //Postcondition: Returns true if tree to which p points 
	  //	is balanced to diff height, false otherwise
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
	  //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.
    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: Memory space occupied by each node, in the
	  //               binary tree to which p points, is deallocatd.
      //               p = NULL;
    void inorder(nodeType<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in inorder sequence.
    void preorder(nodeType<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in preorder sequence.
    void postorder(nodeType<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
	  //Postcondition: Nodes of the binary tree, to which p
	  //               points, are printed in postorder sequence.
	void inorder(nodeType<elemType> *p, void (*visit) (elemType&)) const;
	  //Function to do an inorder traversal of the binary
	  //tree starting at the node specified by the parameter p. 
	  //The parameter visit, which is a function, specifies the
	  //action to be taken at each node.
	  //Postcondition: The action specified by the function visit
	  //               is applied to each node of the binary tree
	  //               to which p points.
    int height(nodeType<elemType>* p) const;
      //Function to determine the height of the binary tree
      //to which p points. 
	  //Postcondition: Height of the binary tree to which 
	  //               p points is returned.
    int max(int x, int y) const;
      //Function to determine the larger of x and y.
	  //Postcondition: Returns the larger of x and y.
    int nodeCount(nodeType<elemType>* p) const;
      //Function to determine the number of nodes in 
      //the binary tree to which p points. 
  	  //Postcondition: The number of nodes in the binary 
	  //               tree to which p points is returned.
    int leavesCount(nodeType<elemType>* p) const;
      //Function to determine the number of leaves in  
      //the binary tree to which p points 
 	  //Postcondition: The number of leaves in the binary 
	  //               tree to which p points is returned.
	bool searchNode(const elemType&, nodeType<elemType>* p) const;
	   //Function to determine if elem is contained in the binary tree
		//pointed to by p
 	  //Postcondition: return true if elem is found in the binary tree,
		//false otherwise.
	int oneChildNodes(nodeType<elemType>* p) const;
	//Function to determine the number of nodes with one child in 
	//the binary tree to which p points. 
	//Postcondition: The number of nodes with one child in the binary 
	//               tree to which p points is returned.
	int twoChildrenNodes(nodeType<elemType>* p) const;
	//Function to determine the number of nodes with two children in 
	//the binary tree to which p points. 
	//Postcondition: The number of nodes with two children in the binary 
	//               tree to which p points is returned.
    int nonLeaves(nodeType<elemType>* p) const;
      //Function to determine the number of non-leaves in  
      //the binary tree to which p points 
 	  //Postcondition: The number of nodes that are not leaves 
	  //               in the binary tree to which p points is returned.
};

//Definition of member functions
template<class elemType>
int binaryTreeType<elemType>::level(const elemType& item) const
{
	stack<nodeType<elemType>*> pth;
	getPath(item, root, pth);
	return pth.size()-1;
}

template<class elemType>
bool binaryTreeType<elemType>::full() const
{
	return isBalanced(root, 0);
}

template<class elemType>
void binaryTreeType<elemType>::path(const elemType& item) const
{
	stack<nodeType<elemType>*> pth;
	getPath(item, root, pth);
	
	while (!pth.empty())
	{
		cout << pth.top()->info << ' ';
		pth.pop();
	}
	cout << endl;
}

template<class elemType>
void binaryTreeType<elemType>::	getPath(const elemType& item, 
	nodeType<elemType>* p, stack<nodeType<elemType>*>& s) const
{
	if (p != NULL)
	{
		s.push(p);
		if (p->info != item)
		{
			getPath(item, p->llink, s);
			
			if (s.top()->info != item)
				getPath(item, p->rlink, s);
			
			if (s.top()->info != item)
				s.pop();
		}
	}
}

template<class elemType>
bool binaryTreeType<elemType>::siblings(
	const elemType& item1, const elemType& item2) const
{
	stack<nodeType<elemType>*> pth1, pth2;
	getPath(item1, root, pth1);
	getPath(item2, root, pth2);
	
	if (pth1.empty() || pth2.empty())
		return false;
	
	//remove items themselves form the end of the paths 
	//and compare their parents
	pth1.pop();
	pth2.pop();
	
	return pth1.top()->info == pth2.top()->info;
}

template<class elemType>
void binaryTreeType<elemType>::breadthFirstTraversal(
	void (*visit) (elemType& item)) const
{
	queue<nodeType<elemType>*> nodeQ;
	nodeType<elemType>* current;
	
	if (root != NULL)
		nodeQ.push(root);
	
	while (!nodeQ.empty())
	{
		current = nodeQ.front();
		
		if (current->llink != NULL)
			nodeQ.push(current->llink);
		if (current->rlink != NULL)
			nodeQ.push(current->rlink);
		
		visit(current->info);
		nodeQ.pop();
	}
}
	
template<class elemType>
bool binaryTreeType<elemType>::balanced() const
{
	return isBalanced(root, 1);
}

template<class elemType>
bool binaryTreeType<elemType>::isBalanced(
	nodeType<elemType>* p, int diff) const
{
	if (p == NULL)
		return true;
	else
	{
		if (abs(height(p->llink)-height(p->rlink)) > diff)
			return false;
		else
			return isBalanced(p->llink, diff) && isBalanced(p->rlink, diff);
	}
}

template<class elemType>
int binaryTreeType<elemType>::nonLeavesCount() const
{
	return nonLeaves(root);
}

template<class elemType>
int binaryTreeType<elemType>::nonLeaves(nodeType<elemType> *p) const
{
	if (p == NULL || (p->llink == NULL && p->rlink == NULL))
		return 0;
	else
		return 1 + nonLeaves(p->llink) + nonLeaves(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::oneChildNodes(nodeType<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink == NULL ^ p->rlink == NULL)
		return 1 + oneChildNodes(p->llink) + oneChildNodes(p->rlink);
	else
		return oneChildNodes(p->llink) + oneChildNodes(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::twoChildrenNodes(nodeType<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink != NULL && p->rlink != NULL)
		return 1 + twoChildrenNodes(p->llink) + twoChildrenNodes(p->rlink);
	else
		return twoChildrenNodes(p->llink) + twoChildrenNodes(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::twoChildrenCount() const
{
	return twoChildrenNodes(root);
}

template<class elemType>
int binaryTreeType<elemType>::oneChildCount() const
{
	return oneChildNodes(root);
}

template<class elemType>
bool binaryTreeType<elemType>::search(const elemType& elem) const
{
	searchNode(elem, root);
}

template<class elemType>
bool binaryTreeType<elemType>::searchNode(
	const elemType& elem, nodeType<elemType> *p) const
{
	if (p == NULL)
 		return false;
 	else if (p->info == elem)
 		return true;
 	else
 		return searchNode(elem, p->llink) || searchNode(elem, p->rlink);
}

template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                      (nodeType<elemType>* &copiedTreeRoot,
		               nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}		
}

   //Overload the assignment operator
template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
           operator=(const binaryTreeType<elemType>& otherTree)
{ 
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL)  //if the binary tree is not empty, 
			              //destroy the binary tree
			destroy(root);

		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else

   return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
              (const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink == NULL && p->rlink == NULL)
		return 1;
	else
		return leavesCount(p->llink) + leavesCount(p->rlink);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal
			                  (void (*visit) (elemType& item)) const
{ 
	inorder(root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p,
							   void (*visit) (elemType& item)) const
{
	if (p != NULL)
	{
		inorder(p->llink, *visit);
		(*visit)(p->info);
		inorder(p->rlink, *visit);
	}
}

#endif