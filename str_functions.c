#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @Sa: type str compared
 * @Sb: type str compared
 * Return: 0 if Sa and Sb are equals.
 *         another value if they are different
 */
int _strcmp(char *Sa, char *Sb)
{
	int i;

	for (i = 0; Sa[i] == Sb[i] && Sa[i]; i++)
		;
	if (Sa[i] > Sb[i])
		return (1);
	if (Sa[i] < Sb[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

