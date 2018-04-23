#include "../include/main.h"

#define MAX_INPUT 250

int main(int argc, char ** argv)
{
        int pipe_to_child[2];
        int pipe_to_parent[2];
        char line[MAX_INPUT];
        pid_t pid;

        if(pipe(pipe_to_child) < 0)
        {
            perror("Error regarding pipe()");
            exit(EXIT_FAILURE);
        }
        if(pipe(pipe_to_parent) < 0)
        {
            perror("Error regarding pipe()");
            exit(EXIT_FAILURE);
        }
        if((pid = fork()) < 0)
        {
            perror("Error regarding fork()");
            exit(EXIT_FAILURE);
        }

        /* Parent process */
        if (pid > 0)
        {
            close(pipe_to_child[0]);
            close(pipe_to_parent[1]);
            printf("I'm parent, please enter characters: ");
            fgets(line, MAX_INPUT, stdin);
            write(pipe_to_child[1], line, strlen(line));

            memset(line,0,MAX_INPUT);

            ssize_t n;
            n = read(pipe_to_parent[0], line, MAX_INPUT);
            if(n >= 10)
            {
                printf("I'm parent, i got from child: %s\n", line);
                exit(EXIT_SUCCESS);
            }

            if(waitpid(pid, NULL, 0) < 0)
            {
                exit(EXIT_FAILURE);
            }
        }

        /* Child process */
        if (pid == 0)
        {
            close(pipe_to_child[1]);
            close(pipe_to_parent[0]);
            ssize_t n;
            n = read(pipe_to_child[0], line, MAX_INPUT);
            if(n >= 10)
            {
                int i;
                for(i = 0; i < n; i++)
                {
                    line[i]=toupper(line[i]);
                }
                write(pipe_to_parent[1], line, strlen(line));
            }
            else
            {
                fprintf(stderr, "Enter at least ten characters!\n");
                exit(EXIT_FAILURE);
            }
        }
    return EXIT_SUCCESS;
}
