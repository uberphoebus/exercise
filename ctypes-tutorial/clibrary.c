#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* display(char* str, int age) {
    // printf("Hello, World!\n");
    printf("Hello, %s! You are %d years old.\n", str, age);
    return "Completed!";
}

char* alloc_memory() {
    char* str = strdup("Hello, World!");
    printf("Memory allocated at: %p\n", str);
    return str;
}

void free_memory(char* ptr) {
    printf("Freeing memory at: %p\n", ptr);
    free(ptr);
}

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int* incArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }
    return arr;
}

int* getArray() {
    int *arr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    return arr;
}

void freeArray(int *arr) {
    free(arr);
}

struct Point {
    int x;
    int y;
};

struct Point* getPoint() {
    struct Point *p = (struct Point *)malloc(sizeof(struct Point));
    p->x = 10;
    p->y = 20;
    return p;
}

void printPoint(struct Point p) {
    printf("Point: (%d, %d)\n", p.x, p.y);
}

struct Student {
    char* name;
};

void printStudentDetails(struct Student s) {
    printf("Student Name: %s\n", s.name);
}
