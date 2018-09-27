#ifndef WIDGET_FACTORY_H
#define WIDGET_FACTORY_H

#include <memory>
#include "scroll_bar.hpp"
#include "window.hpp"

class widget_factory
{
public:
    virtual ~widget_factory() = default;
    virtual std::unique_ptr<scroll_bar> create_scroll_bar() = 0;
    virtual std::unique_ptr<window> create_window() = 0;

};


#endif /* WIDGET_FACTORY_H */
