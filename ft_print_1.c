#include "ft_printf.h"

void    print_char(t_list *info, va_list ap)
{
    unsigned char   c;

    c = va_arg(ap, int);
    if (info->flags & MINUS)
        info->length += write(1, &c, 1);
    while (--info->width > 0)
    {
        write(1, " ", 1);
        info->length += 1;
    }
    if (!(info->flags & MINUS))
        info->length += write(1, &c, 1);
}

void    print_percent(t_list *info)
{
    if (info->flags & MINUS)
        info->length += write(1, "%%", 1);
    while (--info->width > 0)
    {
        write(1, " ", 1);
        info->length += 1;
    }
    if (!(info->flags & MINUS))
        info->length += write(1, "%%", 1);
}

void    print_string(t_list *info, va_list ap)
{
    char *str;
    int   len;
    int     diff;

    str = va_arg(ap, char *);
    if (!str)
        str = "(null)";
    len  = ft_strlen(str);
    if (info->flags & PRECISION && info->precision < len)
        len = info->precision;
    if (info->flags & MINUS)
        info->length += write(1, str, len);
    diff = info->width - len;
    while (diff-- > 0)
    {
        write(1, " ", 1);
        info->length += 1;
    }
    if (!(info->flags & MINUS))
        info->length += write(1, str, len);
}