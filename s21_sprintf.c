#include "s21_string.h"

int s21_sprintf_s(char** str, const char* string, FormatSpec specs);
int s21_sprintf_d(char** str, long long int i, int base, FormatSpec specs);
int s21_sprintf_e(char** str, long double e, int g, int char_case,
                  FormatSpec specs);
int get_power(long double d, FormatSpec specs);
void raund(char* str);
int s21_sprintf_g(char** str, long double g, int char_case, FormatSpec specs);
int s21_sprintf_f(char** str, long double d, int g, FormatSpec specs);
int s21_sprintf_u(char** str, unsigned long long int u, int base, int char_case,
                  FormatSpec specs);

int s21_sprintf(char* str, const char* format, ...) {
  int chars_count = 0;
  va_list arg;
  va_start(arg, format);
  for (const char* j = format; *j; j++) {
    if (*j == '%') {
      j++;
      FormatSpec specs = {0};
      specs.precision = -1;
      while (!s21_strchr("cdieEfgGosuxXpn", *j)) {
        if (*j == '%') {
          chars_count++;
          *str = *j;
          str++;
          j++;
        }
        if (*j == '-') {
          j++;
          specs.flag = 1;
        }
        if (*j == '+') {
          j++;
          specs.sign = 1;
        }
        if (*j == ' ') {
          j++;
          specs.space = 1;
        }
        if (*j == '#') {
          j++;
          specs.sharp = 1;
        }
        while (*j == '0') {
          j++;
          specs.zero = 1;
        }
        if (*j == '*') {
          specs.width = va_arg(arg, int);
          j++;
        } else {
          while (*j >= '0' && *j <= '9') {
            specs.width *= 10;
            specs.width += *j - '0';
            j++;
          }
        }
        if (*j == '.') {
          specs.precision = 0;
          j++;
          if (*j == '*') {
            specs.precision = va_arg(arg, int);
            j++;
          } else {
            while (*j >= '0' && *j <= '9') {
              specs.precision *= 10;
              specs.precision += *j - '0';
              j++;
            }
          }
        }
        if (*j == 'h') {
          specs.length = *j;
          j++;
        } else if (*j == 'l') {
          specs.length = *j;
          j++;
        } else if (*j == 'L') {
          specs.length = *j;
          j++;
        }
      }
      FormatSpec temp = specs;
      switch (*j) {
        case 'c': {
          char c[2];
          c[0] = (char)va_arg(arg, int);
          c[1] = '\0';
          chars_count += s21_sprintf_s(&str, c, specs);
          break;
        }
        case 'i':
        case 'd':
          chars_count +=
              s21_sprintf_d(&str, va_arg(arg, long long int), 10, specs);
          break;
        case 'e': {
          if (specs.length == 'L') {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, long double), 0, 'e', specs);
          } else {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, double), 0, 'e', specs);
          }
          break;
        }
        case 'E': {
          if (specs.length == 'L') {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, long double), 0, 'E', specs);
          } else {
            chars_count +=
                s21_sprintf_e(&str, va_arg(arg, double), 0, 'E', specs);
          }
          break;
        }
        case 'f': {
          if (specs.length == 'L') {
            chars_count +=
                s21_sprintf_f(&str, va_arg(arg, long double), 0, specs);
          } else {
            chars_count += s21_sprintf_f(&str, va_arg(arg, double), 0, specs);
          }
          break;
        }
        case 'g':
          chars_count += s21_sprintf_g(&str, va_arg(arg, double), 'e', specs);
          break;
        case 'G':
          chars_count += s21_sprintf_g(&str, va_arg(arg, double), 'E', specs);
          break;
        case 'o':
          chars_count += s21_sprintf_u(
              &str, va_arg(arg, unsigned long long int), 8, 'a', specs);
          break;
        case 's': {
          char* string = va_arg(arg, char*);
          chars_count += s21_sprintf_s(&str, string, specs);
          break;
        }
        case 'u':
          temp.flag = 0;
          chars_count += s21_sprintf_u(
              &str, va_arg(arg, unsigned long long int), 10, 'a', temp);
          break;
        case 'x':
          chars_count += s21_sprintf_u(
              &str, va_arg(arg, unsigned long long int), 16, 'a', specs);
          break;
        case 'X':
          chars_count += s21_sprintf_u(
              &str, va_arg(arg, unsigned long long int), 16, 'A', specs);
          break;
        case 'p':
          temp = specs;
          temp.sharp = -1;
          temp.length = 'l';
          chars_count += s21_sprintf_u(
              &str, va_arg(arg, unsigned long long int), 16, 'a', temp);
          break;
        case 'n':
          *va_arg(arg, int*) = chars_count;
          break;
      }
    } else {
      *str = *j;
      str++;
      chars_count++;
    }
    if (!*j) break;
  }
  *str = '\0';
  va_end(arg);
  return chars_count;
}

int s21_sprintf_s(char** str, const char* string, FormatSpec specs) {
  int chars_count = 0, flag_char = ' ';
  if (specs.zero) flag_char = '0';
  if (specs.precision != 0) {
    if (specs.precision == -1) {
      specs.precision = 0;
      for (const char* p = string; *p; p++) specs.precision++;
    }
    if (specs.width > 0) specs.width -= specs.precision;
    if (specs.width > 0) specs.precision += specs.width;
    if (!specs.flag) {
      for (; specs.width > 0; specs.width--) {
        **str = flag_char;
        chars_count++;
        (*str)++;
      }
    }
    for (; *string; string++) {
      **str = *string;
      chars_count++;
      (*str)++;
    }
    for (; specs.width > 0; specs.width--) {
      **str = flag_char;
      chars_count++;
      (*str)++;
    }
    if (specs.precision < chars_count)
      *str = *str - (chars_count - specs.precision);
  }
  return chars_count;
}

int s21_sprintf_d(char** str, long long int i, int base, FormatSpec specs) {
  char buf[INT_BUFER_LEN];
  char* s = buf + INT_BUFER_LEN - 1;
  int char_count, num_count;
  if (specs.length == 'h') {
    i = (short int)i;
  } else if (specs.length == 0) {
    i = (int)i;
  }
  char_count = 0;
  if (i < 0) {
    specs.sign = '-';
    i = -i;
  } else if (specs.sign) {
    specs.sign = '+';
  } else if (specs.space) {
    specs.sign = ' ';
  }
  *s = '\0';
  num_count = 0;
  if (i == 0) {
    s--;
    *s = '0';
    num_count++;
  }
  while (i) {
    long long int temp = 0;
    s--;
    num_count++;
    if (base) temp = i % base;
    temp = (temp < 0) ? -temp : temp;
    *s = temp + '0';
    if (base) i /= base;
  }
  if (specs.precision == -2) {
    specs.precision += num_count;
    while (specs.precision < 0) {
      s--;
      *s = '0';
      specs.precision++;
    }
    if (specs.sign) {
      s--;
      *s = specs.sign;
    }
  } else {
    if (specs.sign) {
      s--;
      *s = specs.sign;
    }
    if (specs.precision > 0) {
      specs.precision -= num_count;
      while (specs.precision > 0) {
        s--;
        *s = '0';
        specs.precision--;
      }
    }
  }
  if (specs.width < 0) specs.width = 0;
  specs.precision = -1;
  return char_count + s21_sprintf_s(str, s, specs);
}

int s21_sprintf_e(char** str, long double e, int g, int char_case,
                  FormatSpec specs) {
  char buf[DBL_BUFER_LEN], *s;
  int char_count;
  char_count = 0;
  if (specs.precision == -1) specs.precision = 6;
  FormatSpec temp = {0};
  temp.precision = -1;
  if (e < 0) {
    char_count += s21_sprintf_s(str, "-", temp);
    e = -e;
  } else if (specs.sign) {
    char_count += s21_sprintf_s(str, "+", temp);
  } else if (specs.space) {
    char_count += s21_sprintf_s(str, " ", temp);
  }
  int power = get_power(e, specs);
  if (power > 0) {
    for (int i = power; i > 0; i--) e /= 10;
  } else {
    for (int i = power; i; i++) e *= 10;
  }
  long double frac = e - (int)e;
  s = buf;
  s21_sprintf_d(&s, (long long int)e, 10, temp);
  if (specs.precision > 0) {
    s21_sprintf_s(&s, ".", temp);
    specs.sharp = 0;
  }
  if (specs.precision) {
    for (int i = specs.precision; i > 0; i--) frac = frac * 10;
    FormatSpec temp2 = {0};
    temp2.precision = specs.precision;
    s21_sprintf_d(&s, (int)(frac), 10, temp2);
    *s = '\0';
    if (g) {
      do {
        *s = 0;
        s--;
      } while (*s == '0');
    }
  }
  frac = (frac - (int)frac) * 10;
  if ((int)frac > 4) raund(buf);
  if (specs.sharp) {
    *s = '.';
    s++;
  }
  *s = char_case;
  s++;
  temp.precision = -2;
  temp.sign = 1;
  s21_sprintf_d(&s, power, 10, temp);

  *s = 0;
  temp.width = specs.width - char_count;
  temp.precision = -1;
  temp.flag = specs.flag;
  temp.zero = specs.zero;
  char_count += s21_sprintf_s(str, buf, temp);
  return char_count;
}

void raund(char* str) {
  char* p = str + s21_strlen(str) - 1;
  *p = *p + 1;
  while (*p > '9') {
    *p = '0';
    p--;
    *p = *p + 1;
  }
}

int get_power(long double d, FormatSpec specs) {
  int power = 0;
  if (d < 0) d = -d;
  double calc_error = 1.0;
  for (int i = specs.precision; i > 0; i--) calc_error /= 10;
  if (d > calc_error) {
    for (long double i = d; i > 10; i /= 10) {
      power++;
    }
  } else {
    for (; (d < 10); d *= 10) {
      power--;
    }
    power++;
  }
  return power;
}

int s21_sprintf_g(char** str, long double g, int char_case, FormatSpec specs) {
  int char_count = 0;
  int power = get_power(g, specs);
  if (specs.precision == -1) specs.precision = 6;
  if (specs.precision > power && power >= -4) {
    specs.precision = specs.precision - power - 1;
    char_count += s21_sprintf_f(str, g, 1, specs);
  } else {
    char_count += s21_sprintf_e(str, g, 1, char_case, specs);
  }
  return char_count;
}

int s21_sprintf_f(char** str, long double d, int g, FormatSpec specs) {
  char buf[DBL_BUFER_LEN], *s;
  int char_count;
  long double frac = d - (int)d;
  char_count = 0;
  if (specs.precision == -1) specs.precision = 6;
  FormatSpec temp = {0};
  temp.precision = -1;
  if (d < 0) {
    char_count += s21_sprintf_s(str, "-", temp);
    d = -d;
    frac = -frac;
  } else if (specs.sign) {
    char_count += s21_sprintf_s(str, "+", temp);
  } else if (specs.space) {
    char_count += s21_sprintf_s(str, " ", temp);
  }
  s = buf;
  temp.length = 'l';
  char_count += s21_sprintf_d(&s, (long long int)d, 10, temp);
  if (specs.precision > 0) {
    char_count += s21_sprintf_s(&s, ".", temp);
    specs.sharp = 0;
  }
  for (int i = specs.precision; i > 0; i--) frac = frac * 10;
  if (specs.precision) {
    temp.precision = specs.precision;
    temp.length = 0;
    char_count += s21_sprintf_d(&s, (int)(frac), 10, temp);
    if (g) {
      do {
        *s = 0;
        s--;
      } while (*s == '0');
    }
  }
  frac = (frac - (int)frac) * 10;
  if (specs.sharp) {
    *s = '.';
    s++;
  }
  *s = '\0';
  if ((int)frac > 5) {
    raund(buf);
  }
  specs.precision = -1;
  return char_count + s21_sprintf_s(str, buf, specs);
}

int s21_sprintf_u(char** str, unsigned long long int u, int base, int char_case,
                  FormatSpec specs) {
  char buf[INT_BUFER_LEN];
  char* s = buf + INT_BUFER_LEN - 1;
  int char_count, num_count;

  if (specs.length == 'h') {
    u = (unsigned short int)u;
  } else if (specs.length == 0) {
    u = (unsigned int)u;
  }

  char_count = 0;
  *s = '\0';
  num_count = 0;
  if (u == 0) {
    s--;
    *s = '0';
    num_count++;
  }
  while (u) {
    int temp = 0;
    s--;
    num_count++;
    if (base) temp = u % base;
    if (temp >= 10) temp += char_case - '0' - 10;
    *s = temp + '0';
    if (base) u /= base;
  }
  if (specs.precision > 0) {
    specs.precision -= num_count;
    while (specs.precision > 0) {
      s--;
      *s = '0';
      specs.precision--;
    }
  }
  if (specs.width < 0) specs.width = 0;
  FormatSpec temp = {0};
  if (specs.sharp == 1) {
    if (base == 8) {
      s--;
      *s = '0';
    } else if (base == 16) {
      s--;
      *s = char_case + 23;
      s--;
      *s = '0';
    }
    temp.width = specs.width;
    temp.precision = -1;
    temp.flag = specs.flag;
    temp.zero = specs.zero;
    char_count += s21_sprintf_s(str, s, temp);
  } else if (specs.sharp == -1) {
    if (specs.zero) {
      specs.width = specs.width - num_count - 2;
      while (specs.width) {
        s--;
        *s = '0';
        specs.width--;
      }
    }
    s--;
    *s = 'x';
    s--;
    *s = '0';
    temp.width = specs.width;
    temp.precision = -1;
    temp.flag = specs.flag;
    temp.zero = specs.zero;
    char_count += s21_sprintf_s(str, s, temp);
  } else {
    temp.precision = -1;
    temp.width = specs.width;
    temp.flag = specs.flag;
    temp.zero = specs.zero;
    char_count += s21_sprintf_s(str, s, temp);
  }
  return char_count;
}