/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:36:03 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/11 21:42:28 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <limits.h>

int	ft_contains(long num, long *tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	howinav(char **argv)
{
	int count = 0;
	int i = 0;
	char **args;
	int j;

	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Your existing structures and functions here

char	*process_input_and_check_errors(char *input, long *tab)
{
	long	tmp;
	int		k;

	tmp = ft_atoi(input);
	if (!ft_isnum(input) || tmp < -2147483648 || tmp > 2147483647 || input[0] == '\0')
	{
		return ("Error: Invalid input");
	}
	if (ft_contains(tmp, tab))
	{
		return ("Error: Duplicate numbers");
	}
	k = 0;
	while (tab[k] != 0)
		k++;
	tab[k] = tmp;
	return (NULL);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;
	long	tab[INT_MAX];
	int		j;

	i = 1;
	ft_bzero(tab, howinav(argv)+1);
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			char *error = process_input_and_check_errors(args[j++], tab);
			if (error != NULL)
				ft_error(error);
		}
		i++;
		ft_free(args);
	}
	i = 0;
	while (i < argc)
	{
		if (argv[i++][0] == '\0')
			ft_error("Error: Empty argument");
	}
}

// void ft_check_args(int argc, char **argv)
// {
// 	int i = 1;
// 	long tmp;
// 	char **args;
// 	long tab[] = {0};

// 	while (i < argc)
// 	{
// 		args = ft_split(argv[i], ' ');

// 		int j = 0;
// 		while (args[j])
// 		{
// 			tmp = ft_atoi(args[j]);
// 			if (!ft_isnum(args[j]) || tmp < -2147483648 || tmp > 2147483647
// || args[j][0] == '\0')
// 				ft_error("Error: Invalid input");

// 			if (ft_contains(tmp, tab))
// 				ft_error("Error: Duplicate numbers");

// 			// Insert the number into the tab array
// 			int k = 0;
// 			while (tab[k] != 0)
// 				k++;
// 			tab[k] = tmp;

// 			j++;
// 		}
// 		i++;
// 		ft_free(args);
// 	}
// 	// Check for empty argument after splitting
// 	i = 0;
// 	while (i < argc)
// 	{
// 		if (argv[i][0] == '\0')
// 			ft_error("Error: Empty argument");
// 		i++;
// 	}
// }
