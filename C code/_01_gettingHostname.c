#include <stdio.h>
#include <stdlib.h>

int main() {
    char *hostname = getenv("HOSTNAME"); // Get the value of HOSTNAME environment variable
    /*
    The getenv() function is used to retrieve the value of an environment variable. Here, we're using it to get the value of the HOSTNAME environment variable. The variable hostname will hold the value.
    */
    if (hostname != NULL) {
        printf("Hostname: %s\n", hostname);
    } else {
        printf("HOSTNAME environment variable not set.\n");
    }

    return 0;
}