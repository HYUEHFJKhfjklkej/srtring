// #include "s21_string.h"
// #include "s21_string.h"

#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_
// typedef unsigned long long s21_size_t;
typedef struct {
  int L;
  int l;
  int h;
  int len_str;
  int len_format;
  int res;
  int i;
  int star;
  int width;
  int width_minus;
  int last;
  int index_width;
} flaggs;

// #define LONG_MAX ((long)(~0UL >> 1))
// #define LONG_MIN (~LONG_MAX)

long int s21_strtol(const char *nptr, char **endptr, int base);
long double s21_strtold(const char *str, char **endptr);
#define s21_NULL (void *)0

#endif  // SRC_S21_SSCANF_H_