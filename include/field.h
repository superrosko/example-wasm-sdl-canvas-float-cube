struct Field
{
    int width;
    int height;
    Color color;
};

const int FIELD_WIDTH = 400;
const int FIELD_HEIGHT = 400;
const Color FIELD_COLOR = {19, 38, 81, 255};

extern "C"
{
    EMSCRIPTEN_KEEPALIVE
    void setFieldSize(int width, int height);

    EMSCRIPTEN_KEEPALIVE
    void setFieldColor(Color color);
}

int getFieldWidth();
int getFieldHeight();
void renderField(SDL_Renderer *renderer);
Field *initField();