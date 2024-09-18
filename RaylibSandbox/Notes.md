# Notes

# Previous Sinewave iteration


```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"

struct Pixel {
    int x;
    int y;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - wave pattern");

    SetTargetFPS(120);  // Set our game to run at 120 frames-per-second

    float time = 0.0f;
    float amplitude = 50.0f;
    float movementSpeed = 8.0f;
    float periodicTime = 0.05f;
    int pixelSpace = 2;

    std::vector<Pixel> pixels;

    // Initialize pixel positions
    for (int x = 0; x < screenWidth; x += pixelSpace)
    {
        pixels.push_back({ x, screenHeight / 2 });

    }

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        time += GetFrameTime();  // Update time

        // Update pixel positions
        for (auto& pixel : pixels)
        {
            pixel.y = screenHeight / 2 + amplitude * sinf((pixel.x + time * movementSpeed) * periodicTime);
            

        }

        BeginDrawing();

        ClearBackground(BLACK);

        // Draw the wave pattern
        for (const auto& pixel : pixels)
        {
            DrawPixel(pixel.x, pixel.y, RED);
        }

        DrawText("Wave pattern simulation", 10, 10, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();  // Close window and OpenGL context

    return 0;
}

```

## Adjacent Wave

```cpp

#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"

struct Pixel {
    int x;
    int y;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - wave pattern");

    SetTargetFPS(120);  // Set our game to run at 120 frames-per-second

    float time = 0.0f;
    float amplitude = 50.0f;
    float movementSpeed = 8.0f;
    float periodicTime = 0.05f;
    int pixelSpace = 2;

    std::vector<Pixel> pixels;
    std::vector<Pixel> pixels2;

    // Initialize pixel positions
    for (int x = 0; x < screenWidth; x += pixelSpace)
    {
        pixels.push_back({ x, screenHeight / 2 });
        pixels2.push_back({ x, screenHeight / 2 });
    }

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        time += GetFrameTime();  // Update time

        BeginDrawing();

        ClearBackground(BLACK);

        // Update and draw pixel positions
        for (size_t i = 0; i < pixels.size(); ++i)
        {
            pixels[i].y = screenHeight / 2 + amplitude * sinf((pixels[i].x + time * movementSpeed) * periodicTime);
            pixels2[i].y = screenHeight / 2 + amplitude * sinf((pixels2[i].x + time * movementSpeed) * periodicTime+10);

            DrawPixel(pixels[i].x, pixels[i].y, RED);
            DrawPixel(pixels2[i].x, pixels2[i].y, BLUE);
        }

        DrawText("Wave pattern simulation", 10, 10, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();  // Close window and OpenGL context

    return 0;
}

```

## Function Overloading Examples

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include "raylib.h"

struct Pixel {
	int x;
	int y;
};


void UpdateAndDrawPixels(std::vector<Pixel>& pixels,
	float time, float amplitude, float movementSpeed, float periodicTime, int index)
{
	if (index >= pixels.size())
		return;

	pixels[index].y = 225 + amplitude * tanf((pixels[index].x + time * movementSpeed) * periodicTime);

	DrawPixel(pixels[index].x, pixels[index].y, RED);;

	UpdateAndDrawPixels(pixels, time, amplitude, movementSpeed, periodicTime, index + 1);
}

void UpdateAndDrawPixels(std::vector<Pixel>& pixels, std::vector<Pixel>& pixels2,
	float time, float amplitude, float movementSpeed, float periodicTime, int index)
{
	if (index >= pixels.size())
		return;

	pixels[index].y = 225 + amplitude * sinf((pixels[index].x + time * movementSpeed) * periodicTime + acoshf(2) * index);
	pixels2[index].y = 225 + amplitude * sinf((pixels2[index].x + time * movementSpeed) * periodicTime + asinhf(2) * index);

	DrawPixel(pixels[index].x, pixels[index].y, RED);
	DrawPixel(pixels2[index].x, pixels2[index].y, BLUE);

	UpdateAndDrawPixels(pixels, pixels2, time, amplitude, movementSpeed, periodicTime, index + 1);
}

void UpdateAndDrawPixels(std::vector<Pixel>& pixels, std::vector<Pixel>& pixels2, std::vector<Pixel>& pixels3, 
	float time, float amplitude, float movementSpeed, float periodicTime, int index)
{
	if (index >= pixels.size())
		return;

	pixels[index].y = 225 + amplitude * sinf((pixels[index].x + time * movementSpeed) * periodicTime + sinf(2) * index);
	pixels2[index].y = 225 + amplitude * cosf((pixels2[index].x + time * movementSpeed) * periodicTime + cosf(2) * index);
	pixels3[index].y = 225 + amplitude * tanf((pixels3[index].x + time * movementSpeed) * periodicTime + tanf(2) * index);


	DrawPixel(pixels[index].x, pixels[index].y, RED);
	DrawPixel(pixels2[index].x, pixels2[index].y, BLUE);
	DrawPixel(pixels3[index].x, pixels3[index].y, GREEN);


	UpdateAndDrawPixels(pixels, pixels2,pixels3, time, amplitude, movementSpeed, periodicTime, index + 1);
}


int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - wave pattern");

	SetTargetFPS(120);  // Set our game to run at 120 frames-per-second

	float time = 0.0f;
	float amplitude = 100.0f;
	float movementSpeed = 2.0f;
	float periodicTime = 0.04f;
	int pixelSpace = 1;


	std::vector<Pixel> pixels;
	std::vector<Pixel> pixels2;
	std::vector<Pixel> pixels3;
	// Initialize pixel positions
	for (int x = 0; x < screenWidth; x += pixelSpace)
	{
		pixels.push_back({ x, screenHeight / 2 });
		pixels2.push_back({ x, screenHeight / 2 });
		pixels3.push_back({ x,screenHeight / 2 });
	}

	// Main game loop
	while (!WindowShouldClose())  // Detect window close button or ESC key
	{
		time += GetFrameTime();  // Update time

		BeginDrawing();

		ClearBackground(BLACK);

		// Update and draw pixel positions using recursion
		UpdateAndDrawPixels(pixels, time, amplitude, movementSpeed, periodicTime, 0);

		DrawText("Wave pattern simulation", 10, 10, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();  // Close window and OpenGL context

	return 0;
}



```