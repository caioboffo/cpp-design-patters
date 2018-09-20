#include <iostream>
#include <vector>

using namespace std;

class stooge_t
{
public:
     static stooge_t *make_stooge(int choice);
     virtual void slap_stick() = 0;
};


int main()
{
     vector<stooge_t*> roles;
     int choice;
     while (true)
     {
          cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
          cin >> choice;
          if (choice  == 0)
               break;
          roles.push_back(
               stooge_t::make_stooge(choice)
               );
     }
     for (int i = 0; i < roles.size(); i++)
          roles[i]->slap_stick();
     for (int i = 0; i < roles.size(); i++)
          delete roles[i];
}

class larry_t : public stooge_t
{
public:
     void slap_stick() override
          {
               cout << "Larry: poke eyes\n";
          }
};

class moe_t : public stooge_t
{
public:
     void slap_stick() override
          {
               cout << "Moe: slap head\n";
          }
};

class curly_t : public stooge_t
{
public:
     void slap_stick() override
     {
          cout << "Curly: suffer abuse\n";
     }
};

stooge_t *stooge_t::make_stooge(int choice)
{
     if (choice == 1)
          return new larry_t;
     if (choice == 2)
          return new moe_t;
     else
          return new curly_t;
}
