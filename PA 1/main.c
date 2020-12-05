#include "Fitbit.h"

//Name: Maximillian Obasiolu
//Programming Assignment: PA 1
//Collaborator(s): Kadir Nour, Oumar Sidibe


int main()
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	char line[100];
	int success = 0;
	FitbitData one_day[1440] = { NULL };

	infile = fopen("FitbitData.csv", "r");
	success = success_open(infile);

	//To discard header lines in file
	read_line(infile, line);
	read_line(infile, line);

	int i = 0;
 	while(!feof(infile))
	{
		read_line(infile, line); 
		dedupe(line, one_day, i);
		one_day[i] = analyze_line(infile, line);
		
		i++;
	}

	outfile = fopen("finalResults.csv", "w");

	outputStats(outfile, one_day);

	fclose(infile);
	fclose(outfile);

 	return 0;
}