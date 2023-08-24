/*
fork - create a child process

headers needed - 

#include<sts/types.h>
#include<unistd.h>


pid_t fork(void)

description - 

fork() creates a new process by duplicating the calling process. The new process is referred to as child process. The calling process is referrefd to as the parent process.

The child process and the parent process run in separate memory spaces. At the time of fork() both memory spaces have same content. Memory writes, file mappings(mmap(2)), and unmappings(munmap(2)) performed by one of the processes do not affect the other.

fork can return 3 kinds of value 
1. -1 -> child process creation is failed
2. 0 -> child process
3. greater than 0 -> parent process


*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t q;
    q = fork();
    if(q<0)
    {
        printf("error");
    }
    else if(q == 0){
        //child process
        printf("child having pid %d\n", getpid());
        printf("My parent's pid is %d\n", getppid());
    }
    else{
        //q > 0  -> parent process
        // q now contains the pid of the child
        printf("Parent having pid %d\n", q);
    }
    // if we want both parent and child to do something write the code outside the if else statement
}