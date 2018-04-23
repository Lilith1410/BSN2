#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char ** argv)
{
    for(int i = 0; i < 8; i++)
    {
        pid_t child_pid = fork();
        int wstatus = 0;

        if(child_pid == 0)
        {
            // child
            printf("Child:\t\tRET: %d\t\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());
        }
        else if(child_pid < 0)
        {
            // error
            perror("Error creating process");
            exit(1);
        }
        else
        {
            // parent
            printf("Parent:\t\tRET: %d\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());
            waitpid(child_pid, &wstatus, 0);
            exit(EXIT_SUCCESS);
        }
    }

    return EXIT_SUCCESS;
}

