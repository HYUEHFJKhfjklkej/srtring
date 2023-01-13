#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#define INT_BUFER_LEN 20
#define DBL_BUFER_LEN 400

typedef struct FormatSpec {
  int width;
  int precision;
  int flag;
  int sign;
  int zero;
  int space;
  int sharp;
  int length;
} FormatSpec;

#endif  // SRC_S21_SPRINTF_H_