
#include "EventDistrib.h"
#ifdef  WITH_RVM_PROCESS
#include "RvmProcess.h"
#endif
#ifdef  WITH_SVM_PROCESS
#include "SvmProcess.h"
#endif
#ifdef  WITH_DIAG_PROCESS
#include "DiagProcess.h"
#endif

/*----------------------------------------------------------------------------*/
CEventDistrib  g_EventDistrib;

/*----------------------------------------------------------------------------*/
std::map<enumEvent, std::function<int(enumEvent)>> CEventDistrib::getEventList()
{
    return m_mEventList;
};
/*----------------------------------------------------------------------------*/
void CEventDistrib::insert(enumEvent eventId, std::function<int(enumEvent)> callbackProcEvent)
{
    m_mEventList.insert( std::pair<enumEvent,std::function<int(enumEvent)>>(eventId, callbackProcEvent) );
};
/*----------------------------------------------------------------------------*/
int CEventDistrib::distribEvent(enumEvent eventId)
{
    auto item = m_mEventList.find(eventId);
    if (item == m_mEventList.end()) {
        std::cout << "Event '" << eventId << "' is not serviced now." << std::endl;
        return -1;
    }

    item->second(item->first);

    return 0;
};
/*----------------------------------------------------------------------------*/
int main()
{
#ifdef  WITH_RVM_PROCESS
    CRvmProcess rvm;
    rvm.registEvents();
#endif

#ifdef  WITH_SVM_PROCESS
    CSvmProcess svm;
    svm.registEvents();
#endif

#ifdef  WITH_DIAG_PROCESS
    CDiagProcess diag;
    diag.registEvents();
#endif

    // for Verify
    std::map<enumEvent, std::function<int(enumEvent)>> mEventList = g_EventDistrib.getEventList();

    // for Verify
    for (auto it=mEventList.begin(); it!=mEventList.end(); ++it) {
        it->second(it->first);
    }

    // simulate Event-Queue
    for (;;) {
        char inStr[200];
        std::cin >> inStr;

        if (inStr[0] == 'q')    break;

        int inNum = inStr[0] - '0';
        if (inNum > (int)VHAL_EVENT_UNKNOWN && inNum < (int)VHAL_EVENT_ENDOF) {
            g_EventDistrib.distribEvent((enumEvent)inNum);
        }
    }

    return 0;
}
/*----------------------------------------------------------------------------*/

