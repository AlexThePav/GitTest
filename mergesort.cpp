#include <iostream>
#include <array>

using namespace std;

int merge (int left, int right)
{
	int result = [];
	int i, j, k = 0;

	while (i < sizeof(left) && j < sizeof(right))
	{
		if (left[i] < right[j])
		{
			result[k] = left[i];
			i++;
		} else {
			result [k] = right[j];
			j++;
		}
		k++;
	}

	while (i < sizeof(left))
	{
		result[k] = left[i];
		k++;
	}

	while [j <sizeof(right)]
	{
		result[k] = right[j];
		k++;
	}
	return result;
}

int mergeSort (int A)
{
	if (sizeof(A) < 2) return A;
	else
	{
		int middle = sizeof(A)/2;
		int left = mergeSort(A[:middle]);
		int right = mergeSort(R[middle:]);
		int together = merge(left, right);
	}
	return together;
}

int main ()
{
	int array[100], n;
	
	system("pause");
	return 0;
}