#include "model.h"
#include <QRegExp>
#include <QFile>
#include <QTextStream>

Model::Model()
{

}
void Model::setFname(QString newName)
{
    this->fname = newName;
}

QList<QStringList> Model::getRecords()
{
    return this->records;
}

QStringList parsing(QString str)
{
    QRegExp rx("[,; ]");// Внутри указываем разделители
    QStringList list = str.split(rx, QString::SkipEmptyParts);
    return list;
}

void Model::input(){
    QFile input(fname);
    if (!QFile::exists(fname))
    {
       return;
    }

    if (!input.open(QIODevice::ReadOnly))
    {
        return;
    }

    QTextStream out(&input);

    while(!out.atEnd())
    {
        QString line(out.readLine().simplified());
        QStringList temp = parsing(line);
        records << temp;
    }
}

void Model::filtration(){
    //Что-нибуть. Например, узнаем у скольки городов
    //температура ниже 40
    int count(0);
    for (int i = 0; i < this->records.size(); i++){
        QString temp = records[i][2];
        if(temp.toDouble() < 40)
            count ++;
    }
    this->reportString = QString::fromStdString("Температура ниже 40 градусов наблюдается у %1 городов").arg(count);
}
