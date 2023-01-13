#include "test_string.h"

START_TEST(test1) {
  char str[16] = "";
  int c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test2) {
  char str[16] = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test3) {
  char str[16] = "\0fdsasdf";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test4) {
  char str[16] = "fds\0asdf";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test5) {
  char str[16] = "fdsasDasdasdf";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test6) {
  char str[16] = "fdsasdf";
  int c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  suite_add_tcase(s, tc);
  return s;
}
