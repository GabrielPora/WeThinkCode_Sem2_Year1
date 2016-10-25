#include <stdlib.h>
#include <unistd.h>

void	rules(void);
char	done(void);
void	trues(void);
void	display(void);

char	a = -2;
char	b = -2;
char	c = -2;
char	d = -2;
char	e = -2;
char	f = -2;
char	g = -2;
char	h = -2;
char	i = -2;
char	j = -2;
char	k = -2;
char	l = -2;
char	m = -2;
char	n = -2;
char	o = -2;
char	p = -2;
char	q = -2;
char	r = -2;
char	s = -2;
char	t = -2;
char	u = -2;
char	v = -2;
char	w = -2;
char	x = -2;
char	y = -2;
char	z = -2;

void	error_quit(char e)
{
	if (e == 1)
		write(1, "Error: variable already set.\n", 30);
	else if (e == 2)
		write(1, "Error: contradicting statement.\n", 32);
	exit(1);
}

void	set_var(char *var, char val)
{
	if (*var != 0 && *var != 1)
		*var = val;
	else if ((*var == 0 && val) || (*var == 1 && !val))
		error_quit(1); 
}

void	set_or_case(char *var1, char *var2, char val1, char val2)
{
	if ((*var1 == 0 && val1) || (*var1 == 1 && !val1))
		set_var(var2, val2);
	else if ((*var2 == 0 && val2) || (*var2 == 1 && !val2))
		set_var(var1, val1);
	else if (((*var1 == 0 && val1) || (*var1 == 1 && !val1)) &&
			((*var2 == 0 && val2) || (*var2 == 1 && !val2)))
		error_quit(2);
}

void	set_and_case(char *var1, char *var2, char val1, char val2)
{
	set_var(var1, val1);
	set_var(var2, val2);
}

void	set_xor_case(char *var1, char *var2, char val1, char val2)
{
	if ((*var1 == 1 && val1) || (*var1 == 0 && !val1))
		set_var(var2, val2);
	else if ((*var2 == 1 && val2) || (*var2 == 0 && !val2))
		set_var(var1, val1);
	else if (((*var1 == 1 && val1) || (*var1 == 0 && !val1)) &&
			((*var2 == 0 && val2) || (*var2 == 1 && !val2)))
		error_quit(2);
	else if (((*var2 == 1 && val2) || (*var2 == 0 && !val2)) &&
			((*var1 == 0 && val1) || (*var1 == 1 && !val1)))
		error_quit(2);
}

int		main()
{
	int		count;

	count = 0;
	trues();
	while (count < 9 && done())
	{
		rules();
		count++;
	}
	display();
}

char	done(void)
{
	if (g != 0 && g != 1)
		return (1);
	if (v != 0 && v != 1)
		return (1);
	if (x != 0 && x != 1)
		return (1);
	return (0);
}

void	trues(void)
{
	a = 3;
	b = 3;
	g = 3;
}

void	rules(void)
{
	if ((v > 0) ^ (w > 0))
		set_var(&x, 1);
	if ((c > 0) || (d > 0))
		set_or_case(&x, &v, 1, 1);
	if ((e > 0) && (f > 0))
		set_var(&v, 0);
	if ((a > 0) && (b > 0))
		set_var(&c, 1);
	if ((c > 0))
		set_and_case(&a, &b, 1, 1);
	if ((c > 0))
		set_var(&e, 1);
	if ((a > 0) && (b > 0) && (c > 0))
		set_var(&d, 1);
	if ((a > 0) || (b > 0))
		set_var(&c, 1);
	if ((a > 0) && !(b > 0))
		set_var(&f, 1);
}

void	display(void)
{
	if (g > 0)
		write(1, "g is true.\n", 11);
	else
		write(1, "g is false.\n", 12);
	if (v > 0)
		write(1, "v is true.\n", 11);
	else
		write(1, "v is false.\n", 12);
	if (x > 0)
		write(1, "x is true.\n", 11);
	else
		write(1, "x is false.\n", 12);
}

