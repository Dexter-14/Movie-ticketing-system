#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cancel.h"
#include"selectseat.h"
#ifndef _CONFIRM_H_
#define _CONFIRM_H_
void confirm(char *username,int language,int movie,int date) //Declaring the function
{
	FILE *f;
	f = fopen(username,"a"); //Opening the file in append mode
	printf("\n\t\t\t\t\t\t\t\t\tEnter the number of tickets:\n\t\t\t\t\t\t\t\t\t");
	int n;
	char s[20];
	scanf("%d",&n);
	sprintf(s,"%d",n);
	fputs("numberofseats=",f);
	fputs(s,f);
	fputs(" ",f);
	fputs("price=",f);
	int Total=150*n; //Calculating the total cost
	char temp[20];
	sprintf(temp,"%d",Total);
	fputs(temp,f);
	fputs(" ",f);
	selectseat(n,1,language,movie,date,username); //Calling the selectseat function to select desired seats
	printf("\n\t\t\t\t\t\t\t\t\tTotal amount = Rs. %d", Total);
	printf("\n\t\t\t\t\t\t\t\t\tTo confirm your booking press 1 to exit press 0\n\t\t\t\t\t\t\t\t\t");
	int m;
	scanf("%d",&m);
	if ( m == 1 )
	{
		fputs("\n\n",f);
		printf("\n\t\t\t\t\t\t\t\t\tYour ticket has been confirmed! \n\t\t\t\t\t\t\t\t\t**Kindly show the ticket at the counter and make the payment");
		exit(0);
		//confirmig the ticket and quitting the program
	}
	else
	{
		exit(0);
		printf("\n\t\t\t\t\t\t\t\t\tpls cancel your seat you booked");
		cancel(username);  //cancelling the booked tickets
	}
	printf("\n");
	fclose(f);
}
#endif
