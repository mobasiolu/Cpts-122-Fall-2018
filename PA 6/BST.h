#pragma once
#include "BSTNode.H"

class BST
{
public:
	BST();
	BST(BST &copy);
	~BST();

	//setters and getters




	//other member functions 
	void insertNode(char newLetter,string newData);
	void printBST();
	string searchBST(char &target);
	void deepCopyTree(BST copy);


	


private:
	BSTNode *mpRoot;

	void insertNode(BSTNode *root, char newLetter, string newData);
	void printBST(BSTNode *root);
	string searchBST(BSTNode *root, char &target);
	void deepCopyTree(BSTNode *copy);




	/*void inOrderTraversal(BSTNode *node);
	void preOrderTraversal(BSTNode *node);
	void postOrderTraversal(BSTNode *node);*/

	void destroyTree(BSTNode* node);



};