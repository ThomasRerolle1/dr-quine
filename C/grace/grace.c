#include <stdio.h>

#define CLONE "grace_kid.c"
#define S "#include <stdio.h>%1$c%1$c#define CLONE %2$c%4$s%2$c%1$c#define S %2$c%3$s%2$c%1$c#define MAIN int main() {FILE  *f = fopen(%2$c%4$s%2$c, %2$cw%2$c);fprintf(f, S, 10, 34, S, CLONE);fclose(f);return 0;}%1$c%1$cMAIN%1$c//This is some malicious comment right there"
#define MAIN int main() {FILE  *f = fopen("grace_kid.c", "w");fprintf(f, S, 10, 34, S, CLONE);fclose(f);return 0;}

MAIN
//This is some malicious comment right there