#include "RenderEngine.h"

RenderEngine* RenderEngine::instance = nullptr;
RenderEngine::~RenderEngine() {
	for (auto ro : renderObjects)
		delete ro;
    getch();
    endwin();
}
RenderEngine::RenderEngine() {
	initscr();
	cbreak();
	noecho();
    MAXCOLS = COLS;
    MAXROWS = LINES;
}
RenderEngine* RenderEngine::GetInstance() {
	if (!instance)
		instance = new RenderEngine();
	return instance;
}

RenderEngine::Pixel RenderEngine::Raycast(Vector2 pos) {
    Pixel p = Pixel(' ');
    double shortestD = -__DBL_MAX__;
    for (auto ro : renderObjects)
        for (auto tri : ro->GetTriangles())
            if (tri.Contains(pos)) {
                Vector t = tri.GetPointProjection(pos);
                double d = t.GetLength();
                if (d > shortestD) {
                    shortestD = d;
                    p = Pixel('#');
                }
            }
    return p;
}
void RenderEngine::Render() {
    clear();
    for (int y = 0; y < MAXROWS; y++)
        for (int x = 0; x < MAXCOLS; x++) {
            Pixel p = Raycast(Vector2(x, y));
            mvaddch(y, x, p.self);
        }
    refresh();
}

void RenderEngine::AddRenderObject(RenderObject* ro) {
    renderObjects.push_back(ro);
}