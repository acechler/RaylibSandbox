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


	// Main game loop
	while (!WindowShouldClose())  // Detect window close button or ESC key
	{

		BeginDrawing();

		ClearBackground(BLACK);


		DrawText("Wave pattern simulation", 10, 10, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();  // Close window and OpenGL context

	return 0;
}

