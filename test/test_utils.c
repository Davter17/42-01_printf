/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/15 10:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int	g_pass = 0;
int	g_fail = 0;

int	check(int ok, const char *name)
{
	if (ok)
	{
		printf("  \033[32mPASS\033[0m %s\n", name);
		g_pass++;
		return (0);
	}
	printf("  \033[31mFAIL\033[0m %s\n", name);
	g_fail++;
	return (1);
}

void	capture_ft(char *buf, int size, void (*f)(void *), void *a)
{
	int		p[2];
	pid_t	pid;
	int		ret;

	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
		f(a);
		close(1);
		exit(0);
	}
	close(p[1]);
	ret = read(p[0], buf, size - 1);
	if (ret > 0)
		buf[ret] = '\0';
	else
		buf[0] = '\0';
	close(p[0]);
	waitpid(pid, NULL, 0);
}
