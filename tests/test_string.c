#include "test_string.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      suite_strlen(),  strcpy_s21(),    sscnaf_s21(),    suite_memchr(),
      suite_memcmp(),  suite_memcpy(),  suite_memmove(), suite_memset(),
      suite_strcat(),  suite_strncat(), suite_strchr(),  suite_strcmp(),
      suite_strncmp(), suite_strncpy(), suite_strcspn(), suite_strerror(),
      suite_strpbrk(), suite_strrchr(), suite_strspn(),  suite_strstr(),
      suite_strtok(),  suite_sprintf(), suite_bonus(),   NULL};
  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *runner = srunner_create(s21_string_test[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return failed == 0 ? 1 : 0;
}
