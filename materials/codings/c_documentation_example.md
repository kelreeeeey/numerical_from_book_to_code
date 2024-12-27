# C documentation examples

source: [C Documentation Examples](https://w3.cs.jmu.edu/buchhofp/class/cs361_s18/documentation_examples.html)

## Documentation examples for C program

When documenting your C code, it is important that you provide a clear and concise description of
what your program and/or function(s) accomplish. Furthermore, your code needs to be commented in
a meaningful way. Parameters, return values, behaviors, and side-effects of functions need to be
documented in a fashion that it is straightforward for a reader of your code to learn the purpose
and usage of your functions. Other comments need to add an explanation to the existing code, not
just rephrase the code in English language.

Below is an example of a function that implements the Selection Sort algorithm. First, there is a
bad example of a description of the code and comments, and below that the same code is documented
very well

## Bad Example

The sort function takes a given array (numbers ) and its number of elements (size ) and sorts its
elements. First, the variable i is assigned the value 0 and increased in a loop by one as long as
i is smaller than size -1. Within the loop, the variable `min_index` is first assigned the value
`i`. Then, in a second loop, variable `j` is assigned the value `i +1` and increased by one as long
as `j` is smaller than size . Within the loop, `numbers[j]` is compared with `numbers[min_index]`,
and if the former is smaller, `min_index` is set to the value `j` . After the inner loop, a temporary
variable stores the value of `numbers[i]` , `numbers[i]` is assigned `numbers[min_index]` , and
`numbers[min_index]` is assigned the temporary value

```c
/*
This function sorts a given array of numbers.

Input: an array of unsigned integers and its size
Output: none, but array will be sorted at the end
*/
void sort(unsigned int numbers[], int size)
{
    int i;              // counter
    int j;              // counter
    int min_index;      // holds the index of the minimum value
    unsigned int temp;  // used for swapping
    
    for (i = 0; i < size-1; i++) {  // iterate over array elements
        min_index = i;  // set minimum to current index
        for (j = i+1; j < size; j++) { // iterate over remaining elements
            if (numbers[j] < numbers[min_index]) { // compare values at positions
                                                   // j and min_index
                min_index = j;                     // if smaller, remember the
                                                   // index
            }
        }
        temp = numbers[i];                  // swap the current index with the
        numbers[i] = numbers[min_index];    // minimum's
        numbers[min_index] = temp;
    }
}
```

## Good Example

The sort function takes as input a pointer to an array of unsiged integers, as well as the number
of elements in the array. There is no return value, but the but the elements of the array will be
rearranged so that the first element is the smallest, the second element the next smallest, and so
on, with the last element having the largest value.

The function sorts the array using the Selection Sort algorithm: the function first identifies the
overall minimum value in the array and puts it in the first position of the array. Then, it proceeds
to identify the minimum value in the array excluding the first position and puts it in the second
position. This continues until the last element is reached and the array is sorted. The index `i`
effectively partitions the array in a sorted half ("left" of index `i` ) and an unsorted half (position
`i` and everything to the "right" of it). In each iteration of the outer loop, the minimum value of the
unsorted half is identified (using the inner loop) and brought to the first position of the unsorted
half by swapping out the minimum element with that pointed to by `i`.

```c
/*
This function implements the Selection Sort algorithm to sort
a given array of type unsigned integer in ascending order.

Input: 
    unsigned int numbers[]: a pointer to an array of unsigned integers
    int size: the number of elements in the array

Output: there is no return value, but the elements of numbers[]
        will be rearranged so that the first element is the smallest,
        the second element the next smallest, and so on, with the last
        element having the largest value.
*/

void sort(unsigned int numbers[], int size)
{
    int i;              // will be used in the outer loop of the algorithm
                        // as an index to an element in the array
    int j;              // will be used in the inner loop of the algorithm
                        // as an index to an element in the array
    int min_index;      // in the inner loop, this will hold the index to the
                        // array element that has the minimum value identified
                        // up to that point; once the inner loop is done, it
                        // will hold the index of the overall minimum element
                        // of the positions larger than i
    unsigned int temp;  // this is used as a temporary space to store an array
                        // element when two array elements need to swap positions

    /*
    Starting with the first position, i is assigned all index positions of the
    array, except for the last one. As i iterates over the positions, the inner
    loop will process the array elements that have a larger index than i, and
    the array positions smaller than i will be in their final overall sorted
    order.
    */
    for (i = 0; i < size-1; i++) {
        min_index = i;  // initially, the min_index is set to i, and then the
                        // inner loop is used to see if there is an index with
                        // a smaller value than numbers[i]
        /*
        The inner loop iterates over all elements in the array with a position
        greater than i. When the loop has finished, min_index will point to the
        smallest value of the elements at position i and greater.
        */
        for (j = i+1; j < size; j++) {
            if (numbers[j] < numbers[min_index]) { // check if current number is
                                                   // smaller than the current
                                                   // minimum
                min_index = j;                     // if so, remember the index
            }
        }

        /*
        The next three instructions swap two array elements. At this point,
        min_index points to the smallest element of the unsorted part of the
        array. Note that min_index can be equal to i if the value at position
        i already held that minimum value. In this case, the next three
        instructions would not be necessary.
        */
        temp = numbers[i];                  // remember the value pointed to by i
        numbers[i] = numbers[min_index];    // overwrite position i with the
                                            // minimum value
        numbers[min_index] = temp;          // put the original value at
                                            // position i at position min_index
    }
}
```
