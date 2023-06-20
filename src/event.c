/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:26:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/12 20:37:51by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

static void	resolve_action(t_game *game, t_coord player)
{
	if (game->map->grid[player.y][player.x] == EMPTY
		|| game->map->grid[player.y][player.x] == COLLECTIBLE)
	{
		game->player.y = player.y;
		game->player.x = player.x;
	}
	if (game->map->grid[player.y][player.x] == COLLECTIBLE)
		game->map->grid[player.y][player.x] = EMPTY;
	if (game->map->grid[player.y][player.x] == EXIT)
		my_close(&game->vars);
}

static int	move_player(int keycode, t_game *game)
{
	ft_printf("============================\n");
	for(size_t i = 0; i < game->map->row; i++){
		ft_printf("%s", game->map->grid[i]);
	}
	if (keycode == UP)
		resolve_action(game, (t_coord){game->player.y - 1, game->player.x});
	if (keycode == DOWN)
		resolve_action(game, (t_coord){game->player.y + 1, game->player.x});
	if (keycode == LEFT)
		resolve_action(game, (t_coord){game->player.y, game->player.x - 1});
	if (keycode == RIGHT)
		resolve_action(game, (t_coord){game->player.y, game->player.x + 1});
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		my_close(&game->vars);
	else
		move_player(keycode, game);
	return (0);
}
