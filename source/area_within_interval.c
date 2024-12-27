#include "area_within_interval.h"

/*
 * Definiton of `areaWithinInterval`
 */
void areaWithinInterval(
    func_area_under_curve_t *func,
    area_under_curve_t *areas,
    double left,
    double right,
    int interval)
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

