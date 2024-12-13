#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'entiers en ordre croissant
 *               en utilisant l'algorithme de tri à bulles.
 * @array: Pointeur vers le tableau d'entiers à trier.
 * @size: Taille du tableau.
 *
 * Description: Ce tri compare chaque paire d'éléments adjacents
 *              et les échange si nécessaire pour les trier.
 *              La fonction imprime le tableau à chaque changement.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j; /* Indices pour parcourir le tableau */
	int temp; /* Variable temporaire pour l'échange */
	int swapped; /* Indicateur pour optimiser les itérations */

	/* Vérifie si le tableau est valide et s'il y a au moins 2 éléments */
	if (!array || size < 2)
		return;

	/* Parcours de chaque élément du tableau */
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Initialisation de l'indicateur */
		for (j = 0; j < size - 1 - i; j++)
		{
			/* Si un élément est plus grand que le suivant, on les échange */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Marque qu'un échange a eu lieu */
				print_array(array, size); /* Affiche le tableau */
			}
		}
		/* Si aucun échange n'a eu lieu, le tableau est trié */
		if (!swapped)
			break;
	}
}
