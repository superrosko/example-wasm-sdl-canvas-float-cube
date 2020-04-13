#include "basic.h"
#include "field.h"
#include "cube.h"
#include "core.h"

Context gContext;

SDL_Renderer *getGContextRender()
{
    return gContext.renderer;
}

void renderWindow()
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(getFieldWidth(), getFieldHeight(), 0, &window, &renderer);
    gContext.renderer = renderer;
    gContext.window = window;
}

void mainloop(void *arg)
{
    SDL_Renderer *render = getGContextRender();
    renderField(render);
    renderCube(render);
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

    initField();
    initCube();

    renderWindow();
    runLoop();

    SDL_DestroyRenderer(gContext.renderer);
    SDL_DestroyWindow(gContext.window);
    SDL_Quit();

    return EXIT_SUCCESS;
}