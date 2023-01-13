#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  void* res = calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char));
  if (s21_strlen(src) < start_index) {
    free(res);
    res = s21_NULL;
  } else {
    s21_size_t lensrc = s21_strlen(src), lenstr = s21_strlen(str);
    for (s21_size_t i = 0; i < start_index; i++) ((char*)res)[i] = src[i];
    for (s21_size_t j = 0; j < lenstr; j++)
      ((char*)res)[j + start_index] = str[j];
    for (s21_size_t g = 0; g < lensrc - start_index; g++)
      ((char*)res)[g + start_index + lenstr] = src[g + start_index];
    ((char*)res)[lensrc + lenstr] = '\0';
  }
  return res;
}
