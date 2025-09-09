/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:37:09 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/09/09 20:17:11 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

//Init windown and confiure keys

void	mlx_loop(t_classMlx *mlx)
{
	if (mlx)
		mlx_loop(mlx->mlx);
}

t_classMlx	*init_mlx(void)
{
	t_classMlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	return (&mlx);
}
