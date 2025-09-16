/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:43:04 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/16 08:14:23 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define _POSIX_C_SOURCE 200809L

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef enum e_srv
{
	BIT0_SIG = SIGUSR1,
	BIT1_SIG = SIGUSR2,
	ACK_SIG = BIT0_SIG,
	ACK0_SIG = SIGUSR1,
	ACK1_SIG = SIGUSR2,
	ACK_WAIT_US = 300000,
	ACK_RETRY_MAX = 5,
	ACK_TMO_MS = 300,
	TICK_US = 100,
	ACK_TICKS = ACK_WAIT_US / TICK_US,
	EX_PID = 3,
	EX_TIMEOUT = 4
}								t_e_srv;

extern volatile sig_atomic_t	g_flag;

void							ack_handler(int sig, siginfo_t *si, void *u);
int								cli_send_and_wait(pid_t srv, int sigv, int exp);
int								cli_tx_byte(pid_t srv_pid, unsigned char c);

#endif
