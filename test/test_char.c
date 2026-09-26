/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
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
	ft_printf("%c", (char)(long)a);
}

static int	test_c(const char *desc, char c, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, (void *)(long)c);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	printf("\n--- %%c ---\n");
	test_c("A", 'A', "A");
	test_c("0", '0', "0");
	test_c("space", ' ', " ");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
