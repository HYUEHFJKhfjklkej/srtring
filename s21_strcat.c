#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int i = 0, k = 0;
  while (dest[i] != '\0') i++;
  while (src[k] != '\0') {
    dest[i] = src[k];
    i++;
    k++;
  }
  dest[i] = '\0';
  return dest;
}
