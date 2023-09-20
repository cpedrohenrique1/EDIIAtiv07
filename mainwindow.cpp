#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_gerar_clicked()
{
    try
    {
        bool ok;
        int tamanho_array = ui->lineEdit_qtd_elementos->text().toInt(&ok);
        if (!ok){
            throw QString("Quantidade de elementos inválida");
        }
        Conjunto conj(tamanho_array);
        QString saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetor()[i]) + "| ";
        }
        ui->textEdit_dados_aleatorios->setText(saida_vetor);
        conj.selectionSort();
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorSelectionSort()[i]) + "| ";
        }
        ui->textEdit_selection_sort->setText(saida_vetor);
        ui->textEdit_selection_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
        conj.insertionSort();
        saida_vetor = "";
        for (int i = 0; i < tamanho_array; ++i){
            saida_vetor += "|" + QString::number(conj.getVetorInsertionSort()[i]) + "| ";
        }
        ui->textEdit_insertion_sort->setText(saida_vetor);
        ui->textEdit_insertion_sort_nmr_execucoes->setText(QString::number(conj.getNmrExecucoes()));
    }
    catch(QString& e)
    {
        QMessageBox::critical(this, "ERRO", e);
    }
    
}


void MainWindow::on_lineEdit_qtd_elementos_returnPressed()
{
    on_pushButton_gerar_clicked();
}

