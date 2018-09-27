#include <memory>

#include "window.hpp"
#include "scroll_bar.hpp"
#include "widget_factory.hpp"
#include "motif_widget_factory.hpp"
#include "pm_widget_factory.hpp"

int main()
{
    std::unique_ptr<widget_factory> afactory(new pm_widget_factory);
    std::unique_ptr<window> w(afactory->create_window());
    std::unique_ptr<scroll_bar> s(afactory->create_scroll_bar());

    w->show();
    s->show();

    return 0;
}
