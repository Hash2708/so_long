/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:04:39 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:04:45 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	print_char(int c);
int	print_string(char *s);
int	print_void(void *ptr);
int	print_dec(long num);
int	print_int(int num);
int	print_udec(unsigned int num);
int	print_low_hex(unsigned int num);
int	print_up_hex(unsigned int num);
int	print_percent(void);

#endif
