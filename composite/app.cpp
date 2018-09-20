#include <iostream>
#include <vector>

using namespace std;

class component_t
{
public:
    virtual void traverse() = 0;
};

class leaf_t : public component_t
{
    int value;

public:
    leaf_t(int val) {
        value = val;
    }
    virtual void traverse() override {
        cout << value << ' ';
    }
};

class composite_t : public component_t
{
    vector<component_t*> children;
public:
    void add(component_t *ele) {
        children.push_back(ele);
    }
    virtual void traverse() override {
        for (int i = 0; i < children.size(); i++)
            children[i]->traverse();
    }
};

int main()
{
    composite_t containers[4];
    for(int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            containers[i].add(new leaf_t(i * 3 + j));

    for(int i = 1; i < 4; i++)
        containers[0].add(&(containers[i]));

    for(int i = 0; i < 4; i++)
    {
        containers[i].traverse();
        cout << endl;
    }
}
