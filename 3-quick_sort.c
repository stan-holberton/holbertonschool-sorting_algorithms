#include <stdio.h>
#include "sort.h"

/**
 * partition - Effectue la partition autour du pivot.
 * @array: Le tableau à trier.
 * @low: L'indice bas de la partition.
 * @high: L'indice haut de la partition.
 *
 * Return: L'indice du pivot.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int temp;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, high - low + 1);

	return (i + 1);
}

/**
 * quick_sort_recursive - Fonction récursive pour appliquer le tri rapide.
 * @array: Le tableau à trier.
 * @low: L'indice bas de la sous-partie du tableau.
 * @high: L'indice haut de la sous-partie du tableau.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Fonction principale pour trier le tableau.
 * @array: Le tableau à trier.
 * @size: La taille du tableau.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
