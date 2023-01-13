#include "test_string.h"

START_TEST(test1) {
  s21_size_t n = 3;
  char str1[16] = "abc";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test2) {
  s21_size_t n = 0;
  char str1[16] = "";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test3) {
  s21_size_t n = 2;
  char str1[16] = "abc";
  char str2[16] = "";
  char str3[16] = "";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test4) {
  s21_size_t n = 4;
  char str1[16] = "danila";
  char str2[16] = "sereja clown";
  char str3[16] = "sereja clown";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test5) {
  s21_size_t n = 7;
  char str1[16] = "danila";
  char str2[16] = "sere\0ja clown";
  char str3[16] = "sere\0ja clown";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test6) {
  s21_size_t n = 0;
  char str1[16] = "";
  char str2[16] = "";
  char str3[16] = "";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test7) {
  s21_size_t n = 5;
  char str1[16] = "dan\0ila";
  char str2[16] = "sereja clown";
  char str3[16] = "sereja clown";
  s21_strncpy(str2, str1, n);
  strncpy(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc");
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  suite_add_tcase(s, tc);
  return s;
}
