/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"
#include <limits.h>

static void	call(void *a)
{
	ft_printf("%d", (int)(long)a);
}

static int	test_i(const char *desc, int n, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, (void *)(long)n);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	printf("\n--- %%d ---\n");
	test_i("positive", 42, "42");
	test_i("negative", -42, "-42");
	test_i("zero", 0, "0");
	test_i("INT_MAX", INT_MAX, "2147483647");
	test_i("INT_MIN", INT_MIN, "-2147483648");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
