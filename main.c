/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:25:24 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/29 17:38:37 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    int i;
    
    i = 1;
    if(ac == 5 || ac == 6)
    {
            check_arg(av);
            check_num(av);
            create_args(av);
    }
    else
        printf("Error: more or less arguments\n");
}