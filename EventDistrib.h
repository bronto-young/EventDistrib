#pragma once

#include <iostream>
#include <functional>
#include <map>

/*----------------------------------------------------------------------------*/
enum enumEvent : uint32_t {
    VHAL_EVENT_UNKNOWN,
    VHAL_EVENT_RVM_1,   // RVM Event
    VHAL_EVENT_RVM_2,
    VHAL_EVENT_RVM_3,
    VHAL_EVENT_SVM_1,   // SVM Event
    VHAL_EVENT_SVM_2,
    VHAL_EVENT_SVM_3,
    VHAL_EVENT_DIAG_1,  // DIAG Event
    VHAL_EVENT_DIAG_2,
    VHAL_EVENT_DIAG_3,
    VHAL_EVENT_ENDOF,
};

typedef struct {
    std::string eventName;
    std::function<int(enumEvent)> eventProc;
} stEventInfo;
/*----------------------------------------------------------------------------*/
class CEventDistrib {
private:
    std::map<enumEvent, std::function<int(enumEvent)>> m_mEventList;

public:
    std::map<enumEvent, std::function<int(enumEvent)>> getEventList();
    void insert(enumEvent eventId, std::function<int(enumEvent)> callbackFunc);
    int distribEvent(enumEvent eventId);
};
/*----------------------------------------------------------------------------*/
extern  CEventDistrib  g_EventDistrib;
/*----------------------------------------------------------------------------*/

