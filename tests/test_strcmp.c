#include "test_string.h"

START_TEST(test1) {
  char str1[16] = "";
  char str2[16] = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test2) {
  char str1[16] = "123456";
  char str2[16] = "123456";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test3) {
  char str1[16] = "asd";
  char str2[16] = "asdfgh";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test4) {
  char str1[16] = "asdfgg";
  char str2[16] = "asd";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test5) {
  char str1[16] = "";
  char str2[16] = "asdf";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test6) {
  char str1[16] = " sadf";
  char str2[16] = " ";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

START_TEST(test7) {
  char str1[16] = "asd";
  char str2[16] = "asdfgg";
  int orig = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  if (orig == -1 && s21 < 0) {
    s21 = -1;
  }
  if (orig == 1 && s21 > 0) {
    s21 = 1;
  }
  ck_assert_int_eq(orig, s21);
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("suite_strcmp");
  TCase *tc = tcase_create("strcmp_tc");
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
