#include<stdio.h>
#ifndef _HISTORY_H_
#define _HISTORY_H_

void history(char *username)
{
	int num,size;
	printf("\t\t\t\t\t\t\t\t\tHISTORY\n\n");
	char input[50];
	FILE *f;
	f = fopen(username,"r");       //opening the file in read mode
	fseek(f,0,SEEK_END);         //checking whether the file is empty or not
	size = ftell(f);
	if(size == 0)
		printf("\t\t\t\t\t\t\t\t\t**no bookings found....");
	else
	{
		fseek(f,0,SEEK_SET);
		while(fgets(input,50,f)!=NULL)    //loop to print the input given
		{
			printf("%s",input);
		}
		fclose(f);   //closing the file
	}
	printf("\n\n");
}
#endif
