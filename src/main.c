/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:31:44 by username          #+#    #+#             */
/*   Updated: 2026/11/26 17:11:37 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/codexion.h"

int	main(int argc, char **argv)
{
	int		parsed;
	t_args	args;

	parsed = parser(argc, argv, &args);
	if (parsed)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
