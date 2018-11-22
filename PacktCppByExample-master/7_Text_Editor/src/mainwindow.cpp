#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionSave, SIGNAL(triggered()),
        this, SLOT(onSaveActionTriggered()));

    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
        this, SLOT(onOpenActionTriggered()));
}

void MainWindow::onSaveActionTriggered()
{
    const auto file_path = QFileDialog::getSaveFileName(this,
        tr("Save Text File"),
        QApplication::applicationDirPath(),
        "Text files (*.txt)");
    QFile file(file_path);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream text_stream(&file);
        const auto current_text = ui->plainTextEdit->toPlainText();
        text_stream << current_text;
    }
}

void MainWindow::onOpenActionTriggered()
{
    const auto file_path = QFileDialog::getOpenFileName(this,
        tr("Open Text File"),
        QApplication::applicationDirPath(),
        "Text files (*.txt)");
    QFile file(file_path);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream text_stream(&file);
        const auto text = text_stream.readAll();
        ui->plainTextEdit->setPlainText(text);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
