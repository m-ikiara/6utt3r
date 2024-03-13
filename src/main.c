#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "rcamera.h"

#define MAX_COLUMNS 20

void
draw_camera_controls(Font font)
{
	DrawRectangle(5, 5, 330, 100, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(5, 5, 330, 100, BLUE);

	DrawTextEx(font, "Camera controls:", (Vector2){ 15, 15 }, 12, 1.5, BLACK);
	DrawTextEx(font, "- Move keys: W, A, S, D, Space, Left-Ctrl", (Vector2){ 15, 30 }, 12, 1.5, BLACK);
	DrawTextEx(font, "- Look around: arrow keys or mouse", (Vector2){ 15, 45 }, 12, 1.5, BLACK);
	DrawTextEx(font, "- Camera mode keys: 1, 2, 3, 4", (Vector2){ 15, 60 }, 12, 1.5, BLACK);
	DrawTextEx(font, "- Zoom keys: num-plus, num-minus or mouse scroll", (Vector2){ 15, 75 }, 12, 1.5, BLACK);
	DrawTextEx(font, "- Camera projection key: P", (Vector2){ 15, 90 }, 12, 1.5, BLACK);
}

void
draw_camera_status(Camera camera, Font font, int camera_mode)
{
	DrawRectangle(535, 5, 260, 100, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(535, 5, 260, 100, BLUE);

	DrawTextEx(font, "Camera status:", (Vector2){ 545, 15 }, 12, 1.5, BLACK);
	DrawTextEx(font, TextFormat("- Mode: %s", (camera_mode == CAMERA_FREE) ? "FREE" :
				(camera_mode == CAMERA_FIRST_PERSON) ? "FIRST_PERSON" :
				(camera_mode == CAMERA_THIRD_PERSON) ? "THIRD_PERSON" :
				(camera_mode == CAMERA_ORBITAL) ? "ORBITAL" : "CUSTOM"), (Vector2){ 545, 30 }, 12, 1.5, BLACK);
	DrawTextEx(font, TextFormat("- Projection: %s", (camera.projection == CAMERA_PERSPECTIVE) ? "PERSPECTIVE" :
				(camera.projection == CAMERA_ORTHOGRAPHIC) ? "ORTHOGRAPHIC" : "CUSTOM"), (Vector2){ 545, 45 }, 12, 1.5, BLACK);
	DrawTextEx(font, TextFormat("- Position: (%06.3f, %06.3f, %06.3f)",
				camera.position.x, camera.position.y,
				camera.position.z), (Vector2){ 545, 60 }, 12, 1.5, BLACK);
	DrawTextEx(font, TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", camera.target.x, camera.target.y, camera.target.z), (Vector2){ 545, 75 }, 12, 1.5, BLACK);
	DrawTextEx(font, TextFormat("- Up: (%06.3f, %06.3f, %06.3f)", camera.up.x, camera.up.y, camera.up.z), (Vector2){ 545, 90 }, 12, 1.5, BLACK);
}

int
main(void)
{
	InitWindow(800, 600, "6utt3r: The 3D Raycasting Engine");

	Camera camera = { 0 };
	camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
	camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 60.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

	int camera_mode = CAMERA_FIRST_PERSON;

	Font my_font = LoadFontEx("./fonts/JetBrainsMonoNerdFontMono-Thin.ttf", 12, NULL, 0);

	DisableCursor();                    // Limit cursor to relative movement inside the window

	SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
	while (!WindowShouldClose())        // Detect window close button or ESC key
	{
		if (IsKeyPressed(KEY_ONE))
		{
			camera_mode = CAMERA_FREE;
			camera.up = (Vector3){ 0.0f, 1.0f, 0.0f }; // Reset roll
		}

		if (IsKeyPressed(KEY_TWO))
		{
			camera_mode = CAMERA_FIRST_PERSON;
			camera.up = (Vector3){ 0.0f, 1.0f, 0.0f }; // Reset roll
		}

		if (IsKeyPressed(KEY_THREE))
		{
			camera_mode = CAMERA_THIRD_PERSON;
			camera.up = (Vector3){ 0.0f, 1.0f, 0.0f }; // Reset roll
		}

		if (IsKeyPressed(KEY_FOUR))
		{
			camera_mode = CAMERA_ORBITAL;
			camera.up = (Vector3){ 0.0f, 1.0f, 0.0f }; // Reset roll
		}

		if (IsKeyPressed(KEY_P))
		{
			if (camera.projection == CAMERA_PERSPECTIVE)
			{
				camera_mode = CAMERA_THIRD_PERSON;
				camera.position = (Vector3){ 0.0f, 2.0f, -100.0f };
				camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
				camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
				camera.projection = CAMERA_ORTHOGRAPHIC;
				camera.fovy = 20.0f; // near plane width in CAMERA_ORTHOGRAPHIC
				CameraYaw(&camera, -135 * DEG2RAD, true);
				CameraPitch(&camera, -45 * DEG2RAD, true, true, false);
			}
			else if (camera.projection == CAMERA_ORTHOGRAPHIC)
			{
				camera_mode = CAMERA_THIRD_PERSON;
				camera.position = (Vector3){ 0.0f, 2.0f, 10.0f };
				camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
				camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
				camera.projection = CAMERA_PERSPECTIVE;
				camera.fovy = 60.0f;
			}
		}

		UpdateCamera(&camera, camera_mode);                  // Update camera
		BeginDrawing();

			ClearBackground(RAYWHITE);

			BeginMode3D(camera);

				DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
				DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, GOLD);     // Draw a blue wall
				DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, GOLD);      // Draw a green wall
				DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

				if (camera_mode == CAMERA_THIRD_PERSON)
				{
					DrawCube(camera.target, 0.5f, 0.5f, 0.5f, PURPLE);
					DrawCubeWires(camera.target, 0.5f, 0.5f, 0.5f, DARKPURPLE);
				}

			EndMode3D();

			draw_camera_controls(my_font);
			draw_camera_status(camera, my_font, camera_mode);

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
