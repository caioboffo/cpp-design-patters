#ifndef MOTIF_WIDGET_FACTORY_H
#define MOTIF_WIDGET_FACTORY_H
#include <memory>

#include "widget_factory.hpp"
#include "motif_scroll_bar.hpp"
#include "motif_window.hpp"

class motif_widget_factory : public widget_factory
{
public:
    motif_widget_factory() = default;
    virtual ~motif_widget_factory() = default;
    std::unique_ptr<scroll_bar> create_scroll_bar() override {
        return std::make_unique<motif_scroll_bar>();
    }
    std::unique_ptr<window> create_window() override {
        return std::make_unique<motif_window>();
    }
};


#endif /* MOTIF_WIDGET_FACTORY_H */
