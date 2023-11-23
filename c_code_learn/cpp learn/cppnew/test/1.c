// code here
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct STUDENTMBER
{
    char a[10];
    int MT;
    int EN;
    int PH;
    int SUM;
    float AVER;
    struct STUDENTMBER *next;
}StudentMbr;

StudentMbr* InputArry(StudentMbr *p,int a);
void start();
void Sum(StudentMbr *p,int n,int *mts,int *ens,int *phs);


int main()
{
    start();
    int a=0;
    scanf("%d",&a);
    StudentMbr stu;
    StudentMbr *header=InputArry(&stu,a);
    int summt=0;
    int sumen=0;
    int sumph=0;
    Sum(header,a,&summt,&sumen,&sumph);
    float avemt=(float)summt/a;
    float aveen=(float)sumen/a;
    float aveph=(float)sumph/a;
    
    printf("Counting Result:\n");
    printf("Student’s ID\tMT\tEN\tPH\tSUM\tAVER\n");
    StudentMbr *current=header;
    for(int i=1;i<=a;i++)
    {
        if(i=1)
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",current->a,current->MT,current->EN,current->PH,current->SUM,current->AVER);
        else
        printf("0%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",current->a,current->MT,current->EN,current->PH,current->SUM,current->AVER);
        current=current->next;
    }
    printf("SumofCourse \t%4d\t%4d\t%4d\t\n",summt,sumen,sumph);
    printf("AverofCourse\t%4.1f\t%4.1f\t%4.1f\t\n",avemt,aveen,aveph);
    system("pause");
    return 0;
}

StudentMbr* InputArry(StudentMbr *p,int a)
    {
        StudentMbr *header=p;
        StudentMbr *current=p;
        for(int i=1;i<=a;i++)
        {
            char sry[10];
            scanf("%s %d %d %d",&current->a,&current->MT,&current->EN,&current->PH);
            //strcpy(p->a,sry[10]);
            
            getchar();
            /*
            scanf("%d",p->MT);
            getchar();
            scanf("%d",p->EN);
            getchar();
            scanf("%d",p->PH);
            */
            current->SUM=current->MT+current->EN+current->PH;
            current->AVER=((float)current->SUM)/3.0;
            getchar();
                StudentMbr *temp=(StudentMbr *)malloc(sizeof(StudentMbr));
                current->next=temp;
                current=temp;
                if(i==a)
                     current->next=NULL;
        }
        return header;
    }

void start()
{
    printf("Input the total number of the students(n<40):\nInput student’s ID and score as: MT  EN  PH:\n");
}

void Sum(StudentMbr *p,int n,int *mts,int *ens,int *phs)
{
    int mtsum=0;
    int ensum=0;
    int phsum=0;
    for(int i=1;i<=n;i++)
    {
        mtsum+=p->MT;
        ensum+=p->EN;
        phsum+=p->PH;
        p=p->next;
    }
    *mts=mtsum;
    *ens=ensum;
    *phs=phsum;
}