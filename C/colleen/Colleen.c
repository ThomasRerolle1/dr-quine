#include <stdio.h>

/*
      Hello from outside
*/

char  *get_str(void) 
{
      return "#include <stdio.h>%1$c%1$c/*%1$c%2$cHello from outside%1$c*/%1$c%1$cchar%2$c*get_str(void)%1$c{%1$c%2$creturn %3$c%4$s%3$c;%1$c}%1$c%1$cint%2$cmain(void)%1$c{%1$c%2$c/*%1$c%2$c%2$cHello from inside%1$c%2$c*/%1$c%2$cchar%2$c*str = get_str();%1$c%2$cprintf(str, 10, 9, 34, str);%1$c%2$creturn 0;%1$c}%1$c";
}

int   main(void) 
{
      /*
            Hello from inside
      */
      char *str = get_str();
      printf(str, 10, 9, 34, str);
      return 0;
}
