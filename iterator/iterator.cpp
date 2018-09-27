#include <iostream>
#include <memory>

using namespace std;
class stack_iter_t;
class stack_t
{
    int items[10];
    int sp;
public:
    friend class stack_iter_t;
    stack_t()
    {
        sp = -1;
    }
    void push(int in) noexcept
    {
        items[++sp] = in;
    }
    int pop() noexcept
    {
        return items[sp--];
    }
    bool is_empty() const noexcept
    {
        return (sp == -1);
    }
    unique_ptr<stack_iter_t> create_iterator() const;
};

class stack_iter_t
{
    const stack_t *stack;
    int index;
public:
    stack_iter_t(const stack_t *s)
    {
        stack = s;
    }
    void first() { index = 0; }
    void next() { index++; }
    bool is_done() { return index == stack->sp + 1; }
    int current_item() { return stack->items[index]; }
};

unique_ptr<stack_iter_t> stack_t::create_iterator() const
{
    unique_ptr<stack_iter_t> ptr(new stack_iter_t(this));
    return ptr;
}

bool operator == (const stack_t &l, const stack_t &r)
{
    auto itl = l.create_iterator();
    auto itr = r.create_iterator();

    for (itl->first(), itr->first();
         !itl->is_done();
         itl->next(), itr->next())
        if (itl->current_item() != itr->current_item())
            break;
    return itl->is_done() && itr->is_done();
}

int main()
{
    stack_t s1;
    for (int i = 1; i < 5; i++)
        s1.push(i);
    stack_t s2(s1), s3(s1), s4(s1), s5(s1);
    s3.pop();
    s5.pop();
    s4.push(2);
    s5.push(9);
    cout << "1 == 2 is " << (s1 == s2) << endl;
    cout << "1 == 3 is " << (s1 == s3) << endl;
    cout << "1 == 4 is " << (s1 == s4) << endl;
    cout << "1 == 5 is " << (s1 == s5) << endl;

    return 0;

}
