/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:08:14 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 02:16:44 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//// Lib Includes
# include "ft_colors.h"
# include "ft_macros.h"
# include "ft_structs.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/ioctl.h>

////// SOURCE FILES
//// ft_isx
int		ft_squotesbl(char *line, int *open, int i, int *bl);
int		ft_squotes(char *line, int *open, int i);
int		ft_cquotesn(char *s, int n);
int		ft_cquotes(char *s);
int		ft_cend(char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isupp(int c);
int		ft_islow(int c);

//// ft_tox
t_clist	*ft_stocl(char *str);
char	*ft_ttos(char **tab, char *sep);
char	*ft_cltos(t_clist *lst);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);

//// ft_mem
t_clist	*ft_nfreeclst(t_clist **mem);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_gptr(int id, void *ptr);
void	*ft_nfree(void **mem);
void	*ft_memdel(void *ptr);
void	*ft_free(void *mem);
char	**ft_nfreetab(char ***mem);
char	*ft_nfreestr(char **mem);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_gint(int id, size_t act, int val);

//// ft_put
void	ft_puttab(char **tab, char *prompt);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char *s);
void	ft_putstr(char *s);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_putclst_xfory(t_clist *lst, int x, int y);
void	ft_putclstpos(t_clist *lst, int pos);
void	ft_putnclst(t_clist *lst, int n);
void	ft_putclst(t_clist *lst);
void	ft_putclstval(t_clist *lst);

//// ft_str
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim_xtoy(char *s, int x, int y);
char	*ft_strdrep(char **body, char *news);
char	*ft_strrep(char *body, char *news);
char	**ft_splitq(char const *s);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_freejoin(char **s1, char **s2);
char	*ft_prejoin(char *s1, char **s2);
char	*ft_sujoin(char **s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strchp(char *s, char c);

//// ft_strman
char	*ft_stradd_bgn(char **old, char add);
char	*ft_stradd_end(char **old, char add);
char	*ft_stradd_n(char **old, char add, int n);
char	*ft_strrem_bgn(char **old);
char	*ft_strrem_end(char **old);
char	*ft_strrem_n(char **old, int n);
char	*ft_strnew(char **old, char add);
char	*ft_strins_n(char **old, char *add, int n);
char	*ft_strrem_xtoy(char **s, int x, int y);
void	ft_strrem_qbl(char **str);

//// ft_tab
char	*ft_tabsmove(char **tab, int start, int end);
char	**ft_tabadd_bgn(char ***old, char *add);
char	**ft_tabadd_end(char ***old, char *add);
char	**ft_tabadd_n(char ***old, char *add, int n);
char	**ft_tabrem_bgn(char ***old);
char	**ft_tabrem_end(char ***old);
char	**ft_tabrem_n(char ***old, int n);
char	**ft_freetab(char **tab);
char	**ft_tabdup(char **old);
void	ft_tabrem_qbl(char **tab);
int		ft_tablen(char **tab);

//// ft_ansi
void	ft_ansi_drl(char *prompt);
void	ft_ansi_drd(char *prompt);
void	ft_ansi_dfd(void);
void	ft_ansi_getcp(int *x, int *y);
void	ft_ansi_go(int x, int y);
void	ft_ansi_resetl(void);
void	ft_ansi_clear(void);
void	ft_ansi_sc(void);
void	ft_ansi_lc(void);

//// ft_utils
void	ft_newfile(const char *name);
void	ft_trash_stdin(int dsecs);
void	ft_ungetchar(char ch);
void	ft_getcwd(char **pwd);
void	ft_stdout_off(void);
void	ft_stdout_on(void);
void	ft_close(int fd);
char	*ft_getarg(char **tab, char const *name);
int		ft_getrstr_p(char **tab, char const *name);
int		ft_getstr_p(char **tab, char const *name);
int		ft_getarg_p(char **tab, char const *name);
int		ft_getchar(void);
int		ft_getchar_unb(int dsecs);

//// ft_list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *val);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstfree(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_bgn(t_list **lst, t_list *new);
void	ft_lstadd_end(t_list **lst, t_list *new);
void	ft_lstdel(void *val);
int		ft_lstlen(t_list *lst);

//// ft_clist
t_clist	*ft_clstnew(char val);
t_clist	*ft_clstadd_bgn(t_clist **lst, t_clist *new);
t_clist	*ft_clstadd_end(t_clist **lst, t_clist *new);
t_clist	*ft_clstadd_n(t_clist **lst, t_clist *new, int n);
t_clist	*ft_clstrem_bgn(t_clist **lst);
t_clist	*ft_clstrem_end(t_clist **lst);
t_clist	*ft_clstrem_n(t_clist **lst, int n);
t_clist	*ft_clstpos(t_clist *lst, int pos);
t_clist	*ft_freeclst(t_clist **lst);
char	ft_clstnval(t_clist *lst, int pos);
int		ft_clstlen(t_clist *lst);

//// ft_printf
void	ft_lputchar(int c, int *len);
int		ft_printf(const char *str, ...);
int		ft_printc(char *color, const char *str, ...);
int		ft_ftypes(va_list args, const char format);
int		ft_printpointer(unsigned long long ptr);
int		ft_printhex(int nb, const char format);
int		ft_printunsigned(unsigned int nb);
int		ft_printstr(char *str);
int		ft_printpercent(void);
int		ft_printchar(int c);
int		ft_printnbr(int nb);
int		ft_nbrlen(int nb);

//// ft_gnl
char	*get_next_line(int fd);

//// ft_readline
char	ft_buffer_read(t_readline *rl);
char	rl_bufferuse(t_readline *rl);
char	**ft_add_history(char *new);
char	*ft_sreadline(char *prompt);
char	*ft_readline(const char *prompt);
void	rl_getcp(int *x, int *y, t_readline *rl);
void	rl_init(t_readline *rl, const char *prompt);
void	rl_get_specials(t_readline *rl);
void	rl_do_moviments(t_readline *rl);
void	rl_do_backspace(t_readline *rl);
void	rl_save_home(t_readline *rl);
void	rl_save_end(t_readline *rl);
void	rl_get_back(t_readline *rl);
void	rl_addchar(t_readline *rl);
void	rl_cleard(t_readline *rl);
void	rl_go_right(t_readline *rl);
void	rl_go_left(t_readline *rl);
void	rl_go_home(t_readline *rl);
void	rl_go_end(t_readline *rl);
void	rl_do_tab(t_readline *rl);
void	ft_rl_clear_history(void);
void	rl_termios_ch(int opt);
int		ft_rlconfig(int id, size_t act, int val);
int		rl_checkmove(t_readline *rl);
int		rl_checkreset(t_readline *rl);

#endif
