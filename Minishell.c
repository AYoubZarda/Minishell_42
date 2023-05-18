/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarda <azarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:19:44 by azarda            #+#    #+#             */
/*   Updated: 2023/05/18 04:01:04 by azarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void  ctr_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line(" ", 0);
	rl_redisplay();

}
void ft_exut_cd(char **str)
{
			
	if(!ft_strcmp(str[0], "cd"))
	{
		if(!str[1])
			chdir(getenv("HOME"));
		else if(chdir(str[1]) < 0)
		{
			ft_putstr_fd("Minishell: cd: ", 2);
			perror(str[1]);
		}
	}
	else
		return ;
}

void echo(char **tab)
{
	int i = 0;
	int j = 0;
	int bol = 1;
	
	if(!ft_strcmp(tab[i], "echo"))
	{
		i++;
		if(tab[i] && tab[i][0] == '-' && tab[i][1] == 'n')
		{
			j = 2;
			while(tab[i][j] && tab[i][j] == 'n')
				j++;	
			if(tab[i][j])
				bol = 1;
			else
			{
				bol = 0;
				i++;
			}
		}
		while (tab[i])
			printf("%s ", tab[i++]);
		if(bol)
			printf("\n");
	}
	
}


int main(int ac, char **av, char  **env)
{
	(void)av;
	(void)env;
	char *pwd;
	if(ac != 1)
	{
		printf("Minishell ma katakhod waloo \n"); // change msg
		exit(1);
	}
	char *str;
	while(1337)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT,  ctr_c);
		pwd = ft_strjoin(getcwd(NULL, 0), " -> "); // 1bite leaks pwd
		str = readline(pwd);
		free(pwd);
		if(!str)
		{
			printf("exit\n");
			exit(0);
			free(pwd);
		}
		if(!ft_strcmp(str, "pwd"))
			printf("%s\n", getcwd(NULL, 0));
		// if(!ft_strcmp(str, "cd"))
		// {
		// }
		if(!ft_strcmp(str, "exit"))
		{
			// free(pwd);
			exit(0);
		}
		ft_exut_cd(ft_split(str, ' '));
		echo(ft_split(str, ' '));
		add_history(str);
		free(str);
	}
}
