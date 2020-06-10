/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:40:56 by jnovotny          #+#    #+#             */
/*   Updated: 2020/06/10 12:03:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int argc, char **argv)
{
	t_champ *champ;

	if (argc == 2)
	{
		champ = init_champ(argv[1]);
		ft_printf("Champ initialized\n");
		load_champ(champ);
	}
	return (0);
}