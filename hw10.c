#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

static void sighandler (int signo) {
	if (signo == SIGINT) {
		int file = open("result.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		char msg[] = "I've been interrupted! (exited due to SIGINT)";
		write(file, msg, sizeof(msg));
		close(file);
		exit(1);
	}
	if (signo == SIGUSR1) {
		printf("Parent PID: %d\n", getppid());		
	}
}

int main () {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	while (1) {
		printf("PID: %d\n", getpid());
		sleep(1);
	}
	return 0;
}
