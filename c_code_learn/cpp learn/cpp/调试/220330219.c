#include<stdio.h>
#include<stdlib.h>

int main()
{
    char sex=0,sp,die;
    float fh,mh;

    printf("sex:");
        scanf("%c",&sex);
    printf("\nfaHeight:");
        scanf("%f",&fh);
    printf("\nmoHeight:");
        scanf("%f",&mh);
    printf("\nsports:");
        scanf(" %c",&sp);
    printf("\ndiet:");
        scanf(" %c",&die);
    if(sex=='F')
    {
        if(sp=='Y')
        {
            if(die=='Y')
            printf("height=%f",(fh*0.923+mh)/2*1.02*1.015);
            else
            printf("height=%f",(fh*0.923+mh)/2*1.02);
        }
        else
        {   
            if(die=='Y')
            printf("height=%f",(fh*0.923+mh)/2*1.015);
            else
            printf("height=%f",(fh*0.923+mh)/2);
        }
    }
    else
    {
          if(sp=='Y')
        {
            if(die=='Y')
            printf("height=%f",(fh+mh)*0.54*1.02*1.015);
            else
            printf("height=%f",(fh+mh)*0.54*1.02);
        }
        else
        {   
            if(die=='Y')
            printf("height=%f",(fh+mh)*0.54*1.015);
            else
            printf("height=%f",(fh+mh)*0.54);
        }      



    }
    system("pause");
    return 0;
}