#include "messagegetter.h"

MessageGetter::MessageGetter(Comm_ptr comm)
{
    this->comm = comm;
}

MessageGetter::~MessageGetter()
{

}

void MessageGetter::getMessage()
{
    while (1){
        if (this->comm->readFromCom(this->message)){
            emit setText(QString::fromStdString(message));
        }
        Sleep(50);
    }
}



