#include <stdio.h>
#include <malloc.h>
#include "lab4.h"
#define MAX_STR_LEN 100
#define STR_MAX_STR_LEN "100"

char *my_readline(char *promt)
{
	if(promt!=NULL)
	{
		printf("%s", promt);	
	}
	char *result = calloc(MAX_STR_LEN, sizeof(char));
	int v = scanf("%" STR_MAX_STR_LEN "s", result);
	if(v!=1)
	{
		free(result);
		return NULL;
	}
	return result;
}

char *my_index(char *str, char c)
{
	for(;*str;str++)
	{
		if(*str==c)
		{
			return str;
		}
	}
	return NULL;
}

int my_len(const char *st)
{
    char c = st[0];
    int i = 0;
    while (c != 0){
        i ++;
        c = st[i];
    }
    return i;
}
char *my_strdup(char *s_in){
    if (s_in==NULL){
        return NULL;
    }

    int mylen=my_len(s_in);
    char *s2=malloc(mylen+1);
    char *res=s2;
    while (*s_in){
        *s2++=*s_in++;
    }
    *s2='\0';
    return res;
}

char *max_trim(char* inp){
    char *src=inp,*dst=inp;
    int flag=0;
    while(*src){
        if (*src==' '|| *src=='\t'){
            flag=1;
            src++;
            continue;
        }
        if (flag!=0){
            if (dst!=inp){
                *dst++=' ';
            }
            flag=0;
        }
        *dst++=*src++;
    }
    *dst='\0';
    if (src==dst){
        return inp;
    }
    char *res=my_strdup(inp);
    free(inp);
    return res;
}
