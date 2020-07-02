#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QObject>
#include <QMessageBox>
#include <QCloseEvent>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void OnPushButton();
    void currentIndexChanged(const QString &arg1);
    void onActivatedComboBox();

private:
    Ui::MainWindow *ui;
    QLabel *lbl1, *lbl2, *lbl3;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QComboBox *combo;
    QGridLayout *grid;
    QWidget *widget;
};
#endif // MAINWINDOW_H


