#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#define INT 1
#define FLT 2
#define N 20

typedef struct node
{
    int type;
    union  
    {
        int ival;
        double dval;
    }dat;
    //int ival;
}NodeType;

typedef struct stack
{
     NodeType data[N];
     int top;
}STACK;

 void Push ( STACK * stack , NodeType data ); 
 NodeType Pop ( STACK * stack );
 NodeType OpInt1( int dl , int d2, int op );
 NodeType OpInt4(double d1,double d2,int op);
 NodeType OpInt3(int d1,double d2,int op);
 NodeType OpInt2(double d1,int d2,int op);
 NodeType OpData ( NodeType *d1, NodeType *d2, int op );

 int main (void)
 {
    char word[N];
    NodeType d1,d2,d3;
    STACK stack ;
    stack.top =0;

    while (word[0]!='#')
    {
    int key=scanf("%s", word);
    int import=0;
    int flag=strlen(word);
    for(int i=0;i<flag;i++)
    {
        if(word[i]=='.')
            import=1;
    }
    if(key==1&&import==0)
    {
        if (isdigit(word[0]))
        {
            d1.dat.ival = atoi(word);
            //printf("%d\n",d1.dat.ival);
            d1.type=1;
            Push (&stack ,d1);
        }
        else if(word[0]=='#')
            break;
        else 
        {
            d2= Pop (&stack);
            d1 = Pop (&stack);
            d3= OpData(&d1,&d2,word[0]);
            //printf("%d\n",d3.dat.ival);
            Push (&stack ,d3);
        }

    }
    else
    {
        d1.dat.dval = atof(word);
        d1.type=2;
        //printf("------------------------------------------\n");
        //printf("------%f---------\n",d1.dat.dval);
        Push (&stack ,d1);
    }
    }

    d1 = Pop(&stack);
    if(d1.type==1)
    printf("%d\n ",d1.dat.ival);
    else
    printf("%f\n ",d1.dat.dval);
    system("pause");
    return 0;
}

void Push(STACK* stack ,NodeType data)
{
    memcpy(&stack->data[stack->top],&data,sizeof(NodeType));
    stack->top=stack->top+1;
}



NodeType Pop(STACK *stack )
{
    stack->top=stack->top-1;
    return stack->data[stack->top];
}



NodeType OpInt1(int d1,int d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
            res.type=1;
            res.dat.ival=d1+d2;
            break;
        case '-':
            res.dat.ival=d1-d2;
            res.type=1;
            break;
        case '*':
            res.dat.ival=d1*d2;
            res.type=1;
            break;
        case '/':
            res.dat.ival=d1/d2;
            res.type=1;
            break;

    }
    return res;
}
NodeType OpInt2(double d1,int d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
            res.dat.dval=d1+d2;
            res.type=2;
            break;
        case '-':
            res.dat.dval=d1-d2;
            res.type=2;
            break;
        case '*':
            res.dat.dval=d1*d2;
            res.type=2;
            break;
        case '/':
            res.dat.dval=d1/d2;
            res.type=2;
            break;

    }
    return res;
}
NodeType OpInt3(int d1,double d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
            res.dat.dval=d1+d2;
            res.type=2;
            break;
        case '-':
            res.dat.dval=d1-d2;
            res.type=2;
            break;
        case '*':
            res.dat.dval=d1*d2;
            res.type=2;
            break;
        case '/':
            res.dat.dval=d1/d2;
            res.type=2;
            break;

    }
    return res;
}
NodeType OpInt4(double d1,double d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
            res.dat.dval=d1+d2;
            res.type=2;
            break;
        case '-':
            res.dat.dval=d1-d2;
            res.type=2;
            break;
        case '*':
            res.dat.dval=d1*d2;
            res.type=2;
            break;
        case '/':
            res.dat.dval=d1/d2;
            res.type=2;
            break;

    }
    return res;
}


NodeType OpData(NodeType *d1,NodeType *d2,int op)
{
    NodeType res;
    if(d1->type==1&&d2->type==1)
    {
        res=OpInt1(d1->dat.ival,d2->dat.ival,op);
    }
    else if(d1->type==1&&d2->type==2)
    {
        res=OpInt3(d1->dat.ival,d2->dat.dval,op);
    }
    else if(d1->type==2&&d2->type==1)
    {
        res=OpInt2(d1->dat.dval,d2->dat.ival,op);
    }
    else if(d1->type==2&&d2->type==2)
    {
        res=OpInt4(d1->dat.dval,d2->dat.dval,op);
    }
    else;
    return res;
}