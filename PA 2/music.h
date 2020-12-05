#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>
#include <windows.h>

typedef struct Duration
{
	int min;
	int sec;

}Duration;

typedef struct record
{
	char artist[15];
	char albumTitle[15];
	char songTitle[15];
	char genre[15];
	Duration songLength;
	int timesPlayed;
	int rating;


}Record;


typedef struct Node
{
	
	Record data;
	struct Node *pNext;
	struct Node *pPrev;
 
}Node;

//typedef struct LinkedList
//{
//	Node *pHead;
//	int count;
//
//}LinkedList;


int menu();
int load(FILE *infile, Node **pHead);
Node *makeNode(Record data);
void insertFront(Node* *pHead, Record song);
void store(FILE *infile, Node *phead);
void display(Node *phead);
void rate(Node* *pHead);
void displayEach(Record data);
void editHelper(Node ** pcurr);
void exit(FILE * infile, Node **phead);



