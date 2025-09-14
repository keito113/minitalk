/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:57:47 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/14 14:54:07 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_flag;

static void	ack_handler(int sig, siginfo_t *si, void *u)
{
	(void)u;
	(void)si;
	if (sig == ACK0_SIG)
		g_flag = 0;
	else if (sig == ACK1_SIG)
		g_flag = 1;
}

static int	cli_send_and_wait(pid_t srv, int sigv, int exp)
{
	int	retry;
	int	t;

	retry = 0;
	while (retry <= ACK_RETRY_MAX)
	{
		g_flag = 2;
		if (kill(srv, sigv) == -1)
			return (EX_PID);
		t = 0;
		while (t < ACK_TMO_MS)
		{
			if (g_flag == exp)
				return (0);
			usleep(TICK_US);
			t++;
		}
		retry++;
	}
	return (EX_TIMEOUT);
}

static int	cli_tx_byte(pid_t srv_pid, unsigned char c)
{
	int	i;
	int	sigv;
	int	rc;
	int	k;
	int	exp;

	i = 7;
	while (i >= 0)
	{
		k = 7 - i;
		if ((k & 1) == 0)
			exp = 1;
		else
			exp = 0;
		if (((c >> i) & 1) != 0)
			sigv = BIT1_SIG;
		else
			sigv = BIT0_SIG;
		rc = cli_send_and_wait(srv_pid, sigv, exp);
		if (rc != 0)
			return (rc);
		i--;
	}
	return (0);
}

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
	return (cli_send((pid_t)acc, av[2]));
}
