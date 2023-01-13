#include "test_string.h"

START_TEST(test1) {
  s21_size_t n = 3;
  char str1[16] = "abc";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test2) {
  s21_size_t n = 0;
  char str1[16] = "";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test3) {
  s21_size_t n = 2;
  char str1[16] = "abc";
  char str2[16] = "";
  char str3[16] = "";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test4) {
  s21_size_t n = 4;
  char str1[16] = "danila";
  char str2[16] = "sereja clown";
  char str3[16] = "sereja clown";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test5) {
  s21_size_t n = 7;
  char str1[16] = "danila";
  char str2[16] = "sere\0ja clown";
  char str3[16] = "sere\0ja clown";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test6) {
  s21_size_t n = 0;
  char str1[16] = "";
  char str2[16] = "";
  char str3[16] = "";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test7) {
  s21_size_t n = 5;
  char str1[16] = "dan\0ila";
  char str2[16] = "sereja clown";
  char str3[16] = "sereja clown";
  s21_memmove(str2, str1, n);
  memmove(str3, str1, n);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test8) {
  s21_size_t n = 5 * sizeof(int);
  int str1[16] = {1, 2, 3, 4, 5, 7, 8, 9};
  int str2[16];
  int str3[16];
  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);
  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

Suite *suite_memmove(void) {
  Suite *s = suite_create("suite_memmove");
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);
  suite_add_tcase(s, tc);
  return s;
}
