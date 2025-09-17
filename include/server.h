/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:43:58 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/18 08:45:17 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _POSIX_C_SOURCE 200809L

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef enum e_srv
{
	BIT0_SIG = SIGUSR1,
	BIT1_SIG = SIGUSR2,
	ACK0_SIG = SIGUSR1,
	ACK1_SIG = SIGUSR2,
	RBUFSZ = 4096,
	RMASK = (RBUFSZ - 1)
}							t_e_srv;

typedef struct s_srv
{
	pid_t					sender;
	unsigned char			cur;
	unsigned char			buf[4096];
	volatile sig_atomic_t	head;
	volatile sig_atomic_t	tail;
	int						bit_idx;
}							t_srv;

extern t_srv				*g_srv;

void						srv_push(unsigned char b);
void						srv_handle(int sig, siginfo_t *si, void *u);
void						srv_loop(void);

#endif
