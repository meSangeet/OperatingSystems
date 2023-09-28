/*
pthread_create -> create a new thread of execution in a program.

int pthread_create(pthread_t * thread, const pthread_attr *attr, void*(*start_routine)(void *), void *arg);

the function takes 4 arguments :
 
1) A pointer to a pthread_t object, which will be used to store the thread ID of the newly created thread.

2) A pointer to a pthread_attr_t object, which specifies the attributes for the new thread. If NULL is passed, default attributes are used.

3) A pointer to a function that will be executed by the new thread.

4) A void pointer to any arguments that need to be passed to the thread function. If no arguments are needed, NULL can be passed.
*/

/*
pthread_join -> used to wait for a thread t complete its execution.

int pthread_join(pthread_t thread, void **retval):

two arguments - 

1) a pthread_t object which identifies a thread that needs to be joined.
2) A pointer to a void pointer, which is used to retrieve the exit status of the joined thread.


when this function is called, the calling thread is blocked untill specified thread completes its execution. If the specified thread has already completed its execution, pthread_join returns immediately.

Once the specified thread completes its execution, its exit status is stored in the location pointed to by the void pointer passed as the second argument.

The joined thread is then terminated and its resources (such as memory) are released.

If an error occurs while joining the thread, pthread_join returns an error code.
*/

//code for normal thread creation
/*
#include<stdio.h>
#include<pthread.h>

char* a;

void *func()
{
    printf("in thread function \n");
    pthread_exit("exit thread function \n");
}

int main()
{
    pthread_t thread1;
    void *a;
    printf("In main thread\n");
    pthread_create(&thread1, NULL, func, NULL);
    pthread_join(thread1, &a);
    return 0;
}

*/


//code with arguments passed
/*
#include<stdio.h>
#include<pthread.h>

char* a;

void *func(void *i)
{
    int *p = (int *)i;
    printf("Hello, this statement is printed by thread1\n");
    printf("The argument: %d\n", *p);
    return NULL;
}

int main()
{
    void* status;
    int fun_arg = 10;
    pthread_t thread1;
    printf("In main thread\n");
    pthread_create(&thread1, NULL, func, (void *)&fun_arg);
    pthread_join(thread1, &status);
    printf("%s \n", status);
    return 0;
}
*/

//now we want to pass multiple arguments
/*
#include<stdio.h>
#include<pthread.h>

char* a;

void *func(void *i)
{
    int *p = (int *)i;
    printf("Hello, this statement is printed by thread1\n");
    for(int i = 0; i<10; i++)
    printf("The argument: %d\n", p[i]);
    return NULL;
}

int main()
{
    void* status;
    int fun_arg[10] = {10,9,8,7,6,5,4,3,2,1};
    pthread_t thread1;
    printf("In main thread\n");
    pthread_create(&thread1, NULL, func, (void *)fun_arg);
    pthread_join(thread1, &status);
    printf("%s \n", status);
    return 0;
}
*/

//now to pass a structure
#include<stdio.h>
#include<pthread.h>

char* a;

//struct to hold the arguments to the thread function
struct thread_args{
    int arg1;
    int arg2;
    char *arg3;
};

//this function will execute when a thread is created
void *func(void *arg)
{
    //cast the argument to the correct type
    struct thread_args *myargs = (struct thread_args*)arg;
    printf("Hello, this statement is printed by thread1\n");
    printf("%d", myargs->arg1);
    printf("%d", myargs->arg2);
    printf("%s", myargs->arg3);
    pthread_exit(NULL);
}

int main()
{
    //pointer to store status
    void *status;
    //initialize the arguments to pass into the thread
    struct thread_args myargs = {1,2,"one"};
    //declare a variable to hold the thread ID
    pthread_t tid;
    //thread creation
    pthread_create(&tid, NULL, func, (void *)&myargs);
    //wait for the thread to complete before continuing
    pthread_join(tid, (void *)status);
    return 0;
}