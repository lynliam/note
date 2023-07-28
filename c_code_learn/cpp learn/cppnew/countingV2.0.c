//记账系统V2.0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct UserInfo
{
    long userID;
    char UserName[11];
    int income;
    int outcome;
}User; 
/*---------------------------------------------------------*/
void Choosing(void);
void StartBar(void);
void InputRecord(int *,User *p);
void SoringInput(const int i,User *p);
void SearchUser(const int i,User *p);
int  CalAve(const int i,User *p);
void MaxAve(const int i,User *p);
void OutputInfo(const int i,User p[]);
void Write_Dowm(const int i,User *p);
void Read_Out(const int i);
/*---------------------------------------------------------*/
int i=0;
int hav=0;
User member[10];

int main()
{
    while (1)
    {
        StartBar();
        Choosing();
    }
    system("pause");
    return 0;
}

void Choosing(void)
{
    int key=0;
    scanf("%d",&key);
    switch (key)
    {
    case 0:
        exit(0);
        break;
    case 1:
        InputRecord(&i,member);
        break;
    case 2:
        SoringInput(i,member);
        break;
    case 3:
        SearchUser(i,member);
        break;
    case 4:
        CalAve(i,member);
        break;
    case 5:
        MaxAve(i,member);
        break;
    case 6:
        OutputInfo(i,member);
        break;
    case 7:
        Write_Dowm(i,member);
        break;
    case 8:
        Read_Out(i);
        break;
    default:
        printf("Wrong number!!\n");
        break;
    }
}

void StartBar(void)
{
    printf("\n----------------------start----------------------------\n");
    printf("1. Input record\n");
    printf("2. Sort and list records in reverse order by user name\n");
    printf("3. Search records by user name\n");
    printf("4. Calculate and list per capita income and expenses\n");
    printf("5. List records which have more expenses than per capita expenses\n");
    printf("6. List all records\n");
    printf("7. Write to a file\n");
    printf("8. Read from file\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
}

void InputRecord(int *i,User *p)
{
    printf("\n\n----------------------start----------------------------\n");
    if(*i>9)
    {
        printf("members are full!!!");
        printf("\n\n----------------------end----------------------------\n");
        return;
    }
    for(;*i<10;(*i)++)
    {
        hav=1;
        int controlkey=0;
        printf("\nPlease enter your ID USERNAME INCOME OUTCOME\n");
        scanf("%d %s %d %d",&p[*i].userID,p[*i].UserName,&p[*i].income,&p[*i].outcome);
        printf("\nComplete!Input \"-1\" to go back; \"1\" to continue\n");
        scanf("%d",&controlkey);
        if(controlkey==-1)
        {
            printf("\n\n----------------------end----------------------------\n");
            return;
        }
        else 
            continue;

    }
    
}

int SortingFunction(char a[],char b[])
{
    for(int i=0;;i++)
    {
        if(a[i]=='\0')
        {
            return 0;
        }
        if(b[i]=='\0')
        {
            return 1;
        }
    
    if(strcmp(&a[i],&b[i])>0)
        return 1;
    if(strcmp(&a[i],&b[i])<0)
        return 0;

    }
    
}

void SoringInput(const int i,User *p)
{
    printf("\n\n----------------------start----------------------------\n");
    if(hav==0)
    {
        printf("Please enter at least one member!\n");
        printf("\n\n----------------------end----------------------------\n");
        return;
    }
    User *pointp[10];
    for(int j=0;j<10;j++)
    {
        pointp[j]=&p[j];
    }


    for(int val=1;val<=i;val++)
    {
        User *valkey=pointp[val];
        int vall=val-1;
        
        while(vall>=0&&(SortingFunction(pointp[vall]->UserName,valkey->UserName)))
        {
            pointp[vall+1]=pointp[vall];
            vall=vall-1;
        }
        pointp[vall+1]=valkey;
    }





    printf("UserID\tUserName\tincome\toutcome\n");
    for(int j=0;j<=i;j++)
    {
        printf("%d\t%s\t%d\t%d\n",pointp[j]->userID,pointp[j]->UserName,pointp[j]->income,pointp[j]->outcome);
    }
    return;
}

void SearchUser(const int i,User *p)
{
    printf("\n\n----------------------start----------------------------\n");
    if(hav==0)
    {
        printf("Please enter at least one member!\n");
        printf("\n\n----------------------end----------------------------\n");
        return;
    }
    char tempName[10];
    printf("\nPlease enter one name:");
    scanf("%s",tempName);
    for(int j=0;j<=i;j++)
    {
        if(strcmp(p[j].UserName,tempName)==0)
        {
            printf("UserID\tUserName\tincome\toutcome\n");
            printf("%d\t%s\t%d\t%d\t",&p[j].userID,p[j].UserName,&p[j].income,&p[j].outcome);
            printf("\n\n----------------------end----------------------------\n");
            return;
        }
    }
    printf("Not Found!\n");
}

int  CalAve(const int i,User *p)
{
    printf("\n\n----------------------start----------------------------\n");
    if(hav==0)
    {
        printf("Please enter at least one member!\n");
        printf("\n\n----------------------end----------------------------\n");
        return 0;
    }
    int incomeSum=0;
    int outcomeSum=0;
    for(int j=0;j<=i;j++)
    {
        incomeSum+=p[j].income;
        outcomeSum+=p[j].outcome;
    }
    printf("IncomeAve:%d,OutcomeAve:%d\n",incomeSum/(i+1),outcomeSum/(i+1));
    return outcomeSum/(i+1);
}

void MaxAve(const int i,User *p)
{
    printf("\n\n----------------------start----------------------------\n");
    if(hav==0)
    {
        printf("Please enter at least one member!\n");
        printf("\n\n----------------------end----------------------------\n");
        return;
    }
    int aveMaax=CalAve(i,p);
    printf("UserID\tUserName\tincome\toutcome\n");
    for(int j=0;j<=i;j++)
    {
        if(p[j].outcome>aveMaax)
        {
            printf("%d\t%s\t%d\t%d\n",p[j].userID,p[j].UserName,p[j].income,p[j].outcome);
        }
    }
    printf("\n\n----------------------end----------------------------\n");
    return;

}

void OutputInfo(const int i,User p[])
{
    printf("\n\n----------------------start----------------------------\n");
    if(hav==0)
    {
        printf("Please enter at least one member!\n");
        printf("\n\n----------------------end----------------------------\n");
        return;
    }
    printf("UserID\tUserName\tincome\toutcome\n");
    for(int j=0;j<=i;j++)
    {
        printf("%d\t%s\t%d\t%d\n",p[j].userID,p[j].UserName,p[j].income,p[j].outcome);
    }
    return;
}

void Write_Dowm(const int i,User *p)
{
    FILE *fp;
    if((fp=fopen("E:\\score.txt","w"))==NULL)
    {
        printf("Can't Open File!");
        exit(0);
    }
    for(int j=0;j<=i;j++)
    {
        fprintf(fp,"%d\t%s\t%d\t%d\n",p[j].userID,p[j].UserName,p[j].income,p[j].outcome);
        //printf("%d\t%s\t%d\t%d\n",p[j].userID,p[j].UserName,p[j].income,p[j].outcome);
    }
    printf("Success!");
    fclose(fp);
}

void Read_Out(const int i)
{
    FILE *fp;
    User tempMem[10];
    if((fp=fopen("E:\\score.txt","r"))==NULL)
    {
        printf("Can't Open File!");
        exit(0);
    }
    for(int j=0;j<=i;j++)
    {
        fscanf(fp,"%d\t%s\t%d\t%d\n",&tempMem[j].userID,tempMem[j].UserName,&tempMem[j].income,&tempMem[j].outcome);
        printf("%d\t%s\t%d\t%d\n",tempMem[j].userID,tempMem[j].UserName,tempMem[j].income,tempMem[j].outcome);
    }
    printf("Success!");
    fclose(fp);
}