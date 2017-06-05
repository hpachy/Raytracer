/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:46:32 by jqueyrou          #+#    #+#             */
/*   Updated: 2017/03/23 13:09:43 by jrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "equation.h"
# include "rt.h"
# include "obj.h"
# include "ft_kvlexer.h"
# include "parser.h"
# include "libft.h"

typedef struct	s_triangle
{
	t_vector3f	vertex[3];
	t_vector3f	normal;
}				t_triangle;

typedef struct	s_var
{
	t_vector3f	e1;
	t_vector3f	e2;
	t_vector3f	pvector;
	float		determinant;
	float		invertedeterminant;
	t_vector3f	tvec;
	float		lambda;
	t_vector3f	qvec;
	float		mue;
	float		f;
}				t_var;

int				create_triangle(t_kvlexer *token, t_rt *rt);
float			inter_triangles(t_triangle *t, t_ray *ray);
int				if_touch(t_triangle *t, t_vector3f *impact);

#endif
