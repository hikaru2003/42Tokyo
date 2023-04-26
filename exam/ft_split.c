/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:31:14 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 14:07:44 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	*ft_strncpy(char *str, int start, int strlen)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(strlen + 1);
	if (!tmp)
		return (NULL);
	while(i < strlen)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		start;
	int		count;
	char	**array;

	i = 0;
	j = 0;
	count = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		array[j] = ft_strncpy(str, start, i - start);
		if (!array[j])
			return (ft_free(array));
		j++;
	}
	array[j] = NULL;
	return (array);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*str = "hello world\nI'm	hikaru	morisaki";
// 	char	**tmp;

// 	tmp = ft_split(str);
// 	int i = 0;
// 	while (tmp[i] != NULL)
// 	{
// 		printf("%s\n", tmp[i]);
// 		i++;
// 	}
// 	printf("%d\n", i);
// 	return (0);
// }