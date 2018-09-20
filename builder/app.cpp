#include <iostream>
#include <string>

using namespace std;

enum class hair_color_t { black, white, blond, red, none };
enum class profession_t { thief, warrior, mage, none };
enum class hair_type_t { long_curly, bald, none };
enum class weapon_t { bow, dagger, sword, none };
enum class armor_t { chain_mail, none };

class hero_t
{
public:
    profession_t profession;
    string name;
    hair_color_t hair_color;
    hair_type_t hair_type;
    weapon_t weapon;
    armor_t armor;
};

class builder_t
{
public:
    virtual string set_name() { return ""; }
    virtual profession_t set_profession()
    {
        return profession_t::none;
    }
    virtual hair_color_t set_hair_color()
    {
        return hair_color_t::none;
    }
    virtual hair_type_t set_hair_type() { return hair_type_t::none; }
    virtual weapon_t set_weapon() { return weapon_t::none; }
    virtual armor_t set_armor() { return armor_t::none; }
};

class hero_director_t
{
public:
    void set_builder(builder_t *_builder)
    {
        builder = _builder;
    }

    hero_t* get_hero()
    {
        hero_t* hero     = new hero_t;
        hero->name       = builder->set_name();
        hero->profession = builder->set_profession();
        hero->hair_type  = builder->set_hair_type();
        hero->hair_color = builder->set_hair_color();
        hero->weapon     = builder->set_weapon();
        hero->armor      = builder->set_armor();

        return hero;
    }

private:
    builder_t *builder;
};

class mage_builder_t : public builder_t
{
public:
    virtual string set_name() override
    {
        return "Riobard";
    }
    virtual profession_t set_profession() override
    {
        return profession_t::mage;
    }
    virtual hair_color_t set_hair_color() override
    {
        return hair_color_t::black;
    }
    virtual weapon_t set_weapon() override
    {
        return weapon_t::dagger;
    }
};

class warrior_builder_t : public builder_t
{
public:
    virtual string set_name() override
    {
        return "Amberjil";
    }
    virtual profession_t set_profession() override
    {
        return profession_t::warrior;
    }
    virtual hair_color_t set_hair_color() override
    {
        return hair_color_t::blond;
    }
    virtual hair_type_t set_hair_type() override
    {
        return hair_type_t::long_curly;
    }
    virtual weapon_t set_weapon() override
    {
        return weapon_t::sword;
    }
};

class thief_builder_t : public builder_t
{
public:
    virtual string set_name() override
    {
        return "Desmond";
    }
    virtual profession_t set_profession() override
    {
        return profession_t::thief;
    }
    virtual hair_type_t set_hair_type() override
    {
        return hair_type_t::bald;
    }
    virtual weapon_t set_weapon() override
    {
        return weapon_t::bow;
    }
};


int main()
{
    hero_t* hero;
    hero_director_t hero_director;

    mage_builder_t    mage;
    warrior_builder_t warrior;
    thief_builder_t   thief;

    hero_director.set_builder(&mage);
    hero = hero_director.get_hero();
    cout << hero->name << endl;

    hero_director.set_builder(&warrior);
    hero = hero_director.get_hero();
    cout << hero->name << endl;

    hero_director.set_builder(&thief);
    hero = hero_director.get_hero();
    cout << hero->name << endl;



    return 0;
}
