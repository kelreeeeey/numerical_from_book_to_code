# Numerical Thingy _from book to code_, Calculus, Physics and allhat - written in C and Python

I decide to learn C by solving Calculus and Physics problem
found in any book, mainly from what i got in class(es) as undergrad.
Geophysics student

So please bare with the _MeEsSy_ C code.

source: 
- [2020 - Calculus II - After Mid Term]( https://drive.google.com/drive/folders/1mBOdVSwoBwY-C8VFbK0Sj1ZoNFnRjppd?usp=drive_link )
>**NOTE**: The source currently in private mode, i'll make the public one ASAP

# Content of The Repo

to be added soon.. 😉

---

# Lists of Problems

## Need to be referenced

![Sum of Consecutive Powers](https://ericrowland.github.io/investigations/images/sp16.gif)

## Problem Set 4.1

### no.12

#### Problem

$
\lim_{n\to\infty} \sum_{k=1}^{n} ( 1 + \frac{2k}{n} )^{2} \times ( \frac{2}{n} )
$

#### Solution

the problem would be simplified to

>$
\lim_{n\to\infty} \sum_{k=1}^{n} ( 1 + \frac{2\times2\times k}{n} + \frac{4\times k^2}{n^2} ) \times ( \frac{2}{n} )
$

and then evaluated as

>$
\lim_{n\to+\infty} \sum_{k=1}^{n} \frac{2}{n} + \sum_{k=1}^{n} \frac{8k}{n^2} + \sum_{k=1}^{n} \frac{8k^2}{n^3}
$

finally, by using the rules of sum and multipication of summation, we will get

>$
\lim_{n\to+\infty} [\frac{1}{n}\times 2n] + [\frac{8}{n^2} \times ( \frac{n(n+1)}{2} ) ] + [\frac{8}{n^3} \times ( \frac{n(n+1)(2n+1)}{6} )]
$

exclude the limit terms then simplify as follows

>$
result = 2 + [ \frac{8}{n^2} \times [ \frac{n(n+1)}{2} + \frac{1}{n} \times \frac{n(n+1)(2n+1)}{6} ] ]
$

if we set a large number of `n=5000=N` persay, we will got something like this

>$
result = 2 + [ \frac{8}{N\times N} \times (linearSummation(N) + \frac{quadraticSummation(N)}{N}) ]
$

```c
    double N=5000;
    double result = 
        2.0 + (
            ( 8.0 / ( N*N ) ) * (
                linearSummation((float) N ) + quadraticSummation(N) / N
            )
        );
```

the result would converge to 
> $8.6...$

### no.13

calculate area under the curve of following function $f(x)$

>$
f(x) = 4x + 1, on [0,1]
$

for

- $n=4$, and
- $n=8$

---

if $a+\Delta x = \frac{k}{n}$

using 

>$
S_n = \sum_{k=1}^{n} f(a+\Delta x) \Delta x
$

and 

>$
\Delta x = \frac{b-a}{n} 
$



