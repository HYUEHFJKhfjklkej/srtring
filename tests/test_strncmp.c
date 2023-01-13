#include "test_string.h"

START_TEST(test1) {
  s21_size_t n = 0;
  char str1[16] = "";
  char str2[16] = "";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test2) {
  s21_size_t n = 5;
  char str1[16] = "123456";
  char str2[16] = "123456";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test3) {
  s21_size_t n = 6;
  char str1[16] = "asd";
  char str2[16] = "asdfgh";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test4) {
  s21_size_t n = 6;
  char str1[16] = "asdfgg";
  char str2[16] = "asd";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test5) {
  s21_size_t n = 3;
  char str1[16] = "";
  char str2[16] = "asdf";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test6) {
  s21_size_t n = 3;
  char str1[16] = " sadf";
  char str2[16] = " ";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test7) {
  s21_size_t n = 2;
  char str1[16] = "asd";
  char str2[16] = "asdfgg";
  int orig = strncmp(str1, str2, n);
  int s21 = s21_strncmp(str1, str2, n);
  if (orig == -1 && s21 < 0) s21 = -1;
  if (orig == 1 && s21 > 0) s21 = 1;
  ck_assert_int_eq(orig, s21);
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");
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
