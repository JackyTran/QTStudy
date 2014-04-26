#ifndef MYCLASS_H
#define MYCLASS_H
#include<QString>
#include<QObject>
#include<QDebug>

class MyClass:public QObject
{
    Q_OBJECT
public:

    MyClass(const QString& text, QObject *parent = 0);
    const QString& text() const;
    int getLengthOfText() const;
public slots:
    void setText(const QString& text);
signals:
    void textChanged(const QString&);
private:
    QString m_text;
};

#endif // MYCLASS_H
