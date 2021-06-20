#include "filecreator.h"
#define NL "\n"

FileCreator::FileCreator() {

}

FileCreator::FileCreator(QString startType, QString startEncoding, QString startName, QString startComment, QString startExec, QString startIcon, QString startCategories, bool startTerminal) {
    type = startType;
    encoding = startEncoding;
    name=startName;
    comment=startComment;
    exec = startExec;
    icon = startIcon;
    categories=startCategories;
    isTerminal = startTerminal;
}

void FileCreator::makeOutput() {
    QString data = "[Desktop Entry]\n";
    data += "Type=" + type + NL;
    data += "Encoding=" + encoding + NL;
    data += "Name=" + name + NL;
    data += "Comment=" + comment + NL;
    data += "Exec=" + exec + NL;
    data += "Icon=" + icon + NL;
    data += "Categories=" + categories + NL;
    isTerminal ? data += "Terminal=True" : data += "Terminal=False";
    output = data;
    qDebug().noquote() << data;

}

const QString &FileCreator::getOutput() const {
    return output;
}
