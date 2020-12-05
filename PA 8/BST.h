#pragma once
//#include "Common.h"
//#include "Node.h"
#include "TransactionNode.h"

class BST {

public:
BST();
~BST();

void publicInsert(int units, string type);
TransactionNode& findSmallest(Node* pCur);
TransactionNode& findLargest(Node* pCur);

//setters
void setmpRoot(Node* rootNode);

//getters
Node* getmpRoot();

protected:


private:

void destroyTree(Node *leaf); //called by destructor, uses PostOrderTraversal to delete tree
void privateInsert(Node* pCur, Node*& newNode);
void inOrderTraversal(Node* pCur);


//data member
Node* mpRoot; //ptr to a Node


};