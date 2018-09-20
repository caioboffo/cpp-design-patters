#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class base_t
{
public:
    base_t() {
        next = 0;
    }
    void set_next(base_t *n) {
        next = n;
    }
    void add(base_t *n) {
        if (next)
            next->add(n);
        else
            next = n;
    }
    virtual void handle(int i) {
        next->handle(i);
    }
private:
    base_t *next;
};

class handler_one_t : public base_t
{
public:
    virtual void handle(int i) override {
        if (rand() % 3) {
            cout << "H1 passed: " << i << " ";
            base_t::handle(i);
        }
        else
            cout << "H1 handled " << i << " ";
    }
};

class handler_two_t : public base_t
{
public:
    virtual void handle(int i) override {
        if (rand() % 3 )
        {
            cout << "H2 passed " << i << " ";
            base_t::handle(i);
        } else {
            cout << "H2 handled " << i << " ";
        }
    }
};

class handler_three_t : public base_t
{
public:
    virtual void handle(int i ) override {
        if (rand() % 3)
            {
                cout << "H3 passed " << i << " ";
                base_t::handle(i);
            }
        else
            cout << "H3 handled " << i << " ";
    }
};


int main()
{
    srand(time(0));
    handler_one_t root;
    handler_two_t two;
    handler_three_t thr;
    root.add(&two);
    root.add(&thr);
    thr.set_next(&root);

    for(int i = 1; i < 10; i++)
        {
            root.handle(i);
            cout << "\n";
        }
}
