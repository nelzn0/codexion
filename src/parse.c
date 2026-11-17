/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:33:55 by nda-roch          #+#    #+#             */
/*   Updated: 2026/11/17 17:25:09 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/codexion.h"

int parser(int argc, char **argv)
{

    int i = 1;
    int c = 0;
    int is_digit = 1;

    if (argc != 9)
    {
        fprintf(stderr, "ERROR: Must be 9 arguments\n");
        return (1);
    }
    else
    {
        while (argv[i])
        {
            c = 0;
            while (argv[i][c])
            {
                if (!(argv[i][c] >= '0' && argv[i][c] <= '9'))
                {
                    is_digit = 0;
                }
                c++;
            }
            i++;
            
        }
        
        if (is_digit)
        {
            return (0);
        }
        else
        {
            fprintf(stderr, "ERROR: 1 or more arguments are not digits\n");
            return (1);
        }
        
    }
    
    
}