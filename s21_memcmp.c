#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i;
  unsigned char *simbol, *simbol2;
  if (n == 0) return 0;
  simbol = (unsigned char *)str1;
  simbol2 = (unsigned char *)str2;
  i = 0;
  while (*simbol == *simbol2 && ++i < n) {
    simbol++;
    simbol2++;
  }
  return ((int)(*simbol - *simbol2));
}