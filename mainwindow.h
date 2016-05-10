    #ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <memory>
#include <QMainWindow>
#include <QThread>
#include "comoperator.h"
#include "messagegetter.h"
#include "messagesender.h"
typedef shared_ptr<ComOperator> Comm_ptr;
typedef unique_ptr<MessageGetter> MGet_ptr;
typedef unique_ptr<MessageSender> MSend_ptr;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow( QWidget *parent = 0);
    ~MainWindow();
    void setCom(Comm_ptr comm);
    void setUpComm();
private:
    QThread* getThread;
    QThread* sendThread;
    Comm_ptr comm;
    MGet_ptr getM;
    MSend_ptr sendM;
    void setUpThreads();
    Ui::MainWindow *ui;
    void sendMessage();
    void checkConnection();
    string getComName();
    baudRate getBaudRate();
signals:
    void sendMessaget(QString mess);
public slots:
    void readMessage(QString message);
    void disableSendBtn();
    void enableSendBtn();
private slots:
    void on_btnClearOutput_clicked();
    void on_btnSend_clicked();
    void on_sliderCOM_sliderMoved(int position);
    void on_btnConnect_clicked();
    void on_btnDisconnect_clicked();
    void on_sliderBaud_sliderMoved(int position);
};

#endif // MAINWINDOW_H
