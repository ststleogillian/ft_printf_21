#include "ft_printf.h"

int     ft_find_flags(char *where, char what)
{
    while (where && *where)
    {
        if (*where == what)
            return (1);
        where++;
    }
    return (0);
}

void    parse_flags(t_list *info, const char **ptr)
{
    info->flags = 0;
    if (!info || !ptr)
        return ;
    while (ft_find_flags("0-+ #", **ptr))
    {
        if (**ptr == '#')
            info->flags |= SHARP;
        else if (**ptr == '0' && !(info->flags & MINUS))
            info->flags |= ZERO;
        else if (**ptr == '-')
            info->flags = (info->flags | MINUS) & (~ZERO);
        else if (**ptr == ' ')
            info->flags |= SPACE;
        else if (**ptr == '+')
            info->flags = (info->flags | PLUS) & (~SPACE);
        (*ptr)++;
    }
}

void    parse_width(t_list *info, const char **ptr, va_list ap)
{
    info->width = 0;
    if (**ptr == '*')
    {
        (*ptr)++;
        if ((info->width = va_arg(ap, int)) < 0)
        {
            info->width *= -1;
            info->flags = (info->flags | MINUS) & (~ZERO);
        }
    }
    else
    {
        while (**ptr >= '0' && **ptr <= '9')
        {
            info->width = info->width * 10 + (**ptr -'0');
            (*ptr)++;
        }
    }
}

void    parse_precision(t_list *info, const char **ptr, va_list ap)
{
    info->precision = 0;
    if (**ptr == '.')
    {
        (*ptr)++;
        info->flags |= PRECISION;
        if (**ptr == '*')
        {
            if ((info->precision = va_arg(ap, int)) < 0)
                info->flags &= (~PRECISION);
        }
        else
        {
            while (**ptr > '0' && **ptr <= '9')
            {
                info->precision = info->precision * 10 + **ptr - '0';
                (*ptr)++;
            }
        }
    }
}

void    parse_spec(t_list *info, const char **ptr)
{
    info->spec = **ptr;
    if (ft_find_flags("cspdiuxX%%", **ptr))
        (*ptr)++;
}