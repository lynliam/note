#include<stdio.h>
#include<math.h>

int main ()
{
    int h=0,m=0;
    printf("Please input time\n");
    int ret=scanf("%dh%dm",&h,&m);
    while(ret!=2||h<0||h>12||m<0||m>60)
    {
        printf("invalid nums");
        ret=scanf("%dh%dm",&h,&m);
    }
    float temp=fabs(h*5*6+0.5*m-m*6);
    if(temp>180.0)
    temp=360.0-temp;
    printf("At %d:%02d the angle is %.1f degrees.",h,m,temp);
    return 0;
}