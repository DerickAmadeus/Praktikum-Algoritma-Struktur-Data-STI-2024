#include <stdio.h>
#include <stdlib.h> 
#include "arraydin.h"


ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (ElType *) malloc(sizeof(ElType) * InitialSize); 

    if (array.A == NULL) { 
        printf("Memory allocation failed\n");
        array.Capacity = 0;
        array.Neff = 0;
        return array; 
    }

    array.Capacity = InitialSize;
    array.Neff = 0; 
    return array; 
}


void DeallocateArrayDin(ArrayDin *array) {
    if (array->A != NULL) {
        free(array->A); 
        array->A = NULL; 
    }
    array->Capacity = 0; 
    array->Neff = 0; 
}


boolean IsEmpty(ArrayDin array) {
    return (array.Neff == 0);
}


int Length(ArrayDin array) {
    return array.Neff;
}


ElType Get(ArrayDin array, IdxType i) {
    return array.A[i]; 
}


int GetCapacity(ArrayDin array) {
    return array.Capacity;
}


void ResizeArray(ArrayDin *array) {
    int newCapacity = array->Capacity * 2; 
    ElType *newArray = (ElType *) malloc(sizeof(ElType) * newCapacity); // Allocate new array

    if (newArray == NULL) { 
        printf("Memory allocation failed during resizing\n");
        return; 
    }

    for (int i = 0; i < array->Neff; i++) {
        newArray[i] = array->A[i]; 
    }
    free(array->A); 
    array->A = newArray; 
    array->Capacity = newCapacity; 
}


void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    if (array->Neff >= array->Capacity) {
        ResizeArray(array); 
    }

    for (int j = array->Neff; j > i; j--) {
        array->A[j] = array->A[j - 1]; 
    }
    array->A[i] = el; 
    array->Neff++; 
}


void DeleteAt(ArrayDin *array, IdxType i) {

    // Shift elements to the left
    for (int j = i; j < array->Neff - 1; j++) {
        array->A[j] = array->A[j + 1]; // Shift elements
    }
    array->Neff--; // Decrement the number of effective elements
}