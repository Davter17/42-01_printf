/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned.c                                    :+:      :+:    :+:   */
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
	ft_printf("%u", (unsigned int)(long)a);
}

static int	test_u(const char *desc, unsigned int n, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, (void *)(long)n);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	printf("\n--- %%u ---\n");
	test_u("positive", 42, "42");
	test_u("zero", 0, "0");
	test_u("UINT_MAX", 4294967295u, "4294967295");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
