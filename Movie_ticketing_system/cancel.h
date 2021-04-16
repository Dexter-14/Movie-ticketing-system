#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#ifndef _CANCEL_H_
#define _CANCEL_H_

void cancel(char *username)
{
  int n,row,column,language,movie,date,count=0;
  char ch,extra[20],input[50];
  FILE *f,*g; //declaring file pointers
  label:
  g = fopen(username,"r+"); //opening the file
  fseek(g,0,SEEK_END);
  int size = ftell(g); // checkig if the file is empty or not
  if(size == 0)
  {
    printf("\n\t\t\t\t\t\t\t\t\t**No bookings**");
    exit(0);
  }
  fseek(g,0,SEEK_SET);
  printf("\n\t\t\t\t\t\t\t\t\tPlease refer the ticket for the following\n\t\t\t\t\t\t\t\t\t");
  printf("\n\t\t\t\t\t\t\t\t\tPlease enter the language of the movie: English(1) or Hindi(2)\n\t\t\t\t\t\t\t\t\t");
  scanf("%d",&language);
  printf("\n\t\t\t\t\t\t\t\t\tPlease enter the movie number\n\t\t\t\t\t\t\t\t\t");
  scanf("%d",&movie);
  printf("\n\t\t\t\t\t\t\t\t\tPlease enter the date(1 or 2) of the movie\n\t\t\t\t\t\t\t\t\t");
  scanf("%d",&date);
  if(language>2 || movie >3 || date>2)
  {
    printf("\n\t\t\t\t\t\t\t\t\t**Invalid choice**");
    goto label;
  }
  // if not then checking the values provided by the user to find the specific booking
  while(fgets(input,50,g)!=NULL)
  {
    if((int)input[9]-48 == language)
    {
      if(language==1)
      {
        if((int)input[26]-48 == movie)
        {
          count++;
          break;
        }
      }
      else
      {
        if((int)input[24]-48 == movie)
        {
          count++;
          break;
        }
      }
    }
  }
  printf("\n\t\t\t\t\t\t\t\t\tDo you want to cancel your latest bookings ?\n");
  printf("\t\t\t\t\t\t\t\t\tPress 1 to cancel\n");
  printf("\t\t\t\t\t\t\t\t\tPress 0 to exit\n\t\t\t\t\t\t\t\t\t");
  int a;
  scanf("%d",&a);
  if (a == 1)
  {
    if(count>0)
    {
      fseek(g,-30,SEEK_CUR);
      fputs(" ****THIS TICKET IS CANCELED**** ",g); //cancelling the ticket if bookig is found
    }
    else
    {
      printf("\n\t\t\t\t\t\t\t\t\t**Booking not found**");
      goto label; //repeating the process if booking is not found
    }
    if(language==1)
    {
      if(movie == 1 && date == 1) //opening the specific file to change the status of the seats to empty
        f = fopen("seat1.txt","r+");
      else if(movie == 1 && date == 2)
        f = fopen("seat2.txt","r+");
      else if(movie == 2 && date == 1)
        f = fopen("seat3.txt","r+");
      else if(movie == 2 && date == 2)
        f = fopen("seat4.txt","r+");
      else if(movie == 3 && date == 1)
        f = fopen("seat5.txt","r+");
      else if(movie == 3 && date == 2)
        f = fopen("seat6.txt","r+");
    }
    else
    {
      if(movie == 1 && date == 1)
        f = fopen("seat7.txt","r+");
      else if(movie == 1 && date == 2)
        f = fopen("seat8.txt","r+");
      else if(movie == 2 && date == 1)
        f = fopen("seat9.txt","r+");
      else if(movie == 2 && date == 2)
        f = fopen("seat10.txt","r+");
      else if(movie == 3 && date == 1)
        f = fopen("seat11.txt","r+");
      else if(movie == 3 && date == 2)
        f = fopen("seat12.txt","r+");
    }
    //asking from the user the number of tickets to be cancelled
    printf("\n\t\t\t\t\t\t\t\t\tPlease enter the number of tickets you want to cancel\n\t\t\t\t\t\t\t\t\t");
    scanf("%d",&n);
    for(int i=1 ; i<n+1 ; i++)
    {
      repeat:
      fseek(f,0,SEEK_SET);
      printf("\n\t\t\t\t\t\t\t\t\tPlease enter the row of ticket number %d\n\t\t\t\t\t\t\t\t\t",i);
      scanf("%d",&row);
      printf("\t\t\t\t\t\t\t\t\tPlease enter the column of ticket number %d\n\t\t\t\t\t\t\t\t\t",i);
      scanf("%d",&column);
      for(int i=0 ; i<row ; i++)
      {
        fscanf(f,"%[^\n]%*c",extra); //going the column provided by the user
      }
      for(int i=0 ; i<2*column+1 ;i++)
      {
        ch = fgetc(f); //taking the pointer to the column provided by the user
      }
      if(ch == 'X')
      {
        fseek(f, -1, SEEK_CUR);
        fputc('0',f); //changing the status of the seat if found
        fseek(f, 0, SEEK_CUR);
      }
      else
      {
        printf("\n\t\t\t\t\t\t\t\t\t**Wrong Seat**\t\t\t\t\t\t\t\t\t\n"); //giving error if seat is already empty
        goto repeat;
      }
      printf("\n\n\t\t\t\t\t\t\t\t\tTICKET CANCELED!!\n\n"); //printing the meassage
    }
    fclose(f);
  }
  else if(a==0)
  {
    exit(0); //quiting the programe
  }
  else
  {
      printf("\t\t\t\t\t\t\t\t\t**Invalid Input**");
      goto repeat;
  }
  fclose(g);
}
#endif
