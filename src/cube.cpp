#include "basic.h"
#include "cube.h"

Cube gCube;

extern "C"
{
    EMSCRIPTEN_KEEPALIVE
    void setCubeSize(int width, int height)
    {
        gCube.rect.w = width;
        gCube.rect.h = height;
    }

    EMSCRIPTEN_KEEPALIVE
    void setCubePosition(int x, int y)
    {
        gCube.rect.x = getCubeVerifiedPoint(getFieldWidth(), gCube.rect.w, x);
        gCube.rect.y = getCubeVerifiedPoint(getFieldHeight(), gCube.rect.h, y);
    }

    EMSCRIPTEN_KEEPALIVE
    void setCubeColor(Color color)
    {
        gCube.color = color;
    }
}

int getCubeVerifiedPoint(int sizeField, int sizeCube, int point)
{
    point -= sizeCube / 2;
    if (sizeField < (point + sizeCube))
    {
        return sizeField - sizeCube;
    }
    if (point < 0)
    {
        return 0;
    }
    return point;
}

void renderCube(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, gCube.color.r, gCube.color.g, gCube.color.b, gCube.color.a);
    SDL_RenderFillRect(renderer, &gCube.rect);
    SDL_RenderPresent(renderer);
}

Cube *initCube()
{
    setCubeSize(CUBE_WIDTH, CUBE_HEIGHT);
    setCubePosition(CUBE_X, CUBE_Y);
    setCubeColor(CUBE_COLOR);
    return &gCube;
}
