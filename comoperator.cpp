#include "comoperator.h"


void ComOperator::putToSerial()
{
    DWORD dwBytesRead = 0;
    if(!WriteFile(this->comHandle, data, messageLength, &dwBytesRead, NULL)){
    }

	/* dorzuczam znak konca linii  */
    DWORD dwBytesRead1 = 0;
    char a[1] = {0x0D};
        if(!WriteFile(this->comHandle, a,1, &dwBytesRead1, NULL)){
    }
}

void ComOperator::getFromSerial()
{
    DWORD dwBytesRead = 0;
    if(!ReadFile(this->comHandle, data, 1024, &dwBytesRead, NULL)){

    }
    this->messageLength = dwBytesRead;
}

ComOperator::ComOperator()
{
    this->connected = false;
}

ComOperator::~ComOperator()
{
    delete com;
}

bool ComOperator::readFromCom(string& message)
{
    message.clear();
    getFromSerial();
    if (messageLength>0){
        for (int i = 0; i<this->messageLength;i++){
            message.push_back(data[i]);
        }
        return true;
    }
    return false;
}

void ComOperator::setUpSerialPort(string comName, baudRate b)
{
    if (this->connected){
        delete this->com;
        this->connected = false;
    }
    try{
        com = new ComHandle(comName);
        comHandle = com->getHandle(b);
        this->connected = true;
    }
    catch (SerialPortHandleException e){
        this->connected = false;
    }
}

void ComOperator::writeToCom(string message)
{
    if (message.size()>0){
        int i=0;
        for (char ch: message){
            data[i] = ch;
            i++;
        }
//        char end[1] = {0x0D};
//        message.append(end);
        messageLength = i;
     //   data[i+1] = 0x0D;
        putToSerial();
    }
}

bool ComOperator::isConnected()
{
    return this->connected;
}

void ComOperator::closePort()
{
    if (this->connected){
        delete this->com;
    }
    this->connected = false;
}

