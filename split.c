#include <stdlib.h>

int     word_len(char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
        i++;
    return (i);
}

char *word_dup(char *str)
{
    int i;
    int len;
    char *word;

    i = 0;
    len = word_len(str);
    word = malloc(sizeof(char) * len+1);
    word[len] = '\0';
    while(i < len)
    {
        word[i] = str[i];
        i++;
    }
    return (word);
}

void    fill_word(char **array, char *str)
{
    int word_index;

    word_index = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    while(*str)
    {
        array[word_index] = word_dup(str);
        word_index++;
        while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
            str++;
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
    }
}

int word_count(char *str)
{
    int i;

    i = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    while(*str)
    {
        i++;
        while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
    }
    return (i);
}


char    **ft_split(char *str)
{
    int num_word;
    char **array;

    num_word = word_count(str);
    array = malloc (sizeof(char *) * (num_word + 1));
    array[num_word] = 0;
    fill_word(array, str);
    return(array);
  
}

 #include <stdio.h>

 int		main(void)
 {
 	 char test[] = "\njrS58VHQ	\n   	p70fL		Kx2sRP0So3E4rC9  \n nebpv3J5ousO84Pa1HjUQOImUhjwZpGn	\n \n	X28iT7Ap9 	DIYAF9ZSpKcs0Rcv\n uzO\n		\nZ7zjEeonALOKQF5xq	\n   \nQxp0b1ufFKGJ	\n2n8R9zUvZEtOwmqf\n	";
 	//char test[] = "DIYAF9ZSpKcs0Rcv \n uzO\n		\nZ7zjEeonALOKQF5xq	\n   \nQxp0b1ufFKGJ	\n2n8R9zUvZEtOwmqf\n	";

 	char **arr = ft_split(test);

 	int i = 0;
 	while (arr[i] != 0)
 	{
 		printf("[%s]\n", arr[i]);
 		++i;
 	}
 }
