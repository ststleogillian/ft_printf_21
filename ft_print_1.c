#include "ft_printf.h"

void    print_char(t_list *info, va_list ap)
{
    unsigned char   c;

    c = va_arg(ap, int);
    if (info->flags & MINUS)
        info->length += write(1, &c, 1);
    while (--info->width)
    {
        write(1, " ", 1);
        info->length += 1;
    }
    if (!(info->flags & MINUS))
        info->length += write(1, &c, 1);
}