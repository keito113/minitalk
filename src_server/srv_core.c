/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 08:12:14 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/18 13:41:58 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_srv	g_srv;

void	srv_push(unsigned char b)
{
	volatile sig_atomic_t	next;

	next = (g_srv.head + 1) & RMASK;
	if (next == g_srv.tail)
		g_srv.tail = (g_srv.tail + 1) & RMASK;
	g_srv.buf[g_srv.head] = b;
	g_srv.head = next;
	if (b == '\0')
		g_srv.sender = 0;
}

void	srv_handle(int sig, siginfo_t *si, void *u)
{
	(void)u;
	if (g_srv.sender == 0)
		g_srv.sender = si->si_pid;
	if (si->si_pid != g_srv.sender)
	{
		if (kill(g_srv.sender, 0) == 0)
			return ;
		g_srv.cur = 0;
		g_srv.bit_idx = 0;
		g_srv.sender = si->si_pid;
	}
	g_srv.cur = (g_srv.cur << 1) + (sig == BIT1_SIG);
	g_srv.bit_idx++;
	if (g_srv.bit_idx & 1)
		kill(g_srv.sender, ACK1_SIG);
	else
		kill(g_srv.sender, ACK0_SIG);
	if (g_srv.bit_idx != 8)
		return ;
	srv_push(g_srv.cur);
	g_srv.cur = 0;
	g_srv.bit_idx = 0;
}

void	srv_loop(void)
{
	unsigned char	c;

	while (1)
	{
		if (g_srv.head == g_srv.tail)
		{
			pause();
			continue ;
		}
		c = g_srv.buf[g_srv.tail];
		g_srv.tail = (g_srv.tail + 1) & RMASK;
		if (c == '\0')
		{
			write(1, "\n", 1);
			g_srv.sender = 0;
		}
		else
			write(1, &c, 1);
	}
}
