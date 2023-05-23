#include "simple_shell.h"

/**
 * print_list - function that _print linked list
 * @h: linked list
 * Return: size of linked list
 */
size_t print_list(list_t *h)
{
	list_t *clist = h;
	int counter = 0;
	int b = 0;


	if (!h)
		return (0);
	while (clist != NULL)
	{
		if ((*clist).var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}

		else
		{
			b = 0;
			while (((*clist).var)[b] != '\0')
				b++;
			write(STDOUT_FILENO, (*clist).var, b);
			write(STDOUT_FILENO, "\n", 1);
		}
		clist = (*clist).next;
		counter++;
	}
	return (counter);
}

/**
 * add_end_node - add node to end of linked list
 * @head: pointer to head of linked list
 * @str: data to new_node node
 * Return: pointer to new_node linked list
 */
list_t *add_end_node(list_t **head, char *str)
{
	list_t *new_node;
	list_t *holder;

	if (!head || !str)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	(*new_node).var = _strdup(str);
	(*new_node).next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while ((*holder).next != NULL)
		{
			holder = (*holder).next;
		}
		(*holder).next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (*head);
}

/**
 * delete_nodeint_at_index - removing node at index
 * @head: input head address
 * @index: input index
 * Return: 1 if success, -1 if fail
 */
int delete_nodeint_at_index(list_t **head, int index)
{
	list_t *n_heads;
	list_t *holders;
	int counter = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holders = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holders;
		return (1);
	}
	counter = 1;
	n_heads = *head;
	while (counter < index)
	{
		if (!n_heads)
			return (-1);
		n_heads = (*n_heads).next;
		counter++;
	}
	holders = (*n_heads).next;
	(*n_heads).next = (*holders).next;
	free((*holders).var);
	free(holders);
	return (1);
}

/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_linked_list(list_t *list)
{
	list_t *holders;

	while (list != NULL)
	{
		holders = list;
		list = (*list).next;
		free((*holders).var);
		free(holders);
	}

}
