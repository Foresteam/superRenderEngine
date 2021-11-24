#pragma once
#include "RenderObject.h"
#include <list>
#include <curses.h>

class RenderEngine {
private:
    std::list<RenderObject*> renderObjects;
    static RenderEngine* instance;
    static int MAXCOLS, MAXROWS;
    int defaultPair;

    Pixel Raycast(Vector2 pos);

    RenderEngine();
public:
    ~RenderEngine();
    static RenderEngine* GetInstance();
    void Render();

    void AddRenderObject(RenderObject* ro);
    void SetDefaultColors(int colorPair);
};