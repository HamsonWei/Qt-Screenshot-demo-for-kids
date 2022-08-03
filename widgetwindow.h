#ifndef WIDGETWINDOW_H
#define WIDGETWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QScreen>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetWindow; }
QT_END_NAMESPACE

class WidgetWindow : public QMainWindow
{
    Q_OBJECT

public:
    WidgetWindow(QWidget *parent = nullptr);
    ~WidgetWindow();

private slots:
    void save_shotFile();

    void shortkey();

    void on_newBtn_clicked();

    void on_helpBtn_clicked();

private:
    Ui::WidgetWindow *ui;
    QScreen *m_QScreen_fullScreen;
    QPixmap m_QPixmap_fullScreen;
};
#endif // WIDGETWINDOW_H
