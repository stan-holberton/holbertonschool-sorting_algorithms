#include "sort.h"
#include <stdio.h>

/**
 * partition - Partitionne un tableau en fonction d'un pivot.
 * @array: Le tableau à trier.
 * @low: L'indice bas de la partition.
 * @high: L'indice haut de la partition.
 * @size: La taille du tableau.
 *
 * Return: L'indice du pivot après partitionnement.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	int temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Effectue un tri rapide récursif sur un tableau.
 * @array: Le tableau à trier.
 * @low: L'indice bas de la sous-partie du tableau.
 * @high: L'indice haut de la sous-partie du tableau.
 * @size: La taille du tableau.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers en ordre croissant avec l'algorithme
 * de tri rapide.
 * @array: Le tableau à trier.
 * @size: La taille du tableau.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
