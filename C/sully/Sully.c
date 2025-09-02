#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
        this is a comment
*/

#define NL 10
#define TAB 9
#define QUOTE 34
#define BACKSLASH 92

#define SRC_CODE                                                               \
  "#include <stdio.h>%1$c#include <string.h>%1$c#include "                     \
  "<stdlib.h>%1$c%1$c/*%1$c%2$cthis is a comment%1$c*/%1$c%1$c#define NL "     \
  "10%1$c#define TAB 9%1$c#define QUOTE 34%1$c#define BACKSLASH "              \
  "92%1$c%1$c#define SRC_CODE %3$c%4$s%3$c%1$c%1$c#define MAIN(x) int main() " \
  "{%6$c%1$c%2$cchar%2$ccurrent[100], exec[100], "                             \
  "cmd[100];%6$c%1$c%2$cint%2$ccounter = x;%6$c%1$c%2$csprintf(current, "      \
  "%3$cSully_%%d.c%3$c, counter);%6$c%1$c%2$cif (!strcmp(__FILE__, current)) " \
  "counter--;%6$c%1$c%2$cif (counter < 0) return "                             \
  "0;%6$c%1$c%2$csprintf(current, %3$cSully_%%d.c%3$c, "                       \
  "counter);%6$c%1$c%2$cFILE%2$c*f = fopen(current, "                          \
  "%3$cw%3$c);%6$c%1$c%2$cif (f < 0) return 1;%6$c%1$c%2$csprintf(exec, "      \
  "%3$cSully_%%d%3$c, counter);%6$c%1$c%2$csprintf(cmd, %3$cclang -Wall "      \
  "-Wextra -Werror -o %%s %%s%3$c, exec, current);%6$c%1$c%2$cfprintf(f, "     \
  "SRC_CODE, NL, TAB, QUOTE, SRC_CODE, counter, "                              \
  "BACKSLASH);%6$c%1$c%2$cfclose(f);%6$c%1$c%2$csystem(cmd);%6$c%1$c%2$"       \
  "csprintf(cmd, %3$c./%%s%3$c, "                                              \
  "exec);%6$c%1$c%2$csystem(cmd);%6$c%1$c%2$creturn "                          \
  "0;%6$c%1$c%2$c}%1$c%1$cMAIN(%5$d)"

#define MAIN(x)                                                                \
  int main() {                                                                 \
    char current[100], exec[100], cmd[100];                                    \
    int counter = x;                                                           \
    sprintf(current, "Sully_%d.c", counter);                                   \
    if (!strcmp(__FILE__, current))                                            \
      counter--;                                                               \
    if (counter < 0)                                                           \
      return 0;                                                                \
    sprintf(current, "Sully_%d.c", counter);                                   \
    FILE *f = fopen(current, "w");                                             \
    if (f < 0)                                                                 \
      return 1;                                                                \
    sprintf(exec, "Sully_%d", counter);                                        \
    sprintf(cmd, "clang -Wall -Wextra -Werror -o %s %s", exec, current);       \
    fprintf(f, SRC_CODE, NL, TAB, QUOTE, SRC_CODE, counter, BACKSLASH);        \
    fclose(f);                                                                 \
    system(cmd);                                                               \
    sprintf(cmd, "./%s", exec);                                                \
    system(cmd);                                                               \
    return 0;                                                                  \
  }

MAIN(5)
