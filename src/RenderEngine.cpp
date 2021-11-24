#include "RenderEngine.h"

int RenderEngine::MAXCOLS = 1;
int RenderEngine::MAXROWS = 1;

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
    start_color();
	defaultPair = 0;
    MAXCOLS = COLS;
    MAXROWS = LINES;
}
RenderEngine* RenderEngine::GetInstance() {
	if (!instance)
		instance = new RenderEngine();
	return instance;
}

Pixel RenderEngine::Raycast(Vector2 pos) {
    Pixel p = Pixel(' ');
    double shortestD = -__DBL_MAX__;
    for (auto ro : renderObjects)
        for (auto tri : ro->GetTriangles())
            if (tri.PlaneContains(pos)) {
                Vector t = tri.PlanePointProjection(pos);
                double d = t.Length();
                if (d > shortestD) {
                    p = tri.pixel;
                }
            }
    return p;
}
void RenderEngine::Render() {
    clear();
    for (int y = 0; y < MAXROWS; y++)
        for (int x = 0; x < MAXCOLS; x++) {
            Pixel p = Raycast(Vector2(x, y));
            attron(COLOR_PAIR(p.colorPair));
            mvaddch(y, x, p.self);
            attroff(COLOR_PAIR(p.colorPair));
        }
    refresh();
}

void RenderEngine::AddRenderObject(RenderObject* ro) {
    renderObjects.push_back(ro);
}
void RenderEngine::SetDefaultColors(int colorPair) {
    defaultPair = colorPair;
}