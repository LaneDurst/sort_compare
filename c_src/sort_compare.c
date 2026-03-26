#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void printArray(int a[], int arrSize){
    printf("[");
    for (int i = 0; i < arrSize-1; i++){
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[arrSize-1]);
}

bool isSorted(int a[], int arrSize){
    for (int i = 0; i < arrSize-1; i++){
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

void bubbleSort(int nums[], int arrSize){
    int a[arrSize];
    memcpy(a, nums, sizeof(nums[0])*arrSize);

    for (int i = 0; i < arrSize; i++){
        int end = arrSize-i;
        bool noSwaps = true;

        for (int j = 0; j < end-1; j++){
            if (a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                noSwaps = false;
            }
        }

        // short circuit
        if (noSwaps) break;
    }

    if(!isSorted(a, arrSize)){
        printf("[ERROR] INCORRECT SORT: Bubble Sort\n");
        printArray(a, arrSize);
        exit(1);
    }
}

void selectionSort(int nums[], int arrSize){
    int a[arrSize];
    memcpy(a, nums, sizeof(nums[0])*arrSize);

    for (int i = 0; i < arrSize-1; i++){
        int minIndex = i;
        int minValue = a[i];
        for (int j = i; j < arrSize; j++){
            if (a[j] < minValue){
                minValue = a[j];
                minIndex = j;
            }
        }
        a[minIndex] = a[i];
        a[i] = minValue;
    }

    if(!isSorted(a, arrSize)){
        printf("[ERROR] INCORRECT SORT: Selection Sort\n");
        printArray(a, arrSize);
        exit(1);
    } 
}

int main(){
    printf("[CAUTION] large n values may cause the program to hang\nEnter a value for n: ");
    int n;
    scanf("%d", &n);
    int nums[n];

    printf("generating a %d random number array ...\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        nums[i] = rand() % 100;
    }

    // Bubble Sort
    printf("Beginning Bubble Sort");
    fflush(stdout);
    clock_t begin = clock();
    bubbleSort(nums, n);
    clock_t end = clock();
    printf("\rBubble Sort: ran in %.2f seconds\n", (double)(end-begin)/ CLOCKS_PER_SEC);

    // Selection Sort
    printf("Beginning Selection Sort");
    fflush(stdout);
    begin = clock();
    selectionSort(nums, n);
    end = clock();
    printf("\rSelection Sort: ran in %.2f seconds\n", (double)(end-begin)/ CLOCKS_PER_SEC);

    return 0;
}