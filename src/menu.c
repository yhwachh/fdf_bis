/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:19:00 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:27:27 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_windows(t_fdf *data)
{
	char	*menu;

	menu = "up, down, left, right: move map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x03fc35, menu);
	menu = "zoom: - , +";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0x03fc35, menu);
	menu = "height 42 : q , w";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0x03fc35, menu);
}
