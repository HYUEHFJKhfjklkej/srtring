#include "test_string.h"

START_TEST(test1) {
  for (int i = -100; i < 400; i++)
    ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("strerror_tc");
  tcase_add_test(tc, test1);
  suite_add_tcase(s, tc);
  return s;
}
