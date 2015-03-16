#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	audio = new AudioStream();
	audio->getFrequency ();
}

MainWindow::~MainWindow()
{
	delete ui;
}
