/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

static void	call(void *a)
{
	ft_printf("%s", (char *)a);
}

static int	test_s(const char *desc, char *s, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, s);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	char	*null_str;

	null_str = NULL;
	printf("\n--- %%s ---\n");
	test_s("hello", "hello", "hello");
	test_s("empty", "", "");
	test_s("NULL", null_str, "(null)");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
