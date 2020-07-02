#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    grid = new QGridLayout();
    lbl1 = new QLabel(tr("Text to add : "));
    lbl2 = new QLabel(tr("Push button : "));
    lbl3 = new QLabel(tr("ComboBox : "));
    textEdit = new QTextEdit();
    pushButton = new QPushButton("Add");
    combo = new QComboBox();

    grid->addWidget(lbl1, 0, 0, 1, 1);
    grid->addWidget(lbl2, 1, 0);
    grid->addWidget(lbl3, 2, 0);
    grid->addWidget(textEdit, 0, 1);
    grid->addWidget(pushButton, 1, 1);
    grid->addWidget(combo, 2, 1);

    grid->setSpacing(30);
    grid->setMargin(40);

    widget = new QWidget();
    widget->setMaximumSize(550, 300);
    widget->setLayout(grid);
    setCentralWidget(widget);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(OnPushButton()));
    connect(combo, SIGNAL(activated(const QString &)),
            SLOT(onActivatedComboBox()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnPushButton()
{
    QString str = textEdit->toPlainText();
    combo->insertItem(1, str);
    textEdit->clear();
}

void MainWindow::currentIndexChanged(const QString &arg1)
{
    ui->statusbar->showMessage(arg1);
}

void MainWindow::onActivatedComboBox() {
    QString str = combo->currentText();
    ui->statusbar->showMessage(str);
}

void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox msgBox;
    msgBox.setText("You try to close the application.");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Warning");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);

    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Cancel:
        event->ignore();
        break;
      case QMessageBox::Ok:
        event->accept();
        break;
      default:
        event->ignore();
        break;
    }
}

