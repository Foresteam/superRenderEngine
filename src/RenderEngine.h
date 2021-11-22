#pragma once
#include "RenderObject.h"
#include <list>
#include <curses.h>

class RenderEngine {
private:
    std::list<RenderObject*> renderObjects;
    static RenderEngine* instance;
    static int MAXCOLS, MAXROWS;

    struct Pixel {
        char self;
        int colorPair;
        Pixel(char self = ' ', int colorPair = 0) {
            this->self = self;
            this->colorPair = colorPair;
        }
    };

    Pixel Raycast(Vector2 pos);

    RenderEngine();
public:
    ~RenderEngine();
    static RenderEngine* GetInstance();
    void Render();

    void AddRenderObject(RenderObject* ro);
};