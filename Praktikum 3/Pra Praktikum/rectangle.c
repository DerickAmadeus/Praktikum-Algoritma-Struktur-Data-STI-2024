#include <stdio.h>
#include "rectangle.h" 
#include <stdlib.h>

/* *** DEFINISI FUNGSI PRIMITIF *** */

/* Konstruktor membentuk RECTANGLE */
RECTANGLE MakeRectangle(float width, float height) {
    RECTANGLE R;
    R.width = width;   
    R.height = height;  
    return R;
}

// KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

void readRectangle(RECTANGLE *R) {
    float width, height;
    scanf("%f", &width);    
    scanf("%f", &height);   
    R->width = width;
    R->height = height;
}

void printRectangle(RECTANGLE R) {
    printf("R(%.2fx%.2f)\n", R.width, R.height); 
}

/* *** Kelompok operasi relasional terhadap RECTANGLE *** */

boolean isSquare(RECTANGLE R) {
    return (R.width == R.height);
}

boolean isNotSquare(RECTANGLE R) {
    return (R.width != R.height);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */

float area(RECTANGLE R) {
    return (float)(R.width * R.height); 
}

float perimeter(RECTANGLE R) {
    return (float)(2 * (R.width + R.height)); 
}

void swap(RECTANGLE *R) {
    float temp = R->width;    
    R->width = R->height;    
    R->height = temp;        
}

void add(RECTANGLE *R, float deltaWidth, float deltaHeight) {
    R->width += deltaWidth;   
    R->height += deltaHeight; 
}

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight) {
    RECTANGLE newRectangle; 
    newRectangle.width = R.width + deltaWidth;   
    newRectangle.height = R.height + deltaHeight; 
    return newRectangle; 
}