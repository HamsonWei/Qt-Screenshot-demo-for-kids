#include "widgetwindow.h"
#include "ui_widgetwindow.h"

WidgetWindow::WidgetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WidgetWindow)
{
    ui->setupUi(this);
    shortkey();
}

WidgetWindow::~WidgetWindow()
{
    delete ui;
}

void WidgetWindow::shortkey()
{
    QAction* action_cut = new QAction(this);
    action_cut->setShortcut(QKeySequence("Ctrl+Alt+S"));
    this->addAction(action_cut);
    connect(action_cut, &QAction::triggered, this, &WidgetWindow::on_newBtn_clicked);
}

void WidgetWindow::save_shotFile()
{
    QDateTime cDateTime = QDateTime::currentDateTime();
    QString fileName = QString("LET_Screen_Shot_%1.png").arg(cDateTime.toString("yyyyMMdd_hhmmss_zzz"));
    QString fileDirPath = QDir::currentPath();
    qDebug() << fileDirPath;
    QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Save File"),
                                        QString("%1/%2").arg(fileDirPath).arg(fileName),
                                        tr("image(*.png)"));
    if (!saveFilePath.isEmpty())
    {
        m_QPixmap_fullScreen.save(saveFilePath, Q_NULLPTR, 100);
        QMessageBox::information(this, tr("Congratulations !"),
                                 tr("Save succeed."));
    }
}

void WidgetWindow::on_newBtn_clicked()
{
    m_QScreen_fullScreen = QGuiApplication::primaryScreen();
    m_QPixmap_fullScreen = m_QScreen_fullScreen->grabWindow(0);
    save_shotFile();
}

void WidgetWindow::on_helpBtn_clicked()
{
    QMessageBox::information(this, "Help", "Click \"New\" button, the software will get "
                                           "all you seeing on the current screen, "
                                           "and you can choose whether save or not.\n\n"
                                           "Base on Qt 5.14.2\n\n"
                                           "Hamson@leee.tech\n"
                                           "February 02, 2022");
}

