#include <stdio.h>

#define CLONE "Grace_kid.c"
#define S "#include <stdio.h>%1$c%1$c#define CLONE %2$c%4$s%2$c%1$c#define S %2$c%3$s%2$c%1$c#define MAIN int main() {FILE  *f = fopen(CLONE, %2$cw%2$c);fprintf(f, S, 10, 34, S, CLONE, 9);fclose(f);return 0;}%1$c%1$cMAIN%1$c/*%1$c%5$cThis is some malicious comment right there%1$c*/"
#define MAIN int main() {FILE  *f = fopen(CLONE, "w");fprintf(f, S, 10, 34, S, CLONE, 9);fclose(f);return 0;}

MAIN
/*
	This is some malicious comment right there
*/