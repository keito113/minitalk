/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:46:11 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/09 17:39:45 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_srv	*g_srv;

static void	srv_handle(int sig, siginfo_t *si, void *u)
{
	pid_t	spid;

	(void)u;
	spid = si->si_pid;
	if (g_srv->sender == 0)
		g_srv->sender = spid;
	else if (spid != g_srv->sender)
	{
		g_srv->cur = 0;
		g_srv->bit_idx = 0;
		g_srv->sender = spid;
	}
	g_srv->cur <<= 1;
	if (sig == BIT1_SIG)
		g_srv->cur |= 1;
	g_srv->bit_idx++;
	if (g_srv->bit_idx == 8)
	{
		g_srv->mb = g_srv->cur;
		g_srv->mb_full = 1;
		g_srv->cur = 0;
		g_srv->bit_idx = 0;
		kill(g_srv->sender, ACK_SIG);
		g_srv->flag |= HAVE_BYTE | ((g_srv->mb == '\0') * GOT_NUL);
	}
}

static void	srv_setup_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, BIT0_SIG);
	sigaddset(&sa.sa_mask, BIT1_SIG);
	sa.sa_sigaction = srv_handle;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(BIT0_SIG, &sa, NULL) < 0 || sigaction(BIT1_SIG, &sa,
			NULL) < 0)
	{
		write(2, "[internal] sigaction failed\n",
			ft_strlen("[internal] sigaction failed\n"));
		exit(5);
	}
}

static void	srv_loop(void)
{
	unsigned char	c;

	while (1)
	{
		if (!g_srv->mb_full)
			pause();
		if (!g_srv->mb_full)
			continue ;
		c = (unsigned char)g_srv->mb;
		g_srv->mb_full = 0;
		g_srv->flag &= ~HAVE_BYTE;
		if (c == '\0')
		{
			g_srv->flag &= ~GOT_NUL;
			write(1, "\n", 1);
			g_srv->sender = 0;
		}
		else
			write(1, &c, 1);
	}
}

int	main(void)
{
	g_srv = (t_srv *)malloc(sizeof(*g_srv));
	if (!g_srv)
	{
		write(1, "[internal] malloc failed\n", 25);
		exit(5);
	}
	g_srv->flag = 0;
	g_srv->sender = 0;
	g_srv->cur = 0;
	g_srv->bit_idx = 0;
	g_srv->mb = 0;
	g_srv->mb_full = 0;
	ft_printf("server PID: %d\n", (int)getpid());
	srv_setup_handlers();
	srv_loop();
	free(g_srv);
	return (0);
}
