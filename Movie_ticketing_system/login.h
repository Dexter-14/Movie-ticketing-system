#include"booking.h"
#include"cancel.h"
#include"history.h"
#include<stdio.h>
#ifndef _LOGIN_H_
#define _LOGIN_H_

int login()
{
  int temp,sum=0;
  char username[20],string[20];
  FILE *f;
  printf("\n\n\t\t\t\t\t\t\t\t\tPlease enter your username to login\n\t\t\t\t\t\t\t\t\t");
  scanf("%s",username);
  f = fopen("USERNAME.txt","r");//Reading from the username file
  for(int i=0 ; i<1200 ; i++)
  {
    fscanf(f,"%[^\n]%*c",string);//Reading the elements of the file username.
    if(strcmp(username,string)==0)//Comparing the username already stored with the entered one.
    {
      sum = 1;
      break;
    }
  }
  fclose(f);
  if(sum==1)
  {
    label:
    printf("\n\n\t\t\t\t\t\t\t\t\tWelcome %s here are the option to choose",username);
    printf("\n\t\t\t\t\t\t\t\t\t1. booking a ticket \n\t\t\t\t\t\t\t\t\t2. cancel ticket \n\t\t\t\t\t\t\t\t\t3. viewing history\n\t\t\t\t\t\t\t\t\t4. quit\n\t\t\t\t\t\t\t\t\t");
    scanf("%d",&temp);
    if(temp == 1)//Calling specific function as per instructed
      booking(username);
    else if(temp == 2)
      cancel(username);
    else if(temp == 3)
      history(username);
    else if( temp == 4)
      exit(0);
    else
    {
      printf("\n\t\t\t\t\t\t\t\t\t**invalid choice...\n\n");
      goto label;//On invalid input the process will be called again.
    }
  }
  else
  {
    printf("\n\t\t\t\t\t\t\t\t\t**invalid username pls signup...\n\n");
  }
  return 0;
}
#endif
