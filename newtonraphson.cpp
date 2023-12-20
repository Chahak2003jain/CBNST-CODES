#include<stdio.h>
#include<math.h>

float func(float x)
{
    return (3*x-cos(x)-1);
}

float dfunc(float x)
{
    return (3+sin(x));
}

int main()
{
    int count = 0,flag = 0;
    float x0,x1,x,err,val,temp;

    printf("Enter allowed error");
    scanf("%f",&err);

    do
    {
        printf("Enter x0 and x1\n");
        scanf("%f %f",&x0,&x1);

        if(func(x0)*func(x1)<0)
        {
            flag = 1;
            printf("root lies between %f and %f\n",x0,x1);
        }
    }while(flag!=1);

    x= (x0+x1)/2;
    printf("Iteration\t\tx\t\tval\t\tf(x)\n");

    do
    {
        count++;
        val = x - (func(x)/dfunc(x));

        if(dfunc(x) == 0)
        {
            printf("error\n");
            break;
        }

        printf("%d\t%f\t%f\t%f\n",count,x,val,func(val));

        x = val;
        temp = x - (func(x)/dfunc(x));
    }while(fabs(func(temp)-func(val))>err);

    printf("Root is %f after %d iterations\n",val,count);
}