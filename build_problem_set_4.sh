#! bin/bash

gcc -o problem_set_A_13_21 problemsetA_13_21.c
gcc -fPIC -shared -o area_under_curve.so problemsetA_13_21.c

gcc -o problem_set_4_1 problem_set_4_1.c
gcc -fPIC -shared -o problem.so problem_set_4_1.c
