#include "mainwindowschoolradio.h"

#include <QApplication>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QLockFile lockFile(QDir::temp().absoluteFilePath("SchRadio.lock"));

    if (!lockFile.tryLock(100))
    {
        return 1;
    }

    QApplication a(argc, argv);

    MainWindowSchoolRadio w;
    w.show();

    return a.exec();
}
