/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:46:11 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/16 08:13:49 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_srv		*g_srv;

static void	srv_setup_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, BIT0_SIG);
	sigaddset(&sa.sa_mask, BIT1_SIG);
	sa.sa_sigaction = srv_handle;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(BIT0_SIG, &sa, NULL) < 0 || sigaction(BIT1_SIG, &sa,
			NULL) < 0)
	{
		write(2, "[internal] sigaction failed\n",
			ft_strlen("[internal] sigaction failed\n"));
		exit(5);
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
	g_srv->head = 0;
	g_srv->tail = 0;
	g_srv->sender = 0;
	g_srv->cur = 0;
	g_srv->bit_idx = 0;
	ft_printf("server PID: %d\n", (int)getpid());
	srv_setup_handlers();
	srv_loop();
	free(g_srv);
	return (0);
}
