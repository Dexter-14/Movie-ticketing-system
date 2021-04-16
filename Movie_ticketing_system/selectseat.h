
#include<stdio.h>
#ifndef _SELECTSEAT_H_
#define _SELECTSEAT_H_
int selectseat(int n,int i,int language,int movie,int date,char* username)
{
  if(n>0)
  {
    int row,column;
    char ch,s[20];
    FILE *f,*g; //declaring file pointer
    char temp[20],extra[20];
    g = fopen(username,"a");
    printf("\n\t\t\t\t\t\t\t\t\t**0 means available and X means not available"); //providing instructions for the user
    printf("\n\t\t\t\t\t\t\t\t\trow-> and column ||\n");

    if(language==1) //opening the specific seat matrix file for each show
    {
      if(movie == 1 && date == 1)
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

    label:
    fseek(f,0,SEEK_SET);
    // asking the user to select the row and column of the seat
    if(i==1)
      printf("\n\t\t\t\t\t\t\t\t\tpls select seat for %dst person\n\n",i);
    else if(i==2)
      printf("\n\t\t\t\t\t\t\t\t\tpls select seat for %dnd person\n\n",i);
    else if(i==3)
      printf("\n\t\t\t\t\t\t\t\t\tpls select seat for %drd person\n\n",i);
    else if(i==4)
      printf("\n\t\t\t\t\t\t\t\t\tpls select seat for %drth person\n\n",i);
    else
      printf("\n\t\t\t\t\t\t\t\t\tpls select seat for %dth person\n\n",i);
    while(fgets(temp,20,f)!=NULL)
    {
      printf("\t\t\t\t\t\t\t\t\t%s",temp);
    }
    printf("\n\t\t\t\t\t\t\t\t\tpls select the row...");
    scanf("%d",&row);
    sprintf(s,"%d",row);
    printf("\n\t\t\t\t\t\t\t\t\tpls select the column...");
    scanf("%d",&column);
    if(row>5 || column>5)
    {
      printf("\n\t\t\t\t\t\t\t\t\t**invalid choice...\n\n");
      goto label;
    }
    fseek(f,0,SEEK_SET);
    for(int i=0 ; i<row ; i++)
    {
      fscanf(f,"%[^\n]%*c",extra); //taking the file pointer to that row
    }
    for(int i=0 ; i<2*column+1 ;i++)
    {
      ch = fgetc(f); //takinf the pointer to that column
    }
    if(ch == '0')
    {
      fseek(f, -1, SEEK_CUR);
      fputc('X',f); //changing the status of the seat
      fseek(f, 0, SEEK_CUR);
    }
    else
    {
      printf("\n\t\t\t\t\t\t\t\t\t**this seat is not available pls choose another...\n\n");
      goto label;
    }
    fputs("seat(R,C)=",g);
    fputs(s,g);
    fputs(",",g);
    sprintf(s,"%d",column);
    fputs(s,g);
    fputs(" ",g);
    fclose(f);
    selectseat(n-=1,i+=1,language,movie,date,username);
  }
  return 0;
}
#endif
