#ifndef WIDGET_FACTORY_H
#define WIDGET_FACTORY_H

#include "scroll_bar.hpp"
#include "window.hpp"

class widget_factory
{
public:
    virtual scroll_bar* create_scroll_bar() = 0;
    virtual window* create_window() = 0;

};


#endif /* WIDGET_FACTORY_H */
