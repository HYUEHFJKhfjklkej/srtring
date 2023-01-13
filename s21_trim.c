#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) return NULL;
  s21_size_t len = s21_strlen(src);
  s21_size_t trim_len = s21_strlen(trim_chars);
  s21_size_t start = 0;
  s21_size_t end = len - 1;
  while (start < len) {
    s21_size_t i;
    for (i = 0; i < trim_len; i++) {
      if (src[start] == trim_chars[i]) {
        start++;
        break;
      }
    }
    if (i == trim_len) break;
  }
  while (end > start) {
    s21_size_t i;
    for (i = 0; i < trim_len; i++) {
      if (src[end] == trim_chars[i]) {
        end--;
        break;
      }
    }
    if (i == trim_len) break;
  }
  if (end < start) {
    char *result = malloc(1);
    result[0] = '\0';
    return result;
  }
  s21_size_t new_len = end - start + 1;
  char *trimmed = malloc(new_len + 1);
  if (trimmed == NULL) {
    return NULL;
  }
  s21_memcpy(trimmed, src + start, new_len);
  trimmed[new_len] = '\0';
  return trimmed;
}

// void test_trim(const char *src, const char *trim_chars) {
//   char *trimmed = s21_trim(src, trim_chars);
//   if (trimmed == NULL) {
//     printf("Error: invalid input\n");
//     return;
//   }
//   printf("Input: '%s', Trim characters: '%s'\n", src, trim_chars);
//   printf("Trimmed: '%s'\n\n", trimmed);
//   free(trimmed);
// }

// int main() {
//   test_trim("  Hello, World!  ", " ");
//   test_trim("abcdefabcdef", "abc");
//   test_trim("abcdefabcdef", "ghi");
//   test_trim("  ", " ");
//   test_trim("", "");
//   test_trim(NULL, " ");
//   test_trim("  Hello, World!  ", NULL);
//   test_trim(NULL, NULL);
//   return 0;
// }