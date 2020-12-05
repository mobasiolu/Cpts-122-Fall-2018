#pragma once

#pragma once
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;

template <typename C, typename S>

class BSTNode
{
public:
	BSTNode<C,S>(C letter, S morse);
	BSTNode<C,S>(BSTNode<C,S> &copy);
	~BSTNode<C,S>();



	//setters and getters
	S getMorse();
	void setMorse(S &morse);//I dont understand why we use a reference

	C getLetter();
	void setLetter(C &letter);

	BSTNode* getleftPtr();
	void setleftPtr(BSTNode<C,S> *ptr);

	BSTNode<C,S>* getrightPtr();
	void setrightPtr(BSTNode<C,S> *ptr);




private:
	string morse;
	char letter;
	BSTNode *leftptr;
	BSTNode *rightptr;



};