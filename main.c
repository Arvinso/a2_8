/*
 * main.c
 *
 *  Created on: 2017-02-13
 *      Author: wierie
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main()
{
	int pipefd[2];
	char buf;
	int testvar = 99;

	int readvar = 0;

	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if (write(pipefd[1], &testvar, 1) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	if(read(pipefd[0], &buf, 1)< 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("value read: %d", buf);

	}

	return 0;
}
