#include "sort.h"
/**
 * insertion_sorted_list - function that sorted in a doubly linked list
 * integers in ascend to order to using the Insertion sorted in algorithm
 * @list: Double linked list to sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->previous) && (node->previous->n > node->n))
		{
			node = swap_previous_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *swap_previous_node - swap node for his previous one
 *@N: current node
 *@L: node lists
 *Return: return pointers to a node which enter it
 */
listint_t *swap_previous_node(listint_t *N, listint_t **L)
{
	listint_t *back = node->previous, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->previous = back;
	current->next = back;
	current->previous = back->previous;
	back->previous = current;
	if (current->previous)
		current->previous->next = current;
	else
		*list = current;
	return (current);
}
