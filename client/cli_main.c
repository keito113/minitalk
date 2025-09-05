/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:47 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/02 15:19:12 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	print_usage(void)
{
	write(2, "[usage] client <pid> <string>\n", 30);
	return (2);
}

static int	parse_pid_str(const char *s, pid_t *out)
{
	long long	v;
	int			d;
	pid_t		p;

	if (!s || !*s)
		return (0);
	v = 0;
	while (*s)
	{
		if (!ft_isdigit((unsigned char)*s))
			return (0);
		d = *s - '0';
		if (v > LLONG_MAX / 10 || (v == LLONG_MAX / 10 && d > (int)(LLONG_MAX
					% 10)))
			return (0);
		v = v * 10 + d;
		s++;
	}
	if (v <= 1)
		return (0);
	p = (pid_t)v;
	if ((long long)p != v)
		return (0);
	*out = p;
	return (1);
}

static int	validate_args(int ac, char *av[], pid_t *pid, const char *msg[])
{
	size_t	len;

	if (ac != 3)
		return (print_usage());
	if (!av[2] || !*av[2])
	{
		write(2, "[arg] empty string\n", 19);
		return (2);
	}
	len = ft_strlen(av[2]);
	if (len > 4096)
		write(2, "[warn] msg > 4096B; server may drop old bytes\n", 46);
	if (!parse_pid_str(av[1], pid))
	{
		write(2, "[pid] invalid format/range\n", 27);
		return (3);
	}
	if (kill(*pid, 0) < 0)
	{
		write(2, "[pid] invalid or not alive\n", 28);
		return (3);
	}
	*msg = av[2];
	return (0);
}

int	main(int ac, char *av[])
{
	pid_t		pid;
	const char	*msg;
	int			code;

	code = validate_args(ac, av, &pid, &msg);
	if (code != 0)
		return (code);
	ft_printf("OK: ready to send to %d\n", (int)pid);
	(void)msg;
	return (0);
}
