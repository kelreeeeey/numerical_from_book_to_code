#! /usr/bin bash

echo area within the curve problem
gcc source/area_within_interval.c source/example_area_within_interval.c -o bins/example_area_within_interval
gcc -fPIC -shared -o shared_objects/example_area_within_interval.so source/area_within_interval.c source/example_area_within_interval.c

echo problem set 4 to 1
gcc -o bins/problem_set_4_1 source/problem_set_4_1.c
gcc -fPIC -shared -o shared_objects/problem_set_4_1.so source/problem_set_4_1.c

echo problem set A 13 to 21
gcc -o bins/problemsetA_13_21 source/problemsetA_13_21.c source/area_within_interval.c
gcc -fPIC -shared -o shared_objects/problemsetA_13_21.so source/problemsetA_13_21.c source/area_within_interval.c
