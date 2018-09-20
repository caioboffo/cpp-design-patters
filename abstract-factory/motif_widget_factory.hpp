#ifndef MOTIF_WIDGET_FACTORY_H
#define MOTIF_WIDGET_FACTORY_H

#include "widget_factory.hpp"
#include "motif_scroll_bar.hpp"
#include "motif_window.hpp"

class motif_widget_factory : public widget_factory
{
public:

    virtual scroll_bar* create_scroll_bar() {
        return new motif_scroll_bar();
    }
    virtual window* create_window() {
        return new motif_window;
    }
};


#endif /* MOTIF_WIDGET_FACTORY_H */
