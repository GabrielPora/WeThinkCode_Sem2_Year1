#include "../includes/scop.h"

static size_t	ft_len_untill(const char *str, char c)
{
	size_t	k;
	
	k = 0;
	if (!str)
		return (0);
	while (str[k] != c && str[k] != '\0')
		++k;
	return (k);
}

float			ft_atof(const char *str)
{
	float	result;
	int		i;

	result = (float)ft_atoi(str);
	i = ft_len_untill(str, '.');
	if (i && str[i])
	{
		if (result >= 0 && str[0] != '-')
			result += ((float)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
		else
			result -= ((float)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
	}
	return (result);
}