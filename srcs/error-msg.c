/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:01:54 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/02 10:03:35 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*Contient toutes les fonctions d'erreurs*/

int	msg(char *c)
{
	write(2,c, ft_strlen(c));
	return (1);
}

void	error_msg(char *c)
{
	perror(c);
	exit (1);
}

