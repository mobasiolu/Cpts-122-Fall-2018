#include "music.h"



Node *makeNode(Record data)
{
	Node * pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));// allocate memory from heap

	pMem->data = data;
	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}
   
void insertFront(Node **pHead,Record song)
{
	Node *pMem = makeNode(song); //makes a pMem node
	Node *pCur = *pHead; // to keep a copy of where pHead is pointing to before we change it
	
	if (*pHead != NULL)
	{
		pMem->pNext = *pHead; //points pMem's pNext to *pHead thus connecting it yo the existing list

		*pHead = pMem; //making pMem the new head of the list
		pCur->pPrev = *pHead; // setting the previous pointer of pCur(which points to the former head) to te new pHead
	}
	else
	{
		*pHead = pMem;
	}
}

int load(FILE *infile, Node **pHead)
{
	Record song = { 0 };
	char readString[100];

	while(!feof(infile))
	{
		fgets(readString, 100, infile);

		if (readString[0] == '"')
			{
				strcpy(song.artist, strtok(readString, "\""));
				strcpy(song.albumTitle, strtok(NULL, ","));
				strcpy(song.songTitle, strtok(NULL, ","));
				strcpy(song.genre, strtok(NULL, ","));
				song.songLength.min = atoi(strtok(NULL, ":"));
				song.songLength.sec = atoi(strtok(NULL, ","));
				song.timesPlayed = atoi(strtok(NULL, ","));
				song.rating = atoi(strtok(NULL, ","));
			}
			else
			{
				strcpy(song.artist, strtok(readString, ","));
				strcpy(song.albumTitle, strtok(NULL, ","));
				strcpy(song.songTitle, strtok(NULL, ","));
				strcpy(song.genre, strtok(NULL, ","));
				song.songLength.min = atoi(strtok(NULL, ":"));
				song.songLength.sec = atoi(strtok(NULL, ","));
				song.timesPlayed = atoi(strtok(NULL, ","));
				song.rating = atoi(strtok(NULL, ","));
			}
		insertFront(pHead, song);

	}
}

void store(FILE *infile, Node *phead) 
{
	char line[100] = { 0 };

	while (phead != NULL) {
		if (strlen(phead->data.artist) > 6) {
			fprintf(infile, "\"%s\",", phead->data.artist);
		}
		else {
			fprintf(infile, "%s,", phead->data.artist);
		}
		fprintf(infile, "%s,", phead->data.albumTitle);
		fprintf(infile, "%s,", phead->data.songTitle);
		fprintf(infile, "%s,", phead->data.genre);
		fprintf(infile, "%d:%d,", phead->data.songLength.min, phead->data.songLength.sec);
		fprintf(infile, "%d,", phead->data.timesPlayed);
		fprintf(infile, "%d", phead->data.rating);

		if (phead->pNext != NULL) {
			fprintf(infile, "\n");
		}
		phead = phead->pNext;
	}
}
void displayEach(Record data) // operates as a function that prints one record at a time
{

	printf("\n%s\n", data.artist);
	printf("%s\n", data.albumTitle);
	printf("%s\n", data.songTitle);
	printf("%s\n", data.genre);
	printf("%d:", data.songLength.min);
	printf("%d\n", data.songLength.sec);

	printf("%d\n", data.timesPlayed);
	printf("%d\n", data.rating);


	printf("---------------------------------\n");

}

void display(Node *pHead)
{
	while (pHead != NULL)
	{
		displayEach(pHead->data);

		pHead = pHead->pNext;
	}
}
void editHelper(Node ** pcurr) //operates as an extension of the edit function. it prompts the user about what data point they'd like to change in a specific song
{
	int edit = 0;
	char choice = 'Y';
	int song_length_min = 0;
	int song_length_sec = 0;
	int times_song_played = 0;
	int song_rating = 0;
	char line[50] = {0};

	printf("\nWhat would you like to change?\n1. Artist\n2. Album Tilte\n3. Song Title\n ......\n");
	scanf(" %d",&edit);
	
	while (choice != 'N') {

		switch (edit) {
		case 1:
		printf("What do you want to change the artist name to?\n");
		scanf(" %[^\n]s", line);
		strcpy((*pcurr)->data.artist, line);
			break;
		case 2:
		printf("What do you want to change the album title to?\n");
			scanf(" %[^\n]s", line);
			strcpy((*pcurr)->data.albumTitle, line);
			break;
		case 3:
			printf("What do you want to change the song title to?\n");
			scanf(" %[^\n]s", line);
			strcpy((*pcurr)->data.songTitle, line);
			break;
		case 4:
			printf("What do you want to change the genre name to?\n");
			scanf(" %[^\n]s", line);
			strcpy((*pcurr)->data.genre, line);
			break;
		case 5:
			printf("What do you want to change the song length to?\n");
			scanf(" %d %d", &song_length_min, &song_length_sec);
			(*pcurr)->data.songLength.min = song_length_min;
			(*pcurr)->data.songLength.sec = song_length_sec;
			break;
		case 6:
			printf("What do you want to change the times played to?\n");
			scanf(" %d", &times_song_played);
			(*pcurr)->data.timesPlayed = times_song_played;
			break;
		case 7:
			printf("What do you want to change the song rating to?\n");
			scanf(" %d", &song_rating);
			(*pcurr)->data.rating = song_rating;
			break;
		}





		printf("\nDo you want to change anything else?\n");
		scanf(" %c", &choice);

	}
	
}
void edit(Node* *phead) //
{
	char artistName[25] = { 0 };// making a temporary string 
	char choice = 0;
	int count = 0;
	char songTitle[100];
	Node *pcurr = *phead;

	printf("Enter the name of the artist whose record you'd like to edit\n");
	scanf("%s", artistName);

	while (pcurr != NULL) //while the list is not empty
	{
		if (strcmp(toupper(artistName), toupper(pcurr->data.artist)) == 0) //uses string comp to see iff the given name matches the artist's name from the strict
		{

			displayEach(pcurr->data);
			printf("\nIs this the right record? (Y/N)\n");
			scanf(" %c", &choice);

			if (toupper(choice) == 'Y') {
				editHelper(&pcurr);
				break;
			}

		}
		pcurr = pcurr->pNext; //increments 
	}
}

void rate(Node* *pHead) // NOT FINISHED
{
	char songName[50] = { 0 };
	display(*pHead);
	Node *pcurr = *pHead;
	int user_rating = 0;

	printf("Enter the name of the song you'd like to rate\n");
	scanf(" %[^\n]s", &songName);


	while (pcurr != NULL) //while the list is not empty
	{
		if (strcmp(toupper(songName), toupper(pcurr->data.songTitle)) == 0) //uses string comp to see iff the given name matches the artist's name from the strict
		{
			do {
				printf("enter a valid rating btwn 1 and 5");
				scanf("%d", &user_rating);

			} while (user_rating < 1 || user_rating > 5);
			pcurr->data.rating = user_rating;

		}
		pcurr = pcurr->pNext; 
	}


}


void play(Node *phead) {
	char choice = 0;
	char line[50] = { 0 };
	printf("Do you want play a specific artists songs? (Y/N)\n");
	scanf(" %c", &choice);

	if (toupper(choice) == 'Y') {
		printf("What artist?\n");
		scanf("%s", line);
	}

	while (phead != NULL) {
		if (toupper(choice) == 'N') {
			displayEach(phead->data);
			Sleep(1000);
		}
		else {

			if (strcmp(line, phead->data.artist) == 0) {
				displayEach(phead->data);
				Sleep(1000);
			}
		}
		phead = phead->pNext;
	}		

}

void exit(FILE * infile, Node **phead) {
	store(infile, phead);
}


int menu()
{
	int switch_on;
	FILE *infile = NULL;

	infile = fopen("musicPlaylist.csv", "r");

	Node *pList = NULL; //initializing pointer to a linkedlist

	int loop = 1;
	while (loop) {
		printf("Welcome Heathens!!\n");
		printf("Please choose from the following menu:\n");
		printf("1: Load songs\n");
		printf("2: Store songs\n");
		printf("3: Display songs\n");
		printf("4: Insert songs\n");
		printf("5: Delete songs\n");
		printf("6: Edit songs\n");
		printf("7: Sort songs\n");
		printf("8: Rate songs\n");
		printf("9: Play songs\n");
		printf("10: Shuffle\n");
		printf("11: Exit\n");

		scanf("%d", &switch_on);

		switch (switch_on)
		{

		case 1:
		{
			system("CLS");
			load(infile, &pList);
			break;
		}
		;

		case 2:
		{
			system("CLS");
			store(infile, pList);

			break;
		}
		;
		case 3:
		{
			system("CLS");
			display(pList);
			break;
		}
		;
		case 4:
		{

			break;
		}
		;
		case 5:
		{

			break;
		}
		;
		case 6:
		{
			system("CLS");
			edit(&pList);
			break;
		}
		;
		case 7:
		{

			break;
		}
		;
		case 8:
		{
			system("CLS");
			rate(&pList);
			break;
		}
		;
		case 9:
		{
			system("CLS");
			play(pList);
			break;
		}
		;
		case 10:
		{

			break;
		}
		;
		case 11:
		{
			exit(infile, &pList);
			loop = 0;
			break;
		}
		;
		}

	}


}