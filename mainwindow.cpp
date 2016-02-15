#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cipherButton, &QPushButton::clicked,this, &MainWindow::on_cipherButton_clicked );
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::cipherString(QString inputString)
{
    for(int index = 0; index < inputString.size(); index++)
    {
        QChar charAtIndex = inputString.at(index);
        if( (charAtIndex > 64 && charAtIndex < 91))
        {
            charAtIndex = 154 - charAtIndex.toLatin1();
        }else if( (charAtIndex > 96 && charAtIndex < 123 ) )
        {
            charAtIndex = 218 - charAtIndex.toLatin1();
        }
        inputString[index] = charAtIndex;
    }

    return inputString;
}

void MainWindow::on_cipherButton_clicked()
{
    QString cipheredText = cipherString(ui->inputTextBox->toPlainText());

    ui->cipheredTextBox->setPlainText(cipheredText);
}
