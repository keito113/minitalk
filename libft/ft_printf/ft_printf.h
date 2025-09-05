/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:02:48 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/15 16:26:53 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	handle_c(va_list *ap);
int	handle_percent(va_list *ap);
int	handle_hex_low(va_list *ap);
int	handle_hex_up(va_list *ap);
int	handle_d_i(va_list *ap);
int	handle_u(va_list *ap);
int	handle_s(va_list *ap);
int	handle_p(va_list *ap);

#endif
