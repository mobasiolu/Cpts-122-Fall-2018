#include "BST.h"
//Name:Maximillian Obasiolu
//Collaborators: Matthias Mcfarlane, Jasdeep Singh, Kadir Nour
//TA: Ryan N.
//PA: PA 6, BST
//
int main(void)
{

	fstream convertFileStream; //declares and input output file stream 

	string templine; //used solely for our getline function
	char character;
	int strlen;
	int step = 0;

	convertFileStream.open("Convert.txt", std::ios::in | std::ios::out); //opens the stream to our Convert txt file
	BST treeOfLife; //instantiation of our BST object

	treeOfLife.printBST();

	system("cls");

	cout << "THE DISPLAY BELOW WILL BE WHAT IS CONTAINED IN THE CONVERT TXT FILE" << endl;
	cout << "\n" << endl;


	while (std::getline(convertFileStream,templine)) //iterates through the convert //Matthias also helped me with this 
	{
		strlen = templine.size(); //gets the number of characters that was in the line that was grabbed, counts them, then assigns that number to strlen
		for (step = 0 ; step < strlen; step++)
		{
			character = templine[step]; //stores each indexed value into a character, and does it repeatedly as we go through the loop

			character = toupper(character); //turns the letter to uppercase

			if (character == ' ') //accounts for if the character is a blank space
			{
				cout << " "; 
			}
			else
			{
				
				cout << treeOfLife.searchBST(character) << " " ; // if the character is not a blank space, then the letter is taken and matched with whatever is in our BST using the search function

			}

		}

		cout << endl; 
		
	}

	system("PAUSE");

	convertFileStream.close(); //closes the file stream


}