
#include "SvmProcess.h"

/*----------------------------------------------------------------------------*/
int CSvmProcess::procEvent(enumEvent eventId)
{
    std::cout << "called " << __PRETTY_FUNCTION__ << " : eventId=" << eventId << std::endl;

    int ret((int)VHAL_EVENT_UNKNOWN);

#if 1
    switch (eventId) {
        case VHAL_EVENT_SVM_1 :
            ret = procEvent1();
            break;
        case VHAL_EVENT_SVM_2 :
            ret = procEvent2();
            break;
        case VHAL_EVENT_SVM_3 :
            ret = procEvent3();
            break;
        default :
            std::cout << "Internal error, " << eventId << " is unknown event ID." << std::endl;
            break;
    }
#endif
    return ret;
};
/*----------------------------------------------------------------------------*/
bool CSvmProcess::registEvents() {
    g_EventDistrib.insert( VHAL_EVENT_SVM_1, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_SVM_2, callbackFunc );
    g_EventDistrib.insert( VHAL_EVENT_SVM_3, callbackFunc );
    return true;
};
/*----------------------------------------------------------------------------*/
int CSvmProcess::procEvent1()
{
    std::cout << "called " << __PRETTY_FUNCTION__ << std::endl;
    return 0;
};
/*----------------------------------------------------------------------------*/
int CSvmProcess::procEvent2()
{
    std::cout << "called " << __PRETTY_FUNCTION__ << std::endl;
    return 0;
};
/*----------------------------------------------------------------------------*/
int CSvmProcess::procEvent3()
{
    std::cout << "called " << __PRETTY_FUNCTION__ << std::endl;
    return 0;
};
/*----------------------------------------------------------------------------*/

