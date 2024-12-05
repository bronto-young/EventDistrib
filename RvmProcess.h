#pragma once

#include "EventDistrib.h"

/*----------------------------------------------------------------------------*/
class CRvmProcess {
public:
    int procEvent(enumEvent eventId);
    bool registEvents();

    std::function<int(enumEvent eventId)> callbackFunc
        = std::bind(&CRvmProcess::procEvent, this, std::placeholders::_1);
};
/*----------------------------------------------------------------------------*/

