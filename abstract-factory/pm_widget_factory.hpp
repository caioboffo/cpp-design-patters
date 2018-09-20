#ifndef PM_WIDGET_FACTORY_H
#define PM_WIDGET_FACTORY_H

#include "widget_factory.hpp"
#include "pm_scroll_bar.hpp"
#include "pm_window.hpp"

class pm_widget_factory : public widget_factory
{
public:
    virtual scroll_bar* create_scroll_bar() {
        return new pm_scroll_bar;
    }
    virtual window* create_window() {
        return new pm_window;
    }
};


#endif /* PM_WIDGET_FACTORY_H */
