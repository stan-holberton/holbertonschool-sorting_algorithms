#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement chaînée d'entiers en ordre
 *                       croissant avec l'algorithme de tri par insertion.
 * @list: Pointeur vers la tête de la liste.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap_node;

	/* Vérifie si la liste est vide ou contient un seul élément */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Commence le tri à partir du deuxième élément */
	current = (*list)->next;
	while (current != NULL)
	{
		swap_node = current;

		/* Si élément courant plus petit que élément précédent on échange */
		while (swap_node->prev != NULL && swap_node->n < swap_node->prev->n)
		{
			/* Échange des pointeurs des nœuds */
			swap_node->prev->next = swap_node->next;
			if (swap_node->next != NULL)
				swap_node->next->prev = swap_node->prev;

			swap_node->next = swap_node->prev;
			swap_node->prev = swap_node->prev->prev;

			/* Met à jour la tête de la liste si nécessaire */
			if (swap_node->prev != NULL)
				swap_node->prev->next = swap_node;
			else
				*list = swap_node;

			swap_node->next->prev = swap_node;

			/* Affiche l'état de la liste après chaque échange */
			print_list(*list);
		}
		/* Passe à l'élément suivant */
		current = current->next;
	}
}
