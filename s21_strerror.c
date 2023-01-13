#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char err[BUFF_SIZE] = {'\0'};
  if (errnum < 0 || errnum >= ERROR_LIST_SIZE)
    s21_sprintf(err, "Unknown error: %d", errnum);
  else
    s21_strcpy(err, error_list[errnum]);
  return err;
}
