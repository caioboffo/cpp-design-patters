#include <iostream>
#include <memory>
#include <string>
#include <utility>

class file_selection_dialog_t;

class widget_t
{
public:
    virtual ~widget_t() = default;
    widget_t(file_selection_dialog_t *mediator,
             std::string name) {
        this->mediator = mediator;
        this->name = std::move(name);
    }
    virtual void changed();
    virtual void update_widget() = 0;
    virtual void query_widget() = 0;
protected:
    std::string name;
private:
    file_selection_dialog_t *mediator;
};

class list_t : public widget_t
{
public:
    list_t(file_selection_dialog_t *dir, std::string name)
        : widget_t(dir, std::move(name)) {}
    void query_widget() override {
        std::cout << "  " << name << " list queried" << std::endl;
    }
    void update_widget() override {
        std::cout << "  " << name << " list updated" << std::endl;
    }
};

class edit_t : public widget_t
{
public:
    edit_t(file_selection_dialog_t *dir, std::string name)
        : widget_t(dir, std::move(name)) {}
    void query_widget() override {
        std::cout << "  " << name << " edit queried" << std::endl;
    }
    void update_widget() override {
        std::cout << "  " << name << " edit updated" << std::endl;
    }
};

class file_selection_dialog_t
{
public:
    virtual ~file_selection_dialog_t();
    enum widgets { filter_edit, dir_list, file_list, selection_edit };
    file_selection_dialog_t()
    {
        components[filter_edit] = new edit_t(this, "filter");
        components[dir_list]  = new list_t(this, "dir");
        components[file_list] = new list_t(this, "file");
        components[selection_edit] = new edit_t(this, "selection");

    }
    void handle_event(int which)
    {
        components[which]->changed();
    }
    virtual void widget_changed(widget_t *the_changed_widget)
    {
        if (the_changed_widget == components[filter_edit])
        {
            components[filter_edit]->query_widget();
            components[dir_list]->update_widget();
            components[file_list]->update_widget();
            components[selection_edit]->update_widget();
        }
        else if (the_changed_widget == components[dir_list])
        {
            components[dir_list]->query_widget();
            components[file_list]->update_widget();
            components[filter_edit]->update_widget();
            components[selection_edit]->update_widget();
        }
        else if (the_changed_widget == components[file_list])
        {
            components[file_list]->query_widget();
            components[selection_edit]->update_widget();
        }
        else if (the_changed_widget == components[selection_edit])
        {
            components[selection_edit]->query_widget();
            std::cout << "  file opened" << std::endl;
        }
    }
    private:
        widget_t *components[4]{};

};

file_selection_dialog_t::~file_selection_dialog_t()
{
    for (auto & component : components) {
        delete component;
}
}



void widget_t::changed()
{
    mediator->widget_changed(this);
}

int main(int  /*argc*/, char * /*argv*/[])
{
    file_selection_dialog_t file_dialog;
    int i;
    std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]";
    std::cin >> i;

    while(i != 0)
    {
        file_dialog.handle_event(i - 1);
        std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]";
        std::cin >> i;
    }
    return 0;
}
