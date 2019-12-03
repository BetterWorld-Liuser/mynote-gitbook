#ifndef SHORTCUTHELPER_H
#define SHORTCUTHELPER_H

#include <QWidget>
#include <QString>
#include <QJsonObject>
#include  <QtNetwork/QNetworkAccessManager>
#include  <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QFile>

namespace Ui {
class ShortcutHelper;
}

class ShortcutHelper : public QWidget
{
    Q_OBJECT
    QNetworkAccessManager manager;
    QVector<QNetworkReply *> currentDownloads;
public:
    explicit ShortcutHelper(QWidget *parent = nullptr);
    ~ShortcutHelper();
        void someSet();
        void paintEvent(QPaintEvent *event);
        void ifShow(bool ifshow);
        //void keyPressEvent(QKeyEvent  *event);
        QString GetActiveWindowTitle();
        void DownloadManager();
        void doDownload(const QUrl url);
        QStringList getAllList();
        void updatefile();
        void show_listdata();
        void fileget_local();
        bool ifshow;
        void setting_local();
        void putfile();

private:
    QByteArray setData;
    Ui::ShortcutHelper *ui;
    QNetworkReply *reply;
    QUrl url;
    QByteArray byte;
    QNetworkAccessManager *manage;
    QString window_name;
    QString show_data;
    QJsonObject rootObj;
    QJsonObject setObject;
    bool ifupdate;

private slots:
    void execute();
    void downloadFinished(QNetworkReply *reply);
    void replyFinished(QNetworkReply *reply);
    bool saveToDisk();


};



#endif // SHORTCUTHELPER_H
