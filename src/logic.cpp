#include "lib/logic.h"
#include "lib/data.h"
#include "lib/camera.h"

void update(CameraWorld* cam, std::vector<Cubie*> cubies) {
    while (!WindowShouldClose())
    {
        handleKey(cam, cubies);
        cam->update();
        for (auto& cubie : cubies) cubie->update();
        render(cam, cubies);
    }
    CloseWindow();
}

void handleKey(CameraWorld* cam, std::vector<Cubie*> cubies) {
    if ((IsKeyDown(KEY_LEFT)) || (IsKeyDown(KEY_RIGHT))) {
        int dir = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
        cam->rotate(dir, 0);
    }
    if ((IsKeyDown(KEY_DOWN)) || (IsKeyDown(KEY_UP))) {
        int dir = IsKeyDown(KEY_UP) - IsKeyDown(KEY_DOWN);
        cam->rotate(0, dir);
    }
    if (GetMouseWheelMove()) {
        int dir = -GetMouseWheelMove();
        cam->zoom(dir);
    }
}

void render(CameraWorld* cam, std::vector<Cubie*> cubies) {
BeginDrawing();
    ClearBackground(Data::BGCOLOR);
    BeginMode3D(cam->getCamera());
    rlDisableBackfaceCulling();

    DrawCube({5, 0, 0}, 10, .1f, .1f, RED);
    DrawCube({0, 5, 0}, .1f, 10, .1f, BLUE);
    DrawCube({0, 0, 5}, .1f, .1f, 10, GREEN);

    for (auto& cubie : cubies) {
        cubie->draw();
    }

    rlEnableBackfaceCulling();
    EndMode3D();
    EndDrawing();
}