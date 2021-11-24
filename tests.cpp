#include "src/RenderEngine.h"
#include "src/RORect.h"
#include "src/ROTriangle.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

const int mode = 1;

void FrameLoop() {
    clock_t start = 0;
    while (true) {
        if ((float)(clock() - start) / CLOCKS_PER_SEC < 1 / 60) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60 / 2));
            continue;
        }
        start = clock();
        // here we do our stuff
	}
}

#define BACKGROUND_COLOR COLOR_BLACK
#define CYAN_PAIR 1

int main(int, char**) {
    RenderEngine* render = RenderEngine::GetInstance();
	init_pair(0, COLOR_WHITE, BACKGROUND_COLOR);
	init_pair(1, COLOR_CYAN, BACKGROUND_COLOR);
	render->SetDefaultColors(0);

    ROTriangle* tri;
    RORect* rect;
    switch (mode) {
        case 1:
            tri = new ROTriangle(Vector2(0, 0), Vector2(80, 10), Vector2(27, 30));
            tri->Paint(Pixel('#', CYAN_PAIR));
            render->AddRenderObject(tri);

            while (true) {
                render->Render();
                tri->Rotate(Quaternion(Vector(0, 1, 0), M_PI / 48));
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
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
