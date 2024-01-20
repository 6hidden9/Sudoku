#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shared.h"
#include <iostream>
#include <string>
#include <QRandomGenerator>
using namespace Qt;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTableWidgetItem *item;

    //sefr kardan mmaghadir avaliye jadval
   for (int i =0;i<9;i++)
   {for (int j =0 ; j<9;j++)
       {
           item = new QTableWidgetItem("0");
           item->setData(Qt::DisplayRole,QVariant(0));
           ui->Table->setItem(i,j,item);
            // ui->Table->item(i,j)->setData();
       }
   }


}

MainWindow::~MainWindow()
{
    delete ui;
}
//

void MainWindow::on_pushButton_clicked()
{
    //khandan jadval eraee shode
    for (int i=0;i<9;i++)
    {for (int j =0 ; j<9;j++)
        {
            table[i][j]=ui->Table->item(i,j)->text().toInt();
            std::cout << ui->Table->item(0,0)->text().toInt();
        }
    }
    start();
    ui->count_label->setText(QString::number(count));
    ui->o5->setText("o(n^5)");
    QTableWidgetItem *item;


    //por kardan jdavvale tshkil shode

    for (int i =0;i<9;i++)
    {for (int j =0 ; j<9;j++)
        {
               // ui->Table->item(i,j)->setData(Qt::DisplayRole,QVariant(table[i][j]));
            item = new QTableWidgetItem(QString::number(table[i][j]));
            item->setData(Qt::DisplayRole,QVariant(table[i][j]));
            ui->Table->setItem(i,j,item);
        }
    }
}

