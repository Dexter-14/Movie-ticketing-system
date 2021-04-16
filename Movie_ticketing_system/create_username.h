#include"login.h"
#include<stdio.h>
#include<string.h>
#ifndef _CREATE_USERNAME_H_
#define _CREATE_USERNAME_H_

void create_username()
{
  FILE *f;
  char username[20],temp[20];
repeat:
  printf("\t\t\t\t\t\t\t\t\tEnter your username without spaces\n\t\t\t\t\t\t\t\t\t");
  scanf("%s",username);
  f = fopen("USERNAME.txt","r");//Reading from usernam file
  for(int i=0 ; i<1200 ; i++)
  {
    fscanf(f,"%[^\n]%*c",temp);//Reading the elements of the file username.
    if(strcmp(username,temp)==0)//Comparing the username already stored with the entered one.
    {
      printf("\t\t\t\t\t\t\t\t\t**Enter another username as this username is already taken...\n\n");
      goto repeat;
    }
  }
  //If the username is valid
  fclose(f);
  f = fopen("USERNAME.txt" , "a");
  fputs(username,f);
  fputs("\n",f);//Storing the new username in the file
  fclose(f);
  f = fopen(username,"w");//Making new file for every new user
  printf("\n\t\t\t\t\t\t\t\t\tCongratulations your username has been saved!\n\t\t\t\t\t\t\t\t\tNow all your bookings will be saved under this username\n\n");
  fclose(f);
  login();//Calling the login function.
}
#endif
