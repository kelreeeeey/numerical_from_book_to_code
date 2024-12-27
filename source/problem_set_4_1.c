#include <stdio.h>

double constantSummation (double n, double constant_) { return n * constant_; }
float linearSummation (float n) { return ( ( n * n ) + n ) / 2.0; };
double quadraticSummation (double n) { return (( ( n * n ) + n ) * ( 2.0 * n + 1 )) / 6.0; };
double bicubicSummation (double n) { double temp = n + 1.0; return ((n*n)*(temp*temp)) / 4.0; }

void setA_1_to_8 ()
{
    float setA_1,setA_2,setA_3,setA_4,setA_7,setA_8;
    double setA_5,setA_6;
    const double N7=100, N8=100; 
    
    setA_1 = constantSummation(6.0, 1.0);
    setA_2 = constantSummation(250.0, 1.0);
    setA_3 = linearSummation(15.0);
    setA_4 = linearSummation(10.0);
    setA_5 = bicubicSummation(5.0);
    setA_6 = quadraticSummation(7.0);

    double setA_7_a = 2.0;
    double setA_7_b = linearSummation(N7);
    double setA_7_c = constantSummation(3.0, N7);
    setA_7 = (setA_7_a * setA_7_b) - setA_7_c;

    double setA_8_a = quadraticSummation(N8);
    double setA_8_b = 2 * linearSummation(N8);
    double setA_8_c = N8;
    setA_8 = setA_8_a - setA_8_b + setA_8_c;

    printf("Set 4.1.A.1:  constant summation: %15.4f", setA_1);
    printf("\nSet 4.1.A.2:  constant summation: %15.4f", setA_2);
    printf("\nSet 4.1.A.3:    linear summation: %15.4f", setA_3);
    printf("\nSet 4.1.A.4:    linear summation: %15.4f", setA_4);
    printf("\nSet 4.1.A.5:   bicubic summation: %15.4f", setA_5);
    printf("\nSet 4.1.A.6: quadratic summation: %15.4f", setA_6);
    printf("\nSet 4.1.A.7:    linear summation: %15.4f", setA_7);
    printf("\nSet 4.1.A.8: quadratic summation: %15.4f", setA_8);
}

void setA_9_to_12 ()
{
    double setA_9, setA_10, setA_11, setA_12;
    double N = 5000.0;

    setA_9 = (double) linearSummation((float) N ) / (N * N);
    setA_10 = quadraticSummation( N ) / (N * N * N);
    setA_11 = 2.0 + ( 2.0 * linearSummation((float) N ) / (N * N) );
    setA_12 = 
        2.0 + (
            ( 8.0 / ( N*N ) ) * (
                linearSummation((float) N ) + 
                ( quadraticSummation(N) / N ) 
            ) 
        );
    printf("\nSet 4.1.A.9:    linear summation: %15.4f", setA_9);
    printf("\nSet 4.1.A.10:   linear summation: %15.4f", setA_10);
    printf("\nSet 4.1.A.11:   linear summation: %15.4f", setA_11);
    printf("\nSet 4.1.A.12:   linear summation: %15.4f", setA_12);

}

int main()
{
    setA_1_to_8();
    setA_9_to_12();
    return 0;
}
