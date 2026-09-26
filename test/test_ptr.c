/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptr.c                                         :+:      :+:    :+:   */
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
	ft_printf("%p", a);
}

static int	test_p(const char *desc, void *p, const char *exp)
{
	char	buf[4096];

	capture_ft(buf, sizeof(buf), call, p);
	return (check(strcmp(buf, exp) == 0, desc));
}

int	main(void)
{
	void	*null_ptr;

	null_ptr = NULL;
	printf("\n--- %%p ---\n");
	test_p("NULL", null_ptr, "(nil)");
	test_p("zero", (void *)0, "(nil)");
	printf("\033[32m  PASS: %d\033[0m\n", g_pass);
	printf("\033[31m  FAIL: %d\033[0m\n", g_fail);
	if (g_fail > 0)
		return (1);
	return (0);
}
