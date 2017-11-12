#include <stddef.h>
#include "forlab1.h"
#include <string.h>
#include <stdlib.h>

#define bool  int
#define false 0
#define true  1

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len)
{
	if ((sep > 255) || (sep < 0))
		return 1;

	if (strlen(string) == 0)
		return 1;

	if ((*argz = (char*) malloc(sizeof(char) * (strlen(string) + 1))) == NULL)
		exit(1);


	for (int i = 0; i < strlen(string); ++i)
	{
		if (*(string + i) == sep)
			*(*argz + i) = '\0';
		else
			*(*argz + i) = *(string + i);
	}
	
	*(*argz + strlen(string)) = '\0';
	*argz_len = strlen(string) + 1;

	return 0;
}

size_t  argz_count(const char *argz, size_t argz_len)
{
	int num = 0;
	for (int i = 0; i < argz_len; ++i)
	{
		if (*(argz + i) == '\0')
		{	
			num++;
		}
	}

	return num;
}

error_t argz_add(char **argz, size_t *argz_len, const char *str)
{
	if (realloc(*argz, (*argz_len + strlen(str) + 1) * sizeof(char)) == NULL)
		exit(1);

	for (int i = 0; i < strlen(str) + 1; ++i)
		*(*argz + i + *argz_len) = *(str + i);

	*argz_len += strlen(str) + 1;
	return 0;
}

void argz_delete(char **argz, size_t *argz_len, char *entry)
{
	const int len = strlen(entry);

	memmove(entry, entry + (len + 1) * sizeof(char), (*argz_len - (entry - *argz + len + 1)) * sizeof(char));
	*argz_len -= len + 1;

	*argz = (char*)realloc(*argz, *argz_len * sizeof(char));
}

error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry)
{
	const int len = strlen(entry);

	if (len == 0)
		return ENOMEM;

	if (before == NULL)
	{
		if (realloc(*argz, (*argz_len + len + 1) * sizeof(char)) == NULL)
			return ENOMEM;

		for (int i = 0; i <= len; i++)
		{
			*(*argz + *argz_len + i) = *(entry + i);
		}
	}
	else
	{
		if (realloc(*argz, (*argz_len + len + 1) * sizeof(char)) == NULL)
			return ENOMEM;

		memmove(before + (len + 1) * sizeof(char), before, (*argz_len - (before - *argz)) * sizeof(char));
		
		for (int i = 0; i <= len; i++)
		{
			*(before + i) = *(entry + i);
		}
	}

	*argz_len += len + 1;

	return OK;
}

char* argz_next(char *argz, size_t argz_len, const char *entry)
{
	if (entry == NULL)
		return argz;

	for (char *ptr = entry; ptr <= argz + argz_len; ptr++)
	{
		if (ptr == argz + argz_len - 1)
		{
			return NULL;
		}
		else if (*ptr == '\0')
		{
			return ptr + 1;
		}
	}

	return NULL;
}

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with)
{
	const int len1 = strlen(str);
	const int len2 = strlen(with);

	if (len1 == 0 || len2 == 0)
		return ENOMEM;

	char *ptr = *argz, *begin = NULL;

	while (ptr < *argz + *argz_len)
	{
		begin = strstr(ptr, str);

		if (begin == NULL)
		{
			ptr += strlen(ptr) + 1;
			continue;
		}
		else break;
	}

	if (begin == NULL)
		return ENOMEM;

	if (len1 < len2)
	{
		if (realloc(*argz, (*argz_len - len1 + len2) * sizeof(char)) == NULL)
			return ENOMEM;

		memmove(begin + len2, begin + len1, *argz_len - (begin - *argz + len1) * sizeof(char));
	}
	else if (len1 > len2)
	{
		memmove(begin + len2, begin + len1, *argz_len - (begin - *argz + len1) * sizeof(char));

		if (realloc(*argz, (*argz_len - len1 + len2) * sizeof(char)) == NULL)
			return ENOMEM;
	}

	for (int i = 0; i < len2; i++)
	{
		*(begin + i) = *(with + i);
	}

	*argz_len += len2 - len1;

	return OK;
}

void argz_print(const char *argz, size_t argz_len)
{
	char *entry = NULL;
	while ((entry = argz_next(argz, argz_len, entry)))
	{
		printf("%s\n", entry);
	}
}



// void argz_delete (char **argz, size_t *argz_len, char *entry)
// {
// 	int *point = strstr(*argz, entry);

// 	if (point != NULL)
// 	{




// 		// memove(entry, entry + strlen(entry) + 1, *argz_len - strlen(entry) - 1);

// 		// printf("%d\n", *argz_len);
// 		// *argz_len -= strlen(entry);

// 		// realloc(*argz, *argz_len * sizeof(char));


// 		// int move = 0;
// 		// int pos  = 0;
// 		// for (int i = 0; i < *argz_len; ++i)
// 		// {
// 		// 	if (*(*argz + i) != *entry)
// 		// 	{
// 		// 		while (*(*argz + i) != '\0')
// 		// 			i++;
// 		// 		i++;
// 		// 	}
			
// 		// 	if (*(*argz + i) == *entry)
// 		// 	{
// 		// 		pos = i;
// 		// 		int j = 1;
// 		// 		while (*(*argz + i + j) != '\0')
// 		// 			j++;
// 		// 		move = ++j + i;
// 		// 		break;
// 		// 	}
// 		// 	i--;
// 		// }

// 		// memmove(*argz + pos, *argz + move, (*argz_len - 2) * sizeof(char));

// 		// *argz_len = *argz_len + pos - move;
// 		// // if ((*argz = (char*) realloc(*argz, *argz_len * sizeof(char))) == NULL)
// 		// // 	exit(1);
// 	}		
// }

// error_t argz_insert (char **argz, size_t *argz_len, char *before, const char *entry)
// {
// 	if (strlen(entry) == 0)
// 		return 1;

// 	int len = strlen(entry);

// 	if (NULL == before)
// 		argz_add(argz, argz_len, entry);
// 	else
// 	{
// 		for (int i = 0; i < *argz_len; ++i)
// 		{
// 			if (*(*argz + i) != *before)
// 			{
// 				while (*(*argz + i) != '\0')
// 					i++;
// 				i++;
// 			}

// 			if (*(*argz + i) == *before)
// 			{
// 				// if (realloc(*argz, (*argz_len + len + 1) * sizeof(char)) == NULL)
// 				// 	exit(1);
// 				memmove(*argz + i + len + 1, *argz + i, *argz_len - i);
// 				for (int j = 0; j < len + 1; ++j)
// 					*(*argz + i + j) = *(entry + j);
// 				*argz_len += len + 1;
// 				return 0;
// 			}
// 			i--;
// 		}
// 	}
// }

// char *  argz_next (char *argz, size_t argz_len, const char *entry)
// {
// 	if (entry == NULL)
// 		return argz;

// 	for (char *p = entry; p < argz + argz_len - 1; p++)
// 	{
// 		if (*p == '\0')
// 			return p + 1;
// 	}	
// 	return NULL;
// }

// error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with) 
// {
// 	const int lenStr  = strlen(str);
// 	const int lenWith = strlen(with);

// 	if (lenStr == 0 || lenWith == 0)
// 		return 1;

// 	char *p = *argz, *begin = NULL;

// 	while (p < *argz + *argz_len)
// 	{
// 		begin = strstr(p, str);

// 		if (begin == NULL)
// 		{
// 			p += strlen(p) + 1;
// 			continue;
// 		}
// 		else break;
// 	}

// 	if (begin == NULL)
// 		return 1;

// 	if (lenStr < lenWith)
// 	{
// 		if ((*argz = realloc(*argz, (*argz_len - lenStr + lenWith) * sizeof(char))) == NULL)
// 			return 1;

// 		memmove(begin + lenWith, begin + lenStr, *argz_len - (begin - *argz + lenStr) * sizeof(char));
// 	}
// 	else if (lenStr > lenWith)
// 	{
// 		memmove(begin + lenWith, begin + lenStr, *argz_len - (begin - *argz + lenStr) * sizeof(char));

// 		if ((*argz = realloc(*argz, (*argz_len - lenStr + lenWith) * sizeof(char))) == NULL)
// 			return 1;
// 	}

// 	for (int i = 0; i < lenWith; i++)
// 	{
// 		*(begin + i) = *(with + i);
// 	}

// 	*argz_len += lenWith - lenStr;

// return 0;	
// }