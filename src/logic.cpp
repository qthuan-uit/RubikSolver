#include "lib/logic.h"
#include "lib/data.h"
#include "lib/camera.h"
#include "lib/cube.h"
Cubie* cubieDummy = new Cubie({1, 1, 1}, CubieType::CENTER);

void update(CameraWorld* cam, Cube* cube) {
    while (!WindowShouldClose())
    {
        handleKey(cam, cube);
        cam->update();
        cube->update();
        render(cam, cube);
    }
    CloseWindow();
}

void handleKey(CameraWorld* cam, Cube* cube) {
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
    for (const auto key : notationKeys) {
        if (IsKeyPressed(key)) {
            auto notation = notationKeyTranslation.at(static_cast<int>(key) + IsKeyDown(KEY_LEFT_SHIFT)*100);
            cube->handleNotation(notation);
        }
    }
}

void render(CameraWorld* cam, Cube* cube) {
BeginDrawing();
    ClearBackground(Data::BGCOLOR);
    BeginMode3D(cam->getCamera());
    rlDisableBackfaceCulling();

    DrawCube({5, 0, 0}, 10, .1f, .1f, RED);
    DrawCube({0, 5, 0}, .1f, 10, .1f, BLUE);
    DrawCube({0, 0, 5}, .1f, .1f, 10, GREEN);

    cube->draw();

    rlEnableBackfaceCulling();
    EndMode3D();
    EndDrawing();
}