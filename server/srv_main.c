/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:28:13 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/05 10:43:38 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	srv_handle_bit(int sig, siginfo_t *si, void *u)
{
	int		bit;
	pid_t	spid;
	t_srv g_srv;

	if (sig == SIGUSR2)
		bit = 1;
	else
		bit = 0;
	g_srv = 
	spid = si->si_pid;
}

void	srv_setup_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = srv_handle_bit();
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("server PID: %d\n", (int)pid);
	while (1)
		pause();
	return (0);
}
