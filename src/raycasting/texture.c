/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:47:20 by vjean             #+#    #+#             */
/*   Updated: 2023/05/17 09:25:08 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Cub3D.h"

int	create_colour(int red, int green, int blue, int trans)
{
	return (red << 24 | green << 16 | blue << 8 | trans);
}

//to put in static or not
int	**create_array_pxl(xpm_t *wall)
{
	int			**tab;
	uint32_t	x;
	uint32_t	y;
	int			count;

	y = 0;
	x = 0;
	count = 0;
	tab = malloc(sizeof(int) * (wall->texture.height + 1));
	while (y < wall->texture.height)
	{
		tab[y] = malloc(sizeof(int) * (wall->texture.width + 1));
		while (x < wall->texture.width)
		{
			tab[y][x] = create_colour(wall->texture.pixels[count + 0], \
			wall->texture.pixels[count + 1], wall->texture.pixels[count + 2], \
			wall->texture.pixels[count + 3]);
			x++;
			count += 4;
		}
		tab[y][x] = '\0';
		x = 0;
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

void	add_texture(t_parse *data)
{
	data->xpm = malloc(sizeof(t_xpm) * 4);
	data->xpm->EA = mlx_load_xpm42(data->EA);
	if (!data->xpm->EA)
		exit(1);//need to better deal error and free stuff
	data->xpm->WE = mlx_load_xpm42(data->WE);
	if (!data->xpm->WE)
		exit(1);//need to better deal error and free stuff
	data->xpm->NO = mlx_load_xpm42(data->NO);
	if (!data->xpm->NO)
		exit(1);//need to better deal error and free stuff
	data->xpm->SO = mlx_load_xpm42(data->SO);
	if (!data->xpm->SO)
		exit(1);//need to better deal error and free stuff
	data->xpm->tab_ea_tex = create_array_pxl(data->xpm->EA);
	data->xpm->tab_we_tex = create_array_pxl(data->xpm->WE);
	data->xpm->tab_so_tex = create_array_pxl(data->xpm->NO);
	data->xpm->tab_no_tex = create_array_pxl(data->xpm->SO);

}

