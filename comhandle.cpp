#include "comhandle.h"

ComHandle::ComHandle(string name)
{
    this->name = name;
}

ComHandle::~ComHandle()
{

    CloseHandle(this->comHandler);
}

HANDLE ComHandle::getHandle(int baut)
{
    wstring wstr = wstring (this->name.begin(), this->name.end());
    LPCWSTR n = wstr.c_str();
    this->comHandler = CreateFile(n,
                                  GENERIC_READ | GENERIC_WRITE,
                                  0,
                                  0,
                                  OPEN_EXISTING,
                                  FILE_ATTRIBUTE_NORMAL,
                                  0);
    if(comHandler==INVALID_HANDLE_VALUE){
        throw SerialPortHandleException();
        exit(EXIT_FAILURE);

        if(GetLastError()==ERROR_FILE_NOT_FOUND){
            throw SerialPortHandleException();
            exit(EXIT_FAILURE);
        }
    }
    DCB dcbSerialParams = {0};

    if (!GetCommState(this->comHandler, &dcbSerialParams)) {
        throw SerialPortHandleException();
    }
    dcbSerialParams.BaudRate=baut;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    //
    dcbSerialParams.fOutX = FALSE;
    dcbSerialParams.fInX = FALSE;
    dcbSerialParams.fOutxCtsFlow = FALSE;
    dcbSerialParams.fRtsControl = RTS_CONTROL_HANDSHAKE;
    dcbSerialParams.fOutxDsrFlow = FALSE;
    dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;
    dcbSerialParams.fDtrControl = DTR_CONTROL_DISABLE;
    dcbSerialParams.fDtrControl = DTR_CONTROL_HANDSHAKE;
    //
    if(!SetCommState(this->comHandler, &dcbSerialParams)){
        throw SerialPortHandleException();
    }

    COMMTIMEOUTS timeouts={0};
    timeouts.ReadIntervalTimeout=50;
    timeouts.ReadTotalTimeoutConstant=10;
    timeouts.ReadTotalTimeoutMultiplier=3;
    timeouts.WriteTotalTimeoutConstant=50;
    timeouts.WriteTotalTimeoutMultiplier=10;

    if(!SetCommTimeouts(this->comHandler, &timeouts)){
        throw SerialPortHandleException();
    }

    return this->comHandler;
}


