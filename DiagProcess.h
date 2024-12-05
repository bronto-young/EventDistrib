#pragma once

#include "EventDistrib.h"

/*----------------------------------------------------------------------------*/
class CDiagProcess {
public:
    int procEvent(enumEvent eventId);
    bool registEvents();

    std::function<int(enumEvent eventId)> callbackFunc
        = std::bind(&CDiagProcess::procEvent, this, std::placeholders::_1);
};
/*----------------------------------------------------------------------------*/

