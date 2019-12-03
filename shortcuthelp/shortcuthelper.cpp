#include "shortcuthelper.h"
#include "ui_shortcuthelper.h"
#include "windows.h"
#include <QStyleOption>
#include <Qpainter>
#include <QShortcut>
#include <QHotkey>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include  "tlhelp32.h"
#include  <QtNetwork/QNetworkAccessManager>
#include  <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QSslSocket>
#include <QSsl>
#include <QSslConfiguration>
#include <QtNetwork/QHostInfo>
#include <QFileInfo>
#include <QDir>




//构造函数
ShortcutHelper::ShortcutHelper(QWidget *parent):
    QWidget (parent),
    ui(new  Ui::ShortcutHelper)
{
    QWidget::setEnabled(false);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);


    //给Qlistwidget添加快捷键项目
//    QListWidget *p=ui->listWidget;
//    QStringList k;
//    p->setParent(this);
//    ui->listWidget->addItem("Ctrl+k 不知道叫什么");
//    ui->listWidget->addItem("啦啦啦");
//    p->addItems(k);
//    p->setStyleSheet("QScrollBar{width:0;height:0;color:rgb(255, 255, 255)}");


}




//程序初始化的一些设置
void ShortcutHelper::someSet()
{
    //设置透明度0.9
    setWindowOpacity(0.9);
    //设置永远在屏幕最上方
    setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool | windowFlags());
    //设置背景为黑色
    this->setStyleSheet("QWidget{background-color:rgb(0,0,0);border-radius: 7px}");
    //设置不取得焦点
    setFocusPolicy(Qt::NoFocus);
    //设置窗口大小为1200*800
    setFixedSize(1200,800);
    auto hotkey = new QHotkey(QKeySequence("ctrl+space"), true, this);//The hotkey will be automatically registered
    qDebug() << "Is Registered: " << hotkey->isRegistered();

    //槽函数,绑定全局快捷键,设置widget是否可见
    ifshow=false;//可见性状态储存状态储存

    ifupdate = false;
    QObject::connect(hotkey, &QHotkey::activated, this, [&](){
        qDebug() << "快捷键被成功按下已被识别";
        window_name=ShortcutHelper::GetActiveWindowTitle();
        ui->label_5->setText(("前台程序名称:  "+window_name));

        //设置ifshow
        if(ifshow == true){
            this->setVisible(false);
            ifshow = false;
            qDebug()<<"设置不可见";
        }else{
            show_listdata();
            this->setVisible(true);
            ifshow=true;
            qDebug()<<"设置可见";
            if(ifupdate==false){
                QHostInfo info = QHostInfo::fromName(QString("data.liuzhengdong.top"));
                if(info.addresses().isEmpty()==false){
                    this->updatefile();
                    ifupdate=true;
                }
            }
        }
        });

    //初始化用户自定义设置
    //this->setAttribute(Qt::WA_StyledBackground,true);
    //setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //setWindowFlags(Qt::Tool);
    //setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_TransparentForMouseEvents,true);
    //setWindowFlags(Qt::WindowStaysOnTopHint);

    //QString QCoreApplication::applicationDirPath()



}

//重写paintEvent
void ShortcutHelper::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}



//函数->通过pid号得到程序的名字
LPWSTR GetProcessNameById(DWORD ProcessID)
{
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    LPWSTR result = new WCHAR[32];

    //获取系统中全部进程的快照 Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hProcessSnap) return(FALSE);

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // 获取第一个进程的信息 Retrieve information about the first process,
    // 若获取失败则退出 and exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32))
    {
        // 清除快照 clean the snapshot object
        CloseHandle(hProcessSnap);
        printf("!!! Failed to gather information on system processes! \n");
        return(NULL);
    }

    //匹配进程ID Matching Process ID
    do
    {
        if (ProcessID == pe32.th32ProcessID)
        {
            //拷贝进程名 Copy Process Name
            wcscpy(result, (LPWSTR)pe32.szExeFile);
            break;
        }
    } while (Process32Next(hProcessSnap, &pe32));

    // 清除快照 clean the snapshot object
    CloseHandle(hProcessSnap);

    return result;
}


// 函数->得到前端windows的名称
QString ShortcutHelper::GetActiveWindowTitle()
{
     wchar_t name[200];
     wchar_t name2[200];
     DWORD process_ID = 0;
     HWND hwnd= GetForegroundWindow(); // get handle of currently active window
     GetWindowThreadProcessId(hwnd,&process_ID);
     wcscpy(name, GetProcessNameById(process_ID));
     GetWindowTextW(hwnd,name2,sizeof(name2));
     //获得窗口的名字
     QString name2_q=QString::fromStdWString(name2).section("- ",-1,-1);
     //获取进程的名字
     QString name_q=QString::fromStdWString(name);
     if(name_q.compare(QString("ApplicationFrameHost.exe"))==0)
     {
             name_q=name2_q;
     }
     if(name2_q.compare(QString("Google Chrome"))==0){
            name_q=name2_q;
     }


     return name_q;
}

void ShortcutHelper::execute()
  {
      QStringList args = QCoreApplication::instance()->arguments();
      args.takeFirst();           // skip the first argument, which is the program's name
      if (args.isEmpty()) {
          printf("Qt Download example - downloads all URLs in parallel\n"
                 "Usage: download url1 [url2... urlN]\n"
                 "\n"
                 "Downloads the URLs passed in the command-line to the local directory\n"
                 "If the target file already exists, a .0, .1, .2, etc. is appended to\n"
                 "differentiate.\n");
          QCoreApplication::instance()->quit();
          return;
      }

      for (const QString &arg : qAsConst(args)) {
          QUrl url = QUrl::fromEncoded(arg.toLocal8Bit());
          doDownload(url);
      }
  }



//读取本地资源文件
void ShortcutHelper::fileget_local(){
    QFile loadFile("D:/ShortCutHelper/shortcutdata.json");
    if(!loadFile.open(QIODevice::ReadOnly))
        {
            qDebug() << "could't open projects json";
        }
    QByteArray allData = loadFile.readAll();
    loadFile.close();
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

            if(json_error.error != QJsonParseError::NoError)
            {
                qDebug() << "json error!";
            }
            rootObj = jsonDoc.object();
}

//读取本地设置
void ShortcutHelper::setting_local(){
    QFile settingfile("D:/ShortCutHelper/shortcutsetting.json");
    if(!settingfile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"setting file can't open";
    }
        setData = settingfile.readAll();
        settingfile.close();
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(setData, &json_error));

                if(json_error.error != QJsonParseError::NoError)
                {
                    qDebug() << "json error!";
                }
                setObject = jsonDoc.object();

}


//更新本地文件函数
void ShortcutHelper::updatefile(){
    url="http://data.liuzhengdong.top/data/file/data.json";

        doDownload(url);
        if(saveToDisk()){
            qDebug()<<"下载保存成功";
        }else {
            qDebug()<<"下载保存失败";
    }


}

//负责判断文件下载是否成功
void ShortcutHelper::downloadFinished(QNetworkReply *reply)
  {
      if (reply->error()) {
          qDebug()<<"下载错误";
      } else {
          qDebug()<<"下载成功";
      }
  }

//把数据存入文件
bool ShortcutHelper::saveToDisk()
  {
      QFile file("D://ShortCutHelper/shortcutdata.json");
      if (!file.open(QIODevice::WriteOnly)) {
          fprintf(stderr, "Could not open %s for writing: %s\n",
                  qPrintable(":data.json"),
                  qPrintable(file.errorString()));
                   file.close();
          return false;
      }

      file.write(reply->readAll());
      file.close();

      return true;
  }

//执行下载操作
void ShortcutHelper::doDownload(const QUrl url)
  {
     manage=new QNetworkAccessManager(this);

      QNetworkRequest request;
      request.setUrl(url);

      reply = manage->get(request);
      connect(manage, SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
      connect(reply, SIGNAL(readyRead()),this, SLOT(saveToDisk()));
  }

//下载完成后的确认操作
void ShortcutHelper::replyFinished(QNetworkReply *reply){
    //获取响应的信息，状态码为200表示正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QByteArray bytes = reply->readAll();  //获取字节
    QString result(bytes);  //转化为字符串

    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
    }
    else
    {
        //处理错误
         qDebug()<<"失败";
    }

    reply->deleteLater();//要删除reply，但是不能在repyfinished里直接delete，要调用deletelater;

}



//展示数据函数
void ShortcutHelper::show_listdata(){
    //设置鼠标一到上面的时候没高亮效果
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
            item->setFlags(Qt::NoItemFlags);
            item->setFlags(Qt::ItemIsEnabled);
            ui->label->setWindowOpacity(1);
    QList<QListWidget*> handler;
    handler.append(ui->listWidget);
     handler.append(ui->listWidget_2);
      handler.append(ui->listWidget_3);
      for (int i=0;i<handler.length();i++) {
          handler[i]->clear();
          handler[i]->setWindowOpacity(1);
      }
    int cout=0;
    QStringList all =getAllList();
    int state =0;
    QListWidget *nowWidget=handler[state];
    for(int i =0;i<all.length();i++){

        if(state>=3){
            nowWidget->addItem("抱歉,空间不够了");
            break;
        }else if(cout>=20 ){
            cout=0;
            nowWidget=handler[++state];
        }else if(all[i].at(0) == "·"){
            QListWidgetItem *classify=new  QListWidgetItem(all[i]);
            //classify->setTextAlignment(Qt::AlignHCenter);
            QFont font;
            font.setPointSize(14);
            font.setBold(true);
            classify->setFont(font);
            classify-> setSizeHint(QSize(60,40));
            nowWidget->addItem(classify);
        }else{
            QListWidgetItem *classify=new  QListWidgetItem(all[i]);
            classify->setSizeHint(QSize(80,30));
            nowWidget->addItem(classify);
            cout++;
        }
    }
}
//通过解析json得到所有的条目
QStringList ShortcutHelper::getAllList(){
    show_data="未查询到当前程序的快捷键数据";
    QStringList keys;
    QString sss= "未查询到数据";
    QStringList all;
    this->fileget_local();
    if(rootObj.contains(window_name))
    {
        //keys是分类的字符数组
         keys= rootObj.value(window_name).toObject().keys();
        //secondObject放的是分类的对象数组
        QList<QJsonObject> secondObject;
        QJsonObject matched_object = rootObj.value(window_name).toObject();


        for(int i =0;i<matched_object.keys().size();i++)
        {
            secondObject.append( matched_object.   value(keys[i]).    toObject());
        }
        //读取分类的长度
        for(int i =0;i<secondObject.length();i++){
            all.append("·"+keys[i]);
            //读取每条分类里的每一项
            for(int k =0;k<secondObject[i].keys().size();k++){
                qDebug()<<secondObject[i].keys()[k]<<":"<<secondObject[i].value(secondObject[i].keys()[k]).toString()  ;
                all.append(secondObject[i].keys()[k]+"  "+ secondObject[i].value(secondObject[i].keys()[k]).toString());
            }
        }
    show_data = window_name;
    }else{
        all.append(sss);
    }
    return all;
}


void ShortcutHelper::putfile(){

    QDir dir;
        if (dir.exists("D://ShortCutHelper")==false)
        {
            bool res = dir.mkpath("D://ShortCutHelper");
            qDebug() << "新建目录是否成功" << res;
        }

    QFileInfo fi("D://ShortCutHelper/shortcutsetting.json");
    if(fi.isFile()==false){
        QFile::copy("./setting.json","D://ShortCutHelper/shortcutsetting.json");
        qDebug()<<"输出成功1";
    }
    QFileInfo fi2("D://ShortCutHelper/shortcutdata.json");
    if(fi2.isFile()==false){
         QFile::copy("./data.json","D:/ShortCutHelper/shortcutdata.json");
        qDebug()<<"输出成功2";
    }
};

//析构类函数
ShortcutHelper::~ShortcutHelper(){
    delete ui;
}



