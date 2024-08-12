# Sorting Algorithms



## Bubble Sort Step


```cpp

#include "raylib.h"
#include <vector>
#include <algorithm>

// Function to perform a single pass of bubble sort
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
        return false; // Sorting not finished yet
    }
    return true; // Sorting finished
}

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Sorting Algorithm Visualization");

    // Generate a random array of integers
    int arraySize = 100;
    std::vector<int> array(arraySize);
    for (int i = 0; i < arraySize; i++) {
        array[i] = GetRandomValue(10, screenHeight - 10); // Values between 10 and screenHeight - 10
    }

    int i = 0; // Current index of the outer loop
    int j = 0; // Current index of the inner loop
    bool sorted = false; // Flag to check if sorting is done

    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (!sorted) {
            sorted = BubbleSortStep(array, i, j);
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

```

## Bubble Sort Speed Test

```cpp
#include "raylib.h"
#include <vector>
#include <algorithm>

// Function to perform bubble sort and return the sorted array
void BubbleSort(std::vector<int>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Sorting Algorithm Visualization");

    // Generate a random array of integers
    int arraySize = 100;
    std::vector<int> array(arraySize);
    for (int i = 0; i < arraySize; i++) {
        array[i] = GetRandomValue(10, screenHeight - 10); // Values between 10 and screenHeight - 10
    }

    // Perform the sorting algorithm
    BubbleSort(array);

    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the sorted array as a series of rectangles
        for (int k = 0; k < arraySize; k++) {
            DrawRectangle(k * (screenWidth / arraySize), screenHeight - array[k], (screenWidth / arraySize) - 2, array[k], BLUE);
        }

        // Display a message indicating that the array is sorted
        DrawText("Array is sorted!", screenWidth / 2 - 100, 20, 20, DARKGREEN);

        EndDrawing();
    }

    // Close the window
    CloseWindow();

    return 0;
}


```