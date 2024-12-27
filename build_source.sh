#! /usr/bin bash

# area within the curve problem
gcc source/area_within_interval.c source/example_area_within_interval.c -o bins/example_area_within_interval
gcc -fPIC -shared -o shared_objects/example_area_within_interval.so source/area_within_interval.c source/example_area_within_interval.c

