#ifndef PM_WINDOW_H
#define PM_WINDOW_H

#include <iostream>

#include "window.hpp"

class pm_window : public window
{
public:
    virtual ~pm_window() = default;
    virtual void show() {
        std::cout << "this is a pm_windown\n";
    }
};


#endif /* PM_WINDOW_H */
