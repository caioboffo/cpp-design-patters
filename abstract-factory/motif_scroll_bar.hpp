#ifndef MOTIF_SCROLL_BAR_H
#define MOTIF_SCROLL_BAR_H

#include <iostream>
#include "scroll_bar.hpp"

class motif_scroll_bar : public scroll_bar
{
public:
    virtual void show() {
        std::cout << "this is a motif_scroll_bar\n";
    }
};


#endif /* MOTIF_SCROLL_BAR_H */
