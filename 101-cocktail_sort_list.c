#include "sort.h"
#include <stdio.h>

/**
 * swap_prev_node - Swaps a node with its previous one in a linked list.
 * @Node: The current node to swap.
 * @List: The pointer to the head of the linked list.
 * Return: The pointer to the node that was swapped.
 */
listint_t *swap_prev_node(listint_t *Node, listint_t **List)
{
	listint_t *back = Node->prev, *current = Node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*List = current;
	return (current);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 *			using the Cocktail Shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;

	while (swap_done == 1)
	{
		swap_done = 0;

		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_prev_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}

		if (swap_done == 0)
			break;

		swap_done = 0;

		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_prev_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}

