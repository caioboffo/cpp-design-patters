#ifndef WINDOW_H
#define WINDOW_H

class window
{
public:
    window() = default;
    virtual ~window() = default;
    virtual void show() = 0;
    void set_width(int n) {
        width = n;
    }
    int get_width() const {
        return width;
    }
    void set_height(int n) {
        height = n;
    }
    int get_height() const {
        return height;
    }

private:
    int width, height;
};


#endif /* WINDOW_H */
