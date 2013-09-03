/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/03 14:02:23 by greyrol           #+#    #+#             */
/*   Updated: 2013/09/03 14:02:25 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

/*
** @start, @end must init it with t_clock
** use clock(); like start = clock(); /Code/ end = clock();
*/
void	print_time(char *function, clock_t start, clock_t end)
{
	printf("Timer : ");
	printf("[%s]", function);
	printf(" : %f\n", (end - start) / (float)CLOCKS_PER_SEC);
}
