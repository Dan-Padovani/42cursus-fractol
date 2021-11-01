#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
    printf("%d\n", i);
	return (s1[i] - s2[i]);
}

int main(void)
{
    char    str1[] = "banana";
    char    str2[] = "banana";

    printf("%d\n\n", ft_strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str2));
}

