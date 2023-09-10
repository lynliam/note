#include<stdio.h>
#include"game.h"




void InsetRow(char row[ROWS][COLOMNS],int rows,int cols,char set)
{
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            row[i][j]=set;


        }
    }
}
void InsetCol(char column[ROWS][COLOMNS],int rows,int cols,char set)
{
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            column[i][j]=set;
        }
    }
}

void Display(char column[ROWS][COLOMNS],int rows,int cols)
{
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            printf(" %c",column[i][j]);
        }
    }


    return;
}