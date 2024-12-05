
#include "DiagProcess.h"

/*----------------------------------------------------------------------------*/
int CDiagProcess::procEvent(enumEvent eventId)
{
    std::cout << "called " << __PRETTY_FUNCTION__ << " : eventId=" << eventId << std::endl;
    return (int)eventId;
};
/*----------------------------------------------------------------------------*/
bool CDiagProcess::registEvents()
{
    g_EventDistrib.insert( VHAL_EVENT_DIAG_1, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_DIAG_2, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_DIAG_3, callbackFunc );

    return true;
};
/*----------------------------------------------------------------------------*/

