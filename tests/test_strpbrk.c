#include "test_string.h"

START_TEST(test1) {
  char str[16] = "";
  char str2[16] = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

START_TEST(test2) {
  char str[16] = "";
  char str2[16] = "a";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

START_TEST(test3) {
  char str[16] = "\0fdsasdf";
  char str2[16] = "a";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

START_TEST(test4) {
  char str[16] = "fds\0asdf";
  char str2[16] = "ard";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

START_TEST(test5) {
  char str[16] = "fdsasDasdasdf";
  char str2[16] = "[";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

START_TEST(test6) {
  char str[16] = "fdsasdf9";
  char str2[16] = "7 9";
  ck_assert_ptr_eq(s21_strpbrk(str, str2), strpbrk(str, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc");
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  suite_add_tcase(s, tc);
  return s;
}
