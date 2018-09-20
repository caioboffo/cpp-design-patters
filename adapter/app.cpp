#include <iostream>
#include <memory>

using namespace std;

class rowing_boat_t
{
public:
    virtual void row() {}
};

class  fishing_boat_t
{
public:
    void sail() {
        cout << "this fishing voat is sailing" << endl;
    }
};

class fishing_boat_adapter_t : public rowing_boat_t
{
public:
    fishing_boat_adapter_t()
    {
        boat = new fishing_boat_t;
    }

    virtual void row() override
    {
        boat->sail();
    }

private:
    fishing_boat_t *boat;
};

class captain_t
{
public:
    captain_t(rowing_boat_t* rowing_boat)
    {
        this->rowing_boat = rowing_boat;
    }
    void set_rowing_boat(rowing_boat_t* rowing_boat)
    {
        this->rowing_boat = rowing_boat;
    }
    void row()
    {
        rowing_boat->row();
    }

private:
    rowing_boat_t *rowing_boat;

};
class fishing_boat_adapter_t;


int main()
{
    captain_t *captain = new captain_t(new fishing_boat_adapter_t);
    captain->row();
    return 0;
}
