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

    float gAcceleration = -0.5;

    float jumpInitialVel = 0.1;

    bool jumpAllowed = true;

    

    DisableCursor();

    const float dt = 1.0f/60;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {


        // updating position
        // float tempVel = cameraVel.z * 0.1;
        // std::cout << "temp vel z: " << tempVel << std::endl;

        // cameraPos is my own made up model and it is not agreeing with raylib camera position
        // if I try to add * dt when updating position. But camera.position is not changing dynamically lmao
        cameraPos.z += cameraVel.z;

        // constantly falling if above ground
        if (cameraPos.z > 2) {
            cameraVel.z += gAcceleration * dt;
        } else {
            cameraVel.z = 0;
            jumpAllowed = true;
        }

        std::cout << "camera pos z: " << cameraPos.z << std::endl;
        // std::cout << "camera vel z: " << cameraVel.z << std::endl;

        if (IsKeyDown(KEY_SPACE) && jumpAllowed) {
            cameraVel.z = jumpInitialVel;
            jumpAllowed = false;
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
