#include <raylib.h>
#include "lib/cube.h"
#include "lib/data.h"
#include "lib/init.h"
#include "lib/logic.h"
#include "lib/camera.h"

CameraWorld* camera = new CameraWorld(45.f, 45.f, 10.f, {10, 10, 10});


int main() 
{
    init();
    update(camera); 
}