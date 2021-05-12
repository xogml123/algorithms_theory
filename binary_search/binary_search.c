#include "stdio.h"
#include "stdlib.h"

int	*input_array(int n)
{
	int	i;
	int *arr;

	
	arr = malloc(sizeof(int) * n);
	i = 0;
	printf("input array with space\n");
	while (i < n)
	{
		scanf("%d ", &arr[i]);
		i++;
	}
	return (arr);
}


int	binary_search(int *arr, int start, int end,  int target)
{
	int	pivot;

	pivot = (start + end) / 2;
	if ((start == end) && (arr[pivot] != target))
		return (-1);
	if (arr[pivot] == target)
		return (pivot);
	else if (arr[pivot] > target)
		return (binary_search(arr, start, pivot - 1, target));
	else
		return (binary_search(arr, pivot + 1, end, target));
}

int main(int argc, char **argv)
{
	int	*arr;
	int	target;
	int	n;

	printf("input array size : ");
	scanf("%d\n", &n);
	arr = input_array(n);
	printf("target : ");
	scanf("%d\n", &target);
	binary_search(arr, 0, n - 1, target);
	free(arr);
}