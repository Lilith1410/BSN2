#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char ** argv)
{
    if(argc < 2)
        exit(EXIT_SUCCESS);
    
    for(int i = 1; i <= argc; i++)
    {
        pid_t child_pid = fork();

        if(child_pid == 0)
        {
            // child
            /*printf("Child:\t\tRET: %d\t\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());*/
            execlp(argv[i], "", NULL);
            exit(EXIT_SUCCESS);
        }
        else if(child_pid < 0)
        {
            // error
            perror("Error creating process");
            exit(EXIT_FAILURE);
        }
        else
        {
            // parent
            /*printf("Parent:\t\tRET: %d\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());*/
            waitpid(child_pid, 0, 0);
            /*exit(EXIT_SUCCESS);*/
        }
    }
    return EXIT_SUCCESS;
}

