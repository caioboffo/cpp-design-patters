#include <iostream>
#include <string>

using namespace std;

class thousand_t;
class hundred_t;
class ten_t;
class one_t;

class roman_number_interpreter_t
{
public:
    roman_number_interpreter_t();
    roman_number_interpreter_t(int) {}
    int interpret(string);
    virtual void interpret(string &input, int &total) {
        int index = 0;
        if (input.substr(0,2) == nine())
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (input.substr(0,2) == four())
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
                index = 0;
            for (int end = index + 3; index < end; index++)
                if (input[index] == one())
                    total += 1 * multiplier();
                else
                    break;
        }
        input = input.substr(index);
    }
protected:
    virtual char one() {}
    virtual string four() {}
    virtual char five() {}
    virtual string nine() {}
    virtual int multiplier() {}
private:
    roman_number_interpreter_t *thousands;
    roman_number_interpreter_t *hundreds;
    roman_number_interpreter_t *tens;
    roman_number_interpreter_t *ones;

};

class thousand_t : public roman_number_interpreter_t
{
public:
    thousand_t(int) : roman_number_interpreter_t(1) {}
protected:
    char one()  { return 'M'; }
    string four() { return ""; }
    char five() { return '\0'; }
    string nine() { return ""; }
    int multiplier() { return 1000; }
};


class hundred_t : public roman_number_interpreter_t
{
public:
    hundred_t(int) : roman_number_interpreter_t(1) {}
protected:
    char one()  { return 'C'; }
    string four() { return "CD"; }
    char five() { return 'D'; }
    string nine() { return "CM"; }
    int multiplier() { return 100; }
};

class ten_t : public roman_number_interpreter_t
{
public:
    ten_t(int) : roman_number_interpreter_t(1) {}
protected:
    char one()  { return 'X'; }
    string four() { return "XL"; }
    char five() { return 'L'; }
    string nine() { return "XC"; }
    int multiplier() { return 10; }
};

class one_t : public roman_number_interpreter_t
{
public:
    one_t(int) : roman_number_interpreter_t(1) {}
protected:
    char one()  { return 'I'; }
    string four() { return "IV"; }
    char five() { return 'V'; }
    string nine() { return "IX"; }
    int multiplier() { return 1; }
};

roman_number_interpreter_t::roman_number_interpreter_t()
{
    thousands = new thousand_t(1);
    hundreds = new hundred_t(1);
    tens = new ten_t(1);
    ones = new one_t(1);
}

int roman_number_interpreter_t::interpret(string input)
{
    int total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input,total);
    ones->interpret(input, total);
    if (input.size() > 0) return 0;
    return total;
}

int main()
{
    roman_number_interpreter_t interpreter;
    char input[20];
    cout << "Enter Roman Numeral: ";
    while (cin >> input)
    {
        cout << " interpretation is " << interpreter.interpret(input) << endl;
        cout << "Enter Roman Numeral: ";
    }
}
