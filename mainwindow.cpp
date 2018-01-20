#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->selectFileButton,SIGNAL(clicked()),this,SLOT(selectFileClicked()));
    connect(ui->filterButton, SIGNAL(clicked()),this,SLOT(filterClicked()));
    connect(this,SIGNAL(tableView()),this, SLOT(tableViewWindow()));
}

void MainWindow::selectFileClicked()
{
    QString fname = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    ui->fNameLable->setText(QFileInfo(fname).fileName());
    model.setFname(fname);
}

void MainWindow::filterClicked()
{
    model.input();
    model.filtration();
    emit tableView();
}

void MainWindow::tableViewWindow()
{
    QList<QStringList> resultTable = model.getRecords();
    for(int i = 0; i < resultTable.size(); i++)
    {
        ui->resultBrowser->append(resultTable[i].join(' '));
    }
    ui->resultBrowser->append(model.reportString);
}

MainWindow::~MainWindow()
{
    delete ui;
}
