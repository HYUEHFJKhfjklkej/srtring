#include "s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  s21_size_t count = 0, counter = 0;
  while ((*(str1 + count) != '\0' || *(str2 + count) != '\0') && counter != n) {
    if (*(str1 + count) != *(str2 + count))
      return *(str1 + count) - *(str2 + count);
    count++;
    counter++;
  }
  return 0;
}
