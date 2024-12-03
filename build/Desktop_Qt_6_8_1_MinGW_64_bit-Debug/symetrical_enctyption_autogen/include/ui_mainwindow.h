/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QFrame *phoneFrame;
    QVBoxLayout *phoneLayout;
    QFrame *dynamicIsland;
    QHBoxLayout *islandLayout;
    QFrame *statusBar;
    QHBoxLayout *statusLayout;
    QLabel *timeLabel;
    QLabel *batteryLabel;
    QFrame *navBar;
    QHBoxLayout *navLayout;
    QLabel *contactName;
    QHBoxLayout *keyLayout;
    QLineEdit *keyEdit;
    QPushButton *generateKeyButton;
    QScrollArea *chatScroll;
    QWidget *chatContent;
    QVBoxLayout *chatLayout;
    QHBoxLayout *inputLayout;
    QPlainTextEdit *inputText;
    QPushButton *encryptButton;
    QHBoxLayout *bottomBar;
    QPushButton *clearButton;
    QPushButton *decryptButton;
    QPushButton *copyButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(430, 932);
        MainWindow->setMinimumSize(QSize(430, 932));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    /* Main Window */\n"
"    QMainWindow { \n"
"        background-color: #000000; \n"
"    }\n"
"    QWidget#centralwidget { \n"
"        background-color: #000000; \n"
"    }\n"
"    \n"
"    /* iPhone Frame */\n"
"    QFrame#phoneFrame {\n"
"        background-color: #000000;\n"
"        border: 2px solid #424245;\n"
"        border-radius: 55px;\n"
"        margin: 10px;\n"
"    }\n"
"    \n"
"    /* Dynamic Island */\n"
"    QFrame#dynamicIsland {\n"
"        background-color: #000000;\n"
"        border-radius: 20px;\n"
"        min-height: 35px;\n"
"        max-height: 35px;\n"
"        min-width: 120px;\n"
"        max-width: 120px;\n"
"        margin-top: 12px;\n"
"    }\n"
"    \n"
"    /* Status Bar */\n"
"    QFrame#statusBar {\n"
"        background-color: transparent;\n"
"        margin-top: 5px;\n"
"    }\n"
"    QLabel#timeLabel {\n"
"        color: #ffffff;\n"
"        font-family: SF Pro Display;\n"
"        font-size: 16pt;\n"
"        font-weight: bold;\n"
"    }\n"
"    QLabel#batter"
                        "yLabel {\n"
"        color: #ffffff;\n"
"        font-size: 14pt;\n"
"    }\n"
"    \n"
"    /* Navigation Bar */\n"
"    QFrame#navBar {\n"
"        background-color: rgba(28, 28, 30, 180);\n"
"        border-bottom: 1px solid #2c2c2e;\n"
"        padding: 10px;\n"
"    }\n"
"    QLabel#contactName {\n"
"        color: #ffffff;\n"
"        font-family: SF Pro Display;\n"
"        font-size: 18pt;\n"
"        font-weight: bold;\n"
"    }\n"
"    \n"
"    /* Key Input */\n"
"    QLineEdit {\n"
"        background-color: rgba(28, 28, 30, 180);\n"
"        color: #ffffff;\n"
"        border-radius: 15px;\n"
"        padding: 12px;\n"
"        font-size: 14pt;\n"
"        font-family: SF Pro Text;\n"
"        border: none;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border: 1px solid #0a84ff;\n"
"        background-color: rgba(28, 28, 30, 220);\n"
"    }\n"
"    \n"
"    /* Chat Area */\n"
"    QScrollArea {\n"
"        border: none;\n"
"        background-color: transparent;\n"
"    }\n"
"    QWidget#chatCont"
                        "ent {\n"
"        background-color: transparent;\n"
"    }\n"
"    \n"
"    /* Messages */\n"
"    QFrame.messageFrame {\n"
"        border-radius: 20px;\n"
"        min-height: 40px;\n"
"        padding: 5px;\n"
"    }\n"
"    QFrame#sentMessage {\n"
"        background-color: #0a84ff;\n"
"        margin-left: 60px;\n"
"        margin-right: 15px;\n"
"        border-radius: 20px;\n"
"        padding: 10px;\n"
"    }\n"
"    QFrame#receivedMessage {\n"
"        background-color: rgba(58, 58, 60, 180);\n"
"        margin-left: 15px;\n"
"        margin-right: 60px;\n"
"        border-radius: 20px;\n"
"        padding: 10px;\n"
"    }\n"
"    \n"
"    /* Text Areas */\n"
"    QPlainTextEdit {\n"
"        background-color: rgba(28, 28, 30, 180);\n"
"        color: #ffffff;\n"
"        border: none;\n"
"        border-radius: 20px;\n"
"        padding: 12px;\n"
"        font-size: 14pt;\n"
"        font-family: SF Pro Text;\n"
"        selection-background-color: #0a84ff;\n"
"    }\n"
"    QPlainTextEdit:focus {\n"
""
                        "        background-color: rgba(28, 28, 30, 220);\n"
"    }\n"
"    QPlainTextEdit#outputText {\n"
"        background-color: rgba(44, 44, 46, 180);\n"
"        border: 1px solid rgba(60, 60, 62, 180);\n"
"        font-family: SF Pro Mono;\n"
"        font-size: 12pt;\n"
"    }\n"
"    \n"
"    /* Buttons */\n"
"    QPushButton {\n"
"        background-color: #0a84ff;\n"
"        color: white;\n"
"        border-radius: 22px;\n"
"        padding: 12px;\n"
"        font-size: 14pt;\n"
"        font-family: SF Pro Text;\n"
"        min-height: 44px;\n"
"    }\n"
"    QPushButton:hover { \n"
"        background-color: #0070e0; \n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #005dc2;\n"
"    }\n"
"    QPushButton#sendButton {\n"
"        background-color: #0a84ff;\n"
"        border-radius: 20px;\n"
"        min-width: 40px;\n"
"        max-width: 40px;\n"
"        min-height: 40px;\n"
"        max-height: 40px;\n"
"        font-size: 18pt;\n"
"    }\n"
"    QPushButton#generateKeyButton {\n"
""
                        "        font-size: 16pt;\n"
"    }\n"
"    \n"
"    /* Scroll Bars */\n"
"    QScrollBar:vertical {\n"
"        border: none;\n"
"        background: transparent;\n"
"        width: 8px;\n"
"        margin: 0;\n"
"    }\n"
"    QScrollBar::handle:vertical {\n"
"        background: rgba(255, 255, 255, 60);\n"
"        border-radius: 4px;\n"
"        min-height: 20px;\n"
"    }\n"
"    QScrollBar::handle:vertical:hover {\n"
"        background: rgba(255, 255, 255, 100);\n"
"    }\n"
"    QScrollBar::add-line:vertical,\n"
"    QScrollBar::sub-line:vertical {\n"
"        height: 0;\n"
"    }\n"
"    QScrollBar::add-page:vertical,\n"
"    QScrollBar::sub-page:vertical {\n"
"        background: none;\n"
"    }\n"
"    QLabel {\n"
"        color: white;\n"
"        font-size: 14pt;\n"
"    }\n"
"    QLabel[class=\"details\"] {\n"
"        color: rgba(255,255,255,0.6);\n"
"        font-size: 10pt;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        phoneFrame = new QFrame(centralwidget);
        phoneFrame->setObjectName("phoneFrame");
        phoneLayout = new QVBoxLayout(phoneFrame);
        phoneLayout->setObjectName("phoneLayout");
        dynamicIsland = new QFrame(phoneFrame);
        dynamicIsland->setObjectName("dynamicIsland");
        dynamicIsland->setStyleSheet(QString::fromUtf8("\n"
"           QFrame#dynamicIsland {\n"
"            background-color: black;\n"
"            border-radius: 20px;\n"
"           }\n"
"          "));
        islandLayout = new QHBoxLayout(dynamicIsland);
        islandLayout->setSpacing(0);
        islandLayout->setObjectName("islandLayout");
        islandLayout->setContentsMargins(0, 0, 0, 0);

        phoneLayout->addWidget(dynamicIsland, 0, Qt::AlignHCenter|Qt::AlignTop);

        statusBar = new QFrame(phoneFrame);
        statusBar->setObjectName("statusBar");
        statusLayout = new QHBoxLayout(statusBar);
        statusLayout->setObjectName("statusLayout");
        timeLabel = new QLabel(statusBar);
        timeLabel->setObjectName("timeLabel");

        statusLayout->addWidget(timeLabel);

        batteryLabel = new QLabel(statusBar);
        batteryLabel->setObjectName("batteryLabel");

        statusLayout->addWidget(batteryLabel, 0, Qt::AlignRight);


        phoneLayout->addWidget(statusBar);

        navBar = new QFrame(phoneFrame);
        navBar->setObjectName("navBar");
        navLayout = new QHBoxLayout(navBar);
        navLayout->setObjectName("navLayout");
        contactName = new QLabel(navBar);
        contactName->setObjectName("contactName");
        contactName->setAlignment(Qt::AlignCenter);

        navLayout->addWidget(contactName);


        phoneLayout->addWidget(navBar);

        keyLayout = new QHBoxLayout();
        keyLayout->setObjectName("keyLayout");
        keyEdit = new QLineEdit(phoneFrame);
        keyEdit->setObjectName("keyEdit");

        keyLayout->addWidget(keyEdit);

        generateKeyButton = new QPushButton(phoneFrame);
        generateKeyButton->setObjectName("generateKeyButton");
        generateKeyButton->setMaximumWidth(44);

        keyLayout->addWidget(generateKeyButton);


        phoneLayout->addLayout(keyLayout);

        chatScroll = new QScrollArea(phoneFrame);
        chatScroll->setObjectName("chatScroll");
        chatScroll->setWidgetResizable(true);
        chatContent = new QWidget();
        chatContent->setObjectName("chatContent");
        chatLayout = new QVBoxLayout(chatContent);
        chatLayout->setSpacing(12);
        chatLayout->setObjectName("chatLayout");
        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName("inputLayout");
        inputText = new QPlainTextEdit(chatContent);
        inputText->setObjectName("inputText");
        inputText->setMaximumHeight(100);

        inputLayout->addWidget(inputText);

        encryptButton = new QPushButton(chatContent);
        encryptButton->setObjectName("encryptButton");

        inputLayout->addWidget(encryptButton);


        chatLayout->addLayout(inputLayout);

        bottomBar = new QHBoxLayout();
        bottomBar->setObjectName("bottomBar");
        clearButton = new QPushButton(chatContent);
        clearButton->setObjectName("clearButton");

        bottomBar->addWidget(clearButton);

        decryptButton = new QPushButton(chatContent);
        decryptButton->setObjectName("decryptButton");

        bottomBar->addWidget(decryptButton);

        copyButton = new QPushButton(chatContent);
        copyButton->setObjectName("copyButton");

        bottomBar->addWidget(copyButton);


        chatLayout->addLayout(bottomBar);

        chatScroll->setWidget(chatContent);

        phoneLayout->addWidget(chatScroll);


        mainLayout->addWidget(phoneFrame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Secure iMessage", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "9:41", nullptr));
        batteryLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\224\213 100%", nullptr));
        contactName->setText(QCoreApplication::translate("MainWindow", "\360\237\224\220 Secure Chat", nullptr));
        keyEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter encryption key...", nullptr));
        generateKeyButton->setText(QCoreApplication::translate("MainWindow", "\360\237\216\262", nullptr));
        inputText->setPlaceholderText(QCoreApplication::translate("MainWindow", "iMessage", nullptr));
        encryptButton->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        encryptButton->setObjectName(QCoreApplication::translate("MainWindow", "sendButton", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        decryptButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\223 Decrypt", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
