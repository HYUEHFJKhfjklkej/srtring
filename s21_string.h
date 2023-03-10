#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_sprintf.h"
#include "s21_sscanf.h"
#include "s21_strerror.h"

#define BUFF_SIZE 512

typedef long unsigned int s21_size_t;
typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)

// int s21_isdigit(char c);

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
int s21_sscanf(const char *str, const char *format, ...);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
// int s21_atoi(const char *str);
// int s21_antoi(const char *str, s21_size_t n);
// // long double s21_strtold(const char *buffer);

/* C# String Class Suite */

// void *s21_to_upper(const char *str);
// void *s21_to_lower(const char *str);
// void *s21_insert(const char *src, const char *str, s21_size_t start_index);
// void *s21_trim(const char *src, const char *trim_chars);

// void s21_trim_left(const char **src, const char *trim_chars,
//                    s21_size_t *src_len, const s21_size_t trim_chars_len);

// void s21_trim_right(const char **src, const char *trim_chars,
//                     s21_size_t *src_len, const s21_size_t trim_chars_len);

// int s21_is_delim(char ch, const char *delim);

/* Strtold */
void *s21_to_upper(char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// void symbolcat(char *dest, char cat);
// void s21_reverse(char s[]);
// void s21_itoa(int n, char s[]);
// char *itou_string(long num, char *res, int precision);
// char *itod_string(long num, char *res, int precision);
// char *ftodec_string(long double numf, char *res, s21_size_t presicion);
// char *itohex_string(unsigned long num, char *res, int precision);
// char *itohexup_string(unsigned long num, char *res, int precision);
// char *itoocto_string(unsigned long num, char *res);
// char *ftoexpo_string(long double numf, char *res, int presicion, int mode);
// char *ftogexpo_string(long double numf, char *res, int presicion, int mode);
int s21_sprintf(char *str, const char *format, ...);

// char *s21_strcat(char *dest, const char *src);
// char *s21_strncat(char *dest, const char *src, s21_size_t n);  // +
// char *s21_strchr(const char *source, int ch);
// int s21_strcmp(const char *str1, const char *str2);
// int s21_strncmp(const char *str1, const char *str2, s21_size_t n);  // +
// size_t s21_strlen(const char *str);
// char *s21_strcpy(char *dest, const char *source);
// char *s21_to_upper(char *str);
// void *s21_memset(void *str, int c, s21_size_t n);

// int s21_sprintf(char *str, const char *format, ...);

// void symbolcat(char *dest, char cat);
// void s21_reverse(char s[]);
// char *itod_string(long num, char *res, int precision);
// char *itou_string(long num, char *res, int precision);
// char *ftodec_string(long double numf, char *res, s21_size_t presicion,
//                     int gmode);
// char *itohex_string(unsigned long num, char *res, int precision);
// char *itohexup_string(unsigned long num, char *res, int precision);
// char *itoocto_string(unsigned long num, char *res);
// char *ftoexpo_string(long double numf, char *res, int presicion, int mode);
// char *ftogexpo_string(long double numf, char *res, int presicion, int mode);

#endif  // SRC_S21_STRING_H_