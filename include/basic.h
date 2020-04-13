#include <SDL2/SDL.h>
#include <cstdlib>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

struct Color
{
    int r;
    int g;
    int b;
    int a;
};
