#include "window.hpp"
#include "scroll_bar.hpp"
#include "widget_factory.hpp"
#include "motif_widget_factory.hpp"
#include "pm_widget_factory.hpp"

int main(int argc, char *argv[])
{
    widget_factory *afactory = new pm_widget_factory;
    window *w = afactory->create_window();
    scroll_bar *s = afactory->create_scroll_bar();

    w->show();
    s->show();

    return 0;
}
