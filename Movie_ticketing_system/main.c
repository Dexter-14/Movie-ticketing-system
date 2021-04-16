#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"login.h"
#include"create_username.h"
void main()
{
	label:
	printf("\t\t\t\t\t\t\t\t\t*******WELCOME TO PVR CINEMA********\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t1: Enter Username\n");
	printf("\t\t\t\t\t\t\t\t\t2: New user? Sign up now \n");
	printf("\t\t\t\t\t\t\t\t\tPress 0 to quit the program\n");
	printf("\t\t\t\t\t\t\t\t\tEnter option number \n\t\t\t\t\t\t\t\t\t");

	int i;
	scanf("%d",&i );

	if ( i == 1 )
	{
		login();
		goto label;
	}

	else if ( i == 2 )
	{
		create_username();
	}

	else if ( i == 0 )
	{
		exit(0);
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\t**invalid digit\n\n");
		goto label;
	}

}
