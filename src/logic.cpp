#include "logic.h"
#include "data.h"

void update() {
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(Data::BGCOLOR);
        EndDrawing();
    }
    CloseWindow();
}