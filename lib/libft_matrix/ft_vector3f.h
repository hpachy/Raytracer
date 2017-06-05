/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3f.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichard <jrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:23 by jrichard          #+#    #+#             */
/*   Updated: 2017/03/13 14:03:45 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR3F_H
# define FT_VECTOR3F_H

# include "ft_matrix.h"

typedef struct s_matrix	t_matrix;

typedef struct	s_vector3f
{
	float		x;
	float		y;
	float		z;
	float		length;
}				t_vector3f;

t_vector3f		create_vector3f(float x, float y, float z);
t_vector3f		add_vector3f(t_vector3f v1, t_vector3f v2);
t_vector3f		sub_vector3f(t_vector3f v1, t_vector3f v2);
t_vector3f		mult_vector3f(t_vector3f v1, float nb);
t_vector3f		div_vector3f(t_vector3f v1, float nb);
float			dot_vector3f(t_vector3f v1, t_vector3f v2);
t_vector3f		cross_vector3f(t_vector3f v1, t_vector3f v2);
t_vector3f		normalize_vector3f(t_vector3f v1);
float			length_vector3f(t_vector3f v1);
float			squared_length_vector3f(t_vector3f v1);
t_vector3f		transform_vector3f(t_vector3f v1, t_matrix *transf);
t_vector3f		clamp_vector3f(t_vector3f v1, float min, float max);
t_vector3f		mult_by_vector3f(t_vector3f v1, t_vector3f v2);
t_vector3f		div_float_by_vector3f(float nb, t_vector3f v);

#endif
