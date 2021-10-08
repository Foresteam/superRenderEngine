#include "RenderEngine.h"
// #include "RORect.h"
#include "ROTriangle.h"
#include <iostream>

int main(int, char**) {
    RenderEngine* render = RenderEngine::GetInstance();
    // render->AddRenderObject(new RORect(Vector2(0, 0), Vector2(10, 10)));
    auto tri = new ROTriangle(Vector2(0, 0), Vector2(40, 10), Vector2(27, 20));
    render->AddRenderObject(tri);
    // tri->Rotate(Angle(0, M_PI_4));

    // Vector2 a = Vector2(5, 5);
    // Vector2 b = Vector2(9, 9);
    // Vector2 ba = b - a;
    // Vector2 c = (b - a).Angle();
    // Vector2 d = Vector2(cos(M_PI) * a.x - sin(M_PI) * a.y, sin(M_PI) * a.x + cos(M_PI) * a.y);

    while (true) {
        render->Render();
        break;
    }

    delete render;

    return 0;
}
