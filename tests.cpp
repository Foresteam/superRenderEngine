#include "src/RenderEngine.h"
#include "src/RORect.h"
#include "src/ROTriangle.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

const int mode = 1;

int main(int, char**) {
    RenderEngine* render = RenderEngine::GetInstance();

    ROTriangle* tri;
    RORect* rect;
    switch (mode) {
        case 1:
            tri = new ROTriangle(Vector2(0, 0), Vector2(40, 10), Vector2(27, 20));
            render->AddRenderObject(tri);

            while (true) {
                render->Render();
                tri->Rotate(Quaternion(Vector(0, 1, 0), M_PI / 16));
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            break;
        case 2:
            rect = new RORect(Vector2(8, 8), Vector2(20, 20));
            render->AddRenderObject(rect);

			while (true) {
				render->Render();
				rect->Rotate(Quaternion(Vector(0, 0, 1), M_PI / 16));
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			break;
    }

    delete render;

    return 0;
}
