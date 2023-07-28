#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nums=0;
    int *p=0;
    scanf("%d",&nums);
    p=(int *)malloc(nums*sizeof(int));
    int key=1;
    while(key<=nums)
    {
        scanf("%d",p+key-1);
        getchar();
        key++;
    }
    

    int sum=0;

    //Mean
    for(int i=0;i<nums;i++)
    {
        sum+=*(p+i);
    }
    printf("Mean=%d\n",sum/nums);

    //Median
    if(nums%2==1)
    {
        printf("Median=%d\n",*(p+(nums+1)/2));
    }
    else{
        printf("Median=%d\n",  (*(p+(nums+1)/2)+*(p+(nums+1)/2+1))/2  );
    }
    
    //Mode
    

    for(int j=1;j<nums;j++)
    {
        int i=j-1;
        int key=p[j];
        while(i>=0&&p[i]>key)
        {
            p[i+1]=p[i];
            i=i-1;
            p[i+1]=key;
        }
    }
    int Mcount=0,Mval=0;
    for(int i=1;i<nums;i++)
    {
        int val=0,count=0;
        val=*(p+i);
        while(*(p+i-1)==val)
        {
            count++;
            i++;
        }
        if(count>Mcount)
        {
            Mcount=count;
            Mval=val;
        }
    }
    printf("Mode=%d\n",Mval);


    return 0;
}