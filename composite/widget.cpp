#include <vector>
#include <memory>

class Widget
{
public:
    Widget() = default;
    ~Widget() = default;
    //Widget(const Widget&) = delete;
    //Widget& operator=(const Widget&) = delete;
    virtual void add(std::unique_ptr<Widget> w) {
        widget = std::move(w);
    }
protected:
    std::unique_ptr<Widget> widget;
};

int main(int argc, char *argv[])
{
    std::unique_ptr<Widget> w(new Widget()), w1(new Widget());
    w->add(std::move(w1));
    return 0;
}
