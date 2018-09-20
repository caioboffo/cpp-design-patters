#include <iostream>
#include <memory>

using namespace std;

class draw_api_t
{
public:
    virtual void draw_circle(int, int, int) {}
};

class red_circle_t : public draw_api_t
{
    virtual void draw_circle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: red, radius: " << radius
             << ", x: " << x << ", y: " << y << "]" << endl;
    }

};

class green_circle_t : public draw_api_t
{
     virtual void draw_circle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: green, radius: " << radius
             << ", x: " << x << ", y: " << y << "]" << endl;
     }
};

class shape_t
{
public:
    shape_t() = default;
    shape_t(draw_api_t *_draw_api) {
        this->draw_api = _draw_api;
    }
    virtual void draw() = 0;
protected:
    draw_api_t *draw_api;
};

class circle_t : public shape_t
{
public:
    circle_t(int x, int y, int radius, draw_api_t *draw_api) {
        this->draw_api = draw_api;
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() override {
        this->draw_api->draw_circle(radius, x, y);
    }

private:
    int x, y, radius;
};

int main(int argc, char *argv[])
{
    circle_t red_c = circle_t(100, 100, 10,
                              new red_circle_t);

    circle_t gre_c = circle_t(100, 100, 10,
                              new green_circle_t);

    red_c.draw();
    gre_c.draw();
    return 0;
}
