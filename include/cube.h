struct Cube
{
    SDL_Rect rect;
    Color color;
};

const int CUBE_WIDTH = 50;
const int CUBE_HEIGHT = 50;
const int CUBE_X = 200;
const int CUBE_Y = 200;
const Color CUBE_COLOR = {196, 85, 0, 255};

extern "C"
{
    EMSCRIPTEN_KEEPALIVE
    void setCubeSize(int width, int height);

    EMSCRIPTEN_KEEPALIVE
    void setCubePosition(int x, int y);

    EMSCRIPTEN_KEEPALIVE
    void setCubeColor(Color color);
}

extern int getFieldWidth();
extern int getFieldHeight();

int getCubeVerifiedPoint(int sizeField, int sizeCube, int point);
void renderCube(SDL_Renderer *renderer);
Cube *initCube();