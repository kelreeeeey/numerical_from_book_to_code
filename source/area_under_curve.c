#include <stdio.h>

typedef struct { double partition, summation; } area_under_curve_t ;

typedef double (*partition_f)(double);
double quadraticPartition_f(double x) { return x * x; };

typedef void (*summation_f)(double*, double);
void quadraticSummation_f(double *x, double j) { *x = ( ( 1.0 + j )*( 2.0 + j ) ) / 6.0; };

typedef struct { partition_f partition; summation_f summation; } func_area_under_curve_t ;
void areaWithinInterval(func_area_under_curve_t *func, 
                        area_under_curve_t *areas,
                        double left, double right, int interval)
{
    double div = 1.0 / (double) interval;
    double range = (right-left);
    double sub_interval = range * div;
    double temp;
    double i;
    for (i = left; i <= right; i += sub_interval)
    {
        temp += ( func->partition(i) * div );
    }
    areas->partition = temp;
    func->summation(&areas->summation, div);
};

int main()
{
    int n;
    double left, right;
    const int STEP = 1;
    const int MAX_N = 5000;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &quadraticPartition_f;
    mainFunctions.summation = &quadraticSummation_f;

    area_under_curve_t mainOutputs;
    mainOutputs.partition = 0.0;
    mainOutputs.summation = 0.0;

    double errSartition, errSummation;
    left = 0.0;
    right = 1.0;
    
    for (n = 1; n < MAX_N + STEP; n+=STEP)
    {
        areaWithinInterval(&mainFunctions, &mainOutputs, left, right, n);
        printf("\nk:%d | partition = %lf | summation = %lf",
               n, mainOutputs.partition, mainOutputs.summation);
    }
    return 0;
}
