//---------------------------------------------------------------------------

#ifndef PROTOCOLH
#define PROTOCOLH

#include "var.h"
#include "PTRAFFIC.h"
#include "PDEVICE.h"
//---------------------------------------------------------------------------
class PROTOCOL
{
    public:

        PROTOCOL(void);
        ~PROTOCOL(void);
        bool DoWork(MESSAGEOK);                                                 //�ھ�readJob��writeJob�ǨӪ�Structure�@�Ʊ�

    private:

        PTRAFFIC pTraffic;
        PDEVICE pDevice;

};
//---------------------------------------------------------------------------
extern PROTOCOL protocol;
#endif