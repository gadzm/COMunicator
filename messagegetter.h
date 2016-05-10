#ifndef MESSAGEGETTER_H
#define MESSAGEGETTER_H
#include "comoperator.h"
#include <QObject>
#include <QThread>
#include <string>
#include <memory>

typedef shared_ptr<ComOperator> Comm_ptr;
class MessageGetter :public QObject
{
Q_OBJECT
private:
    Comm_ptr comm;
    string message;
public:
    MessageGetter(Comm_ptr comm);
    ~MessageGetter();
signals:
    void setText(QString message);
public slots:
    void getMessage();
};

#endif // MESSAGEGETTER_H
