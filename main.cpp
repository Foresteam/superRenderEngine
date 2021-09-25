#include "RenderEngine.h"
#include "RORect.h"
#include "ROTriangle.h"
#include <iostream>

int main(int, char**) {
    RenderEngine* render = RenderEngine::GetInstance();
    render->AddRenderObject(new RORect(Vector2(0, 0), Vector2(10, 10)));
    render->AddRenderObject(new ROTriangle(Vector2(15, 0), Vector2(40, 7), Vector2(27, 10)));

    while (true) {
        render->Render();
        break;
    }

    delete render;

    return 0;
}
