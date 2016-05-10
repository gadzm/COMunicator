#include "messagesender.h"

MessageSender::MessageSender(Comm_ptr comm)
{
    this->comm = comm;
}

MessageSender::~MessageSender()
{

}

void MessageSender::sendMessage(QString message)
{
    emit commStarted();
    this->comm->writeToCom(message.toStdString());
    emit finished();
}
