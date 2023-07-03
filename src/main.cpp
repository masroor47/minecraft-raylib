#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include <iostream>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_FIRST_PERSON;

    Vector3 cameraVel = { 0.0f, 0.0f, 0.0f };
    Vector3 cameraPos = { 0.0f, 0.0f, 4.0f };

    Vector3 boxPosition = { 0.0f, 1.0f, -3.0f };

    

    DisableCursor();

    const float dt = 1.0f/60;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {



        cameraPos.z += cameraVel.z;

        if (cameraPos.z > 2) {
            cameraVel.z += -0.01;
        } else {
            cameraVel.z = 0;
        }

        
        std::cout << "camera pos z: " << cameraPos.z << std::endl;
        std::cout << "camera vel z: " << cameraVel.z << std::endl;

        if (IsKeyDown(KEY_SPACE)) {
            cameraVel.z = 0.1;
        }
    
        UpdateCamera(&camera, cameraMode);
        UpdateCameraPro(&camera, cameraVel, (Vector3) {0.0f, 0.0f, 0.0f}, 0.0f);



        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){32.0f, 32.0f }, LIGHTGRAY);
                DrawCube(boxPosition, 1.0f, 1.0f, 1.0f, GREEN);

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
