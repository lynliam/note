#include <stdio.h>
#include<stdlib.h>

void ReadScore(int a[][3], char num[][10], int n)
{
    int i, j;
    printf("Input student’s ID and score as: MT  EN  PH:\n");
    for (i = 0; i<n; i++)
    {
        scanf("%s", &num[i][10]);         
        for (j = 0; j < 3; j++) 
        {
            scanf("%d", &a[i][j]); 
        }
    }
}

int main()
{
    int n,a[40][3],sumstu[40],sumcour[3],i,j,sum;
    float averstu[40],avercour[3];
    char num[40][10];

    printf("Input the total number of the students(n<40):\n" );
    scanf("%d",&n);
    ReadScore(a,num,n);


    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            sum=0;
            sum+=a[i][j];
        }
        sumstu[i]=sum;
        averstu[i]=(float)sum/j;
        sum=0;
    }//算每个学生总分和平均分


    i=0,j=0;
    for(;j<n;j++){
        for(;i<3;i++){
            sum+=a[i][j];
        }
        sumcour[j]=sum;
        avercour[j]=(float)sum/i;
        sum=0;
    }//算每个课总分和平均分
    printf("Counting Result:\n");
    printf("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    
/*
    for(i=0;num[i][40]!='\0';i++){
        printf("%12s\t",num[i][40]);
        for(j=0;j<3;j++){
            printf("%4d\t",a[i][j]);
        }
        printf("%4d\t%5.1f\n",sumstu[i],averstu[i]);
    }
*/
    char (*p)[10]=num;
    for(i=0;i<n;i++){
        printf("%12s\t",*(p+i));
        for(j=0;j<3;j++){
            printf("%4d\t",a[i][j]);
        }
        printf("%4d\t%5.1f\n",sumstu[i],averstu[i]);
    }

    printf("SumofCourse \t");

    for(j=0;j<3;j++){
        printf("%4d\t",sumcour[j]);
    }
    printf("\nAverofCourse\t");

    for(j=0;j<3;j++){
        printf("%4.1f\t");
    }
    system("pause");
    return 0;
}



