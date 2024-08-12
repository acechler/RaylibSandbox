#include "raylib.h"
#include <vector>
#include <algorithm>

// Enum to select sorting algorithm
enum SortingAlgorithm { BUBBLE_SORT, SELECTION_SORT };

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

// Function to perform a single pass of selection sort
bool SelectionSortStep(std::vector<int>& array, int& i, int& j, int& minIndex) {
    if (i < array.size() - 1) {
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
            minIndex = i;
        }
        return false; // Sorting not finished yet
    }
    return true; // Sorting finished
}

// Function to generate a new random array
void GenerateRandomArray(std::vector<int>& array, int screenHeight) {
    for (int i = 0; i < array.size(); i++) {
        array[i] = GetRandomValue(10, screenHeight - 10); // Values between 10 and screenHeight - 10
    }
}

int main() {
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Sorting Algorithm Visualization");

    // Generate a random array of integers
    int arraySize = 20;
    std::vector<int> array(arraySize);
    GenerateRandomArray(array, screenHeight);

    int i = 0; // Current index of the outer loop
    int j = 0; // Current index of the inner loop
    int minIndex = 0; // Index of the minimum element for selection sort
    bool sorted = false; // Flag to check if sorting is done
    bool sortingPaused = true; // Flag to pause/resume sorting

    SortingAlgorithm currentAlgorithm = BUBBLE_SORT; // Default to BubbleSort

    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Toggle sorting algorithm with key press
        if (IsKeyPressed(KEY_ONE)) {
            currentAlgorithm = BUBBLE_SORT;
            i = 0; j = 0; sorted = false; sortingPaused = true;
        }
        if (IsKeyPressed(KEY_TWO)) {
            currentAlgorithm = SELECTION_SORT;
            i = 0; j = 1; minIndex = 0; sorted = false; sortingPaused = true;
        }

        // Toggle pause/resume with spacebar
        if (IsKeyPressed(KEY_SPACE)) {
            sortingPaused = !sortingPaused;
        }

        // Refill array with new random values with R key
        if (IsKeyPressed(KEY_R)) {
            GenerateRandomArray(array, screenHeight);
            i = 0; j = (currentAlgorithm == SELECTION_SORT) ? 1 : 0; minIndex = 0;
            sorted = false; sortingPaused = true;
        }

        // Update only if sorting is not paused and not finished
        if (!sortingPaused && !sorted) {
            if (currentAlgorithm == BUBBLE_SORT) {
                sorted = BubbleSortStep(array, i, j);
            }
            else if (currentAlgorithm == SELECTION_SORT) {
                sorted = SelectionSortStep(array, i, j, minIndex);
            }
        }

        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the array as a series of rectangles
        for (int k = 0; k < arraySize; k++) {
            Color color = (k == j - 1 || k == minIndex) ? RED : BLUE; // Highlight the elements being compared
            DrawRectangle(k * (screenWidth / arraySize), screenHeight - array[k], (screenWidth / arraySize) - 2, array[k], color);
        }

        // Draw the sorting status
        if (sorted) {
            DrawText("Array is sorted!", screenWidth / 2 - 100, 20, 20, DARKGREEN);
        }
        else if (sortingPaused) {
            DrawText("Press SPACE to start sorting", screenWidth / 2 - 130, 20, 20, DARKGRAY);
        }
        else {
            DrawText("Sorting...", screenWidth / 2 - 70, 20, 20, DARKGRAY);
        }

        DrawText(currentAlgorithm == BUBBLE_SORT ? "Algorithm: Bubble Sort (Press 1)" : "Algorithm: Selection Sort (Press 2)", 10, 10, 20, BLACK);
        DrawText("Press R to generate new array", 10, 40, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
