//in the previous modules we were taking input from the user and we were printing the output on the console  but now we want to perform the operations in the file system here we use

//open()  system call

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    int n, fd;
    char buf[50];
    fd = open("test.txt", O_RDONLY);//this file already exists
    n = read(fd,buf,20);

    // write(1, buf, n);  this is to print the file content to console
    int fd1 = open("target", O_CREAT|O_WRONLY,  0642);

    write(fd1, buf, n);

    //now to append something to original content

    int p = read(0, buf, 20);
    write(1,buf,p);
    int fd2 = open("target", O_WRONLY|O_APPEND);
    write(fd2, buf, p);
}