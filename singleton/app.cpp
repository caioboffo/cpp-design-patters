#include <iostream>
#include <string>

using namespace std;

class singleton_t
{
public:
    string name;
    static singleton_t* instance();
protected:
    singleton_t() = default;
private:
    static singleton_t* _singleton;
};

singleton_t* singleton_t::_singleton = nullptr;

singleton_t* singleton_t::instance()
{
    if (_singleton == nullptr)
    {
        _singleton = new singleton_t;
    }
    return _singleton;
}

int main(int argc, char *argv[])
{
    singleton_t* s = singleton_t::instance();
    s->name = "Caio";

    singleton_t* t = singleton_t::instance();

    cout << t->name << endl;
    return 0;
}
