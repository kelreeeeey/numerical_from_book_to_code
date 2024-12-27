#ifndef AREA_WITHIN_INTERVAL
#define AREA_WITHIN_INTERVAL

/*
 * A struct that points to a function that takes one parameter
 * of double.
*/
typedef double ( *partition_f ) ( double );

/*
 * A struct that points to a function that takes two parameters
 * first parameter of the function is a pointer to a double
 * the second one is just a double.
*/
typedef void ( *summation_f ) ( double * , double );

/*
 * Struct of `area_under_curve_t`
 * This strcut contains 2 fields that later will hold the results
 * of partition and summation problem. Both field are type of 
 * double.
*/
typedef struct {
  double partition;
  double summation;
} area_under_curve_t ;

/*
 * Struct of `func_area_under_curve_t`
 * This struct contains 2 fields which are the functions of the
 * partition problem and summation problem. Both are custom `typedef`
 * that defined before.
*/
typedef struct {
  partition_f partition;
  summation_f summation;
} func_area_under_curve_t ;

/*
 * This function will calculate area under certain curve with
 * given function and bounded with left and right parameters.
 * The interval parameter will controll how much the detail of
 * sub-interval of the curve.
 *
 * Inputs:
 * -------
 *
 *  func_area_under_curve_t *func: a pointer to the specific
 *  function specified by the problem.
 *
 *  area_under_curve_t *areas: a pointer to the struct of
 *  area_under_curve_t, that will contain the result calculated
 *  later in this function definition.
 *
 *  double left: left bound specified in problem.
 *
 *  double right: right bound specified in the problem.
 *
 *  int interval: size of the sub-interval.
 *
*/
void areaWithinInterval(
  func_area_under_curve_t *func,
  area_under_curve_t *areas,
  double left,
  double right,
  int interval
);

#endif
