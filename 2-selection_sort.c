#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers en ordre croissant avec
 *                  l'algorithme de tri par sélection.
 * @array: Tableau à trier.
 * @size: Taille du tableau.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	/* Si le tableau est vide ou taille < 2, on ne fait rien */
	if (array == NULL || size < 2)
		return;

	/* Parcours du tableau */
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		/* Trouver le plus petit élément dans le reste du tableau */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/* Si un plus petit élément est trouvé, on échange */
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;

			/* Affichage après chaque échange */
			print_array(array, size);
		}
	}
}
