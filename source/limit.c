#include <stdio.h>
#include <math.h>

long double limitOf ( double x )
{
    return sqrt( (x * x) + x - 1.0 ) - x;
}

int main()
{
    double i, j, k, l, LIM = 0.001;
    double y = 0.0;

    for (i = 0.70; i >= 0.600; i -= LIM)
    {
        y = limitOf(i);
        printf("y = %f for x = %f\n", y, i);
    }

    printf("==================================\n");

    for (j = -1.600; j > -1.70; j -= LIM)
    {
        y = limitOf(j);
        printf("y = %f for x = %f\n", y, j);
    }

    printf("==================================\n");

    for (k = 1000.600; k < 100000.70; k += 1000.0)
    {
        y = limitOf(k);
        printf("y = %f for x = %f\n", y, k);
    }

    printf("==================================\n");

    for (l = -500.600; l > -10000.70; l -= 100.0)
    {
        y = limitOf(l);
        printf("y = %f for x = %f\n", y, l);
    }
    return 0;
}
