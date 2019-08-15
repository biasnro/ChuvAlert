#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSerialPort serial;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void dadosRecebidos();

    //void on_btn_desligasistema_clicked();

    void on_botao_conectar_clicked();

    void on_botao_desconectar_clicked();

    void on_botao_janela_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
