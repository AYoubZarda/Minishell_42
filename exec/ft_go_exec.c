/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarda <azarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:11:26 by azarda            #+#    #+#             */
/*   Updated: 2023/06/22 00:22:47 by azarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"


int ft_execut_cmd(splitnode *cmd, t_env *env)
{


	if(ft_execut_bultins(cmd->splitdata, env, 0))
		return 1;
	ft_exec(cmd->splitdata , env);
	return (1);
}


	// if (cmd && cmd->next)
	// {
	// 	while(cmd && cmd->next)
	// 	{
	// 		pipe(fd);
	// 		if (cmd->out == -1)
	// 			cmd->out = fd[1];
	// 		if (cmd->in == -1)
	// 			cmd->in = fd[0];
	// 		if (i)
	// 			cmd->in = cmd->prev->in;
	// 		// ft_execut_bultins(cmd, env);
	// 		if(ft_execut_bultins(cmd, env))
	// 		{
	// 			cmd = cmd->next;
	// 			continue;
	// 		}
	// 		else
	// 			ft_exec(cmd , env);
	// 		close(fd[1]);
	// 		if (i)
	// 			close(cmd->in);
	// 		cmd = cmd->next;

	// 		i = !i;

	// 	}
	// 	if(ft_execut_bultins(cmd, env))
	// 		;
	// 	else
	// 		ft_exec(cmd , env);
	// 	close(fd[0]);
	// }
//---------------------------------------------------------------------------------------------------
	// int fd[2];
	// if (cmd->out == -1)
	// 	cmd->out = fd[1];
	// if (cmd->in == -1)
	// 	cmd->in = fd[0];


	// unsigned int i = 0;
	// int id;
	// if(cmd && cmd->next)
	// {
	// 	while (cmd->next)
	// 	{
	// 	pipe(fd);
	// 	id = fork();
	// 	// if(!i)
	// 	// 	close(fd[0]);
	// 	if(ft_execut_bultins(cmd, env))
	// 	{

	// 		exit(0);
	// 		cmd = cmd->next;
	// 		continue;
	// 	}
	// 	ft_exec(cmd , env);
	// 		cmd = cmd->next;
	// 	}
		// if(ft_execut_bultins(cmd, env))
		// 	return 1;
		// ft_exec(cmd , env);
		// return (1);
		// // wait(&id);

	// }
	// else
	// {