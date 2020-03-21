#include <SDL2/SDL.h>
#include <cstdlib>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif
#include "core.h"

Context gContext;

extern "C"
{
    EMSCRIPTEN_KEEPALIVE
    void setFieldSize(int width, int height)
    {
        gContext.field.size.w = width;
        gContext.field.size.h = height;
    }

    EMSCRIPTEN_KEEPALIVE
    void setFieldColor(int r, int g, int b, int a)
    {
        gContext.field.color.r = r;
        gContext.field.color.g = g;
        gContext.field.color.b = b;
        gContext.field.color.a = a;
    }

    EMSCRIPTEN_KEEPALIVE
    void setCubeSize(int width, int height)
    {
        gContext.cube.size.w = width;
        gContext.cube.size.h = height;
    }

    EMSCRIPTEN_KEEPALIVE
    void setCubePoint(int x, int y)
    {
        if (gContext.field.size.w < (x + gContext.cube.size.w))
        {
            x = gContext.field.size.w - gContext.cube.size.w;
        }
        if (x < 0)
        {
            x = 0;
        }

        if (gContext.field.size.h < y + gContext.cube.size.h)
        {
            y = gContext.field.size.h - gContext.cube.size.h;
        }
        if (y < 0)
        {
            y = 0;
        }

        gContext.cube.point.x = x;
        gContext.cube.point.y = y;
    }

    EMSCRIPTEN_KEEPALIVE
    void setCubeColor(int r, int g, int b, int a)
    {
        gContext.cube.color.r = r;
        gContext.cube.color.g = g;
        gContext.cube.color.b = b;
        gContext.cube.color.a = a;
    }
}

void renderWindow()
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(gContext.field.size.w, gContext.field.size.h, 0, &window, &renderer);
    gContext.renderer = renderer;
    gContext.window = window;
}

void renderField()
{
    SDL_SetRenderDrawColor(gContext.renderer, gContext.field.color.r, gContext.field.color.g, gContext.field.color.b, gContext.field.color.a);
    SDL_RenderClear(gContext.renderer);
}

void renderCube()
{
    SDL_Rect r;
    r.x = gContext.cube.point.x;
    r.y = gContext.cube.point.y;
    r.w = gContext.cube.size.w;
    r.h = gContext.cube.size.h;
    SDL_SetRenderDrawColor(gContext.renderer, gContext.cube.color.r, gContext.cube.color.g, gContext.cube.color.b, gContext.cube.color.a);
    SDL_RenderFillRect(gContext.renderer, &r);
    SDL_RenderPresent(gContext.renderer);
}

void mainloop(void *arg)
{
    renderField();
    renderCube();
}

void runLoop()
{
    const int simulate_infinite_loop = 1;
    const int fps = -1;
    emscripten_set_main_loop_arg(mainloop, &gContext, fps, simulate_infinite_loop);
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    setFieldSize(400, 400);
    setFieldColor(19, 38, 81, 255);

    setCubeSize(50, 50);
    setCubeColor(196, 85, 0, 255);
    setCubePoint(175, 175);

    renderWindow();
    runLoop();

    SDL_DestroyRenderer(gContext.renderer);
    SDL_DestroyWindow(gContext.window);
    SDL_Quit();

    return EXIT_SUCCESS;
}