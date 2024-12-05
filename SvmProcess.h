#pragma once

#include "EventDistrib.h"

/*----------------------------------------------------------------------------*/
class CSvmProcess {
public:
    int procEvent(enumEvent eventId);
    bool registEvents();

    std::function<int(enumEvent eventId)> callbackFunc
        = std::bind(&CSvmProcess::procEvent, this, std::placeholders::_1);
    
private:
    int procEvent1();
    int procEvent2();
    int procEvent3();
};
/*----------------------------------------------------------------------------*/

