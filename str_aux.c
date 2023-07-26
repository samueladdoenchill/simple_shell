#include "main.h"

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: Destination string where source string will be concatenated.
 * @src: Source string that will be appended to destination.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	/* Finding the end of the destination string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Appending the source string to the destination */
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - Copies the string pointed to by src to dest.
 *
 * @dest: Destination where the string will be copied.
 * @src: Source string that will be copied to the destination.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	/* Copying each character from src to dest */
	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string compared.
 * @s2: Second string compared.
 * Return: Integer less than, equal to, or greater than zero if s1
 * is found,to be less than, to match, or be greater than s2
 * respectively.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	/* Comparing each character of s1 and s2 */
	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strchr - Locates a character in a string.
 *
 * @s: String where the character will be searched.
 * @c: Character to be located.
 * Return: Pointer to first occurrence of character c in string s.
 * If the character is not found, returns NULL.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	/* Searching for the character c in the string s */
	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/**
 * _strspn - Gets the length of a prefix substring.
 *
 * @s: Initial segment to be checked.
 * @accept: String containing the accepted characters.
 * Return: The number of accepted characters at the beginning of s.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	/* Searching for the first character in s that is not in accept */
	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

