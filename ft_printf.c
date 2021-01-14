#include "ft_printf.h"

static void ft_print_struct(t_list *info)
{
    printf("flags - %5u\n", info->flags);
    printf("width - %5d\n", info->width);
    printf("precision - %5d\n", info->precision);
    printf("spec - %5c\n", info->spec);
}

static t_list *create_list(void)
{
    t_list *info;

    if (!(info = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    info->flags = 0;
    info->width = 0;
    info->precision = 0;
    info->spec = '\0';
    info->length = 0;
    return (info);
}

static void parsestruct(const char **ptr, va_list ap, t_list *info)
{
    parse_flags(info, ptr);
    parse_width(info, ptr, ap);
    parse_precision(info, ptr, ap);
    parse_spec(info, ptr);
    ft_print_struct(info);
}

static void  writespec(const char **ptr, va_list ap, t_list *info)
{
    parsestruct(ptr, ap, info);
    if (info->spec == 'c')
        print_char(info, ap);
    // else if (info->spec == 's')
    //     print_string(info, ap);
    // else if (ft_find_flags("diu", info->spec))
    //     print_number(info, ap, 10);
    // else if (ft_find_flags("xXp", info->spec))
    //     print_number(info, ap, 16);
    // else if (info->spec == '%')
    //     print_percent(info);
}

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    t_list      *info;

    if (!(format))
        return (-1);
    va_start(ap, format);
    info = create_list();
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            writespec(&format, ap, info);
        }
        else
        {
            info->length = write(1, format, 1);
            format++;
        }
    }
    va_end(ap);
    return (info->length);
}