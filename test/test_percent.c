/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
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
	ft_printf((const char *)a);
}

static int	test_one(const char *desc, const char *fmt, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, (void *)fmt);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	printf("\n--- %% ---\n");
	test_one("percent", "%%", "%");
	test_one("100%%", "100%%", "100%");
	test_one("%%%%", "%%%%", "%%");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
