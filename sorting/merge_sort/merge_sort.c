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
		scanf("%d", &arr[i]);
		i++;
	}
	return (arr);
}

void	merge(int *arr, int s, int f)
{
	int	mid = (f + s) / 2;
	int	left[mid + 1];
	int	right[f - mid];
	int	i;
	int	j;
	int	arr_i;

	i = 0;
	j = s;
	while (i < mid + 1)
	{
		left[i] = arr[j];
		i++;
		j++;
	}
	i = 0;
	j = mid + 1;
	while (i < f - mid)
	{
		right[i] = arr[j];
		i++;
		j++;
	}
	i = 0;
	j = 0;
	arr_i = s;
	while (1)
	{
		if (i == mid + 1 || j == f - mid)
			break;
		if (left[i] <= right[j])
			arr[arr_i++] = left[i++];
		if (left[i] > right[j])
			arr[arr_i++] = right[j++];
	}
	if (i == mid + 1)
	{
		while (j < f - mid)
			arr[arr_i++] = right[j++];
	}
	else if (j == f - mid)
	{
		while (i < mid + 1)
			arr[arr_i++] = left[i++];
	}
}

void	merge_sort(int *arr, int s, int f)
{
	int	mid;

	if (f - s + 1 > 1)
	{
		mid = (s + f)/2;
		merge_sort(arr, s, mid);
		merge_sort(arr, mid + 1, f);
		merge(arr, s, f);
	}
}

int main(int argc, char **argv)
{
	int	*arr;
	int	target;
	int	n;

	printf("input array size : ");
	scanf("%d", &n);
	arr = input_array(n);
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
}