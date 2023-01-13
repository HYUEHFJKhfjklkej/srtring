#include "s21_string.h"

int is_decimal(char c) { return ((c >= '0') && (c <= '9')) ? 1 : 0; }

long s21_strtol(const char *restrict nptr, char **restrict endptr, int base) {
  const char *p = nptr, *endp;
  _Bool is_neg = 0, overflow = 0;
  /* Need unsigned so (-LONG_MIN) can fit in these: */
  unsigned long n = 0UL, cutoff;
  int cutlim;
  if (base < 0 || base == 1 || base > 36) {
    return 0L;
  }
  endp = nptr;
  if (*p == '-') {
    is_neg = 1, p++;
  }
  if (*p == '0') {
    p++;
    /* For strtol(" 0xZ", &endptr, 16), endptr should point to 'x';
     * pointing to ' ' or '0' is non-compliant.
     * (Many implementations do this wrong.) */
    endp = p;
    if (base == 16 && (*p == 'X' || *p == 'x')) {
      p++;
    } else if (base == 0) {
      if (*p == 'X' || *p == 'x') {
        base = 16, p++;
      } else {
        base = 8;
      }
    }
  } else if (base == 0) {
    base = 10;
  }
  cutoff = (is_neg) ? -(LONG_MIN / base) : LONG_MAX / base;
  cutlim = (is_neg) ? -(LONG_MIN % base) : LONG_MAX % base;
  while (1) {
    int c;
    if (*p >= 'A')
      c = ((*p - 'A') & (~('a' ^ 'A'))) + 10;
    else if (*p <= '9')
      c = *p - '0';
    else
      break;
    if (c < 0 || c >= base) break;
    endp = ++p;
    if (overflow) {
      /* endptr should go forward and point to the non-digit character
       * (of the given base); required by ANSI standard. */
      if (endptr) continue;
      break;
    }
    if (n > cutoff || (n == cutoff && c > cutlim)) {
      overflow = 1;
      continue;
    }
    n = n * base + c;
  }
  if (endptr) *endptr = (char *)endp;
  if (overflow) {
    // errno = ERANGE;
    return ((is_neg) ? LONG_MIN : LONG_MAX);
  }
  return (long)((is_neg) ? -n : n);
}

long double s21_strtold(const char *str, char **endptr) {
  if (endptr != s21_NULL) *endptr = (char *)str;

  if (str == s21_NULL) return 0;

  while (*str == ' ') str++;

  long double mult = 1;
  if (*str == '-') {
    mult = -1;
    str++;
  } else if (*str == '+')
    str++;

  long double ret = 0;

  while (*str && *str != '\n' && *str != '.') {
    if (*str == ' ' || *str == ',') {
      str++;
      continue;
    }

    if (*str < '0' || *str > '9') {
      if (endptr != s21_NULL) *endptr = (char *)str;
      return ret * mult;
    }

    ret *= 10;
    ret += *str - '0';

    str++;
  }

  if (*str == '.') {
    str++;
    long double div = 0.1F;
    while (*str && *str != '\n') {
      if (*str == ' ' || *str == ',') {
        str++;
        continue;
      }

      if (*str < '0' || *str > '9') {
        if (endptr != s21_NULL) *endptr = (char *)str;
        return ret * mult;
      }

      ret += (*str - '0') * div;
      div /= 10.0F;

      str++;
    }
  }

  if (endptr != s21_NULL) *endptr = (char *)str;

  return ret * mult;
}

void is_space(const char *str, flaggs *f) {
  while (str[f->i] == ' ' && (f->i < f->len_str)) {
    f->i++;
  }
}

void s21_sscanf_f(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '.' && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '.' && str[f->i] != '-') ||
          j == f->width) {
        break;
      }
    }
    res[j] = str[f->i];
    f->i++;
    j++;
  }
  if (res[0] == '\0') {
    return;
  }
  float *arg = va_arg(*list, float *);
  *arg = s21_strtold(res, s21_NULL);
}

void s21_sscanf_lf(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '.' && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '.' && str[f->i] != '-') ||
          j == f->width) {
        break;
      }
    }
    res[j] = str[f->i];
    f->i++;
    j++;
  }

  if (res[0] == '\0') {
    return;
  }
  long double *arg = va_arg(*list, long double *);
  *arg = s21_strtold(res, s21_NULL);
}

void s21_sscanf_c(const char *str, flaggs *f, va_list *list) {
  *va_arg(*list, char *) = str[f->i];
  f->i++;
}

void s21_sscanf_d(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-') || j == f->width) {
        break;
      }
    }
    res[j] = str[f->i];
    f->i++;
    j++;
  }
  f->width = 0;
  if (res[0] == '\0') {
    return;
  }
  if (f->l == 1) {
    long *arg = va_arg(*list, long *);

    *arg = s21_strtol(res, s21_NULL, 10);
    f->l = 0;
  } else if (f->h == 1) {
    short *arg = va_arg(*list, short *);
    *arg = s21_strtol(res, s21_NULL, 10);
    f->h = 0;
  } else {
    int *arg = va_arg(*list, int *);
    *arg = s21_strtol(res, s21_NULL, 10);
  }
}

void s21_sscanf_i(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  int z = 0;
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-' && str[f->i] != 'x' &&
           str[f->i] != 'X')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-') || j == f->width) {
        break;
      }
    }
    res[j] = str[f->i];
    f->i++;
    j++;
    if ((str[f->i] == 'x') || (str[f->i] == 'X')) {
      z = f->i;
    }
  }
  int z_z = z;
  if (res[0] == '\0') {
    return;
  }
  if ((str[z - 1] == '0') && (z >= 0)) {
    if ((str[z_z] == 'x') || (str[z_z] == 'X')) {
      if (f->l == 1) {
        long *arg = va_arg(*list, long *);
        *arg = strtol(res, s21_NULL, 16);
        f->i += 2;
      } else if (f->h == 1) {
        short *arg = va_arg(*list, short *);
        *arg = strtol(res, s21_NULL, 16);
        f->i += 2;
      } else {
        int *arg = va_arg(*list, int *);
        *arg = strtol(res, s21_NULL, 16);
        f->i += 2;
      }
    } else {
      if (f->l == 1) {
        long *arg = va_arg(*list, long *);
        *arg = s21_strtol(res, s21_NULL, 8);
        f->i++;
      } else if (f->h == 1) {
        short *arg = va_arg(*list, short *);
        *arg = s21_strtol(res, s21_NULL, 8);
        f->i++;
      } else {
        int *arg = va_arg(*list, int *);
        *arg = s21_strtol(res, s21_NULL, 8);
        f->i++;
      }
    }
  } else {
    if (f->l == 1) {
      long *arg = va_arg(*list, long *);
      *arg = s21_strtol(res, s21_NULL, 10);
      // f->i++;
    } else if (f->h == 1) {
      short *arg = va_arg(*list, short *);
      *arg = strtol(res, s21_NULL, 10);
      // f->i++;
    } else {
      int *arg = va_arg(*list, int *);
      *arg = s21_strtol(res, s21_NULL, 10);
      // f->i++;
    }
  }
}

void s21_sscanf_s(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (j == f->width && f->width > 0) {
      break;
    }
    res[j] = str[f->i];
    f->i++;
    j++;
  }
  if (res[0] == '\0') {
    return;
  }
  char *p = va_arg(*list, char *);
  s21_strcpy(p, res);
}

void s21_sscanf_u(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-') || j == f->width) {
        break;
      }
    }

    res[j] = str[f->i];
    f->i++;
    j++;
  }
  if (res[0] == '\0') {
    return;
  }

  if (f->l == 1) {
    unsigned long *arg = va_arg(*list, unsigned long *);
    *arg = s21_strtol(res, s21_NULL, 10);
    f->l = 0;
  } else if (f->h == 1) {
    unsigned short *arg = va_arg(*list, unsigned short *);
    *arg = s21_strtol(res, s21_NULL, 10);
    f->h = 0;
  } else {
    unsigned int *arg = va_arg(*list, unsigned int *);
    *arg = s21_strtol(res, s21_NULL, 10);
  }
}

void s21_sscanf_o(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";
  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-') || j == f->width) {
        break;
      }
    }

    res[j] = str[f->i];
    f->i++;
    j++;
  }
  if (res[0] == '\0') {
    return;
  }
  if (f->l == 1) {
    long *arg = va_arg(*list, long *);
    *arg = s21_strtol(res, s21_NULL, 8);
    f->l = 0;
  } else if (f->h == 1) {
    short *arg = va_arg(*list, short *);
    *arg = s21_strtol(res, s21_NULL, 8);
    f->h = 0;
  } else {
    int *arg = va_arg(*list, int *);
    *arg = s21_strtol(res, s21_NULL, 8);
  }
}

void s21_sscanf_x(const char *str, flaggs *f, va_list *list) {
  int j = 0;
  char res[8000] = "\0";

  is_space(str, f);
  while (str[f->i] != ' ' && (f->i <= f->len_str)) {
    if (f->width == 0) {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-')) {
        break;
      }
    } else {
      if ((!is_decimal(str[f->i]) && str[f->i] != '-') || j == f->width) {
        break;
      }
    }
    res[j] = str[f->i];
    f->i++;
    j++;
  }
  if (res[0] == '\0') {
    return;
  }
  if (f->l == 1) {
    long *arg = va_arg(*list, long *);
    *arg = s21_strtol(res, s21_NULL, 16);
    f->l = 0;
  } else if (f->h == 1) {
    short *arg = va_arg(*list, short *);
    *arg = s21_strtol(res, s21_NULL, 16);
    f->h = 0;
  } else {
    int *arg = va_arg(*list, int *);
    *arg = s21_strtol(res, s21_NULL, 16);
  }
}

void parce_format(const char *str, const char *format, flaggs *f,
                  va_list *list) {
  int j = 0;
  while (format[j] != '\0') {
    if (format[j] == '%') {
      j++;
      if (is_decimal(format[j])) {
        while (is_decimal(format[j])) {
          f->width = f->width * 10 + (format[j] - '0');
          j++;
        }
      }
      if (format[j] == 'l') {
        f->l = 1;
        j++;
      }
      if (format[j] == 'L') {
        f->L = 1;
        j++;
      }
      if (format[j] == 'h') {
        f->h = 1;
        j++;
      }
      if (format[j] == '*') {
        f->star = 1;
        j++;
      }
      if (format[j] == 'o') {
        f->star == 1 ? j++ : s21_sscanf_o(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'u') {
        f->star == 1 ? j++ : s21_sscanf_u(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'p') {
        if (f->star == 1) {
          j++;
          f->star = 0;
        } else {
          const char *p = str;
          void **ptr_p = va_arg(*list, void **);
          *ptr_p = (void *)strtol(p, (char **)&p, 16);
        }
        f->res++;
      }
      if (format[j] == 'i') {
        f->star == 1 ? j++ : s21_sscanf_i(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'f' || (format[j] == 'e') || (format[j] == 'E') ||
          (format[j] == 'g') || (format[j] == 'G')) {
        if (f->l == 1 || f->L == 1) {
          if (f->star == 1) {
            j++;
            f->star = 0;
            f->l = 0;
            f->L = 0;
          } else {
            s21_sscanf_lf(str, f, list);
            f->l = 0;
            f->L = 0;
          }
          f->l = 0;
        } else {
          if (f->star == 1) {
            j++;
            f->star = 0;
          } else {
            s21_sscanf_f(str, f, list);
          }
        }
        f->res++;
      }
      if (format[j] == 'c') {
        if (f->star == 1) {
          j++;
          f->star = 0;
        } else {
          s21_sscanf_c(str, f, list);
        }
        f->res++;
      }
      if (format[j] == 's') {
        f->star == 1 ? j++ : s21_sscanf_s(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'd') {
        f->star == 1 ? j++ : s21_sscanf_d(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'x' || format[j] == 'X') {
        f->star == 1 ? j++ : s21_sscanf_x(str, f, list);
        f->star = 0;
        f->res++;
      }
      if (format[j] == 'n') {
        *va_arg(*list, int *) = f->i;
      }
    }
    j++;
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list list;
  va_start(list, format);
  flaggs f = {0};
  f.width = 0;
  f.star = 0;
  f.res = 0;
  f.i = 0;
  f.l = 0;
  f.L = 0;
  f.last = 0;
  f.h = 0;
  f.index_width = 0;
  f.width_minus = 0;
  if (str != s21_NULL && format != s21_NULL) {
    f.len_str = s21_strlen(str);
    f.len_format = s21_strlen(format);
    parce_format(str, format, &f, &list);
  }
  va_end(list);
  return f.res;
}

// int main() {
// long a;
// int b, ib, ib2;
// unsigned int ob;
// unsigned int ob2;
// unsigned int ka;
// unsigned int ki;
// long a1;
// int b1;
// unsigned int b12, b22;
// int n12, n22, n31, n32, n41, n42, n1, n2;
// float f = 2;
// char s[20];
// float f1 = 2;
// double f11 = 2;
// double f12 = 2;m
// char s1[20];
// int *pipka, *bibka;
// char sinok[10], bobik[10], rt[1];

// int a11;
// int a22;
// s21_sscanf("-256", "%c%c%c%c%c", &a11, &a11, &a11, &a11, &a11);
// sscanf("-256", "%c", &a22);
// printf("%d\n", a11);
// printf("%d\n", a22);

// int a11;
// int a22;
// s21_sscanf("-256 2", "%li%n", &a, &n12);
// sscanf("-256 2", "%li%n", &a1, &n22);
// printf("%ld\n%d\n", a, n12);
// printf("%ld\n%d\n", a1, n22);

// int a11;
// int a22;
// s21_sscanf("-256 2", "%lo%n", &a, &n12);
// sscanf("-256 2", "%lo%n", &a1, &n22);
// printf("%ld\n%d\n", a, n12);
// printf("%ld\n%d\n", a1, n22);

// int a11;
// int a22;
// int lo_1, lo_2;
// int n_o1, n_o2;
// s21_sscanf("256 2", "%lo%n%o%n", &a, &n_o1, &lo_1, &n12);
// sscanf("256 2", "%lo%n%o%n", &a1, &n_o2, &lo_2, &n22);
// printf("%ld\n%d\n%d\n%d\n_", a, n_o1, lo_1, n12);
// printf("%ld\n%d\n%d\n%d", a1, n_o2, lo_2, n22);

// int a11;
// int a22;
// int n__1;
// int n__2;
// s21_sscanf(" -256", "%u%n", &a11, &n__1);
// sscanf(" -256", "%u%n", &a22, &n__2);
// printf("%d\n%d", a11, n__1);
// printf("%d\n%d", a22, n__2);

// s21_sscanf("-256 2", "%lu%n", &a, &n12);
// sscanf("-256 2", "%lu%n", &a1, &n22);
// printf("%ld\n%d\n", a, n12);
// printf("%ld\n%d\n", a1, n22);

// s21_sscanf("-10", "%x%n", &ki, &n1);
// sscanf("-10", "%x%n", &ka, &n2);
// printf("%x\n%d\n", ki, n1);
// printf("%x\n%d\n", ka, n2);

// s21_sscanf("256 ", "%x%n", &ob, &n12);
// sscanf("256 ", "%x%n", &ob2, &n22);
// printf("%d\n%d\n", ob, n12);
// printf("%d\n%d\n", ob2, n22);

// int n_1, n_2;
// s21_sscanf("gcs ", "%2s%n", s, &n_1);
// sscanf("gcs ", "%2s%n", s1, &n_2);
// printf("%s\n%d\n", s, n_1);
// printf("%s\n%d", s1, n_2);

// s21_sscanf("10", "%x%n", &ki, &n1);
// sscanf("10", "%x%n", &ka, &n2);
// printf("%x\n%d\n", ki, n1);
// printf("%x\n%d\n", ka, n2);

// s21_sscanf("564     3774", "%u%n%i", &b12, &n31, &ob);
// sscanf("564     3774", "%u%n%i", &b22, &n32, &ob2);
// printf("%d\n%d\n%d\n%d\n%d\n_", b12, n31, ob, n41, ib);
// printf("%d\n%d\n%d\n%d\n%d\n", b22, n32, ob2, n42, ib2);

// s21_sscanf("564     3774", "%u%n%o%n%i", &b12, &n31, &ob, &n41,
// &ib);
// sscanf("564     3774", "%u%n%o%n%i", &b22, &n32, &ob2, &n42, &ib2);
// printf("%d\n%d\n%d\n%d\n%d\n_", b12, n31, ob, n41, ib);
// printf("%d\n%d\n%d\n%d\n%d\n", b22, n32, ob2, n42, ib2);

// char m[100] = "\0";
// char m1[100] = "\0";
// printf("(%d)", s21_sscanf("564 3774 34 56 78", "%s%n%o%n%ld", m,
// &n31,
// &ob,
//                           &n41, &ib));
// printf("(%d)", sscanf("564 3774 34 56 78", "%s%n%o%n%ld", m1, &n32,
// &ob2,
//                       &n42, &ib2));
// s21_sscanf("564 3774 34 56 78", "%s%n%o%n%d", m, &n31, &ob, &n41,
// &ib);
// sscanf("564 3774 34 56 78", "%s%n%o%n%d", m1, &n32, &ob2, &n42,
// &ib2);
// printf("%s\n%d\n%d\n%d\n%d\n_", m, n31, ob, n41, ib);
// printf("%s\n%d\n%d\n%d\n%d\n", m1, n32, ob2, n42, ib2);

// int n_0, n_1;
// s21_sscanf("g", "%c%n", &bobik[1], &n_0);
// sscanf("g", "%c%n", &sinok[1], &n_1);
// printf("%c\n%d\n", bobik[1], n_0);
// printf("%c\n%d", sinok[1], n_1);

// s21_sscanf("%%", "%%", rt);
// sscanf("%%", "%%", rt);
// printf("%s", rt);

// s21_sscanf("21213", "%p", &bibka);
// sscanf("21213", "%p", &pipka);
// printf("%p\n", bibka);
// printf("%p\n", pipka);

// int c_n1, c_n2;
// long double ld_1, ld_2;
// s21_sscanf("1.23", "%lf%n", &ld_1, &c_n1);
// sscanf("1.23", "%lf%n", &ld_2, &c_n2);
// printf("%lf\n%d\n", ld_1, c_n1);
// printf("%lf\n%d", ld_2, c_n2);

//   char m[100] = "\0";
//   char m2[100] = "\0";
//   s21_sscanf("12.2 44", "%s", m);
//   sscanf("12.2 44", "%s", m2);
//   printf("%s\n", m);
//   printf("%s", m2);
// }
// int main() {
//   short a1, a2;
//   const char str[] = "0x12";
//   const char fstr[] = "%hi";
//   int res1 = s21_sscanf(str, fstr, &a1);
//   int res2 = sscanf(str, fstr, &a2);
//   printf("%d\n", a1);
//   printf("%d", a2);
// }