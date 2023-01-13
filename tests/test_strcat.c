#include "test_string.h"

START_TEST(test1) {
  char str1[16] = "abc";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test2) {
  char str1[16] = "";
  char str2[16] = "qwe";
  char str3[16] = "qwe";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test3) {
  char str1[16] = "abc";
  char str2[16] = "";
  char str3[16] = "";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test4) {
  char str1[16] = "danila";
  char str2[16] = "clown";
  char str3[16] = "clown";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test5) {
  char str1[16] = "danila";
  char str2[16] = "sere\0clown";
  char str3[16] = "sere\0clown";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test6) {
  char str1[16] = "";
  char str2[16] = "";
  char str3[16] = "";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

START_TEST(test7) {
  char str1[16] = "dan\0ila";
  char str2[16] = "clown";
  char str3[16] = "clown";
  s21_strcat(str2, str1);
  strcat(str3, str1);
  ck_assert_str_eq(str2, str3);
}
END_TEST

Suite *suite_strcat(void) {
  Suite *s = suite_create("suite_strcat");
  TCase *tc = tcase_create("strcat_tc");
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
