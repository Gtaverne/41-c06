/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:12:05 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/19 16:28:03 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
void printsorted(int n, char **tab);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	printsorted(int n, char **tab)
{
	int i;

	i = 1;
	while (i < n)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*min;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				min = argv[j];
				argv[j] = argv[i];
				argv[i] = min;
			}
			j++;
		}
		i++;
	}
	printsorted(argc, argv);
	return (0);
}
