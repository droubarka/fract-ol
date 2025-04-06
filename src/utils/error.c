
#include "utils.h"

void	error(const char *errmsg)
{
	write(2, errmsg, ft_strlen(errmsg));
	exit(EXIT_FAILURE);
}

void	usage_error(int nargs)
{
	const char	*errmsg;

	if (nargs <= 4)
	{
		errmsg = \
		"./fractol: missing operand\n" \
		"Try './fractol --help' for more information.\n";
	}
	else
	{
		errmsg = \
		"./fractol: too many arguments\n" \
		"Try './fractol --help' for more information.\n";
	}
	error(errmsg);
}

