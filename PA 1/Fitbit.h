#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

}Sleep;


typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;


} FitbitData;

int success_open(FILE *infile);
void read_line(FILE *infile, char arr[]);
FitbitData analyze_line(FILE *infile, char arr[]);
void insert(char* token, FitbitData *holder, int count);
void clean(char *line);
void dedupe(char *line, FitbitData arr[], int j);
void outputStats(FILE *outfile, FitbitData arr[]);