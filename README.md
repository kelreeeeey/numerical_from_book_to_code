# Numerical Thingy _from book to code_, Calculus, Physics and allthat - written in C and Python

I decide to learn C by solving Calculus and Physics problem
found in any book, mainly from what i got in class(es) as undergrad.
Geophysics student

So please bare with the _MeEsSy_ C code. Also a disclaimer, i will make a
bunch of typo, it is just me bad at typing, i'm working on it.

source: 
- [2020 - Calculus II - After Mid Term]( https://drive.google.com/drive/folders/1mBOdVSwoBwY-C8VFbK0Sj1ZoNFnRjppd?usp=drive_link )
>**NOTE**: The source currently in private mode, i'll make the public one ASAP

## How i approach this thing.

### Background
1. i need to:
- Learn C
- Being able to integrate C and my mother language Python as she's being so slow for some reason.
- it is just fun to learn new language, especially when you was so traumatized by C++ back then.
- also some bash scripting to make life more easy.

2. As i implicityly said before, i'm coming from python, so the c codes written would be smelled like a snake :)

### Now get to my point

here's how i write the code
1. Read some book
2. look up for the problems
3. try to solve it using pencil and papers
4. code the problem and solution in C
5. ofc compile and check the results
6. write a wrapper for python

---

here's some example of the c code to calculate area under given curve $f(x)$
I compute area based on the rigth-partition and summation rules.

```c
typedef struct { double partition, summation; } area_under_curve_t ;
typedef double (*partition_f)(double  );
typedef void (*summation_f)(double * , double  );
typedef struct { partition_f partition; summation_f summation; } func_area_under_curve_t ;
void areaWithinInterval(
        func_area_under_curve_t *func, 
        area_under_curve_t *areas,
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
        /*printf("i=%lf temp2=%lf, div=%lf\n", i, temp_2, div);*/
    }
    areas->partition = temp;
    func->summation(&areas->summation, div); // div is supposed to be 1/n 
};
```
and here how i use them in `main()`
```c
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


void main()
{
    example();
    return 0;
}

```

before the result, here's i usually compile and run the solution using shell script just so i dont have to type all the commands.
```raw
bash build_problem_set_4.sh
problem_set_A_13_21.exe
```

>NOTE: make sure y'all make the shell script runable by simply run this in y'all terminal in the root folder
`chmod u+x build_problem_set_4.sh`

and here's what it would look like in terminall
```raw
k:1 | partition = 1.000000 | summation = 1.000000
k:1001 | partition = 0.333833 | summation = 0.333833
k:2001 | partition = 0.333583 | summation = 0.333583
k:3001 | partition = 0.333167 | summation = 0.333500
k:4001 | partition = 0.333458 | summation = 0.333458
k:5001 | partition = 0.333433 | summation = 0.333433

```
---

so far i've solved and coded several of sets of problem-solution

```c
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
```
---

For python implementation, currently, i've implented the solution in C and
wrapper for python for [problem_set_4_1.c](https://github.com/kelreeeeey/numerical_from_book_to_code/blob/main/problem_set_4_1.c) that later be compiled as shared lib(?) with given name of `problem.so`. 

The c source:
```c
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

```
Ok, now here's the python code

```python
import os
import cffi

class ProblemA1:
    def __init__(self,):
        ffi = cffi.FFI()
        ffi.cdef("""
            double constantSummation(double n, double constant_);
            float linearSummation (float n);
            double quadraticSummation (double n);
            double bicubicSummation (double n);
        """)
        self.lib = ffi.dlopen(os.path.join(os.path.dirname(__file__), "problem.so"))
    def constantSummation(self, n, constant): return self.lib.constantSummation(n, constant)
    def linearSummation(self, n): return self.lib.linearSummation(n)
    def quadraticSummation(self, n): return self.lib.quadraticSummation(n)
    def bicubicSummation(self, n): return self.lib.bicubicSummation(n)

def main():
    cmod = ProblemA1()
    setA_1 = cmod.constantSummation(6.0, 1.0)
    setA_2 = cmod.constantSummation(250.0, 1.0)
    setA_3 = cmod.linearSummation(15.0)
    setA_4 = cmod.linearSummation(10.0)
    setA_5 = cmod.bicubicSummation(5.0)
    setA_6 = cmod.quadraticSummation(7.0)

    N7, N8 = 100.0, 100.0
    setA_7_a = 2.0
    setA_7_b = cmod.linearSummation(N7)
    setA_7_c = cmod.constantSummation(3.0, N7)

    setA_8_a = cmod.quadraticSummation(N8)
    setA_8_b = 2 * cmod.linearSummation(N8)
    setA_8_c = N8
    
    setA_7 = (setA_7_a * setA_7_b) - setA_7_c
    setA_8 = setA_8_a - setA_8_b + setA_8_c

    print(f"Set A.1:  constant summation: {setA_1:10.2f}")
    print(f"Set A.2:  constant summation: {setA_2:10.2f}")
    print(f"Set A.3:    linear summation: {setA_3:10.2f}")
    print(f"Set A.4:    linear summation: {setA_4:10.2f}")
    print(f"Set A.5:   bicubic summation: {setA_5:10.2f}")
    print(f"Set A.6: quadratic summation: {setA_6:10.2f}")
    print(f"Set A.7:    linear summation: {setA_7:10.2f}")
    print(f"Set A.8: quadratic summation: {setA_8:10.2f}")

if __name__ == "__main__":
    main()
```


# Content of The Repo

to be added soon 😉

---

# Lists of Problems

## Need to be referenced

![Sum of Consecutive Powers](https://ericrowland.github.io/investigations/images/sp16.gif)

## Problem Set 4.1

### no.12

#### Problem

$\lim_{n\to\infty} \sum_{k=1}^{n} ( 1 + \frac{2k}{n} )^2 \times ( \frac{2}{n} )$

#### Solution

the problem would be simplified to

$\lim_{n\to\infty} \sum_{k=1}^{n} ( 1 + \frac{2\times2\times k}{n} + \frac{4\times k^2}{n^2} ) \times ( \frac{2}{n} )$

and then evaluated as

$\lim_{n\to+\infty} \sum_{k=1}^{n} \frac{2}{n} + \sum_{k=1}^{n} \frac{8k}{n^2} + \sum_{k=1}^{n} \frac{8k^2}{n^3}$

finally, by using the rules of sum and multipication of summation, we will get

$\lim_{n\to+\infty} [\frac{1}{n}\times 2n] + [\frac{8}{n^2} \times ( \frac{n(n+1)}{2} ) ] + [\frac{8}{n^3} \times ( \frac{n(n+1)(2n+1)}{6} )]$

exclude the limit terms then simplify as follows

$result = 2 + [ \frac{8}{n^2} \times [ \frac{n(n+1)}{2} + \frac{1}{n} \times \frac{n(n+1)(2n+1)}{6} ] ]$

if we set a large number of `n=5000=N` persay, we will got something like this

$result = 2 + [ \frac{8}{N\times N} \times (linearSummation(N) + \frac{quadraticSummation(N)}{N}) ]$

```c
    double N=5000;
    double result = 
        2.0 + (
            ( 8.0 / ( N*N ) ) * (
                linearSummation((float) N ) + quadraticSummation(N) / N
            )
        );
```

the result would converged to 
> $8.6...$

### no.13

calculate area under the curve of following function $f(x)$

$f(x) = 4x + 1, on [0,1]$

for

- $n=4$, and
- $n=8$

---

if $a+\Delta x = \frac{k}{n}$

using 

$S_n = \sum_{k=1}^{n} f(a+\Delta x) \Delta x$

and 

$\Delta x = \frac{b-a}{n}$



