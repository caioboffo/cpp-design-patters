#ifndef MOTIF_WINDOW_H
#define MOTIF_WINDOW_H

#include <iostream>

#include "window.hpp"

class motif_window : public window
{
public:
    virtual void show() {
        std::cout << "This is a motif window\n";
    }
};


#endif /* MOTIF_WINDOW_H */
