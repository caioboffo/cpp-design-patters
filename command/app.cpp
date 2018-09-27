#include <iostream>
#include <memory>

class command_t{
public:
    virtual void execute() = 0;
    virtual ~command_t() = default;
};

class light_t
{
public:
    void on() {
        state = true;
        std::cout << "The light is on\n";
    }
    void off() {
        state = false;
        std::cout << "The light is off\n";
    }
    void get_state() {
        std::cout << "The light is ";
        if (state)
            std::cout << "on\n";
        else
            std::cout << "off\n";
    }
private:
    bool state;
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
    void set_command(std::unique_ptr<command_t>& cmd) {
        this->command = std::move(cmd);
    }
    void button_pressed() {
        command->execute();
    }
private:
    std::unique_ptr<command_t> command;
};

int main() {
    light_t light;
    std::unique_ptr<command_t> light_on(new light_on_command_t(light));
    std::unique_ptr<command_t> light_off(new light_off_command_t(light));

    remote_control_t control;
    control.set_command(light_on);
    control.button_pressed();
    light.get_state();
    control.set_command(light_off);
    control.button_pressed();
    light.get_state();
    return 0;
}
