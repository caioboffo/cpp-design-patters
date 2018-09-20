#include <iostream>
using namespace std;

class widget_t
{
public:
    virtual void draw() = 0;
};

class text_field_t : public widget_t
{
public:
    text_field_t(int w, int h) : width(w), height(h) {}
    virtual void draw() override {
        cout << "TextField: " << width << ", " << height << endl;
    }
private:
    int width, height;
};

class decorator_t : public widget_t
{
public:
    decorator_t(widget_t *w) : widget(w) {}
    virtual void draw() override {
        widget->draw();
    }
private:
    widget_t *widget;
};

class border_decorator_t : public decorator_t
{
public:
    border_decorator_t(widget_t *w) : decorator_t(w) {}
    virtual void draw() override {
        decorator_t::draw();
        cout << "   BorderDecorator" << endl;
    }
};

class scroll_decorator_t : public decorator_t
{
public:
    scroll_decorator_t(widget_t *w) : decorator_t(w) {}
    virtual void draw() {
        decorator_t::draw();
        cout << "   ScrollDecorator" << endl;
    }
};

int main() {
    widget_t *widget =
        new border_decorator_t(
            new border_decorator_t(
                new scroll_decorator_t(
                    new text_field_t(80, 24))));
    widget->draw();
}
