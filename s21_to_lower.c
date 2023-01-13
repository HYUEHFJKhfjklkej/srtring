#include "s21_string.h"

void* s21_to_lower(const char* str) {
  void* res = calloc(s21_strlen(str) + 1, sizeof(char));
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      ((char*)res)[i] = str[i] + 32;
    else
      ((char*)res)[i] = str[i];
  }
  ((char*)res)[s21_strlen(str)] = '\0';
  return res;
}
