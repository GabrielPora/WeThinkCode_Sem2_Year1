#include "../includes/scop.h"

char	*trim_start(char *str)
{
	int		k;

	k = 0;
	while (str[k] == ' ' || str[k] == '\t')
		k++;
	if (k > 0)
	{
		str = ft_strcpy(str, &str[k]);
		str[ft_strlen(str) - k] = '\0';
	}
	return (str);
}

void	trim_end(char *str)
{
	int		k;

	if (str == NULL)
		return ;
	k = ft_strlen(str) - 1;
	while (k >= 0 && (str[k] == ' ' || k == '\t'))
		k--;
	if (str[k] && str[k + 1] &&
			(str[k + 1] == ' ' || str[k + 1] == '\t'))
		str[k + 1] = '\0';
}

int		trim_tabs(char *line)
{
	int		k;

	k = -1;
	if (!line || ! *line)
		return (-1);
	while (line[++k])
		if (line[k] == '\t')
			line[k] = ' ';
	return (k);
}

void	trim_str(char *str)
{
	if (str == NULL || *str == '\0')
		return ;
	trim_tabs(str);
	trim_start(str);
}
