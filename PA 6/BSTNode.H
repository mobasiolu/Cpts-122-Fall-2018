#pragma once
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;

class BSTNode
{
public:
	BSTNode(char letter = 0, string morse = "\0");
	BSTNode(BSTNode &copy);
	~BSTNode();



	//setters and getters
	string getMorse();
	void setMorse(string &morse);//I dont understand why we use a reference

	char getLetter();
	void setLetter(char &letter);

	BSTNode* getleftPtr();
	void setleftPtr(BSTNode *ptr);

	BSTNode* getrightPtr();
	void setrightPtr(BSTNode *ptr);




private:
	string morse;
	char letter;
	BSTNode *leftptr;
	BSTNode *rightptr;



};