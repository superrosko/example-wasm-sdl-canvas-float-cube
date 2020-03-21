struct Size
{
    int w;
    int h;
};

struct Point
{
    int x;
    int y;
};

struct Color
{
    int r;
    int g;
    int b;
    int a;
};

struct Field
{
    Size size;
    Color color;
};

struct Cube
{
    Size size;
    Point point;
    Color color;
};

struct Context
{
    Field field;
    Cube cube;
    SDL_Window *window;
    SDL_Renderer *renderer;
};