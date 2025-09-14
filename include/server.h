/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:43:58 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/14 13:43:35 by keitabe          ###   ########.fr       */
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

typedef enum m_srv
{
	BIT0_SIG = SIGUSR1,
	BIT1_SIG = SIGUSR2,
	ACK_SIG = BIT0_SIG,
	ACK0_SIG = SIGUSR1,
	ACK1_SIG = SIGUSR2,
	HAVE_BYTE = 1u << 0,
	GOT_NUL = 1u << 1

}							t_m_srv;

typedef struct s_srv
{
	volatile sig_atomic_t	flag;
	pid_t					sender;
	unsigned char			cur;
	int						bit_idx;
	volatile sig_atomic_t	mb;
	volatile sig_atomic_t	mb_full;
}							t_srv;

extern t_srv				*g_srv;

#endif
