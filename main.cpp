#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include "myclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    QWidget widget;
    QLineEdit * lineEdit = new QLineEdit;
    QLabel* label = new QLabel;
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(lineEdit);
    layout->addWidget(label);

    widget.setLayout(layout);

    MyClass *bridge = new MyClass("",&a);

    // get connection
    // line Edit --> bridge --> label

    QObject::connect(lineEdit,SIGNAL(textChanged(QString)),bridge,SLOT(setText(QString)));
    QObject::connect(bridge,SIGNAL(textChanged(QString)),label,SLOT(setText(QString)));

    widget.show();

    return a.exec();
}
