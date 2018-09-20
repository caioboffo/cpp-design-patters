#include <iostream>
#include <memory>
using namespace std;


class command_t{
public:
    virtual void execute() = 0;
};

class light_t
{
public:
    void on() {
        cout << "The light is on\n";
    }
    void off() {
        cout << "The light is off\n";
    }
};

class light_on_command_t : public command_t
{
public:
    light_on_command_t(light_t light) : light(light) {}
    virtual void execute() override {
        light.on();
    }
private:
    light_t light;
};

class light_off_command_t : public command_t
{
public:
    light_off_command_t(light_t light) {
        this->light = light;
    }
    virtual void execute() override {
        light.off();
    }
private:
    light_t light;
};

class remote_control_t
{
public:
    void set_command(unique_ptr<command_t> cmd) {
        this->command = move(cmd);
    }
    void button_pressed() {
        command->execute();
    }
private:
    unique_ptr<command_t> command;
};

int main() {
    light_t light;

    unique_ptr<command_t> light_on(new light_on_command_t(light));
    unique_ptr<command_t> light_off(new light_off_command_t(light));

    remote_control_t control;
    control.set_command(move(light_on));
    control.button_pressed();
    control.set_command(move(light_off));
    control.button_pressed();

    return 0;
}
