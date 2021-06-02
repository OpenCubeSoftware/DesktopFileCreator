#include "filecreator.h"
#define NL "\n"

FileCreator::FileCreator() {

}

FileCreator::FileCreator(QString startType, QString startEncoding, QString startName, QString startComment, QString startExec, QString startIcon, QString startCategories) {
    type = startType;
    encoding = startEncoding;
    name=startName;
    comment=startComment;
    exec = startExec;
    icon = startIcon;
    categories=startCategories;
}

void FileCreator::makeOutput() {
    QString data = "[Desktop Entry]\n";
    data += "Type=" + type + NL;
    data += "Encoding=" + encoding + NL;
    data += "Name=" + name + NL;
    data += "Comment=" + comment + NL;
    data += "Exec=" + exec + NL;
    data += "Icon=" + icon + NL;

}
