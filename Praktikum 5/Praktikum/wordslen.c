#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int wordCount = 0;
    int firstLength = 0, middleLength = 0, lastLength = 0;

    Word WordList[100]; // Array of words

    STARTWORD(); // Start the word machine

    while (!isEndWord()) {
        int currentLength = currentWord.Length; // Length of the current word

        WordList[wordCount] = currentWord; // Store the current word
        ADVWORD(); // Move to the next word
        wordCount++; // Increment the word count
    }
    
    // Calculate the length of the first, middle, and last word
    firstLength = WordList[0].Length;
    middleLength = WordList[wordCount / 2].Length;
    lastLength = WordList[wordCount-1].Length;

    // Calculate the sum of lengths
    int result = firstLength + middleLength + lastLength;
    printf("%d\n", result);

    return 0;
}