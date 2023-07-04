#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include <iostream>

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Camera initialization
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    int cameraMode = CAMERA_FIRST_PERSON;

    // Custom variables for kinematics
    Vector3 cameraVel = { 0.0f, 0.0f, 0.0f };
    Vector3 cameraPos = { 0.0f, 0.0f, 4.0f };

    // Just a sample box
    Vector3 boxPosition = { 0.0f, 1.0f, -3.0f };

    // Kinematics parameters
    float gAcceleration = -9.8;

    float jumpInitialVel = 3;
    // To prevent double jumping
    bool jumpAllowed = true;


    DisableCursor();

    int targetFPS = 60;
    SetTargetFPS(targetFPS);
    const float dt = 1.0f/targetFPS;

    while (!WindowShouldClose())
    {
        // updating position
        Vector3 displacement = cameraVel;
        displacement.z = displacement.z * dt;

        cameraPos.z += displacement.z;

        // constantly accelerating down if above ground
        if (cameraPos.z > 2) {
            cameraVel.z += gAcceleration * dt;
        } else {
            cameraVel.z = 0;
            jumpAllowed = true;
            // set position z at exactly 2 when arrive to ground
            displacement = { 0, 0, 2 - cameraPos.z }; // displace camera slightly up so that it reaches height 2
            cameraPos.z = 2;
        }

        std::cout << "camera pos z: " << cameraPos.z << std::endl;
        std::cout << "camera vel z: " << cameraVel.z << std::endl;

        if (IsKeyDown(KEY_SPACE) && jumpAllowed) {
            cameraVel.z = jumpInitialVel;
            jumpAllowed = false;
        }
    
        UpdateCamera(&camera, cameraMode);
        UpdateCameraPro(&camera, displacement, (Vector3) {0.0f, 0.0f, 0.0f}, 0.0f);

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
