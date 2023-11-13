#include "./Unity/src/unity.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#include"Functions.c"
#include"BMP.h"

jmp_buf jump_buffer;

void segfault_handler(int signal) {
    longjmp(jump_buffer, 1);
}

void setUp(void) {
    // This function will be called before each test case
    // You can use it for any test-specific setup
}

void tearDown(void) {
    // This function will be called after each test case
    // You can use it for any test-specific cleanup
}

void test_readImage(){
    File file = openFile("sample_640x426.bmp");
    TEST_ASSERT_EQUAL(426, file.image.height);
    TEST_ASSERT_EQUAL(640, file.image.width);
    freeImage(file.image);
}

void test_freeImage(){
    File file = openFile("sample_640x426.bmp");
    freeImage(file.image);
    TEST_ASSERT_EQUAL(0, file.image.height);
    TEST_ASSERT_EQUAL(0, file.image.width);
}

void test_printInfo(){
    File file = openFile("sample_640x426.bmp");
    printInfo(file.header, file.dibheader, file.image);
    freeImage(file.image);
}

void test_FillArea(){
    File file = openFile("sample_640x426.bmp");

    freopen("test_FillArea_input.txt", "r", stdin);
    file.image = FillArea(file.image);
    writeImage(file, (char*)("why.bmp"));
    freeImage(file.image);
}

void test_openFile(){
    File file = openFile("sample_640x426.bmp");
    TEST_ASSERT_EQUAL(426, file.image.height);
    TEST_ASSERT_EQUAL(640, file.image.width);
    freeImage(file.image);
}

void test_writeImage(){
    File file = openFile("sample_640x426.bmp");
    writeImage(file, "test");
    freeImage(file.image);
}

void RUN_TEST_(void (*test)(void)){
    double time = clock();
    printf("Running test:\n");
    int pid = fork();
    if(pid == 0){
        RUN_TEST(test);
        exit(0);
    }
    else{
        int status;
        waitpid(pid, &status, 0);
        if(status != 0){
            printf("Test failed.\n");
        }
    }
    printf("Time taken: %f\n\n", (clock() - time) / (double)CLOCKS_PER_SEC * 1000);
}

int main(void){

    signal(SIGSEGV, segfault_handler);

    UNITY_BEGIN();

    RUN_TEST_(test_readImage);
    RUN_TEST_(test_freeImage);
    RUN_TEST_(test_printInfo);
    RUN_TEST_(test_openFile);
    RUN_TEST_(test_writeImage);

    UNITY_END();

    return 0;
}