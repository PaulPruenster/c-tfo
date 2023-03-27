#include <stdio.h>
#include <string.h>

char* substring(const char* str, int begin, int len)
{
  if (str == 0 || strlen(str) == 0 || strlen(str) < begin || strlen(str) < (begin+len))
    return 0;

  return strndup(str + begin, len);
}

int main ()
{
	char *test = "this is a test plus test";

	printf("String before cut:\n[%s]\n", test);
	printf("Length: %i\n", strlen(test));
	
	// cut the string after the first "test" with substring
	test = substring(test, 0, 14);
	
	printf("String after cut:\n[%s]\n", test);
	printf("Length: %i\n", strlen(test));

	return 0;
}
