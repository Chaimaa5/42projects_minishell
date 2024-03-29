/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:14:55 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/09/02 23:14:57 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	is_numeric(char *ar)
{
	int	i;

	i = 0;
	if (ar[0] == '-' || ar[0] == '+')
		i++;
	while (ar[i])
	{
		if (ar[i] < '0' || ar[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_number(char *nb)
{
	if (ft_atoi(nb) == -1 && ft_strncmp(nb, "-1", 2))
		return (0);
	return (1);
}

void	exec_exit(t_parser *parser)
{
	if (!parser->args[1])
	{
		if (parser->flag != 1)
			ft_putendl_fd("exit", 1);
		exit(0);
	}
	if (parser->args[2])
	{
		ft_putendl_fd("exit\nexit: too many arguments", 2);
		g_exit_status = 1;
	}
	else if (!is_numeric(parser->args[1]) || !check_number(parser->args[1]))
	{
		ft_putendl_fd("exit\nexit: numeric argument required", 2);
		g_exit_status = 255;
		exit(g_exit_status);
	}
	else if (check_number(parser->args[1]))
	{
		if (ft_atoi(parser->args[1]) > 255)
			g_exit_status = ft_atoi(parser->args[1]) % 256;
		else
			g_exit_status = ft_atoi(parser->args[1]);
		exit(g_exit_status);
	}
}
