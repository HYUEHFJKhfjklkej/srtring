#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *simbol;
  const unsigned char *simbol2;
  simbol = (unsigned char *)dest;
  simbol2 = (unsigned char *)src;
  while (n-- > 0) *(simbol++) = *(simbol2++);
  return (dest);
}