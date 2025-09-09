/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:15:07 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/09/09 19:29:38 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "cub3d.h"

/**
 * @brief Structure to hold game context
 * @param map pointer to game map array
 * @param exit_status Last Command exit status
 */
typedef struct s_init_game
{
	char	**map;
	int		exit_status;
}	t_init_game;

/**
 * @brief Structure to hold mlx context
 * @param mlx void mlx pointer
 * @param win void poiter to the game windown
 */
typedef struct s_classMlx
{
	void	*mlx;
	void	*win;
}	t_classMlx;

#endif
