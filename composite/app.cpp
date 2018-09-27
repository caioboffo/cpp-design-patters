#include <array>
#include <iostream>
#include <memory>
#include <vector>

class component_t
{
public:
    virtual void traverse() = 0;
};

class leaf_t : public component_t
{
    int value;

public:
    explicit leaf_t(int val) {
        value = val;
    }
    void traverse() override {
        std::cout << value << ' ';
    }
};

class composite_t : public component_t
{
    std::vector<component_t*> children;
public:
    void add(component_t *ele) {
        children.push_back(ele);
    }
    void traverse() override {
        for (auto &c : children)
        {
            c->traverse();
        }
    }
};

int main()
{
    std::array<composite_t, 4> containers;
    for(auto container : containers)
    {
        for (int j = 0; j < 3; j++)
        {
            container.add(new leaf_t(i * 3 + j));
        }
    }

    for(auto& container : containers)
    {
        container.add(container;
    }

    for(auto container : containers)
    {
        container.traverse();
        std::cout << std::endl;
    }
}
