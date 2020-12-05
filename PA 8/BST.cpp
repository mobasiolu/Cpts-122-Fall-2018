#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::publicInsert(int units, string type)
{

	Node* pMem = new TransactionNode(type, units);
	privateInsert(mpRoot, pMem);


}

TransactionNode& BST::findSmallest(Node* pCur)
{
	
	if (pCur->getmpLeft() == nullptr) //base case recursion
	{
		return *((TransactionNode*)pCur);
	}
	else
	{
		findSmallest(pCur->getmpLeft());
	}

	
	
}

TransactionNode& BST::findLargest(Node* pCur)
{

	if (pCur->getmpRight() == nullptr) //base case recursion
	{
		return *((TransactionNode*)pCur);
	}
	else
	{
		findLargest(pCur->getmpRight());
	}


}

void BST::setmpRoot(Node * rootNode)
{
	this->mpRoot = rootNode;
}

Node * BST::getmpRoot()
{
	return mpRoot;
}

void BST::destroyTree(Node* leaf)
{
	if (leaf != NULL) //postorder traversal 
	{
		destroyTree(leaf->getmpLeft());
		destroyTree(leaf->getmpRight());
		delete leaf;
	}
	
}

void BST::privateInsert(Node* pCur, Node *& newNode)
{


	if (mpRoot == nullptr)
	{
		mpRoot = newNode;

	}
	
	else if (((TransactionNode*)newNode)->getmUnits() < ((TransactionNode*)pCur)->getmUnits())
	{
		if (pCur->getmpLeft() == nullptr)
		{
			pCur->setmpLeft(newNode);
		}
		else
		{

			privateInsert(pCur->getmpLeft(),newNode);
		}
	}

	else if (((TransactionNode*)newNode)->getmUnits() > ((TransactionNode*)pCur)->getmUnits())
	{
		if (pCur->getmpRight() == nullptr)
		{
			pCur->setmpRight(newNode);
		}
		else
		{

			privateInsert(pCur->getmpRight(), newNode);
		}
	}

}

void BST::inOrderTraversal(Node * pCur) //LRP
{
	if (pCur == nullptr) //exit statement 
	{
		return;
	}

	inOrderTraversal(pCur->getmpLeft());
	((TransactionNode*)pCur)->printData();
	inOrderTraversal(pCur->getmpRight());

}
