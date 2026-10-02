#include "lib/logic.h"
#include "lib/data.h"
#include "lib/camera.h"

void update(CameraWorld* cam) {
    while (!WindowShouldClose())
    {
        handleKey(cam);
        cam->update();
        render(cam);
    }
    CloseWindow();
}

void handleKey(CameraWorld* cam) {
    if ((IsKeyDown(KEY_LEFT)) || (IsKeyDown(KEY_RIGHT))) {
        int dir = IsKeyDown(KEY_LEFT) - IsKeyDown(KEY_RIGHT);
        cam->rotate(dir * cam->rotateSpeed, 0);
    }
    if ((IsKeyDown(KEY_DOWN)) || (IsKeyDown(KEY_UP))) {
        int dir = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
        cam->rotate(0, dir * cam->rotateSpeed);
    }
    if (GetMouseWheelMove()) {
        int dir = -GetMouseWheelMove();
        cam->zoom(dir);
    }
}

void render(CameraWorld* cam) {
BeginDrawing();
    ClearBackground(Data::BGCOLOR);
    BeginMode3D(cam->camera);

    DrawSphere({0, 0, 0}, .3f, BLACK);
    DrawCube({5, 0, 0}, 10, .1f, .1f, RED);
    DrawCube({0, 5, 0}, .1f, 10, .1f, BLUE);
    DrawCube({0, 0, 5}, .1f, .1f, 10, GREEN);

    EndMode3D();
    EndDrawing();
}