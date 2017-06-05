/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:23 by jrichard          #+#    #+#             */
/*   Updated: 2017/02/25 13:12:06 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR3D_H
# define FT_VECTOR3D_H

typedef struct	s_vector3d
{
	double		x;
	double		y;
	double		z;
}				t_vector3d;

t_vector3d		create_vector3d(double x, double y, double z);
t_vector3d		add_vector3d(t_vector3d v1, t_vector3d v2);
t_vector3d		sub_vector3d(t_vector3d v1, t_vector3d v2);
t_vector3d		mult_vector3d(t_vector3d v1, float nb);
t_vector3d		div_vector3d(t_vector3d v1, float nb);
double			dot_vector3d(t_vector3d v1, t_vector3d v2);
t_vector3d		cross_vector3d(t_vector3d v1, t_vector3d v2);
t_vector3d		normalize_vector3d(t_vector3d v1);
float			length_vector3d(t_vector3d v1);
float			squared_length_vector3d(t_vector3d v1);
t_vector3d		clamp_vector3d(t_vector3d v1, double min, double max);

#endif
