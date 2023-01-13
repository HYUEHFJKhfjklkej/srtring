#include "test_string.h"

START_TEST(test_c) {
  char a11;
  char a22;
  int res1 = s21_sscanf("-256", "%c", &a11);
  int res2 = sscanf("-256", "%c", &a22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a11, a22);
}
END_TEST

START_TEST(test2_str) {
  char m[100] = "\0";
  char m2[100] = "\0";
  int res1 = s21_sscanf("12.2 44", "%s", m);
  int res2 = sscanf("12.2 44", "%s", m2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(m, m2);
}
END_TEST

START_TEST(test3_lfn) {
  int c_n1, c_n2;
  long double ld_1, ld_2;
  int res1 = s21_sscanf("-1.23+1.12", "%Lf%n", &ld_1, &c_n1);
  int res2 = sscanf("-1.23+1.12", "%Lf%n", &ld_2, &c_n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c_n1, c_n2);
}
END_TEST

START_TEST(test4_chars) {
  long double ld_1, ld_2;
  int res1 = s21_sscanf("+1.23 +1.12", "%Lf", &ld_1);
  int res2 = sscanf("+1.23 +1.12", "%Lf", &ld_2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test5_special_symb) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\v\t";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test6_chars) {
  int *pipka, *bibka;
  int res1 = s21_sscanf("21213", "%p", &bibka);
  int res2 = sscanf("21213", "%p", &pipka);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test7_chars) {
  int d, d1, n12, n22;
  long int a, a1;
  s21_sscanf("256 234", "%1ld%1d%n", &a, &d, &n12);
  sscanf("256 234", "%1ld%1d%n", &a1, &d1, &n22);
  int res1 = s21_sscanf("256 234", "%1ld%1d%n", &a, &d, &n12);
  int res2 = sscanf("256 234", "%1ld%1d%n", &a1, &d1, &n22);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(d, d1);
  ck_assert_double_eq(n12, n22);
}
END_TEST

START_TEST(test9_chars) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "qwer";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  unsigned int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  unsigned int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test10_chars) {
  unsigned int a11;
  unsigned int a22;
  unsigned int res1 = s21_sscanf(" 25612132", "%2o", &a11);
  unsigned int res2 = sscanf(" 25612132", "%2o", &a22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a11, a22);
}
END_TEST

START_TEST(test11_chars) {
  unsigned int lo_1, lo_2;
  int n_o1, n_o2;
  long unsigned int a, a1;
  int n12, n22;
  int res1 = s21_sscanf("256 2", "%lo%n%o%n", &a, &n_o1, &lo_1, &n12);
  int res2 = sscanf("256 2", "%lo%n%o%n", &a1, &n_o2, &lo_2, &n22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(lo_1, lo_2);
  ck_assert_int_eq(n_o1, n_o2);
}
END_TEST

START_TEST(test12_chars) {
  unsigned int a11;
  unsigned int a22;
  int n__1;
  int n__2;
  int res1 = s21_sscanf(" -256", "%u%n", &a11, &n__1);
  int res2 = sscanf(" -256", "%u%n", &a22, &n__2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test13_int) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%d %d %d %d";
  const char str[] = "3 12 123 1543";

  long int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  long int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test14_short) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "32767 -32767 0 1432";
  const char fstr[] = "%hd %hd %hd %hd";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test15_long) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "2147483647 -2147483647 0 1432";
  const char fstr[] = "%ld %ld %ld %ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test16_int_width) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "3 12 123 1543";
  const char fstr[] = "%1ld %3ld %1ld %4ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test17_int_width) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1234";
  const char fstr[] = "%1ld %1ld %1ld %1ld";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test18_int_width) {
  float f, f1;
  int n2, n1;
  int res1 = s21_sscanf("-23.2345", "%2f%n", &f, &n2);
  int res2 = sscanf("-23.2345", "%2f%n", &f1, &n1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test19_int_width) {
  int i_1, i_2, b, b1, n2, n1;
  int res1 = s21_sscanf("89   12", "%d%i%n", &b, &i_1, &n2);
  int res2 = sscanf("89   12", "%d%i%n", &b1, &i_2, &n1);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(b, b1);
  //   ck_assert_int_eq(n2, n1);
}
END_TEST

START_TEST(test21_int_i) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 0x600 700";

  int res1 = s21_sscanf(str, "%li %li %li %li", &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, "%li %li %li %li", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test73_hex) {
  unsigned a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test74_hex) {
  unsigned a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test75_hex) {
  unsigned short a1, a2;
  const char str[] = "0x12";
  const char fstr[] = "%hx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test76_hex) {
  unsigned int a1, a2;
  const char str[] = "0x12";
  const char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test77_hex) {
  short a1, a2;
  const char str[] = "0x12";
  const char fstr[] = "%hi";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test78_hex) {
  int a1, a2;
  const char str[] = "0x12";
  const char fstr[] = "%i";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test79_hex) {
  long a1, a2;
  const char str[] = "0x12";
  const char fstr[] = "%li";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
START_TEST(test80_hex) {
  short a1, a2;
  const char str[] = "012";
  const char fstr[] = "%hi";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test81_hex) {
  int a1, a2;
  const char str[] = "012";
  const char fstr[] = "%i";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test82_hex) {
  long a1, a2;
  const char str[] = "012";
  const char fstr[] = "%li";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *sscnaf_s21(void) {
  Suite *s = suite_create("suite_sscanf");
  TCase *tc = tcase_create("sscanf_tc");
  tcase_add_test(tc, test_c);
  tcase_add_test(tc, test2_str);
  tcase_add_test(tc, test3_lfn);
  tcase_add_test(tc, test4_chars);
  tcase_add_test(tc, test5_special_symb);
  tcase_add_test(tc, test6_chars);
  tcase_add_test(tc, test7_chars);
  tcase_add_test(tc, test9_chars);
  tcase_add_test(tc, test10_chars);
  tcase_add_test(tc, test11_chars);
  tcase_add_test(tc, test12_chars);
  tcase_add_test(tc, test13_int);
  tcase_add_test(tc, test14_short);
  tcase_add_test(tc, test15_long);
  tcase_add_test(tc, test16_int_width);
  tcase_add_test(tc, test17_int_width);
  tcase_add_test(tc, test18_int_width);
  tcase_add_test(tc, test19_int_width);
  tcase_add_test(tc, test21_int_i);
  tcase_add_test(tc, test73_hex);
  tcase_add_test(tc, test74_hex);
  tcase_add_test(tc, test75_hex);
  tcase_add_test(tc, test76_hex);
  tcase_add_test(tc, test77_hex);
  tcase_add_test(tc, test78_hex);
  tcase_add_test(tc, test79_hex);
  tcase_add_test(tc, test80_hex);
  tcase_add_test(tc, test81_hex);
  tcase_add_test(tc, test82_hex);
  suite_add_tcase(s, tc);
  return s;
}
