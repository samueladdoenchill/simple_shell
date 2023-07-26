#include "main.h"

/**
 * add_sep_node_end - Adds new separator node at end of sep_list.
 * @head: Pointer to head of linked list.
 * @sep: Separator found (';', '|', or '&').
 * Return: Address of head after adding new node.
 *
 * This function allocates memory for new sep_list node and adds it to end
 * of linked list pointed to by @head. New node stores separator found
 * in command line (';', '|', or '&'). If memory allocation fails, function
 * returns NULL.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		/* Linked list is empty; make new node as head */
		*head = new;
	}
	else
	{
		/* Traverse to end of linked list and add new node */
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - Frees entire sep_list and deallocates memory.
 * @head: Pointer to head of linked list.
 * Return: No return value.
 *
 * This function deallocates memory used by entire sep_list linked list
 * pointed to by @head. It frees each node, starting from head, until all
 * nodes in list are freed. After freeing all nodes, it sets head pointer
 * to NULL to indicate empty list.
 *
 * Note: Make sure to call this function to avoid memory leaks when
 * linked list is no longer needed.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - Adds new command line at end of line_list.
 * @head: Pointer to head of linked list.
 * @line: Command line (a string).
 * Return: Address of head after adding new node.
 *
 * This function allocates memory for new line_list node and adds it to end
 * of linked list pointed to by @head. New node stores command line
 * (a string) passed to function. If memory allocation fails, function
 * returns NULL.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		/* The linked list is empty; make new node as head */
		*head = new;
	}
	else
	{
		/* Traverse to end of linked list and add new node */
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - Frees entire line_list and deallocates memory.
 * @head: Pointer to head of linked list.
 * Return: No return value.
 *
 * This function deallocates memory used by entire line_list linked list
 * pointed to by @head. It frees each node, starting from head, until all
 * nodes in the list are freed. After freeing all nodes, it sets head pointer
 * to NULL to indicate an empty list.
 *
 * Note: Make sure to call this function to avoid memory leaks when
 * linked list is no longer needed.
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

