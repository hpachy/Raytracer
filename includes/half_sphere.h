/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_sphere.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:03:35 by abitoun           #+#    #+#             */
/*   Updated: 2017/03/30 20:03:39 by abitoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALF_SPHERE_H
# define HALF_SPHERE_H

# include "rt.h"
# include "obj.h"
# include "ft_kvlexer.h"

typedef struct	s_half_sphere
{
	float		radius;
	float		reflexion;
	t_vector3f	dir;
}				t_half_sphere;

int				create_half_sphere(t_kvlexer *token, t_rt *rt);

#endif
