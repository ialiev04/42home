/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:42:30 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/13 19:00:56 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_atoi_2(const char *s, t_fractol *f)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (s[i] == '-')
		clean_exit(f, 1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0' && s[i] != '.')
		clean_exit(f, 1);
	return (ret);
}

static char	*skip_digits(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	return (s);
}

static void	check_exit(char s, int which, t_fractol *f)
{
	if (which == 1)
	{
		if (s != '.' && s != '\0')
			clean_exit(f, 1);
	}
	if (which == 2)
	{
		if (s != '\0')
			clean_exit(f, 1);
	}
}

static void	check_dot(char *s, t_fractol *f)
{
	if (*s == '.')
	{
		s++;
		if (*s == '\0')
			clean_exit(f, 1);
	}
}

double	ft_atof(char *s, t_fractol *f)
{
	double	res1;
	double	res2;
	int		len;
	double	norp;

	norp = 1.0;
	if (s[0] == '-')
	{
		norp = -1.0;
		s++;
	}
	check_dot(s, f);
	res1 = (double)ft_atoi_2(s, f);
	s = skip_digits(s);
	check_exit(*s, 1, f);
	if (*s == '\0')
		return (norp * res1);
	s++;
	res2 = (double)ft_atoi_2(s, f);
	len = ft_strlen(s);
	s = skip_digits(s);
	check_exit(*s, 2, f);
	while (len--)
		res2 = res2 / 10;
	return (norp * (res1 + res2));
}
