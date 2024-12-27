#include <stdio.h>
#include "area_within_interval.h"

/*
 * Definiton of `areaWithinInterval`
 */
void areaWithinInterval(func_area_under_curve_t *func, area_under_curve_t *areas,
                        double left, double right, int interval)
{
    double div = 1.0 / (double) interval;
    double sub_interval = (right-left) * div;
    double temp = 0.0;
    double i;
    for (i = left; i <= right; i += sub_interval)
    {
        double temp_2 = func->partition(i) * div;
        temp += temp_2;
    }
    areas->partition = temp;
    func->summation(&areas->summation, div); // div is supposed to be 1/n 
};


/* all of the *summation_f should take j as (1/n) so the function decomposing 
 * should ended as a function of j that take the j as 1/n
*/
double quadraticPartition_f(double x) { return x * x; };
void quadraticSummation_f(double *x, double j) { *x = ( ( 1.0 + j )*( 2.0 + j ) ) / 6.0; };

double A13Partition_f(double x) { return ( (4.0 * x) + 1 ); };
void A13Summation_f(double *x, double j) { *x = ( 2.0 * j ) + 3.0; };

double A14Partition_f(double x) { return 3.0 - (2.0 * x); };
void A14Summation_f(double *x, double j) { *x =  2.0 - j; };

double A15Partition_f(double x) { return x * x; };
void A15Summation_f(double *x, double j)
{
    *x = 
        1.0 
        + (1.0 + j)
        + (
            (( 1.0 + j )*(2.0 + j)) / 6.0
        );
};


double A18Partition_f(double x) { return 1.0 / (x * x); };
void A18Summation_f(double *x, double j) { 
    double temp=0.0, i;
    for (i = 1; i < 2; i+=j)
    {
        double a = 1 / (i*i);
        temp += j * a;
    }
    *x = temp;
};

double A22Partition_f(double x) { return ( 4 * x * x * x ) + ( 2 * x); };
void A22Summation_f(double *x, double j) { 
    double temp = 4.0 * (1.0 + j);
    *x = ( temp + ( temp * temp ) );
};
void A23Summation_f(double *x, double j) { 
    double temp = 1.0 + j;
    *x =  2.0 * ( ( temp * temp ) + ( 4.0 * temp ) + 3.0 ) ;
};

double A24Partition_f(double x) { return ( 6 * x * x ) + ( 2 * x ) + 4; };
void A24Summation_f(double *x, double j) { 
    double temp = (1.0 + j);
    *x = 3.0 * ( ( 9.0 * temp * temp ) + ( 10.0 * temp ) + 4.0 );
};

double A25Partition_f(double x) { return ( 6 * x * x ) + ( 2 * x ) + 4; };
void A25Summation_f(double *x, double j) { 
    double temp = (1.0 + j);
    *x = ( ( 8.0 * temp * temp ) + ( 36.0 * temp ) + 22.0 );
};

double A26Partition_f(double x) { return ( 3 * x * x ) + ( 2 * x ) + 1; };
void A26Summation_f(double *x, double j) { 
    double temp = (1.0 + j);
    *x = ( ( 0.5 * temp * temp ) + ( 1.0 * temp ) + 2.0 );
};


void example()
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
        printf("\nk:%d | partition = %lf | summation = %lf",
               n, mainOutputs.partition, mainOutputs.summation);
    }
}

void problem13()
{
    printf("\n================== Problem 13 ==================\n");
    const double left = 0.0, right = 1.0;
    const int STEP = 1;
    const int MAX_N_A = 4;
    const int MAX_N_B = 16;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A13Partition_f;
    mainFunctions.summation = &A13Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}


void problem14()
{
    printf("\n================== Problem 14 =================\n");
    double left = 0.0, right = 1.0;
    const int STEP = 1;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A14Partition_f;
    mainFunctions.summation = &A14Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

void problem15()
{
    printf("\n================== Problem 15 =================\n");
    double left = 1.0, right = 2.0;
    const int STEP = 1;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A15Partition_f;
    mainFunctions.summation = &A15Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

void problem18()
{
    printf("\n================== Problem 18 =================\n");
    double left = 1.0, right = 2.0;
    const int STEP = 1;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A18Partition_f;
    mainFunctions.summation = &A18Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}


void problem22()
{
    printf("\n================== Problem 22 =================\n");
    double left = 0.0, right = 2.0;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A22Partition_f;
    mainFunctions.summation = &A22Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

void problem23()
{
    printf("\n================== Problem 23 =================\n");
    double left = 1.0, right = 2.0;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A22Partition_f;
    mainFunctions.summation = &A23Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 5000);
    printf("k:%d | partition = %lf | summation = %lf\n",
           5000, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);

}

void problem24()
{
    printf("\n================== Problem 24 =================\n");
    double left = 0.0, right = 3.0;
    const int MAX_N_A = 5;
    const int MAX_N_B = 15;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A24Partition_f;
    mainFunctions.summation = &A24Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 10);
    printf("k:%d | partition = %lf | summation = %lf\n",
           10, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

void problem25()
{
    printf("\n================== Problem 25 =================\n");
    double left = 0.0, right = 3.0;
    const int MAX_N_A = 3;
    const int MAX_N_B = 6;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A25Partition_f;
    mainFunctions.summation = &A25Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 10);
    printf("k:%d | partition = %lf | summation = %lf\n",
           10, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

void problem26()
{
    printf("\n================== Problem 26 =================\n");
    double left = 0.0, right = 1.0;
    const int MAX_N_A = 5;
    const int MAX_N_B = 15;

    func_area_under_curve_t mainFunctions;
    mainFunctions.partition = &A26Partition_f;
    mainFunctions.summation = &A26Summation_f;

    area_under_curve_t mainOutputsA;
    mainOutputsA.partition = 0.0;
    mainOutputsA.summation = 0.0;
    area_under_curve_t mainOutputsB;
    mainOutputsB.partition = 0.0;
    mainOutputsB.summation = 0.0;

    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, MAX_N_A);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_A, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsA, left, right, 10);
    printf("k:%d | partition = %lf | summation = %lf\n",
           10, mainOutputsA.partition, mainOutputsA.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, MAX_N_B);
    printf("k:%d | partition = %lf | summation = %lf\n",
           MAX_N_B, mainOutputsB.partition, mainOutputsB.summation);
    areaWithinInterval(&mainFunctions, &mainOutputsB, left, right, 20);
    printf("k:%d | partition = %lf | summation = %lf\n",
           20, mainOutputsB.partition, mainOutputsB.summation);
}

int main()
{
    example();
    problem13();
    problem14();
    problem15();
    problem18();
    problem22();
    problem23();
    problem24();
    problem25();
    problem26();
    return 0;
}
