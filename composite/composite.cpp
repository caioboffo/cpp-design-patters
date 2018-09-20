#include <iostream>
#include <vector>
using namespace std;

class composite_t
{
public:
    virtual void print_this_before() = 0;
    virtual void print_this_after() = 0;
    virtual void print() = 0;
};

class letter_composite_t : public composite_t
{
public:
    void add(composite_t *c) {
        children.push_back(c);
    }

    virtual void print_this_before() override {}
    virtual void print_this_after() override {}
    virtual void print() override {
        print_this_before();
        for (composite_t *c : children)
            c->print();
        print_this_after();
    }
private:
    vector<composite_t*> children;
};

class letter_t : public letter_composite_t
{
public:
    letter_t(char c) {
        this->c = c;
    }
    virtual void print_this_before() override {
        cout << c ;
    }

private:
    char c;
};

class word_t : public letter_composite_t
{
public:
    word_t(vector<letter_t*> letters) {
        for (letter_t *l : letters) {
            this->add(l);
        }
    }
    virtual void print_this_before() override {
        cout << " ";
    }
};


class sentence_t : public letter_composite_t
{
public:
    sentence_t(vector<word_t*> words) {
        for (word_t *w : words)
            this->add(w);
    }

    virtual void  print_this_after() override {
        cout << ".\n";
    }
};

int main()
{
    word_t *w = new word_t({new letter_t('C'),
                            new letter_t('a'),
                            new letter_t('i'),
                            new letter_t('o')});

    letter_composite_t *s = new sentence_t(
                {new word_t({new letter_t('I')}),
                 new word_t({new letter_t('a'), new letter_t('m')}),
                 w});
    s->print();
    return 0;
}
