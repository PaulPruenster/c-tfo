#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	printf("(3-2)*(6-4):\n");

	int ret = fork();

	if (ret == 0) // Child
	{
		printf(" >child\n");
		return (6 - 4);
	}

	//Parent
	printf(" >parent\n");

	int left = (3 - 2);
	int rigth = wait(&ret);

	printf("%i\n", left * rigth);

	return 0;
}
