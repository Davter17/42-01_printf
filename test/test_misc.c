/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_misc.c                                        :+:      :+:    :+:   */
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
	(void)a;
	ft_printf("Hello %s, age %d", "World", 42);
}

static int	test_mix(const char *desc, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, NULL);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	printf("\n--- mixed ---\n");
	test_mix("str+int", "Hello World, age 42");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
