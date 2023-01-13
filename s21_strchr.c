#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  while (*str) {
    if (*str == c) {
      return ((char *)str);
    }
    ++str;
  }
  if (c == '\0') return ((char *)str);
  return 0;
}