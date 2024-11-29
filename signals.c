/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:40:19 by labderra          #+#    #+#             */
/*   Updated: 2024/10/18 13:45:37 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigquit_fork(int sig)
{
	printf("Quit (core dumped)");
	g_signal = sig;
	kill(0, SIGINT);
}

void	handle_sigint_fork(int sig)
{
	printf("\n");
	if (g_signal == 0)
		g_signal = sig;
}

void	handle_sigint_main(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
