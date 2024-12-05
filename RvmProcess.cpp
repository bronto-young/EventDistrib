
#include "RvmProcess.h"

/*----------------------------------------------------------------------------*/
int CRvmProcess::procEvent(enumEvent eventId)
{
    std::cout << "called " << __PRETTY_FUNCTION__ << " : eventId=" << eventId << std::endl;
    return (int)eventId;
};
/*----------------------------------------------------------------------------*/
bool CRvmProcess::registEvents()
{
    g_EventDistrib.insert( VHAL_EVENT_RVM_1, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_RVM_2, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_RVM_3, callbackFunc );
    return true;
};
/*----------------------------------------------------------------------------*/

