#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
    this->getThread->quit();
    this->sendThread->quit();
    delete getThread;
    delete sendThread;
}

void MainWindow::setCom(Comm_ptr comm)
{
    ui->labelCOM1->setFont(QFont( "Arial", 9, QFont::Bold));
    ui->labelBaud4->setFont(QFont( "Arial", 9, QFont::Bold));
    this->comm = comm;
    checkConnection();
}

void MainWindow::setUpComm()
{
    setUpThreads();
}

void MainWindow::setUpThreads()
{
    this->getM.reset(new MessageGetter(this->comm));
    this->getThread = new QThread;
    this->getM->moveToThread(getThread);
    connect(getThread,SIGNAL(started()),getM.get(),SLOT(getMessage()));
    connect(getM.get(),SIGNAL(setText(QString)),this,SLOT(readMessage(QString)));
    connect(getThread,SIGNAL(finished()),getM.get(),SLOT(deleteLater()));
    getThread->start();


    this->sendM.reset(new MessageSender(this->comm));
    connect(this,SIGNAL(sendMessaget(QString)),sendM.get(),SLOT(sendMessage(QString)));


    connect(sendM.get(),SIGNAL(commStarted()),this,SLOT(disableSendBtn()));
    connect(sendM.get(),SIGNAL(finished()),this,SLOT(enableSendBtn()));
    this->sendThread = new QThread;
    this->sendM->moveToThread(sendThread);
    this->sendThread->start();
}

void MainWindow::sendMessage()
{
    emit sendMessaget(ui->textInput->toPlainText());
    ui->textInput->clear();
}

void MainWindow::checkConnection()
{
    if (this->comm.get()->isConnected()){
        ui->labelCon->setText("Connected");
        ui->btnSend->setEnabled(true);
    }
    else {
        ui->labelCon->setText("Not connected");
        ui->btnSend->setEnabled(false);
    }
}

string MainWindow::getComName()
{
    switch (ui->sliderCOM->value()) {
    case 0: return "COM1";
    case 1: return "COM2";
    case 2: return "COM3";
    case 3: return "COM4";
    default:     break;
    }
}

baudRate MainWindow::getBaudRate()
{
    switch (ui->sliderBaud->value()) {
    case 0: return Baud1200;
    case 1: return Baud2400;
    case 2: return Baud4800;
    case 3: return Baud9600;
    case 4: return Baud19200;
    case 6: return Baud38400;
    default:     break;
    }
}

void MainWindow::readMessage(QString message)
{
    if (message.size()>0){

        ui->textOutput->append(message);
    }
}

void MainWindow::disableSendBtn()
{
    ui->btnSend->setEnabled(false);
}

void MainWindow::enableSendBtn()
{
    ui->btnSend->setEnabled(true);
}

void MainWindow::on_btnClearOutput_clicked()
{
    ui->textOutput->clear();
}

void MainWindow::on_btnSend_clicked()
{
    sendMessage();
}

void MainWindow::on_sliderCOM_sliderMoved(int position)
{
    QFont f1( "Arial", 9, QFont::Bold);
    QFont f2( "Arial", 9);
    switch (position) {
    case 0: ui->labelCOM1->setFont(f1);
        ui->labelCOM2->setFont(f2);
        ui->labelCOM3->setFont(f2);
        ui->labelCOM4->setFont(f2);
        break;
    case 1: ui->labelCOM2->setFont(f1);
        ui->labelCOM1->setFont(f2);
        ui->labelCOM3->setFont(f2);
        ui->labelCOM4->setFont(f2);
        break;
    case 2: ui->labelCOM3->setFont(f1);
        ui->labelCOM1->setFont(f2);
        ui->labelCOM2->setFont(f2);
        ui->labelCOM4->setFont(f2);
        break;
    case 3: ui->labelCOM4->setFont(f1);
        ui->labelCOM1->setFont(f2);
        ui->labelCOM2->setFont(f2);
        ui->labelCOM3->setFont(f2);
        break;
    default:
        break;
    }
}

void MainWindow::on_btnConnect_clicked()
{

    this->comm.get()->setUpSerialPort(getComName(),getBaudRate());
    ui->sliderCOM->setEnabled(false);
    ui->sliderBaud->setEnabled(false);
    checkConnection();
}

void MainWindow::on_btnDisconnect_clicked()
{
    this->comm->closePort();
    ui->sliderCOM->setEnabled(true);
    ui->sliderBaud->setEnabled(true);
    checkConnection();
}

void MainWindow::on_sliderBaud_sliderMoved(int position)
{
    QFont f1( "Arial", 9, QFont::Bold);
    QFont f2( "Arial", 9);
    switch (position) {
    case 0: ui->labelBaud1->setFont(f1);
        ui->labelBaud2->setFont(f2);
        ui->labelBaud3->setFont(f2);
        ui->labelBaud4->setFont(f2);
        ui->labelBaud5->setFont(f2);
        ui->labelBaud6->setFont(f2);
        break;
    case 1: ui->labelBaud2->setFont(f1);
        ui->labelBaud1->setFont(f2);
        ui->labelBaud3->setFont(f2);
        ui->labelBaud4->setFont(f2);
        ui->labelBaud5->setFont(f2);
        ui->labelBaud6->setFont(f2);
        break;
    case 2: ui->labelBaud3->setFont(f1);
        ui->labelBaud2->setFont(f2);
        ui->labelBaud1->setFont(f2);
        ui->labelBaud4->setFont(f2);
        ui->labelBaud5->setFont(f2);
        ui->labelBaud6->setFont(f2);
        break;
    case 3: ui->labelBaud4->setFont(f1);
        ui->labelBaud2->setFont(f2);
        ui->labelBaud3->setFont(f2);
        ui->labelBaud1->setFont(f2);
        ui->labelBaud5->setFont(f2);
        ui->labelBaud6->setFont(f2);
        break;
    case 4: ui->labelBaud5->setFont(f1);
        ui->labelBaud2->setFont(f2);
        ui->labelBaud3->setFont(f2);
        ui->labelBaud4->setFont(f2);
        ui->labelBaud1->setFont(f2);
        ui->labelBaud6->setFont(f2);
        break;
    case 5: ui->labelBaud6->setFont(f1);
        ui->labelBaud2->setFont(f2);
        ui->labelBaud3->setFont(f2);
        ui->labelBaud4->setFont(f2);
        ui->labelBaud5->setFont(f2);
        ui->labelBaud1->setFont(f2);
        break;
    default:
        break;
    }
}
