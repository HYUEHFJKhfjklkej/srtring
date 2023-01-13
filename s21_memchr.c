#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i;
  unsigned char *ptr;
  i = 0;
  ptr = (unsigned char *)str;
  while (++i <= n)
    if (*(ptr++) == (unsigned char)c) return ((void *)--ptr);
  return s21_NULL;
}