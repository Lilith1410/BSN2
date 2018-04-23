#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char ** argv)
{
    int wstatus = 0;

    const char * temp_child = "Ich bin ein Kind\n";
    const char * temp_parent = "Ich bin Eltern\n";
    size_t temp_child_size = strlen(temp_child);
    size_t temp_parent_size = strlen(temp_parent);

    pid_t child_pid = fork();
    int file = open("abc.txt", O_RDWR | O_TRUNC | O_CREAT, S_IWUSR);

    if(child_pid == 0)
    {
        // child
        printf("Child:\t\tRET: %d\t\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());

        for(int i = 0; i < 10000; i++)
            write(file, temp_child, temp_child_size);
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
        printf("Parent:\t\tRET: %d\tPID: %d\tPPID: %d\n", child_pid, getpid(), getppid());
        for(int i = 0; i < 1000; i++)
            write(file, temp_parent, temp_parent_size);
        /*waitpid(child_pid, &wstatus, 0);*/
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}

