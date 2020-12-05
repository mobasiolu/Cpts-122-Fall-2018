#include "BSTNode.H"

BSTNode::BSTNode (char letter, string morse)
{
	this->letter = letter;
	this->morse = morse;
	this->leftptr = nullptr;
	this->rightptr = nullptr;

}

BSTNode::BSTNode(BSTNode &copy)
{

	this->letter = copy.letter;
	this->morse = copy.morse;
}

BSTNode::~BSTNode()
{

	//cout << "destructor is being called" << endl;

}

string BSTNode::getMorse()
{

	return morse;

}

void BSTNode::setMorse(string &morse) //I dont understand why we use a reference
{
	this->morse = morse;
}

char BSTNode::getLetter()
{

	return letter;
}

void BSTNode::setLetter(char &letter)
{

	this->letter = letter;

}

BSTNode* BSTNode:: getleftPtr()
{
	
	return leftptr;
}

void BSTNode:: setleftPtr(BSTNode *ptr)
{
	this->leftptr = ptr;
}

BSTNode* BSTNode::getrightPtr()
{

	return rightptr;

}

void BSTNode::setrightPtr(BSTNode *ptr)
{

	this->rightptr = ptr;

}
