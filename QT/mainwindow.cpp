#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));

    for(auto& item : QSerialPortInfo::availablePorts())
        ui->porta->addItem(item.portName());

    for(auto& item : QSerialPortInfo::standardBaudRates())
        ui->velocidade->addItem(QString::number(item) );
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::dadosRecebidos()
{
    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();
    qDebug()<< dados;

    if(dados.contains("SENSOR")) {
        if(dados["SENSOR"].toInt() >= 590){
            ui->label_sensor->setText(dados["SENSOR"].toString());
            ui->label_tempo->setText("SEM CHUVA!");
        }else{
            ui->label_sensor->setText(dados["SENSOR"].toString());
            ui->label_tempo->setText("COM CHUVA!");
        }
       }


    if(dados.contains("JANELA")){
        if(dados["JANELA"].toInt() == 1){
            ui->label_janela->setText("ABERTA");
        }
        if(dados["JANELA"].toInt() == 0){
            ui->label_janela->setText("FECHADA");
        }
    }

}

//void MainWindow::on_btn_desligasist_clicked()


//}

void MainWindow::on_botao_conectar_clicked()
{

    serial.setPortName(ui->porta->currentText());
    serial.setBaudRate(ui->velocidade->currentText().toInt());

    if(serial.open(QIODevice::ReadWrite)){
        ui->label_status->setText("Status: Conectado");

}
}

void MainWindow::on_botao_desconectar_clicked()
{
    serial.close();
    ui->label_status->setText("Status: Desconectado");
}

void MainWindow::on_botao_janela_clicked()
{
    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

    if(dados.contains("JANELA")){
        if(dados["JANELA"].toInt() == 1){
            serial.write("{\"JANELA\": 0}");
            ui->label_janela->setText("FECHADA");
        }
    }
}
