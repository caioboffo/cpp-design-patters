#ifndef PM_WIDGET_FACTORY_H
#define PM_WIDGET_FACTORY_H

#include <memory>

#include "widget_factory.hpp"
#include "pm_scroll_bar.hpp"
#include "pm_window.hpp"

class pm_widget_factory : public widget_factory
{
public:
    pm_widget_factory() = default;
    virtual ~pm_widget_factory() = default;
    std::unique_ptr<scroll_bar> create_scroll_bar() override {
        return std::make_unique<pm_scroll_bar>();
    }
    std::unique_ptr<window> create_window() override {
        return std::make_unique<pm_window>();
    }
};


#endif /* PM_WIDGET_FACTORY_H */
