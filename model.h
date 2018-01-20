#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QList>
#include <QStringList>

class Model
{
public:
    Model();
    void input();
    void filtration();
    void setFname(QString newName);
    QList<QStringList> getRecords();
    QString reportString;
private:
    QString fname;
    QList<QStringList> records;
};

#endif // MODEL_H
