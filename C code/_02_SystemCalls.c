/*
System calls is a mechanism to access the operating system services.
eg - read(), write(), open() etc

write() -

to open manual

command - man 2 write

header file needed -> <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);  this returns the size of the data which we entered in the 3rd parameter

if we enter a smaller count than length of the data than the data of length count will be printed and if it is greater than it will only print the entered data   but it will return the entered 3rd parameter.

fd -> file descriptor
*buf contains the data that needs to be written
count is the size of the data tha needs to be written

our screen has the fd = 1.

*/

// #include<stdio.h>
// #include<unistd.h>

// int main()
// {
//     int n;

//     n = write(1, "Hello", 6);

//     printf("\nthe value of n is - %d\n", n);
//     return 0;
// }



//read() system call

//write a program which will take input from the user and than print it onto the screen
#include<stdio.h>
#include<unistd.h>

int main()
{
    char b[30];
    //b array is the buffer array  as we will have to first save the input into some buffer memory (b is that memory)
    int n = read(0,b,10);
    //read function will return the number of characters the user have entered this will help if the user entered less than required characters.
    write(1,b,n);
    return 0;
}