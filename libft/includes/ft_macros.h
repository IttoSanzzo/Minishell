/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:08:54 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:08:56 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

//// Macros
/// MAXs & MINs
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

/// BUFFERS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef GMEM_BUFFER
#  define GMEM_BUFFER 1024
# endif
# define CP_BUFFER 13
# define BUFFER_PWD 1024

/// File Descriptors
# ifndef STDIN
#  define STDIN 0
# endif
# ifndef STDOUT
#  define STDOUT 1
# endif
# ifndef STDERR
#  define STDERR 2
# endif

// Exit Codes
# ifndef EXIT_SUCC
#  define EXIT_SUCC 0
# endif
# ifndef EXIT_FAIL
#  define EXIT_FAIL 1
# endif

// Miscs
# define RL_FORCE_END 999
# define PUTV 1
# define GETV 0

#endif
