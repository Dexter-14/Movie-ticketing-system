#include<stdio.h>
#include<stdlib.h>
#ifndef _SHOW_H_
#define _SHOW_H_
void show(char *username, int language) //Declaring function
{
	FILE *f;	//Declaring file pointer
	f = fopen(username,"a");	 //Opening the file in append mode
	label:
	printf("\t\t\t\t\t\t\t\t\tChoose movie\n");

	if (language == 1)
	{
		fputs("language(1)=English",f);	//Adding a language to the file
		fputs(" ",f);
		printf("\t\t\t\t\t\t\t\t\tShowing English Movies\n");  //Showing the english movie available
		printf("\t\t\t\t\t\t\t\t\t1. Casino Royal : 1 Dec, 3 Dec\n");
		printf("\t\t\t\t\t\t\t\t\t2. Hangover : 2 Dec, 3 Dec\n");
		printf("\t\t\t\t\t\t\t\t\t3. Joker : 1 Dec, 2 Dec\n");
	}

	else if (language == 2)
	{
		fputs("language(2)=Hindi",f); //Adding a language to the file
		fputs(" ",f);
    		printf("\t\t\t\t\t\t\t\t\tShowing Hindi Movies\n");		//Showing the hindi movie available
    		printf("\t\t\t\t\t\t\t\t\t1. Housefull 4 : 1 Dec, 3 Dec\n");
    		printf("\t\t\t\t\t\t\t\t\t2. Andhadhun : 2 Dec, 3 Dec\n");
    		printf("\t\t\t\t\t\t\t\t\t3. Made in China : 1 Dec, 2 Dec\n");
	}

	else
	{
		printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n");
		goto label;		//If a person choose any other option then it will repeat the menu
	}
	fclose(f);
}
#endif
