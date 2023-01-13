#include "test_string.h"

START_TEST(test1) {
  char str1[16] = "";
  char str2[16] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test2) {
  char str1[16] = "123456";
  char str2[16] = "123456";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test3) {
  char str1[16] = "asd";
  char str2[16] = "qwe";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test4) {
  char str1[16] = "asdfggweq";
  char str2[16] = "asd";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test5) {
  char str1[16] = "";
  char str2[16] = "asdf";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test6) {
  char str1[16] = " sadf";
  char str2[16] = " ";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test7) {
  char str1[16] = "asdfghjk";
  char str2[16] = "fgh";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

Suite *suite_strspn(void) {
  Suite *s = suite_create("suite_strspn");
  TCase *tc = tcase_create("strspn_tc");
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
