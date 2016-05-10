#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H
#include "comoperator.h"
#include <QObject>
#include <QThread>
#include <string>
#include <QString>
#include <memory>
typedef shared_ptr<ComOperator> Comm_ptr;
class MessageSender :public QObject
{
Q_OBJECT
private:
    Comm_ptr comm;
public:
    MessageSender(Comm_ptr comm);
    ~MessageSender();
signals:
    void finished();
    void commStarted();
public slots:
    void sendMessage(QString message);
};
#endif // MESSAGESENDER_H
