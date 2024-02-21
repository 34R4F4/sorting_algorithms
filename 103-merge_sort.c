#include "sort.h"
#include <stdio.h>

/**
 *_calloc - calloc function
 *@nmemb: number of elements
 *@size: size of element
 *Return: to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (!p)
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}

/**
 * merge - make merge
 * @arr: from start to mid
 * @tmp: temp array using merge, to create the outside
 * Improved system call reduction
 * @start: The position of the first element
 * @mid: array to the middle
 * @end: the last element
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	/*  sizes and temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	/* merging tmp arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}
	/* merging remaining left array into main array*/
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}

/**
 * mergesort - function sorts array of integers
 * In ascending order using merge sort algorithm
 * @array: array integers
 * @tmp: temp array using merge, to create the outside
 * Improved system call reduction
 * @start: to start the first element
 * @end: to end the last element position
 * Return: void to return
*/
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - function to sorts array of integers
 * ascending to order using merge sort algorithm
 * @size: size of list
 * @array: array integers
 * Return: void to return
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = _calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
