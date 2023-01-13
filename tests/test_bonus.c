#include "test_string.h"

START_TEST(test_trim) { s21_trim("  Hello, World!  ", " "); }
END_TEST

START_TEST(test_up) {
  char m[100] = "qwerty";
  s21_to_upper(m);
}
END_TEST

START_TEST(test_doun) {
  char m[100] = "qwerty";
  s21_to_lower(m);
}
END_TEST

START_TEST(test_insert) {
  char m[100] = "qwerty";
  char m2[100] = "qwe";
  s21_insert(m, m2, 2);
}
END_TEST

Suite *suite_bonus(void) {
  Suite *s = suite_create("test_bonus");
  TCase *tc = tcase_create("all fun");
  tcase_add_test(tc, test_trim);
  tcase_add_test(tc, test_up);
  tcase_add_test(tc, test_doun);
  tcase_add_test(tc, test_insert);
  suite_add_tcase(s, tc);
  return s;
}