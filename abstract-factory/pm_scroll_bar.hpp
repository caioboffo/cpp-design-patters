#ifndef PM_SCROLL_BAR_H
#define PM_SCROLL_BAR_H

#include <iostream>
#include "scroll_bar.hpp"

class pm_scroll_bar : public scroll_bar
{
public:
    virtual ~pm_scroll_bar() = default;
    virtual void show() {
        std::cout << "this is a pm_scroll_bar\n";
    }
};


#endif /* PM_SCROLL_BAR_H */
