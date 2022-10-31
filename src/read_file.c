/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:19:31 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:35:49 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_wdcounter(char const *str, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_height(char *name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr_fd("file does not exist or permission denied\n", 1);
		exit(0);
	}
	height = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr_fd("file does not exist or permission denied\n", 1);
		exit(0);
	}
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line > 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *z, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(line);
	free(nums[i]);
	free(nums);
}

void	read_map(char *name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(name);
	data->width = get_width(name);
	data->z = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		fill_matrix(data->z[i++], line);
		line = get_next_line(fd);
	}
	close(fd);
	data->z[i] = NULL;
}
