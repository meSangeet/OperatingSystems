//In the previous module we see that we can't determine that whether the child process or the parent process will run first or whether they will be overlapped or not.
//We can't say anything confidently

//We can use wait system call -> Now the parent will wait for child to complete.

//sleep(n) -> process will sleep for n seconds.

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    pid_t q;
    printf("before fork\n");
    q = fork();
    if(q == 0)
    {
        sleep(3);//if you want parent to rum first
        printf("I am child process having id %d\n", getpid());
        printf("My parent's id is %d\n",, getppid());
    }
    else{
        wait(NULL); //if you want child to rum first
        printf("My child id is %d\n", q);
        printf("I am parent having id %d\n", getpid());
    }
}