#ifndef FILECREATOR_H
#define FILECREATOR_H

#include <QString>
#include <QDebug>

class FileCreator {
public:
    FileCreator();
    FileCreator(QString startType, QString startEncoding, QString startName, QString startComment, QString startExec, QString startIcon, QString startCategories, bool startTerminal);
    void makeOutput();
    void createFile();
    const QString &getOutput() const;

private:
    QString type;
    QString encoding;
    QString name;
    QString comment;
    QString exec;
    QString icon;
    QString categories;
    bool isTerminal;
    QString output;
};

#endif // FILECREATOR_H
