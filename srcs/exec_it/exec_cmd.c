/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 03:13:02 by salomon           #+#    #+#             */
/*   Updated: 2016/06/16 16:44:47 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void 		exect_it(t_data *data, t_llist *env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait();
		return ;
	}
	if (father == 0)
		execve(data->cmd, data->option, NULL);
}


void 		exec_cmd(t_llist *env, char *line)
{
	t_data	*data;
	char	**pline;
	int		lenght;
 	int		tab[] = {9, 32, 0};

	data = NULL;
	lenght = ft_strsplit(&pline, line, tab);
	if (lenght > 0)
	{
		if ((parser_data(env, pline, &data)) == -1)
			ft_print_error(pline[0], ": command not found");
		else
			exect_it(data, env);
	}
	free_d(pline, lenght);
}
