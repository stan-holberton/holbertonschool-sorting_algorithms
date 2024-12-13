#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Structure d'une liste doublement chaînée
 * @n: Donnée de l'élément
 * @prev: Pointeur vers le précédent élément de la liste
 * @next: Pointeur vers le suivant élément de la liste
 *
 * Description: Structure représentant un nœud dans une liste
 * doublement chaînée utilisée pour certains algorithmes de tri.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes des fonctions */

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void insertion_sort_list(listint_t **list);

listint_t *create_listint(const int *array, size_t size);

#endif /* SORT_H */
