#include <stdio.h>
#include "area_within_interval.h"

/* all of the *summation_f should take j as (1/n) so the function decomposing
 * should ended as a function of j that take the j as 1/n
*/
double quadraticPartition_f(double x)
{
    return x * x;
};

void quadraticSummation_f(double *x, double j)
{
    *x = ( ( 1.0 + j )*( 2.0 + j ) ) / 6.0;
};

int main()
{
    int n;
    double left, right;
    const int STEP = 1000;
    const int MAX_N = 5000;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &quadraticPartition_f;
    mainFunctions.summation = &quadraticSummation_f;

    area_under_curve_t mainOutputs;
    mainOutputs.partition = 0.0;
    mainOutputs.summation = 0.0;

    left = 0.0;
    right = 1.0;

    for (n = 1; n < MAX_N + STEP; n+=STEP)
    {
        areaWithinInterval(&mainFunctions, &mainOutputs, left, right, n);
        printf("k:%d | partition = %lf | summation = %lf\n",
               n, mainOutputs.partition, mainOutputs.summation);
    }
    return 0;
}
