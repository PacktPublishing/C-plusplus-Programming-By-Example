#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()),
        this, SLOT(showText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
    ui->label->setText(tr("HELLO"));
}
