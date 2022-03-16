#include <stdio.h> 
#include <stdlib.h>
#include "input.h"

#define LEN 10

int sequentialSearch(int val, int arr[], int arrLength);
int maximumIndex(int arr[], int arrLength);
int minimumIndex(int arr[], int arrLength);
void bubbleSortAscending(int arr[], int arrLength);
void selectionSortDescending(int arr[], int arrLength);
void printArray(int arr[], int arrLength);

int main() {

    int v[LEN] = {26, 49, 1, 12, 2, 14, 29, 34, 44, 35};
    printArray(v, LEN);

    int val;
    printf("Lets search a number?: ");
    readInteger(&val);

    int index = sequentialSearch(val, v, LEN);


    sequentialSearch(val, v, LEN);
    printArray(v, LEN);
    maximumIndex(v, LEN);
    minimumIndex(v, LEN);
    selectionSort(v, LEN);
    bubbleSort(v, LEN);

    if(index != -1) {
        printf("The number %d exists at position %d of the array!\n", val, index);
    } else {
        printf("The number %d does not exist in the array!\n", val);
    }

    /* TODO: test other functions */
    

    return EXIT_SUCCESS;
}

/* TODO: missing function definitions */ 

int sequentialSearch(int val, int arr[], int arrLength) {

    for (int i = 0 ; i < arrLength ; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void printArray(int arr[], int arrLength) {
    printf("[ ");
    for(int i=0; i<arrLength; i++) {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}


int maximumIndex(int arr[], int arrlength){

    if (arrlength == 0 ) return -1;
    int max = arr[0];
    int indexMax = 0;
    
    for(int i=0; i<arrlength; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            indexMax = 1;
        }
    }
    return indexMax;

}

int minimumIndex(int arr[], int arrlength){

    if (arrlength == 0 ) return -1;
    int min = arr[0];
    int indexMin = 0;
    
    for(int i=0; i<arrlength; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            indexMin = 1;
        }
    }
    return indexMin;

}

void selectionSort(int arr[], int arrSize)
{
    for(int i=0; i<arrSize; i++)
    {
        int indexMin = i;
        for(int j=i; j<arrSize-1; j++)
        {
            if(arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = tmp;
    }
}

void bubbleSort(int arr[], int arrSize)
{
    for(int i=0; i<arrSize; i++)
    {
        for(int j=1; j<arrSize-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}