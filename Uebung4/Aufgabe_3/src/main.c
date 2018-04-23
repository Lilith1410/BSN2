#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char ** argv)
{
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        // Child
        printf("Kind [%d]: %d\n", child_pid, getpid());
    }
    else if(child_pid < 0)
    {
        perror("Error at creating child");
    }
    else 
    {
        // Parent
        printf("Eltern [%d]: %d\n", child_pid, getpid());
    }

    while(1);
}
