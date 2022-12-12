/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:01:54 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/09 10:51:38 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*Contient toutes les fonctions d'erreurs*/

int	msg(char *c)
{
	write(2, c, ft_strlen(c));
	return (1);
}

void	error_msg(char *c)
{
	perror(c);
	exit (1);
}
