/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:19:28 by keitabe           #+#    #+#             */
/*   Updated: 2025/09/05 10:28:54 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_srv
{
	volatile sig_atomic_t	flag;
	pid_t					sender;
	unsigned char			cur;
	int						bit_idx;
	unsigned char			mb;
	sig_atomic_t			mb_full;
}							t_srv;


#endif
