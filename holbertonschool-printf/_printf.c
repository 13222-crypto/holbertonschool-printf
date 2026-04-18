#include "main.h"

int print_address(void *p, int minus, int width) {
    unsigned long addr = (unsigned long)p;
    int count = 0, len = 14; 
    if (!p) {
        char *n = "(nil)";
        while (n[count]) count += _putchar(n[count++]);
        return (count);
    }
    if (!minus) while (width-- > len) count += _putchar(' ');
    count += _putchar('0'); count += _putchar('x');
    count += print_base(addr, 16, 0, 0, 0, 0, 0, -1);
    if (minus) while (width-- > len) count += _putchar(' ');
    return (count);
}

int print_S(char *s) {
    int i, count = 0;
    char *hex = "0123456789ABCDEF";
    if (!s) s = "(null)";
    for (i = 0; s[i]; i++) {
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127) {
            count += _putchar('\\'); count += _putchar('x');
            count += _putchar(hex[(unsigned char)s[i] / 16]);
            count += _putchar(hex[(unsigned char)s[i] % 16]);
        } else count += _putchar(s[i]);
    }
    return (count);
}

int print_base(unsigned long n, int base, int hash, int upper, int zero, int minus, int width, int precision) {
    char *set = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    char buffer[64];
    int i = 0, count = 0, len = 0;
    unsigned long temp = n;
    if (precision == 0 && n == 0) return (0);
    do { buffer[i++] = set[temp % base]; temp /= base; } while (temp > 0);
    len = i;
    if (precision > len) len = precision;
    if (hash && n != 0) len += (base == 8) ? 1 : 2;
    if (!minus && !zero) while (width-- > len) count += _putchar(' ');
    if (hash && n != 0) { count += _putchar('0'); if (base == 16) count += _putchar(upper ? 'X' : 'x'); }
    if (zero && !minus) while (width-- > len) count += _putchar('0');
    while (precision-- > i) count += _putchar('0');
    while (--i >= 0) count += _putchar(buffer[i]);
    if (minus) while (width-- > len) count += _putchar(' ');
    return (count + len - (hash && n != 0 ? (base == 8 ? 1 : 2) : 0));
}

int print_number(long n, int plus, int space, int zero, int minus, int width, int precision) {
    unsigned long n1;
    char buffer[64];
    int i = 0, count = 0, len = 0, neg = 0;
    if (n < 0) { n1 = -n; neg = 1; } else n1 = n;
    if (precision == 0 && n == 0) return (0);
    do { buffer[i++] = (n1 % 10) + '0'; n1 /= 10; } while (n1 > 0);
    len = i;
    if (precision > len) len = precision;
    if (neg || plus || space) len++;
    if (!minus && !zero) while (width-- > len) count += _putchar(' ');
    if (neg) count += _putchar('-'); else if (plus) count += _putchar('+'); else if (space) count += _putchar(' ');
    if (zero && !minus) while (width-- > len) count += _putchar('0');
    while (precision-- > i) count += _putchar('0');
    while (--i >= 0) count += _putchar(buffer[i]);
    if (minus) while (width-- > len) count += _putchar(' ');
    return (count + (len - (neg || plus || space ? 1 : 0)));
}

int print_rev(char *s) {
    int i = 0, count = 0;
    if (!s) s = "(null)";
    while (s[i]) i++;
    while (--i >= 0) count += _putchar(s[i]);
    return (count);
}

int print_rot13(char *s) {
    int i, j, count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    if (!s) s = "(null)";
    for (i = 0; s[i]; i++) {
        for (j = 0; in[j]; j++) if (s[i] == in[j]) { count += _putchar(out[j]); break; }
        if (!in[j]) count += _putchar(s[i]);
    }
    return (count);
}

int _printf(const char *format, ...) {
    va_list args;
    int i = 0, count = 0, plus, space, hash, zero, minus, width, precision, l, h;
    if (!format || (format[0] == '%' && !format[1])) return (-1);
    va_start(args, format);
    while (format && format[i]) {
        if (format[i] == '%') {
            plus = space = hash = zero = minus = width = l = h = 0; precision = -1; i++;
            while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-') {
                if (format[i] == '+') plus = 1; else if (format[i] == ' ') space = 1;
                else if (format[i] == '#') hash = 1; else if (format[i] == '0') zero = 1;
                else if (format[i] == '-') minus = 1; i++;
            }
            if (format[i] == '*') { width = va_arg(args, int); i++; }
            else { while (format[i] >= '0' && format[i] <= '9') width = width * 10 + (format[i++] - '0'); }
            if (format[i] == '.') { i++; if (format[i] == '*') { precision = va_arg(args, int); i++; }
                else { precision = 0; while (format[i] >= '0' && format[i] <= '9') precision = precision * 10 + (format[i++] - '0'); }
            }
            if (format[i] == 'l') { l = 1; i++; } else if (format[i] == 'h') { h = 1; i++; }
            if (format[i] == 'd' || format[i] == 'i') {
                long n = l ? va_arg(args, long) : (h ? (short)va_arg(args, int) : va_arg(args, int));
                count += print_number(n, plus, space, zero, minus, width, precision);
            } else if (format[i] == 'u' || format[i] == 'o' || format[i] == 'x' || format[i] == 'X' || format[i] == 'b') {
                unsigned long n = l ? va_arg(args, unsigned long) : (h ? (unsigned short)va_arg(args, int) : va_arg(args, unsigned int));
                if (format[i] == 'b') {
                    int b_i = 0; char b_buf[64]; do { b_buf[b_i++] = (n % 2) + '0'; n /= 2; } while (n > 0);
                    while (--b_i >= 0) count += _putchar(b_buf[b_i]);
                } else count += print_base(n, (format[i] == 'o' ? 8 : (format[i] == 'u' ? 10 : 16)), hash, (format[i] == 'X'), zero, minus, width, precision);
            } else if (format[i] == 'p') count += print_address(va_arg(args, void *), minus, width);
            else if (format[i] == 'S') count += print_S(va_arg(args, char *));
            else if (format[i] == 'r') count += print_rev(va_arg(args, char *));
            else if (format[i] == 'R') count += print_rot13(va_arg(args, char *));
            else if (format[i] == 'c') count += _putchar(va_arg(args, int));
            else if (format[i] == 's') {
                char *s = va_arg(args, char *);
                int j = 0; if (!s) s = "(null)";
                while (s[j] && (precision < 0 || j < precision)) count += _putchar(s[j++]);
            } else if (format[i] == '%') count += _putchar('%');
            else { count += _putchar('%'); count += _putchar(format[i]); }
        } else count += _putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
