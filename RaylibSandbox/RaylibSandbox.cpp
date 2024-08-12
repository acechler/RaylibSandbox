#include "raylib.h"
#include <vector>
#include <algorithm>



bool BubbleSortStep(std::vector<int>& array, int& i, int& j) {
    if (i < array.size() - 1) {
        if (j < array.size() - i - 1) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
            j++;
        }
        else {
            j = 0;
            i++;
        }
        return false;
    }
    return true;
}


bool selectionSort(std::vector<int>& array, int& i, int& j) {
    if (i < array.size() - 1) {
        int minIndex = i;

        if (j < array.size()) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
            j++;
        }
        else {
            std::swap(array[i], array[minIndex]);
            i++;
            j = i + 1;
        }

        return false;
    }
    return true;
}



int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Sorting Algorithm Visualization");

    // Generate a random array of integers
    int arraySize = 20;
    std::vector<int> array(arraySize);
    for (int i = 0; i < arraySize; i++) {
        array[i] = GetRandomValue(10, screenHeight - 10);
    }

    int i = 0; 
    int j = 0; 
    bool sorted = false;

    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (!sorted) {
            sorted = selectionSort(array, i, j);
        }

        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the array as a series of rectangles
        for (int k = 0; k < arraySize; k++) {
            Color color = (k == j || k == j + 1) ? RED : BLUE; // Highlight the elements being compared
            DrawRectangle(k * (screenWidth / arraySize), screenHeight - array[k], (screenWidth / arraySize) - 2, array[k], color);
        }

        // Draw the sorting status
        if (sorted) {
            DrawText("Array is sorted!", screenWidth / 2 - 100, 20, 20, DARKGREEN);
        }
        else {
            DrawText("Sorting...", screenWidth / 2 - 70, 20, 20, DARKGRAY);
        }

        EndDrawing();
    }

    // Close the window
    CloseWindow();

    return 0;
}