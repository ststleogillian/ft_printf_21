#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MINUS      0b00000001
# define PLUS       0b00000010
# define SPACE      0b00000100
# define SHARP      0b00001000
# define ZERO       0b00010000
# define PRECISION  0b00100000
# define ARR_FOR_X  "0123456789ABCDEF"
# define ARR_FOR_x  "0123456789abcdef"

typedef struct parse_list {
    unsigned char flags;
    int           width;
    int           precision;
    char          spec;
    int           length;
}              t_list;

int     ft_printf(const char *format, ...);
void    parse_flags(t_list *info, const char **ptr);
int     ft_find_flags(char *where, char what);
void    parse_width(t_list *info, const char **ptr, va_list ap);
void    parse_precision(t_list *info, const char **ptr, va_list ap);
void    parse_spec(t_list *info, const char **ptr);
int     ft_find_flags(char *where, char what);
void    print_char(t_list *info, va_list ap);

# endif