/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:23 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/13 17:19:01 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// librarys
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

// functions
int		ft_printf(const char *format, ...);
int		put_all(char *format, va_list args);
int		what_case(char format, va_list args);
int		put_hex(uintptr_t x, char format);
int		hex_len(uintptr_t p);
char	*ft_uitoa(unsigned int n);
int		unsigned_num_len(unsigned int n);
int		print_hex(unsigned int x, char format);
int		print_sint(int num);
int		print_uint(int num);
int		print_adr(uintptr_t p);
int		print_str(char *str);
int		print_c(int c);

#endif