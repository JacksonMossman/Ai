
#include "raylib.h"
#include "KeyboardBehavior.h"
#include"SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition({ 100,100 });
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior;
	player->addBehaviour(keyboardBehavior);
	

	Agent* enemy = new Agent();
	enemy->setPosition({ 500,500 });
	WanderBehavior* wanderBehavior = new WanderBehavior();
	
	
	enemy->addBehaviour(wanderBehavior);


	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player->update(GetFrameTime());
		enemy->update(GetFrameTime());
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		player->draw();
		enemy->draw();
		ClearBackground(BLACK);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}