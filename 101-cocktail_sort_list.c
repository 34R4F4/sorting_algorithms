#include "sort.h"
#include <stdio.h>
/**
 * *swap_prev_node - swap node to previous one
 * @Node: current node
 * @List: node list
 * Return: return pointer to node which enter it
 */
listint_t *swap_prev_node(listint_t *Node, listint_t **List)
{
	listint_t *back = Node->prev, *current = Node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

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
 * cocktail_sort_list - This is cocktail type execution
 * working on double linked list
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

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
