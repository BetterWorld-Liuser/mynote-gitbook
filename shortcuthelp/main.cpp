#include "shortcuthelper.h"
#include <QApplication>
#include <QListWidget>
#include <QSettings>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    ShortcutHelper w;
    w.putfile();
    w.updatefile();
    w.someSet();
    w.setAttribute(Qt::WA_TransparentForMouseEvents,true);

    QString appName = QApplication::applicationName();//程序名称

     QString appPath = QApplication::applicationFilePath();// 程序路径

     appPath = appPath.replace("/","\\");

     QSettings *reg=new QSettings(
                    "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                    QSettings::NativeFormat);

        QString val = reg->value(appName).toString();// 如果此键不存在，则返回的是空字符串
        if(val != appPath)
            reg->setValue(appName,appPath);// 如果移除的话，reg->remove(applicationName);
    //reg->deleteLater();
    //w.show();

    return a.exec();
}
