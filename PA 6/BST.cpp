#include "BST.h"

BST::BST()
{
	//initializes the contents of the BST
	mpRoot = nullptr;
	string code;
	char character;

	//initializes a string variable to hold the contents from the file
	string templine;

	fstream morseCodeTree; //sets up a two way file stream 
	
	morseCodeTree.open("MorseTable.txt", std::ios::in | std::ios::out); //opens the file to do input/output operations
	
	while (std::getline(morseCodeTree, templine)) //Matthias helped me with this specific part
	{
		character = templine[0]; //since our file is storing each line as a string, the 0th index of our string will always be a letter
		code = templine.substr(2); //after the letter, the 2nd index of the string will be defined as a substring that will contain our morse code

		insertNode(character, code); // makes a node with the newly made character and code we have made above

	}


	morseCodeTree.close(); //closes the file stream

}

BST:: BST(BST &copy)
{
	this->mpRoot = nullptr;

	BSTNode *copyNode = copy.mpRoot; //sets the pointer value of the root to our original tree to that of our copy's root

	deepCopyTree(copyNode); //calls our deep copy constructor and uses the copyNode ptr as the root for our new tree
}

BST:: ~BST()
{

	//cout << "BST destructor being called" << endl;
	destroyTree(mpRoot);
}

void BST::insertNode(char newLetter, string newData) //public function
{
	
	insertNode(mpRoot, newLetter, newData);
}



void BST::insertNode(BSTNode *root, char newLetter, string newData) //private function
{
	//BSTNode *pMem = new BSTNode(newLetter, newData);

	if (root != nullptr)
	{
		// right subtree
		if (newLetter > root->getLetter())
		{
			if (root->getrightPtr() == nullptr)
			{
				root->setrightPtr(new BSTNode(newLetter, newData));
			}
			else //recursive step
			{
				insertNode(root->getrightPtr(), newLetter, newData);
			}

		}
		// we should check to see if the left and/or right
		// pointers are nullptrs

		else if (newLetter < root->getLetter())
		{
			// check left subtree
			if (root->getleftPtr() != nullptr)
			{
				// have not found place to insert yet,
				// go futher down the left subtree
				insertNode(root->getleftPtr(), newLetter, newData);
			}
			else
			{
				// found place to insert in left subtree
				root->setleftPtr(new BSTNode(newLetter, newData));
			}
		}
		else // duplicates
		{
			cout << "duplicate" << endl;
		}
	}
	else // root == nullptr
	{
		this->mpRoot = new BSTNode(newLetter, newData);
	}
}

void BST::printBST() //public function
{

	printBST(mpRoot);

	

}

void BST::printBST(BSTNode *root) //private function
{
	//printing in order

	if (root != nullptr)
			{
				// there are nodes to visit
			// 1. go left
			printBST(root->getleftPtr());
				// 2. process the node
			cout << root->getLetter() << endl;
			cout << root->getMorse() << endl;
			// 3. go right
				printBST(root->getrightPtr());
			}

}

string BST::searchBST(char &target)//
{
	string morse;

	morse = searchBST(mpRoot, target);

	return morse;
}

string BST::searchBST(BSTNode *root, char &target)
{
	string morseCode;

	if (target > root->getLetter()) //go to right
	{
		//checks to see if the right ptr is populated
		if (root->getrightPtr() != nullptr)
		{
			morseCode = searchBST(root->getrightPtr(), target);
		}
		else //if it's not populated
		{
			cout << "target does not exist in our list" << endl;
		}
	}

	else if (target < root->getLetter())

	{
		if (root->getleftPtr() != nullptr)
		{
			morseCode = searchBST(root->getleftPtr(), target);
		}
		else //if it's not populated
		{
			cout << "target does not exist in our list" << endl;
		}

	}
	else if (target == root->getLetter())
	{
		morseCode = root->getMorse();

	}

	return morseCode;
}


void BST::destroyTree(BSTNode* root) //uses a post-order BST traversal to delete all nodes
{
	if (root != nullptr)
	{
		destroyTree(root->getleftPtr()); //left
		destroyTree(root->getrightPtr()); //right

		delete root; //delete
	}

}

void BST::deepCopyTree(BST copy)
{

	deepCopyTree(copy.mpRoot);

}

void BST::deepCopyTree(BSTNode *copy) //makes a deep copy of our original tree
{
	if (copy != nullptr) //if not populated
	{
		string copystring = copy->getMorse();
		char copychar = copy->getLetter();

		BSTNode copyNode(copychar, copystring);

		//goes in the order of a preorder traversal to make a deep copy of our original tree
		insertNode(copy, copychar, copystring);
		deepCopyTree(copy->getleftPtr());
		deepCopyTree(copy->getrightPtr());

	}

}