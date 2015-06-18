/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	// your code here
 // Call the mirror function implement at the end
	mirror(root);		
	
}

/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
	return isOrdered(root);
}

/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
    // your code here
	vector<T> t;
	printPaths(root, t);
}

/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    return sumDistances(root, -1);
}


template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
	if(subRoot == NULL)
		return;
	
	Node* temp;

	temp = subRoot->left;
	subRoot->left = subRoot->right;
	subRoot->right = temp;
	
	mirror(subRoot->left);
	mirror(subRoot->right);
	
}


template <typename T>
bool BinaryTree<T>::isOrdered(Node* subRoot) const
{
  if(subRoot == NULL)
	return true;

bool leftOrder = true;
bool rightOrder= true;

	if(subRoot->left != NULL)
	{
  		if(subRoot->elem < subRoot->left->elem) 
		return false;
	leftOrder = isOrdered (subRoot->left);
	}

	if(subRoot->right !=NULL)
	{
		if(subRoot->elem > subRoot->right->elem )
		return false;
	rightOrder = isOrdered (subRoot->right);
	}
   
  return leftOrder && rightOrder;
}

template <typename T>
void BinaryTree<T>::printPaths(Node* subRoot, vector<T> t) const
{

	if(subRoot == NULL)
		return;
	
	// Adding all elements of the very left path into vector "t"
	t.push_back(subRoot->elem);
	printPaths(subRoot->left, t);
	
	// When reaching the bottom Noded (which means there are no left and right element exists)
	if(subRoot->left == NULL && subRoot->right ==NULL)
	{
	int size = t.size();
	 	std::cout<<"Path: ";
	 	for (int i =0; i< size; i++)
		std::cout<<t[i] <<" ";
	
		std::cout<<endl;
	}

	printPaths(subRoot->right, t);

}

template <typename T>
int BinaryTree<T>::sumDistances(Node* subRoot, int sum) const
{
	if(subRoot == NULL)
	return 0;

 sum++;
  int sumLeft = sum + sumDistances(subRoot->left, sum);
  int sumRight = sumDistances(subRoot->right, sum);
 
  //return sum + sumDistances(subRoot->left, sum) + sumDistances(subRoot->right,sum);
return sumLeft + sumRight;

 
}








