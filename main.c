#include <stdio.h>
#include <assert.h>
#include "Color.h"
#include "Test.c"

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

const int MAX_COLORPAIR_NAME_CHARS = 16;
const int numberOfMajorColors  = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const int numberOfMinorColors  = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void PrintColorReferenceManual() {
    printf("Reference Manual for Wiring Personnel:\n");
    printf("Major Color Codes:\n");
    for (int i = 0; i < numberOfMajorColors ; i++) {
        printf("  %d: %s\n", i + 1, MajorColorNames[i]);
    }
    printf("Minor Color Codes:\n");
    for (int i = 0; i < numberOfMinorColors ; i++) {
        printf("  %d: %s\n", i + 1, MinorColorNames[i]);
    }
}

int main() {
    run_tests();
    PrintColorReferenceManual();
    return 0;
}
