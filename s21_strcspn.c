#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  const char *cp1, *cp2;
  for (cp1 = str1; *cp1 != '\0'; ++cp1)
    for (cp2 = str2; *cp2 != '\0'; ++cp2)
      if (*cp1 == *cp2) return (cp1 - str1);
  return (cp1 - str1);  // terminate nulls match
}