#include <stdio.h>
#include <malloc.h>
#include <readline/readline.h>
#include "lab4.h"

char *letters = "eEyYuUiIoOAa";

char *per_task(char *s)
{
	if(!s)
	{
		fprintf(stderr, "No String Entered\n");
		return NULL;
	}
	int lcount = 0;

	for(int i = 0; s[i]; i++)
	{
		if(index(letters, s[i]))
		{
			lcount++;
		}
		lcount++;
	}

	char *s2 = malloc(lcount+1);
	char *s01 = s;
	char *s21 = s2;

	for(; *s01; s01++)
	{
		*s21++ = *s01;
		if(index(letters, *s01))
		{
			*s21++ = *s01;
		}
	}
	
	*s21 = '\0';
	return s2;
}
