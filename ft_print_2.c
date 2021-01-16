#include "ft_printf.h"

void    ft_putnbr(long long int num, int len, int base, t_list *info)
{
    char c;

    if (len <= 0)
        return ;
    if (len > 1)
        ft_putnbr(num / 10, len - 1, base, info);
    if (info->spec == 'X')
        c = ARR_FOR_X[num % 16];
    else
        c = ARR_FOR_x[num % 10];
    info->length += write(1, &c, 1);
}

void    printlenprecnum(int diff2, long long int num, int len, t_list *info)
{
    int base;

    if (info->spec == 'p')
    {
        info->length += write(1, "0x", 2);
        info->spec = 'x';
        len -= 2;
    }
    if (num < 0)
    {
        info->length += write(1, "-", 1);
        num = -num;
        len--;
    }
    while (diff2-- > 0)
        info->length += write(1, "0", 1);
    if (info->spec == 'x' || info->spec == 'X')
        base = 16;
    else
        base = 10;
    ft_putnbr(num, len, base, info);
}

void    managediffs(int *diffs, int len, t_list *info, long long int num)
{
    int flag;

    flag = 0;
    if (num < 0)
    {
        flag = 11;
        len--;
    }
    diffs[1] = (info->flags & PRECISION) ? info->precision - len : 0;
    if (info->width > len && info->width > info->precision)
        diffs[0] = ((diffs[1] > 0) ? info->width - info->precision \
        : info->width - len) - flag;
    else
        diffs[0] = 0;
    if (info->flags & ZERO && !(info->flags & PRECISION))
    {
        diffs[1] += diffs[0];
        diffs[0] = 0;
    }
}

static  void    lenmax(long long int num, int len, int base, t_list *info)
{
    if (info->spec == 'p')
    {
        info->length += write(1, "0x", 2);
        ft_putnbr(num, len - 2, base, info);
    }
    else if (num < 0)
    {
        info->length += write(1, "-", 1);
        ft_putnbr(-num, len - 1, base, info);
    }
    else
        ft_putnbr(num, len, base, info);
}

int     numlen(long long int n, int base)
{
    int  len;

    len = 1;
    if (n < 0)
    {
        len++;
        n *= -1;
    }
    while (n /= base)
        len++;
    return (len);
}

static long long int   get_number(va_list ap, char spec)
{
    if (spec == 'd' || spec == 'i')
        return (va_arg(ap, int));
    if (spec == 'x' || spec == 'X' || spec == 'u')
        return (va_arg(ap, unsigned int));
    if (spec == 'p')
        return (va_arg(ap, size_t));
        return 0;
}

void    print_number(t_list *info, va_list ap, int base)
{
    long long int   num;
    int             len;
    int             diffs[2];

    num = get_number(ap, info->spec);
    len = numlen(num, base);
    if (num == 0 && info->flags & PRECISION && !info->precision)
        len = 0;
    len = (info->spec == 'p') ? len + 2: len;
    if (len > info->precision && len > info->width)
    {
        lenmax(num, len, base, info);
        return ;
    }
    if (info->spec == 'p')
        info->precision += 2;
    managediffs(diffs, len, info, num);
    if (info->flags & MINUS)
        printlenprecnum(diffs[1], num, len, info);
    while (diffs[0]-- > 0)
        info->width += write(1, " ", 1);
    if (!(info->flags & MINUS))
        printlenprecnum(diffs[1], num, len, info);
}