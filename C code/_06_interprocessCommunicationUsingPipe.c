//pipe function will create a unidirectional pipe with two ends   
/*
1. reading end
2. writing end

reading end is used by the process which has to send the data. writing end is used by the process which has to write the data

let's say parent process has to send the data to child process and the child process has to print it to the screen

parent - sender
child - receiver

fd[1] -> writing end
fd[0] -> reading end
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();
    if(p>0)
    {
        printf("Passing value to child\n");
        write(fd[1], "hello\n", 6);
    }
    else
    {
        printf("Child received data\n");
        n = read(fd[0], buffer, 100);
        //above command reads the data and save it to buffer
        write(1, buffer, n);
    }
}