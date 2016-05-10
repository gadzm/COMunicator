#ifndef COMOPERATOR_H
#define COMOPERATOR_H
#include <string>
#include <windows.h>
#include "comhandle.h"
#include <stddef.h>

enum baudRate{
    Baud1200 = 1200,
    Baud2400 = 2400,
    Baud4800 = 4800,
    Baud9600 = 9600,
    Baud19200 = 19200,
    Baud38400 = 38400
};

using namespace std;

class ComOperator
{
private:
    HANDLE comHandle;
    ComHandle* com;
    char data[1024];
    int messageLength;
    void putToSerial();
    void getFromSerial();
    bool connected;
public:
    ComOperator();
    ~ComOperator();
    bool readFromCom(string &message);
    void setUpSerialPort(string comName, baudRate b);
    void writeToCom(string message);
    bool isConnected();
    void closePort();
};

#endif // COMOPERATOR_H
