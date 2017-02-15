#include<iostream>
using namespace std;

// Definition of the node used for the BST
struct BinarySearchTreeNode {

	int data; // The data to store in the node
	BinarySearchTreeNode* left; // The left "leaf" of the node
	BinarySearchTreeNode* right; // The right "leaf" of the node
};

// Function for creating a new node
BinarySearchTreeNode* GetNewNode(int data) {

	BinarySearchTreeNode* newNode = new BinarySearchTreeNode(); // Instantiate the new node
	newNode -> data = data; // Set the data in the new node to the parameter
	newNode -> left = newNode -> right = NULL; // Set left and right leafs to NULL
	return newNode;
}

// Return the address of root node for inserting its data in the BST
BinarySearchTreeNode* Insert(BinarySearchTreeNode* root, int data) {

	if (root == NULL) { // Set the tree to empty
		root = GetNewNode(data);
	}
	// If incoming data is lesser, insert it in the left subtree
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	// Else insert it in the right subtree 
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

//To search an element in BST, returns true if element is found
bool Search(BinarySearchTreeNode* root, int data) {

	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

int maxValue(BinarySearchTreeNode *node)
{
	// If the tree is empty, do nothing. 
	if (node == nullptr)
		cout << "The BST is empty";

	int max = node -> data;

	// Grab the max on the left side of the BST
	if (node->left != nullptr) {
		int leftMax = maxValue(node -> left);
		if (max < leftMax)
			max = leftMax;
	}

	// Grab the max on the right side of the BST, compare to the original max
	if (node->right != nullptr) {
		int rightMax = maxValue(node -> right);
		if (max < rightMax)
			max = rightMax;
	}

	// Return the max number
	return max;
}

int main() {
	BinarySearchTreeNode* root = NULL;  // Create an empty tree

	root = Insert(root, 2);
	root = Insert(root, 28);
	root = Insert(root, 11);
	root = Insert(root, 50);
	root = Insert(root, 46);

	root = Insert(root, 30);
	root = Insert(root, 5);
	root = Insert(root, 13);
	root = Insert(root, 40);
	root = Insert(root, 77);

	root = Insert(root, 72);
	root = Insert(root, 10);
	root = Insert(root, 30);
	root = Insert(root, 74);
	root = Insert(root, 12);

	root = Insert(root, 32);
	root = Insert(root, 45);
	root = Insert(root, 65);
	root = Insert(root, 21);
	root = Insert(root, 19);

	int number;

	// Prompt the user for a number a number
	cout << "Which number are you looking for?\n";
	cin >> number;

	// If the number is found, print the following:
	if (Search(root, number) == true) cout << number << " is in the BST!\n";
	else cout << number << " was not found in the BST\n";
	
	// Print the max
	cout << "\nThe max number in the tree is " << maxValue(root) << "\n\n";
	
	system("pause");
}