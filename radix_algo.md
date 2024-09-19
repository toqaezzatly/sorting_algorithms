# Radix (LSD) Sorting Algorithms

![Example Image](https://i.redd.it/il2jz9cvaez31.jpg)

---

## Radix Sort (LSD):

- The LSD variant of radix sort performs a stable counting sort on the list for each digit, starting from the least significant (right-most) digit.

- **When learning about the radix sort (LSD) I'm reading that the initial input array has a "current digit". For example, it says 48 has a current digit of 8. What does current digit mean?**

- The "current digit" refers to the digit in the number being processed at a particular step in the radix sort algorithm. In the case of a Least Significant Digit (LSD) radix sort, the current digit refers to the rightmost digit of the number being processed.

  For example, if the input array consists of the numbers 48, 35, 12, 19, and the algorithm is processing the LSD, the current digit would be the rightmost digit of each number in the array. In the first step, the current digit would be 8, 5, 2, 9.

  Each digit of the numbers in the input array is processed from right to left, starting with the least significant digit (the LSD). After processing each digit, the input array is rearranged so that the numbers are in order based on their current digit. This process is repeated for each digit of the numbers in the array, until all the digits have been processed and the array is fully sorted.

## Example:

Consider the input array **[19, 48, 99, 71, 13, 52, 96, 73, 86, 7]**
(**REMINDER**.. the array positions are: [zero, first, second, third, fourth, fifth, sixth, seventh, eighth, ninth])

1.  We initialize two arrays, count_array and auxiliary_array, both with the length of 10 to represent the possible values of a digit (0 to 9).
2.  We process the least significant digit of each number in the input array and count the occurrences of each digit in the count_array.
3.  We perform a "rolling summation" on the count*array by adding the value of each element to the previous element. The first element of the count_array is subtracted by 1 to make sure that the resulting sums yield the correct positions in the `auxiliary_array`.
4.  We use the count_array to determine the positions of each element in the input_array in the auxiliary_array.
5.  We copy the elements in the auxiliary_array back to the input_array.
6.  We repeat the same process, but this time using the next significant digit (moving from right to left).
7.  Repeat this process until all the digits of the numbers in the input_array have been processed.
8.  The input_array is now fully sorted in non-decreasing order.

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
auxillary_array = []
```

# Steps:

- Starting Radix Sort. We will process digits from right to left. The first step will be to count occurances of digits from the input array.

> **Counting sort is a linear sorting algorithm that sorts data with integer keys by counting the number of occurrences of each key and using this information to determine the position of each key in the sorted output. In the context of radix sort, counting sort is used as a subroutine to sort the elements of the input array based on a specific digit of the numbers being processed.**

- After first iteration through input_array:

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [0, 1, 1, 2, 0, 0, 2, 1, 1, 2]
auxillary_array = []
```

- The next step is to do a rolling summation:

- **What is a rolling summation?:**

  - The term "rolling summation" is not commonly used in the context of the radix sort algorithm. Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by the individual digits which share the same significant position and value. The process does not involve any kind of summation.

- But first we subtract 1 from the 0 position so that the resulting sums yield correct positions in the Auxilliary array.

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [-1, 0, 1, 3, 3, 3, 5, 6, 7, 9]
auxillary_array = []
```

- Now use the Count array to decide where to move values into the Auxilliary array

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [-1, -1, 0, 1, 3, 3, 3, 5, 6, 7]
auxillary_array = [71, 52, 13, 73, 96, 86, 7, 48, 19, 99]
```

- Now we move the value back to the Input Array.
- We repeat the same process, but this time using the 1st digit.

```
input_array = [71, 52, 13, 73, 96, 86, 7, 48, 19, 99]
count_array = [-1, 0, 2, 2, 2, 3, 4, 4, 6, 7]
auxillary_array = [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
```

- Now we move the value back to the input array.

```
input_array = [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
count_array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
auxillary_array = []
```

# Done sorting!

## Radix Algo Pseudo Code:
```
Radix_Sort(Array, p) // p is the number of passes

       for j = 1 to p do

            int count_array[10] = {0};

            for i = 0 to n do

                count_array[key of(Array[i]) in pass j]++ // count array stores the count of key

            for k = 1 to 10 do

                count_array[k] = count_array[k] + count_array[k-1]

            for i = n-1 downto 0 do

                result_array[ count_array[key of(Array[i])] ] = Array[j]

                                                          //Construct the resulting array (result_array) by checking

                                                                                 //new Array[i] position from count_array[k]

                count_array[key of(Array[i])]--

            for i=0 to n do

                Array[i] = result_array[i]  

                                                             //The main array Array[] now contains sorted numbers based on the current digit position.

       the end for(j)

 end function
```

```
#include <stdio.h>
#include <math.h>

#define BASE 10
#define WIDTH 3

void radix_sort(int *arr, int n) {
  int i, j, k, m, p, q, w = WIDTH, d = 1;
  int temp[n];

  for (i = 0; i < w; i++, d *= BASE) {
    for (j = 0; j < BASE; j++) {
      m = 0;
      for (k = 0; k < n; k++) {
        p = arr[k] / d % BASE;
        if (p == j) temp[m++] = arr[k];
      }
      for (k = 0, q = j; k < m; k++) arr[q] = temp[k], q += BASE;
    }
  }
}

int main(int argc, char *argv[]) {
  int i, arr[] = {329, 457, 657, 839, 436, 720, 355};
  int n = sizeof(arr) / sizeof(arr[0]);

  radix_sort(arr, n);

  printf("Sorted Array:\n");
  for (i = 0; i < n; i++) printf("%d ", arr[i]);

  return 0;
}
```

# **Hope you enjoyed my guide.**

# **www.github.com/claybowl**
