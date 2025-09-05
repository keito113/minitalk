/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:17:12 by keitabe           #+#    #+#             */
/*   Updated: 2025/06/25 17:46:29 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	format_handles(va_list *ap, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += handle_c(ap);
	else if (format == '%')
		len += handle_percent(ap);
	else if (format == 'x')
		len += handle_hex_low(ap);
	else if (format == 'X')
		len += handle_hex_up(ap);
	else if (format == 'd' || format == 'i')
		len += handle_d_i(ap);
	else if (format == 'u')
		len += handle_u(ap);
	else if (format == 's')
		len += handle_s(ap);
	else if (format == 'p')
		len += handle_p(ap);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		tmp;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			tmp = format_handles(&ap, *str);
			if (tmp < 0)
				len += putchar_len('%') + putchar_len(*str);
			else
				len += tmp;
		}
		else
			len += putchar_len(*str);
		str++;
	}
	va_end(ap);
	return (len);
}

// #include "ft_printf.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		var;
// 	char	*test23;

// 	int r1, r2;
// 	var = 42;
// 	printf("Test 1: %%c 'A'\n");
// 	printf("orig: ");
// 	r1 = printf("%c", 'A');
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%c", 'A');
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 2: %%c 256\n");
// 	printf("orig: ");
// 	r1 = printf("%c", 256);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%c", 256);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 3: %%%% literal\n");
// 	printf("orig: ");
// 	r1 = printf("%%");
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%%");
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 4: %%s \"Hello, world!\"\n");
// 	printf("orig: ");
// 	r1 = printf("%s", "Hello, world!");
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%s", "Hello, world!");
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 5: %%s empty string\n");
// 	printf("orig: ");
// 	r1 = printf("%s", "");
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%s", "");
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 6: %%s NULL\n");
// 	printf("orig: ");
// 	r1 = printf("%s", (char *)NULL);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%s", (char *)NULL);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 7: %%p &var\n");
// 	printf("orig: ");
// 	r1 = printf("%p", (void *)&var);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%p", (void *)&var);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 8: %%p NULL\n");
// 	printf("orig: ");
// 	r1 = printf("%p", (void *)0);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%p", (void *)0);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 9: %%d 0\n");
// 	printf("orig: ");
// 	r1 = printf("%d", 0);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%d", 0);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 10: %%i 42\n");
// 	printf("orig: ");
// 	r1 = printf("%i", 42);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%i", 42);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 11: %%d -42\n");
// 	printf("orig: ");
// 	r1 = printf("%d", -42);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%d", -42);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 12: %%d INT_MAX\n");
// 	printf("orig: ");
// 	r1 = printf("%d", INT_MAX);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%d", INT_MAX);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 13: %%i INT_MIN\n");
// 	printf("orig: ");
// 	r1 = printf("%i", INT_MIN);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%i", INT_MIN);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 14: %%u 0u\n");
// 	printf("orig: ");
// 	r1 = printf("%u", 0u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%u", 0u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 15: %%u 123456789u\n");
// 	printf("orig: ");
// 	r1 = printf("%u", 123456789u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%u", 123456789u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 16: %%u UINT_MAX\n");
// 	printf("orig: ");
// 	r1 = printf("%u", UINT_MAX);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%u", UINT_MAX);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 17: %%x 0u\n");
// 	printf("orig: ");
// 	r1 = printf("%x", 0u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%x", 0u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 18: %%x 48879u (0xBEEF)\n");
// 	printf("orig: ");
// 	r1 = printf("%x", 48879u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%x", 48879u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 19: %%X 48879u (0xBEEF)\n");
// 	printf("orig: ");
// 	r1 = printf("%X", 48879u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%X", 48879u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 20: %%x %%X UINT_MAX\n");
// 	printf("orig: ");
// 	r1 = printf("%x %X", UINT_MAX, UINT_MAX);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("%x %X", UINT_MAX, UINT_MAX);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 21: Mix all specifiers\n");
// 	printf("orig: ");
// 	r1 = printf("Mix:%c%s%p%d%u%x%X%%", 'A', "Hi", (void *)&var, -1, 1u, 255u,
// 			255u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("Mix:%c%s%p%d%u%x%X%%", 'A', "Hi", (void *)&var, -1, 1u,
// 			255u, 255u);
// 	printf(" | ret=%d\n\n", r2);
// 	printf("Test 22: %%c NULL\n");
// 	printf("orig: ");
// 	r1 = printf(NULL);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf(NULL);
// 	printf(" | ret=%d\n\n", r2);
// 	test23 = 0;
// 	printf("Test 23: Mix all specifiers\n");
// 	printf("orig: ");
// 	r1 = printf("Mix:%c%s%p%d%u%x%X%%", 'A', test23, (void *)&var, -1, 1u, 255u,
// 			255u);
// 	printf(" | ret=%d\n", r1);
// 	ft_printf("ft :  ");
// 	r2 = ft_printf("Mix:%c%s%p%d%u%x%X%%", 'A', test23, (void *)&var, -1, 1u,
// 			255u, 255u);
// 	printf(" | ret=%d\n", r2);
// 	return (0);
// }
