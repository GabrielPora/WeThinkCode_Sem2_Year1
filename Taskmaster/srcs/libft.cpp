/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:04 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

/*
** ------------------------------\
** Functions extracted from libft |
** ------------------------------/
*/

/*
** ft_putstr_fd
*/

void		ft_putstr_fd(char const *s, int fd)
{
	int	k;

	k = 0;
	while (s[k] != '\0')
		k++;
	write(fd, s, k);
}

/*
** ft_putstr_fd
*/
void		ft_putstr(const char *s) {
	ft_putstr_fd(s, 1);
}

/*
** ft_putnbr_fd
*/

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		k;

	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	k = 1;
	while (n % k != n)
		k = 10 * k;
	while (n > 0)
	{
		c = (n / (k / 10)) + '0';
		n = n - ((n / (k / 10)) * (k / 10));
		k = k / 10;
		write(fd, &c, 1);
	}
}

/*
** ft_strsub
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	k;

	k = start;
	if (s == NULL || len == 0)
		return (NULL);
	temp = (char *)malloc((unsigned int)len);
	while ((k < len + start) && s[k] != '\0')
	{
		temp[k - start] = s[k];
		k++;
	}
	temp[k] = '\0';
	return (temp);
}

/*
** ft_strnew
*/

char		*ft_strnew(size_t size)
{
	char	*temp;
	size_t	k;

	temp = (char *)malloc((unsigned int)size + 1);
	k = 0;
	while (k <= size)
	{
		temp[k] = '\0';
		k++;
	}
	return (temp);
}

/*
** ft_strdup
*/

char		*ft_strdup(const char *s1)
{
	size_t	k;
	char	*copy;

	k = 0;
	while (s1[k] != '\0')
		k++;
	if (!(copy = ft_strnew((unsigned int)k + 1)))
		return (NULL);
	while (k > 0)
	{
		copy[k] = s1[k];
		k--;
	}
	*copy = *s1;
	return (copy);
}

/*
** ft_strchr
*/

char		*ft_strchr(const char *s, int c)
{
	char	*k;

	k = (char *)s;
	while (*k != c)
	{
		if (*k == '\0')
			return (NULL);
		k++;
	}
	return (k);
}

/*
** ft_strsplit
*/

static int	ft_tab_count(const char *str, char c)
{
	int		k;

	k = 1;
	while (str)
	{
		str = ft_strchr(str, c);
		while (str && *str == c)
			++str;
		if (!str || !*str)
			return (k);
		k++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		k;
	char	*tmp;
	char	**result;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!*s)
		return ((char **)ft_strnew(sizeof(char *)));
	k = ft_tab_count(s, c) + 1;
	arr = (char **)ft_strnew((k) * sizeof(char *));
	result = arr;
	while (--k)
	{
		tmp = ft_strchr(s, c);
		if (!tmp && (*(arr++) = ft_strdup(s)))
			break ;
		*(arr++) = ft_strsub(s, 0, tmp - s);
		while (*tmp == c)
			++tmp;
		s = tmp;
	}
	return (result);
}

/*
** ft_itoa_base
*/

static void	neg_case(char **str, unsigned int *k, long int *num, int base)
{
	if (*num < 0)
	{
		*num *= -1;
		if (base == 10)
		{
			*str[*k] = '-';
			(*k)++;
		}
	}
}

char		*ft_itoa_base(int value, int base)
{
	long int		num;
	long int		l;
	unsigned int	k;
	long int		ba;
	char			*str;
	string			bas = "0123456789ABCDEF";
	static char 	*b;

	num = value;
	ba = base;
	b = (char *)bas.c_str();
	k = 0;
	l = 1;
	if ((str = (char *)malloc(40)) == NULL)
		return (NULL);
	if (base < 2 || base > 16)
		return (NULL);
	neg_case(&str, &k, &num, base);
	while ((num / (l)) >= base)
		l *= base;
	while (l > 0)
	{
		str[k] = b[((num / l) % ba)];
		num -= (num / l) * l;
		k++;
		if (l == 1)
			l = 0;
		l = l / base;
	}
	str[k] = '\0';
	return (str);
}

/*
** ft_itoa
*/

char		*ft_itoa(int value)
{
	return (ft_itoa_base(value, 10));
}

/*
** ft_strjoin
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		k;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	temp = ft_strnew(strlen(s1) + strlen(s2) + 1);
	k = -1;
	while (*s1)
		temp[++k] = *(s1++);
	while (*s2)
		temp[++k] = *(s2++);
	return (temp);
}

/*
** ------------------------------\
** New Functions for the project  |
** ------------------------------/
*/

/*
** print_2d
*/

void	print_2d(char **sa)
{
	int		i;

	i = 0;
	while (sa[i])
	{
		ft_putstr_fd(sa[i++], 1);
		ft_putstr_fd("\n", 1);
	}
}


int			ft_is_all_print(char *str) {
	int			k = -1;

	while (str[++k])
		if (!isprint(str[k]))
			return (0);
	return (1);
}

void		print_fd(string str, int fd) {
	const char	*s = str.c_str();
	write(fd, s, str.length());
}

void		print(string str) {
	print_fd(str, 1);
}
