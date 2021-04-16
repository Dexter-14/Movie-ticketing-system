#include<stdio.h>
#include"confirm.h"
#ifndef _CHOOSE_H_
#define _CHOOSE_H_
void choose(char *username, int language)  //Declaring function
{
  int movie,date;  //Declaring variables
  FILE *f;  //Declaring file pointer
  label:
  f = fopen(username,"a");  //opening the file in append mode

	printf("\n\t\t\t\t\t\t\t\t\tChoose the movie number :\n\t\t\t\t\t\t\t\t\t");
	scanf("%d",&movie);

	if ( language == 1 )  //language = 1 is for english movies
	{
    //choosing the movie numbers
		if (movie == 1)
		{
    			fputs("movie(1)=Casino,Royal",f);
    			fputs(" ",f);  //adding the movie name in file

			printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Casino Royal\n");
			printf("\t\t\t\t\t\t\t\t\tEnter 1 for 1st Dec and 2 for 3rd Dec\n");

			printf("\n\n\t\t\t\t\t\t\t\t\tEnter Date :\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&date);  //entering the date number

      //choosing movie date number and adding it to the file of the user
			if(date == 1)
			{
  				fputs("date(1)=1stDec",f);
  				fputs(" ",f);
			}
			else if(date == 2)
			{
  				fputs("date(2)=3rdDec",f);
  				fputs(" ",f);
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n\n");
				goto label;  //returns the person to the initial state of choosing movie number
			}
		}

		else if (movie == 2)
		{
			fputs("movie(2)=Hangover",f);
			fputs(" ",f);

			printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Hangover\n");
			printf("\t\t\t\t\t\t\t\t\tEnter 1 for 2nd Dec and 2 for 3rd Dec\n");


			printf("\t\t\t\t\t\t\t\t\tEnter date....\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&date);

			if(date == 1)
			{
				fputs("date(1)=2ndDec",f);
				fputs(" ",f);
			}
			else if(date == 2)
			{
				fputs("date(2)=3rdDec",f);
				fputs(" ",f);
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t**Invalid Digit");
				goto label;
			}
		}

		else if (movie == 3)
		{
  		fputs("movie(3)=Joker",f);
  		fputs(" ",f);

  		printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Joker\n");
  		printf("\t\t\t\t\t\t\t\t\tEnter 1 for 1st Dec and 2 for 2nd Dec\n");


  		printf("\t\t\t\t\t\t\t\t\tEnter date:\n\t\t\t\t\t\t\t\t\t");
  		scanf("%d",&date);

  		if(date == 1)
  		{
  				fputs("date(1)=1stDec",f);
  				fputs(" ",f);
  		}
  		else if(date == 2)
  		{
  				fputs("date(2)=2ndDec",f);
  				fputs(" ",f);
  		}
  		else
  		{
  			printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n\n");
  			goto label;
  		}
		}
    else
    {
      printf("\n\t\t\t\t\t\t\t\t\t**invalid choice...\n\n");
      goto label; //if a person enters wrong movie number then returns to initial state
    }
	}

  if ( language == 2 ) // language = 2 is for hindi movies
	{
		if (movie == 1)
		{
    	fputs("movie(1)=Housefull,4",f);
    	fputs(" ",f);

			printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Housefull 4\n");
			printf("\t\t\t\t\t\t\t\t\tEnter 1 for 1st Dec and 2 for 3rd Dec\n");


			printf("\t\t\t\t\t\t\t\t\tEnter Date :\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&date);

			if(date == 1)
			{
				fputs("date(1)=1stDec",f);
				fputs(" ",f);
			}
			else if(date == 2)
			{
				fputs("date(2)=3rdDec",f);
				fputs(" ",f);
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n\n");
				goto label;
			}
		}

		else if (movie == 2)
		{
			fputs("movie(2)=Andhadhun",f);
			fputs(" ",f);

			printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Andhadhun\n");
			printf("\t\t\t\t\t\t\t\t\tEnter 1 for 2nd Dec and 2 for 3rd Dec\n");


			printf("\t\t\t\t\t\t\t\t\tEnter date:\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&date);

			if(date == 1)
			{
				fputs("date(1)=2ndDec",f);
				fputs(" ",f);
			}
			else if(date == 2)
			{
				fputs("date(2)=3rdDec",f);
			fputs(" ",f);
			}

			else
			{
				printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n\n");
				goto label;
			}
		}

  	else if (movie == 3)
  	{
			fputs("movie(3)=Made,in,China",f);
			fputs(" ",f);

			printf("\n\n\t\t\t\t\t\t\t\t\tChoose date for Made in China\n");
			printf("\t\t\t\t\t\t\t\t\tEnter 1 for 1st Dec and 2 for 2nd Dec\n");

			printf("\t\t\t\t\t\t\t\t\tEnter date...\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&date);

			if(date == 1)
			{
				fputs("date(1)=1stDec",f);
				fputs(" ",f);
			}
			else if(date == 2)
			{
				fputs("date(2)=2ndDec",f);
				fputs(" ",f);
			}
			else
			{
				printf("\t\t\t\t\t\t\t\t\t**Invalid Digit\n\n");
				goto label;
			}
		}
    else
    {
      printf("\n\t\t\t\t\t\t\t\t\t**invalid choice...\n\n");
      goto label;
    }
	}
  fclose(f); //closes the file of the user
  confirm(username,language,movie,date);  //calling the confirm function
}
#endif
