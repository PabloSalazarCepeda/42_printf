#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_check(char const *string, int i, va_list vargs);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);


int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    return 1;
}

int ft_printf(char const *string, ...) 
{
    int i = 0;
    int j = 0;
    va_list vargs;
    va_start(vargs, string);
    while (string[i] != '\0')
    {
        if (string[i] != '%')
        {
            j = j + ft_putchar_fd(string[i], 1);
        }
        else
        {
            i++;
            j = j + ft_check(string, i, vargs);
        }
        i++;
    }
    va_end(vargs);
    return j;
}

int ft_check(char const *string, int i, va_list vargs)
{
    int j;
    if (string[i] == 'c')
    {
        char c;
        c = va_arg(vargs, int);
        j = ft_putchar_fd(c, 1);
    }
    else if (string[i] == 's') {
        char *str = va_arg(vargs, char*);
        j = ft_putstr_fd(str, 1);
    }
    else if (string[i] == 'p') {

    }
    else if (string[i] == 'd' || string[i] == 'i') {
        int n;
        n = va_arg(vargs, int);
        j = ft_putnbr_fd(n, 1);
    }
    else if (string[i] == 'u') {
        unsigned int n;
        n = va_arg(vargs, unsigned int);
        j = ft_putnbr_fd(n, 1);
    }
    else if (string[i] == 'x') {

    }
    else if (string[i] == 'X') {

    }
    else
        j = ft_putchar_fd('%', 1);
    return (j);
}

int	ft_putstr_fd(char *s, int fd)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
	write(fd, s, i);
    return i;
}
int    ft_putnbr_fd(int n, int fd)
{
    int cont;

    cont = 0;
    if (n == -2147483648)
    {
        cont = ft_putstr_fd("-2147483648", 1);
    }
    else
    {
        if (n < 0)
        {
            cont = cont + ft_putchar_fd('-', fd);
            n = n * -1;
        }
        if (n > 9)
        {
            cont = cont + ft_putnbr_fd(n / 10, fd);
            n = n % 10;
        }
        if (n < 10)
            cont = cont + ft_putchar_fd(n + 48, fd);
    }
    return cont;
}
int ft_basehex(int n) {
    char *str = "0123456789ABCDEF";
    int cont = 0;
    if (n > 16)
    {
        cont = cont 
    }
    return cont;
}
int main(void) {
    int i, j;
    i = printf("%dasa%%s%X\n", 5, -1);
    j = ft_printf("%dasa%%s%u\n", 5, -1);
    printf("el print: %d\ntu print: %d\n", i, j);
    printf("%c\n", 'h');
    ft_printf("%c\n", 'h');

    return 0;
}