#include "RenderEngine.h"
// #include "RORect.h"
#include "ROTriangle.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

int main(int, char**) {
    RenderEngine* render = RenderEngine::GetInstance();
    // render->AddRenderObject(new RORect(Vector2(0, 0), Vector2(10, 10)));
    auto tri = new ROTriangle(Vector2(0, 0), Vector2(40, 10), Vector2(27, 20));
    render->AddRenderObject(tri);

    double j;
    while (true) {
        render->Render();
        tri->Rotate(Quaternion(Vector(0, 0, 1), M_PI / 16));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

    delete render;

    return 0;
}
