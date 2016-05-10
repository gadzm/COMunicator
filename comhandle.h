#ifndef COMHANDLE_H
#define COMHANDLE_H
#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ComHandle
{
private:
    HANDLE comHandler;
    string name;
public:
    ComHandle(string name);
    ~ComHandle();
    HANDLE getHandle (int baut);

};

class SerialPortHandleException :public exception{

};

#endif // COMHANDLE_H
