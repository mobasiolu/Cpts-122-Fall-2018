#include "Common.h"
#include "Node.h"


Node::Node(string const & data)
{
	this->mData = data;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node() //virtual destructor
{
	//cout << "Node class destructor called" << endl;
}

string Node::getmData()
{
	return mData;
}

Node *& Node::getmpLeft()
{
	return mpLeft;
}

Node *& Node::getmpRight()
{
	return mpRight;
}

void Node::setmData(string data)
{
	this->mData = data;
}

void Node::setmpLeft(Node* leftPtr)
{
	this->mpLeft = leftPtr;

}

void Node::setmpRight(Node* rightPtr)
{

	this->mpRight = rightPtr;

}
