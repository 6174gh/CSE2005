#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    printf("Hi");
    fork();
    print("Hello");
    return 0;
}