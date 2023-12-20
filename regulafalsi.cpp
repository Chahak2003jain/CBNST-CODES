#include <stdio.h>
#include <math.h>

// float func(float x)
// {
//     return (3 * x + sin(x) - exp(x));
// }
float func(float x)
{
    return(x*log10(x) - 1.2);
}

int main()
{
    int count = 0, flag = 0;

    float x, x0, x1, err,val;

    printf("Enter the allowed error\n");
    scanf("%f", &err);

    do
    {
        printf("Enter the values of x0 and x1\n");
        scanf("%f %f", &x0, &x1);

        if (func(x0) * func(x1) < 0)
        {
            printf("Root lies between %f and %f\n", x0, x1);
            flag = 1;
        }
        else
            printf("Wrong intervals\n");
    } while (flag != 1);

    printf("Iteration\t\tx0\t\tx1\t\tx\t\tf(x)\n");
    do
    {
        count++;
        x = x0 - ((x1 - x0) / (func(x1) - func(x0))) * func(x0);

        printf("%d\t%f\t%f\t%f\t%f\n", count, x0, x1, x, func(x));
         if (func(x0) * func(x) < 0)
            x1 = x;
        else
            x0 = x;
            
        val = x0 - ((x1 - x0) / (func(x1) - func(x0))) * func(x0);
    }while(fabs(func(x)-func(val))>err);

    printf("The root of equation is:%f after %d iterations", x, count);
    return 0;
}
