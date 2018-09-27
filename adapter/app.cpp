#include <iostream>
#include <memory>

using namespace std;

class rowing_boat_t
{
public:
    rowing_boat_t() = default;
    virtual ~rowing_boat_t() = default;
    virtual void row() {}
};

class  fishing_boat_t
{
public:
    fishing_boat_t() = default;
    virtual ~fishing_boat_t() = default;
    void sail() {
        cout << "this fishing boat is sailing" << endl;
    }
};

class fishing_boat_adapter_t : public rowing_boat_t
{
public:
    fishing_boat_adapter_t()
    {
        boat = std::make_unique<fishing_boat_t>();
    }
    virtual ~fishing_boat_adapter_t() = default;

    void row() override
    {
        boat->sail();
    }

private:
    std::unique_ptr<fishing_boat_t> boat;
};

class captain_t
{
public:
    captain_t(std::unique_ptr<rowing_boat_t> rowing_boat)
    {
        this->rowing_boat = std::move(rowing_boat);
    }
    virtual ~captain_t() = default;
    void set_rowing_boat(std::unique_ptr<rowing_boat_t> rowing_boat)
    {
        this->rowing_boat = std::move(rowing_boat);
    }
    void row()
    {
        rowing_boat->row();
    }

private:
    std::unique_ptr<rowing_boat_t> rowing_boat;

};

int main()
{
    std::unique_ptr<rowing_boat_t> fishing_boat(new fishing_boat_adapter_t);
    std::unique_ptr<captain_t> captain = std::make_unique<captain_t>(std::move(fishing_boat));
    captain->row();
    return 0;
}
