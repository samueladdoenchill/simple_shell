#include "main.h"

/**
 * add_rvar_node - Adds new variable node at end of r_var list.
 * @head: Pointer to head of linked list.
 * @lvar: Length of variable.
 * @val: Value of variable (a string).
 * @lval: Length of value (length of the string).
 * Return: Address of head after adding new node.
 *
 * This function allocates memory for new r_var node and adds it to end
 * of linked list pointed to by @head. The new node contains information
 * about variable, such as its length, value, and length of value.
 * If memory allocation fails, function returns NULL.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * free_rvar_list - Frees entire r_var list and deallocates memory.
 * @head: Pointer to head of linked list.
 * Return: No return value.
 *
 * This function deallocates memory used by entire r_var linked list
 * pointed to by @head. It frees each node, starting from head, until all
 * nodes in list are freed. After freeing all nodes, it sets head
 * pointer to NULL to indicate empty list.
 *
 * Note: Make sure to call this function to avoid memory leaks when
 * linked list is no longer needed.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

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

