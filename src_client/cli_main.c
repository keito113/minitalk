/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:47 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/16 08:14:37 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_flag;

static int	cli_send(pid_t srv, const char *s)
{
	struct sigaction	sa;
	size_t				i;
	int					rc;

	g_flag = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, BIT0_SIG);
	sigaddset(&sa.sa_mask, BIT1_SIG);
	sa.sa_sigaction = ack_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(ACK0_SIG, &sa, NULL) < 0)
		return (5);
	if (sigaction(ACK1_SIG, &sa, NULL) < 0)
		return (5);
	i = 0;
	while (1)
	{
		rc = cli_tx_byte(srv, (unsigned char)s[i]);
		if (rc != 0)
			return (rc);
		if (s[i++] == '\0')
			return (0);
	}
}

int	main(int ac, char **av)
{
	const char	*p;
	long		acc;
	int			r;

	if (ac != 3)
		return (2);
	p = av[1];
	acc = 0;
	while (*p)
	{
		if ((*p < '0' || *p > '9') || acc > (INT_MAX - (*p - '0')) / 10)
			return (3);
		acc = acc * 10 + (*p - '0');
		p++;
	}
	if (acc <= 1 || kill((pid_t)acc, 0) < 0)
		return (3);
	r = cli_send((pid_t)acc, av[2]);
	if (r == 0)
		write(1, "ACK received\n", 13);
	return (r);
}
