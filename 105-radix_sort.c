#include "sort.h"
#include <stdio.h>
/**
* getMax - Auxiliary function to get maximum value in arr[]
* @arr: Shortcut to array
* @n: array size
* Return: to array
*/
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* countSort - A function to do some type of arr[] according to
* The number that EXP represents.
* @arr: Shortcut to array
* @n: size of array
* @exp: exp 10^i
* @output: array to save temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Store the number of events in the count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains an actual count
    * Position of this number in the output[]
	*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so arr[] is now
    * Contains numbers arranged according to the current number
	*/
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	/*print_array(arr, n);*/
}

/**
* radix_sort - Main function of this type arr[]
* with size n using Radix Sort
* @array: meaning array
* @size: size of array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (!array || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (!output)
		return;
/*
 * Sort the count per number. Notice that instead
 * From passing the number, exp passed. exp is 10^i
 * Where I is the current number
*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
