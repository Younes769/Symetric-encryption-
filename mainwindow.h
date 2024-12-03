#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>
#include <QStatusBar>
#include <QFrame>
#include "symmetric_encryption.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEncryptClicked();
    void onDecryptClicked();
    void onKeyChanged(const QString& text);
    void onClearClicked();
    void onCopyEncrypted();
    void onGenerateKey();
    void updateTime();

private:
    void setupAnimations();
    void setupEffects();
    void playEncryptAnimation();
    void playDecryptAnimation();
    void showStatusMessage(const QString& message, bool isError = false);
    QString generateRandomKey(int length);
    void addMessage(const QString& text, bool isSent, bool isEncrypted = false);
    QFrame* findLastEncryptedMessage();
    
    Ui::MainWindow *ui;
    SymmetricEncryption cipher;
    QParallelAnimationGroup* encryptAnimGroup;
    QParallelAnimationGroup* decryptAnimGroup;
    QGraphicsDropShadowEffect* phoneShadow;
};

#endif // MAINWINDOW_H
