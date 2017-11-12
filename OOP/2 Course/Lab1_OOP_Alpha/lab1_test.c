#include "forlab1.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *argz;
	size_t argz_len;

	if (argz_create_sep("kekos;lolos;oru", ';', &argz, &argz_len) == OK)
	{
		printf("(argz_create_sep('kekos;lolos;oru', ';', &argz, &argz_len):\n");
		for (int i = 0; i < argz_len; ++i)
		{
			if (*(argz + i) == '\0')
				printf("\\0\n");
			else
				printf("%c", *(argz + i));
		}
		printf("\n");

		printf("argz_count(argz, argz_len): %d\n\n", argz_count(argz, argz_len));

		printf("argz_add (&argz, &argz_len, 'oslole'):\n");
		argz_add(&argz, &argz_len, "oslole");
		for (int i = 0; i < argz_len; ++i)
		{
			if (*(argz + i) == '\0')
				printf("\\0\n");
			else
				printf("%c", *(argz + i));
		}
		printf("argz_len = %d\n\n", argz_len);

		printf("argz_delete (&argz, &argz_len, argz + 6):\n");
		argz_delete(&argz, &argz_len, argz + 6);
		for (int i = 0; i < argz_len; ++i)
		{
			if (*(argz + i) == '\0')
				printf("\\0\n");
			else
				printf("%c", *(argz + i));
		}
		printf("argz_len = %d\n\n", argz_len);

		printf("argz_insert(&argz, &argz_len, argz + 2, 'please'):\n");
		argz_insert(&argz, &argz_len, argz + 2, "please");
		for (int i = 0; i < argz_len; ++i)
		{
			if (*(argz + i) == '\0')
				printf("\\0\n");
			else
				printf("%c", *(argz + i));
		}
		printf("argz_len = %d\n\n", argz_len);

		printf("argz_next: \n");
		for (char *entry = argz; entry; entry = argz_next(argz, argz_len, entry))
			printf("%s\n", entry);
		printf("\n");

		printf("argz_replace(&argz, &argz_len, 'oslole', 'ura'):\n");
		argz_replace(&argz, &argz_len, "oslole", "ura");
		for (int i = 0; i < argz_len; ++i)
		{
			if (*(argz + i) == '\0')
				printf("\\0\n");
			else
				printf("%c", *(argz + i));
		}
		printf("argz_len = %d\n\n", argz_len);

		printf("argz_print(argz, argz_len):\n");
		argz_print(argz, argz_len);
	}

	return 0;
}