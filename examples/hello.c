// hello.c
// infer run -- gcc -c hello.c
// infer run -- gcc -c hello.c
// infer run -- clang -c hello.c
#include <stdlib.h>


// void test() {
//   int *s = NULL;
//   *s = 42;
// }

void test() {
  int *s = NULL;
  if (s != NULL) {
    *s = 42;
  }
}