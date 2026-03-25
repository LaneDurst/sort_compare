#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArray(int a[], int arrSize){
    printf("[");
    for (int i = 0; i < arrSize-1; i++){
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[arrSize-1]);
}

int* bubbleSort(int a[], int arrSize){
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

    return a;

}

bool isSorted(int a[], int arrSize){
    for (int i = 0; i < arrSize-1; i++){
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int main(){
    // TODO: actually read user input
    printf("[CAUTION] large n values may cause the program to hang\nEnter a value for n: ");
    printf("\n");
    int n = 15;
    int nums[100];

    srand(time(NULL));
    for (int i = 0; i < n; i++){
        nums[i] = rand() % 100;
    }

    // Bubble Sort
    clock_t begin = clock();
    int* bubbleSorted = bubbleSort(nums, n);
    clock_t end = clock();
    if (!isSorted(bubbleSorted, n)) {printf("ERROR, INCORRECT SORT: BUBLE SORT"); exit(1);}
    printf("Bubble Sort: ran in %f seconds\n", (double)(end-begin)/ CLOCKS_PER_SEC);

    return 0;
}