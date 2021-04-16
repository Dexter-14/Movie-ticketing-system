#include"show.h"
#include"choose.h"
#include<stdio.h>
#ifndef _BOOKING_H_
#define _BOOKING_H_
void booking(char *username)
{
	int language;
	label:
	printf("\n\t\t\t\t\t\t\t\t\tChoose Language : English(1) or Hindi(2)");  //choosing the language
	printf("\n\t\t\t\t\t\t\t\t\t");
	scanf("%dChoose Language's Digit (1 or 2) :",&language);
	if(language!=1 && language!=2)
	{
		printf("\n\t\t\t\t\t\t\t\t\t**invalid choice...\n\n");      //invalid optio choosen
		goto label;
	}
	printf("\n");

	show(username, language);         //calling show function
	choose(username, language);       //calling choose function
}
#endif
