#include "test_string.h"

START_TEST(s21_sprintf_empty_format) {
  char str1[100] = {0};
  char str2[100] = {0};

  // ck_assert_int_eq(s21_sprintf(str1, ""), sprintf(str2, ""));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_max_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = INT_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_min_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = INT_MIN;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus) {
  char str1[100] = {0};
  char str2[100] = {0};
  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%d", s21_int),
                   sprintf(str2, "%d", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%.6d", s21_int),
                   sprintf(str2, "%.6d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%.6d", s21_int),
                   sprintf(str2, "%.6d", s21_int));

  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, "%.2d", s21_int),
                   sprintf(str2, "%.2d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, "%.2d", s21_int),
                   sprintf(str2, "%.2d", s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%9.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%1.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%-9.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%-1.6d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%09d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_force_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% d";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_wight_var) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% *d";
  ck_assert_int_eq(s21_sprintf(str1, format, 6, s21_int),
                   sprintf(str2, format, 6, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_spec_var) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "% .*d";
  ck_assert_int_eq(s21_sprintf(str1, format, 6, s21_int),
                   sprintf(str2, format, 6, s21_int));

  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_short_max) {
  char str1[100] = {0};
  char str2[100] = {0};
  short int s21_int = SHRT_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%hd", s21_int),
                   sprintf(str2, "%hd", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};
  long int s21_int = 87878123578;
  ck_assert_int_eq(s21_sprintf(str1, "%ld", s21_int),
                   sprintf(str2, "%ld", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_int_plus_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};
  long int s21_int = LONG_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%ld", s21_int),
                   sprintf(str2, "%ld", s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = UINT_MAX;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_long_max) {
  char str1[100] = {0};
  // char str2[100] = {0};

  unsigned long int s21_int = ULONG_MAX - 1;
  char format[] = "%lu";
  // ck_assert_int_eq(
  s21_sprintf(str1, format, s21_int);
  sprintf(str1, format, s21_int);
  //  )

  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_uint_short_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned short int s21_int = USHRT_MAX;
  char format[] = "%hu";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  uint s21_int = -123;
  char format[] = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = -123;
  char format[] = "%.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = 123;
  char format[] = "%.2u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  unsigned int s21_int = -123;
  char format[] = "%.2u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%1.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -123;
  char format[] = "%1.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 123;
  char format[] = "%-9.6u";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6u";
  int s21_int = -123;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_uint_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09u";
  int s21_int = 123;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.9f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.9f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10f";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Lf";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_comb) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_f = 123.157;
  int s21_int = 123;
  char format[] = "%+10f %d";
  s21_sprintf(str1, format, s21_f, s21_int);
  sprintf(str2, format, s21_f, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_c) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int = 'v';
  char format[] = "%c";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int[] = "1578";
  char format[] = "%s";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s_prec) {
  char str1[100] = {0};
  char str2[100] = {0};

  char s21_int[] = "1578";
  char format[] = "%.2s";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.;
  char format[] = "%#e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Le";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
}
END_TEST

START_TEST(s21_sprintf_E_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10e";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.;
  char format[] = "%#E";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%LE";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
}
END_TEST

START_TEST(s21_sprintf_g_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  s21_int = -0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
}
END_TEST

START_TEST(s21_sprintf_g_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
}
END_TEST

START_TEST(s21_sprintf_g_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;

  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
}
END_TEST

START_TEST(s21_sprintf_g_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_g_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2g";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_g_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.0000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_g_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%#.10g";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_g_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%Lg";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str1);
  s21_int = -0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%.7G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = -123.157;
  char format[] = "%.7G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);

  ck_assert_str_eq(str1, str2);
  s21_int = -0.000157;

  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_dot) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_prec_less) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = -123.157;
  char format[] = "%.2G";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
  s21_int = 0.000157;

  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_wight_plus) {
  char str1[100] = {0};
  char str2[100] = {0};
  float s21_int = 123.157;
  char format[] = "%+10G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.0000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  float s21_int = 123.157;
  char format[] = "%#.10G";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_G_plus_long) {
  char str1[100] = {0};
  char str2[100] = {0};

  long double s21_int = 0.000000075893;
  char format[] = "%LG";
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
  s21_int = 0.000157;
  s21_sprintf(str1, format, s21_int);
  sprintf(str2, format, s21_int);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_o_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_o_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%ho";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_o_long_max) {
  char str1[100] = {0};
  // char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lo";
  // ck_assert_int_eq(
  s21_sprintf(str1, format, s21_int);
  sprintf(str1, format, s21_int);
  //  )

  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(s21_sprintf_x_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_x_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%hx";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_x_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lx";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = UINT_MAX;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_shrt_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = USHRT_MAX;
  char format[] = "%hX";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_X_long_max) {
  char str1[100] = {0};
  char str2[100] = {0};

  long int s21_int = ULONG_MAX;
  char format[] = "%lX";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6o";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09o";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_o_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#o";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6x";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09x";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#x";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%.2X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_less_len) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%.2X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len_wight_more) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%1.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len_wight_less) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = -193;
  char format[] = "%1.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_prec_more_len_wight_more_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%-9.6X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_minus_prec_more_len_wight_less_left) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%-9.6X";
  int s21_int = -193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_wight_zero) {
  char str1[100] = {0};
  char str2[100] = {0};

  char format[] = "%09X";
  int s21_int = 193;
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_X_plus_sharp) {
  char str1[100] = {0};
  char str2[100] = {0};

  int s21_int = 193;
  char format[] = "%#X";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_p) {
  char str1[100] = {0};
  char str2[100] = {0};

  char *s21_int = str1;
  char format[] = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_p_wight) {
  char str1[100] = {0};
  char str2[100] = {0};

  char *s21_int = str1;
  char format[] = "%24p";
  ck_assert_int_eq(s21_sprintf(str1, format, s21_int),
                   sprintf(str2, format, s21_int));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_n) {
  char str1[100] = {0};
  char str2[100] = {0};
  int n1 = 10;
  int n2 = 10;
  int d1, d2;
  char format[] = "abra %ncdabrs";
  d1 = s21_sprintf(str1, format, &n1);
  d2 = sprintf(str2, "abra %ncdabrs", &n2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s;
  TCase *tc_empty_format, *tc_int, *tc_uint, *tc_f, *tc_comb, *tc_c, *tc_s,
      *tc_e, *tc_g;
  TCase *tc_o, *tc_x, *tc_p, *tc_n, *tc_percent;
  s = suite_create("suite_sprintf");
  tc_empty_format = tcase_create("empty_format");
  tcase_add_test(tc_empty_format, s21_sprintf_empty_format);
  suite_add_tcase(s, tc_empty_format);
  tc_int = tcase_create("int");
  tcase_add_test(tc_int, s21_sprintf_int_plus);
  tcase_add_test(tc_int, s21_sprintf_int_max_plus);
  tcase_add_test(tc_int, s21_sprintf_int_min_plus);
  tcase_add_test(tc_int, s21_sprintf_int_minus);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_less_len);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_less_len);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len_wight_more);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len_wight_less);
  tcase_add_test(tc_int, s21_sprintf_int_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_int, s21_sprintf_int_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_int, s21_sprintf_int_plus_wight_zero);
  // tcase_add_test(tc_int, s21_sprintf_int_plus_short);
  tcase_add_test(tc_int, s21_sprintf_int_plus_long);
  tcase_add_test(tc_int, s21_sprintf_int_plus_short_max);
  tcase_add_test(tc_int, s21_sprintf_int_force_plus);
  tcase_add_test(tc_int, s21_sprintf_int_wight_var);
  tcase_add_test(tc_int, s21_sprintf_int_spec_var);

  tcase_add_test(tc_int, s21_sprintf_int_plus_long_max);
  suite_add_tcase(s, tc_int);
  tc_uint = tcase_create("uint");
  tcase_add_test(tc_uint, s21_sprintf_uint_minus);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_less_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_less_len);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len_wight_more);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len_wight_less);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_uint, s21_sprintf_uint_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_uint, s21_sprintf_uint_plus_wight_zero);
  tcase_add_test(tc_uint, s21_sprintf_uint_max);
  tcase_add_test(tc_uint, s21_sprintf_uint_long_max);
  tcase_add_test(tc_uint, s21_sprintf_uint_short_max);
  suite_add_tcase(s, tc_uint);
  tc_f = tcase_create("float");
  tcase_add_test(tc_f, s21_sprintf_f_plus);
  tcase_add_test(tc_f, s21_sprintf_f_minus);
  tcase_add_test(tc_f, s21_sprintf_f_plus_prec_more_len);
  tcase_add_test(tc_f, s21_sprintf_f_minus_prec_more_len);
  tcase_add_test(tc_f, s21_sprintf_f_dot);
  tcase_add_test(tc_f, s21_sprintf_f_prec_less);
  tcase_add_test(tc_f, s21_sprintf_f_wight_plus);
  tcase_add_test(tc_f, s21_sprintf_f_plus_long);
  suite_add_tcase(s, tc_f);
  tc_comb = tcase_create("comb");
  tcase_add_test(tc_f, s21_sprintf_comb);
  suite_add_tcase(s, tc_comb);
  tc_c = tcase_create("char");
  tcase_add_test(tc_c, s21_sprintf_c);
  suite_add_tcase(s, tc_c);
  tc_s = tcase_create("str");
  tcase_add_test(tc_s, s21_sprintf_s);
  tcase_add_test(tc_s, s21_sprintf_s_prec);
  suite_add_tcase(s, tc_s);
  tc_e = tcase_create("e");
  tcase_add_test(tc_e, s21_sprintf_e_plus);
  tcase_add_test(tc_e, s21_sprintf_e_minus);
  tcase_add_test(tc_e, s21_sprintf_e_plus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_e_minus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_e_dot);
  tcase_add_test(tc_e, s21_sprintf_e_prec_less);
  tcase_add_test(tc_e, s21_sprintf_e_wight_plus);
  tcase_add_test(tc_e, s21_sprintf_e_plus_sharp);
  tcase_add_test(tc_e, s21_sprintf_e_plus_long);
  tcase_add_test(tc_e, s21_sprintf_E_plus);
  tcase_add_test(tc_e, s21_sprintf_E_minus);
  tcase_add_test(tc_e, s21_sprintf_E_plus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_E_minus_prec_more_len);
  tcase_add_test(tc_e, s21_sprintf_E_dot);
  tcase_add_test(tc_e, s21_sprintf_E_prec_less);
  tcase_add_test(tc_e, s21_sprintf_E_wight_plus);
  tcase_add_test(tc_e, s21_sprintf_E_plus_sharp);
  tcase_add_test(tc_e, s21_sprintf_E_plus_long);
  suite_add_tcase(s, tc_e);
  tc_g = tcase_create("g");
  tcase_add_test(tc_g, s21_sprintf_g_plus);
  tcase_add_test(tc_g, s21_sprintf_g_minus);
  tcase_add_test(tc_g, s21_sprintf_g_plus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_g_minus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_g_dot);
  tcase_add_test(tc_g, s21_sprintf_g_prec_less);
  tcase_add_test(tc_g, s21_sprintf_g_wight_plus);
  tcase_add_test(tc_g, s21_sprintf_g_plus_sharp);
  tcase_add_test(tc_g, s21_sprintf_g_plus_long);
  tcase_add_test(tc_g, s21_sprintf_G_plus);
  tcase_add_test(tc_g, s21_sprintf_G_minus);
  tcase_add_test(tc_g, s21_sprintf_G_plus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_G_minus_prec_more_len);
  tcase_add_test(tc_g, s21_sprintf_G_dot);
  tcase_add_test(tc_g, s21_sprintf_G_prec_less);
  tcase_add_test(tc_g, s21_sprintf_G_wight_plus);
  tcase_add_test(tc_g, s21_sprintf_G_plus_sharp);
  tcase_add_test(tc_g, s21_sprintf_G_plus_long);
  suite_add_tcase(s, tc_g);
  tc_o = tcase_create("o");
  tcase_add_test(tc_o, s21_sprintf_o_minus);
  tcase_add_test(tc_o, s21_sprintf_o_plus);
  tcase_add_test(tc_o, s21_sprintf_o_max);
  tcase_add_test(tc_o, s21_sprintf_o_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_o_long_max);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_less_len);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_less_len);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len_wight_more);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len_wight_less);
  tcase_add_test(tc_o, s21_sprintf_o_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_o, s21_sprintf_o_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_o, s21_sprintf_o_plus_wight_zero);
  tcase_add_test(tc_o, s21_sprintf_o_plus_sharp);
  suite_add_tcase(s, tc_o);
  tc_x = tcase_create("x");
  tcase_add_test(tc_x, s21_sprintf_x_minus);
  tcase_add_test(tc_x, s21_sprintf_x_plus);
  tcase_add_test(tc_o, s21_sprintf_x_max);
  tcase_add_test(tc_o, s21_sprintf_x_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_x_long_max);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len_wight_more);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len_wight_less);
  tcase_add_test(tc_x, s21_sprintf_x_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_x, s21_sprintf_x_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_x, s21_sprintf_x_plus_wight_zero);
  tcase_add_test(tc_x, s21_sprintf_x_plus_sharp);
  tcase_add_test(tc_x, s21_sprintf_X_minus);
  tcase_add_test(tc_x, s21_sprintf_X_plus);
  tcase_add_test(tc_o, s21_sprintf_X_max);
  tcase_add_test(tc_o, s21_sprintf_X_shrt_max);
  tcase_add_test(tc_o, s21_sprintf_X_long_max);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_less_len);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len_wight_more);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len_wight_less);
  tcase_add_test(tc_x, s21_sprintf_X_plus_prec_more_len_wight_more_left);
  tcase_add_test(tc_x, s21_sprintf_X_minus_prec_more_len_wight_less_left);
  tcase_add_test(tc_x, s21_sprintf_X_plus_wight_zero);
  tcase_add_test(tc_x, s21_sprintf_X_plus_sharp);
  suite_add_tcase(s, tc_x);
  tc_p = tcase_create("p");
  tcase_add_test(tc_p, s21_sprintf_p);
  tcase_add_test(tc_p, s21_sprintf_p_wight);
  suite_add_tcase(s, tc_p);
  tc_n = tcase_create("n");
  tcase_add_test(tc_n, s21_sprintf_n);
  suite_add_tcase(s, tc_n);
  tc_percent = tcase_create("percent");
  suite_add_tcase(s, tc_percent);
  return s;
}
