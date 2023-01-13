#include "test_string.h"

START_TEST(test1) {
  s21_size_t n = 2;
  char str[16] = "qwert";
  int c = '\0';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test2) {
  s21_size_t n = 10;
  char str[16] = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test3) {
  s21_size_t n = 2;
  char str[16] = "fdsasdf";
  int c = 'a';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test4) {
  s21_size_t n = 14;
  char str[16] = "fdsasdf";
  int c = 'a';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test5) {
  s21_size_t n = 7;
  char str[16] = "";
  int c = '\0';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test6) {
  s21_size_t n = 0;
  char str[16] = "fdsasdf";
  int c = ' ';
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(test7) {
  s21_size_t n = 5 * sizeof(int);
  int str[16] = {134, 234, 543, 345, 253, 1, 2, 3};
  int c = 543;
  ck_assert_ptr_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");
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
