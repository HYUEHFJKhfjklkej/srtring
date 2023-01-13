#include "s21_string.h"

void* s21_to_upper(char* str) {
  int count = 0;
  while (*(str + count) != '\0') {
    if (*(str + count) > 96 && *(str + count) < 123)
      *(str + count) = *(str + count) - 32;
    count++;
  }
  return str;
}
