/* use the copy constructor to clone objects */
class beast_t
{
public:
    beast_t* clone() const;
};

class warlord_t
{
public:
    warlord_t* clone() const;
};

class mage_t
{
public:
    mage_t* clone() const;
};

class hero_factory_t
{
public:
    virtual mage_t* create_mage() = 0;
    virtual warlord_t* create_warlord() = 0;
    virtual beast_t* create_beast() = 0;
};

class hero_factory_impl_t : public hero_factory_t
{
public:
    hero_factory_impl_t(mage_t* _mage,
                        warlord_t* _warlord,
                        beast_t* _beast) :
        mage(_mage), warlord(_warlord), beast(_beast) {}

    virtual mage_t* create_mage() override
    {
        return mage->clone();
    }

    virtual warlord_t* create_warlord() override
    {
        return warlord->clone();
    }

    virtual beast_t* create_beast() override
    {
        return beast->clone();
    }

private:
    mage_t *mage;
    warlord_t *warlord;
    beast_t *beast;
};

int main(int argc, char *argv[])
{
    hero_factory_t *factory;
    mage_t *mage;
    warlord_t *warlord;
    beast_t *beast;

    factory = new hero_factory_impl_t(new elf_mage_t("cooking"),
                                      new elf_warlord_t("cleaning"),
                                      new elf_beast_t("protecting"));

    mage = factory->create_mage();
    warlord = factory->create_warlord();
    beast = factory->create_beast();

    factory = new hero_factory_impl_t(new orc_mage_t("axe"),
                                      new orc_warlord_t("sword"),
                                      new orc_beast_t("laser"));

    mage = factory->create_mage();
    warlord = factory->create_warlord();
    beast = factory->create_beast();


    return 0;
}
