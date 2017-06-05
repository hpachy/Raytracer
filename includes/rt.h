/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:06:26 by hpachy            #+#    #+#             */
/*   Updated: 2017/03/24 17:39:22 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL2/SDL.h>
# include "camera.h"
# include "libft.h"
# include "libft_matrix.h"

# define DIST_MAX 9999999.9f

typedef struct		s_fog
{
	float			type;
	float			distance;
	t_vector3f		color;
}					t_fog;

typedef struct s_camera	t_camera;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Texture		*text;
	SDL_Renderer	*rend;
	t_vector2f		size;
	int				pitch;
	int				wh[2];
	Uint32			*pixels;
	Uint32			format;
}					t_env;

typedef	struct		s_rt
{
	t_env			env;
	t_camera		*camera;
	t_dlist			*objs;
	t_dlist			*materials;
	t_dlist			*textures;
	t_fog			*fog;
}					t_rt;

t_rt				*create_rt(int x, int y, char *name);
void				destroy_rt(t_rt *rt);
void				refresh_rt(t_rt *rt);
void				*render_chunk(void *data);
void				render_rt(t_rt *rt);

#endif
