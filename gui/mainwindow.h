#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <QStringListModel>
#include <QFileDialog>
#include "codeview.h"
#include "../simulateur/utilities.h"
#include "../simulateur/debug.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QStringList _code;
    QListWidget *_list_view;
    CodeView *_code_view;

private slots:
   void open_file();
};

#endif // MAINWINDOW_H
