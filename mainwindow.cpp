#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QGuiApplication>
#include <QClipboard>
#include <QTimer>
#include <QTime>
#include <random>
#include <QThread>
#include <QAbstractAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupEffects();
    setupAnimations();

    // Connect signals and slots
    connect(ui->encryptButton, &QPushButton::clicked, this, &MainWindow::onEncryptClicked);
    connect(ui->decryptButton, &QPushButton::clicked, this, &MainWindow::onDecryptClicked);
    connect(ui->keyEdit, &QLineEdit::textChanged, this, &MainWindow::onKeyChanged);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(ui->copyButton, &QPushButton::clicked, this, &MainWindow::onCopyEncrypted);
    connect(ui->generateKeyButton, &QPushButton::clicked, this, &MainWindow::onGenerateKey);

    // Setup time update timer
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000); // Update every second
    updateTime(); // Initial update
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupEffects() {
    // Add shadow effect to phone frame
    phoneShadow = new QGraphicsDropShadowEffect(this);
    phoneShadow->setBlurRadius(20);
    phoneShadow->setColor(QColor(74, 158, 255, 160));
    phoneShadow->setOffset(0, 0);
    ui->phoneFrame->setGraphicsEffect(phoneShadow);
}

void MainWindow::setupAnimations() {
    // Setup encryption animation
    encryptAnimGroup = new QParallelAnimationGroup(this);
    
    auto shadowAnim = new QPropertyAnimation(phoneShadow, "blurRadius");
    shadowAnim->setDuration(500);
    shadowAnim->setStartValue(20);
    shadowAnim->setEndValue(40);
    shadowAnim->setEasingCurve(QEasingCurve::InOutQuad);
    
    auto colorAnim = new QPropertyAnimation(ui->phoneFrame, "styleSheet");
    colorAnim->setDuration(500);
    colorAnim->setStartValue("QFrame#phoneFrame { background-color: #000000; border-radius: 40px; border: 2px solid #2c2c2e; }");
    colorAnim->setEndValue("QFrame#phoneFrame { background-color: #001a33; border-radius: 40px; border: 2px solid #4a9eff; }");
    
    encryptAnimGroup->addAnimation(shadowAnim);
    encryptAnimGroup->addAnimation(colorAnim);
    
    // Setup decryption animation
    decryptAnimGroup = new QParallelAnimationGroup(this);
    
    auto shadowDecryptAnim = new QPropertyAnimation(phoneShadow, "blurRadius");
    shadowDecryptAnim->setDuration(500);
    shadowDecryptAnim->setStartValue(40);
    shadowDecryptAnim->setEndValue(20);
    shadowDecryptAnim->setEasingCurve(QEasingCurve::InOutQuad);
    
    auto colorDecryptAnim = new QPropertyAnimation(ui->phoneFrame, "styleSheet");
    colorDecryptAnim->setDuration(500);
    colorDecryptAnim->setStartValue("QFrame#phoneFrame { background-color: #001a33; border-radius: 40px; border: 2px solid #4a9eff; }");
    colorDecryptAnim->setEndValue("QFrame#phoneFrame { background-color: #000000; border-radius: 40px; border: 2px solid #2c2c2e; }");
    
    decryptAnimGroup->addAnimation(shadowDecryptAnim);
    decryptAnimGroup->addAnimation(colorDecryptAnim);
    
    // Dynamic Island animations
    auto islandExpandAnim = new QPropertyAnimation(ui->dynamicIsland, "minimumWidth");
    islandExpandAnim->setDuration(300);
    islandExpandAnim->setStartValue(120);
    islandExpandAnim->setEndValue(200);
    islandExpandAnim->setEasingCurve(QEasingCurve::OutQuad);
    
    auto islandContractAnim = new QPropertyAnimation(ui->dynamicIsland, "minimumWidth");
    islandContractAnim->setDuration(300);
    islandContractAnim->setStartValue(200);
    islandContractAnim->setEndValue(120);
    islandContractAnim->setEasingCurve(QEasingCurve::InQuad);
    
    encryptAnimGroup->addAnimation(islandExpandAnim);
    decryptAnimGroup->addAnimation(islandContractAnim);
}

void MainWindow::onEncryptClicked()
{
    if (ui->keyEdit->text().isEmpty()) {
        showStatusMessage("Please enter an encryption key first", true);
        ui->keyEdit->setFocus();
        return;
    }

    QString plaintext = ui->inputText->toPlainText().trimmed();
    if (plaintext.isEmpty()) {
        showStatusMessage("Please enter a message to encrypt", true);
        ui->inputText->setFocus();
        return;
    }

    try {
        // Set the encryption key
        cipher.set_key(ui->keyEdit->text().toStdString());
        
        // Encrypt the message
        std::string encrypted = cipher.encrypt(plaintext.toStdString());
        
        // Add encrypted message to chat
        addMessage(QString::fromStdString(encrypted), true, true);
        
        // Clear input field
        ui->inputText->clear();
        
        playEncryptAnimation();
        showStatusMessage("Message sent encrypted! 🔒");
    }
    catch (const std::exception& e) {
        showStatusMessage(QString("Encryption failed: %1").arg(e.what()), true);
    }
}

void MainWindow::onDecryptClicked()
{
    // Get the last encrypted message
    QFrame* lastMessage = findLastEncryptedMessage();
    if (!lastMessage) {
        showStatusMessage("No encrypted message to decrypt", true);
        return;
    }

    QString key = ui->keyEdit->text();
    if (key.isEmpty()) {
        showStatusMessage("Please enter the decryption key first", true);
        ui->keyEdit->setFocus();
        return;
    }

    // Get the encrypted text from the message
    QLabel* messageLabel = lastMessage->findChild<QLabel*>();
    if (!messageLabel) return;

    QString encryptedText = messageLabel->text();

    try {
        // Set the decryption key
        cipher.set_key(key.toStdString());

        // Decrypt the message
        std::string decrypted = cipher.decrypt(encryptedText.toStdString());
        
        // Add decrypted message to chat
        addMessage(QString::fromStdString(decrypted), false, false);
        
        playDecryptAnimation();
        showStatusMessage("Message decrypted! 🔓");
    }
    catch (const std::exception& e) {
        showStatusMessage("Could not decrypt. Wrong key?", true);
    }
}

void MainWindow::onKeyChanged(const QString& text)
{
    try {
        if (!text.isEmpty()) {
            cipher.set_key(text.toStdString());
        } else {
            cipher.clear();
        }
        
        // Visual feedback for key change
        ui->keyEdit->setStyleSheet(text.isEmpty() ? 
            "background-color: #1c1c1e;" : 
            "background-color: #0084ff;");
    }
    catch (const std::exception& e) {
        showStatusMessage("Invalid key", true);
    }
}

QString MainWindow::generateRandomKey(int length) {
    const QString chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.length() - 1);
    
    QString result;
    for (int i = 0; i < length; ++i) {
        result += chars[dis(gen)];
    }
    return result;
}

void MainWindow::onClearClicked()
{
    ui->inputText->clear();
    ui->keyEdit->clear();
    
    // Clear all messages from chat
    while (QLayoutItem* item = ui->chatLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    
    showStatusMessage("Chat cleared");
}

void MainWindow::onCopyEncrypted()
{
    // Get the last encrypted message
    QFrame* lastMessage = findLastEncryptedMessage();
    if (!lastMessage) {
        showStatusMessage("No encrypted message to copy", true);
        return;
    }

    // Get the text from the message label
    QLabel* messageLabel = lastMessage->findChild<QLabel*>();
    if (!messageLabel) return;

    QString text = messageLabel->text();
    QGuiApplication::clipboard()->setText(text);
    showStatusMessage("Encrypted message copied to clipboard");
}

void MainWindow::onGenerateKey()
{
    QString key = generateRandomKey(16); // Generate a 16-character key
    ui->keyEdit->setText(key);
    showStatusMessage("New random key generated");
}

void MainWindow::playEncryptAnimation()
{
    if (encryptAnimGroup && encryptAnimGroup->state() != QAbstractAnimation::Running) {
        encryptAnimGroup->start();
    }
}

void MainWindow::playDecryptAnimation()
{
    if (decryptAnimGroup && decryptAnimGroup->state() != QAbstractAnimation::Running) {
        decryptAnimGroup->start();
    }
}

void MainWindow::showStatusMessage(const QString& message, bool isError)
{
    // Create status label
    QLabel* statusLabel = new QLabel(message, ui->dynamicIsland);
    statusLabel->setStyleSheet(QString(
        "color: %1; "
        "font-family: SF Pro Text; "
        "font-size: 12pt; "
        "background: transparent;"
    ).arg(isError ? "#ff453a" : "#32d74b"));
    statusLabel->setAlignment(Qt::AlignCenter);
    
    // Add to dynamic island
    QLayout* islandLayout = ui->dynamicIsland->layout();
    if (islandLayout) {
        // Clear any existing widgets
        while (QLayoutItem* item = islandLayout->takeAt(0)) {
            delete item->widget();
            delete item;
        }
        islandLayout->addWidget(statusLabel);
    }
    
    // Animate island width
    QPropertyAnimation* expandAnim = new QPropertyAnimation(ui->dynamicIsland, "minimumWidth");
    expandAnim->setDuration(300);
    expandAnim->setStartValue(120);
    expandAnim->setEndValue(300);
    expandAnim->setEasingCurve(QEasingCurve::OutQuad);
    expandAnim->start(QAbstractAnimation::DeleteWhenStopped);
    
    // Contract after delay
    QTimer::singleShot(2000, this, [this]() {
        QPropertyAnimation* contractAnim = new QPropertyAnimation(ui->dynamicIsland, "minimumWidth");
        contractAnim->setDuration(300);
        contractAnim->setStartValue(300);
        contractAnim->setEndValue(120);
        contractAnim->setEasingCurve(QEasingCurve::InQuad);
        contractAnim->start(QAbstractAnimation::DeleteWhenStopped);
    });
    
    // Remove label after animation
    QTimer::singleShot(2500, statusLabel, &QLabel::deleteLater);
}

void MainWindow::addMessage(const QString& text, bool isSent, bool isEncrypted)
{
    QFrame* messageFrame = new QFrame(this);
    messageFrame->setObjectName(isSent ? "sentMessage" : "receivedMessage");
    messageFrame->setProperty("class", "messageFrame");
    messageFrame->setProperty("encrypted", isEncrypted);
    
    QVBoxLayout* layout = new QVBoxLayout(messageFrame);
    layout->setContentsMargins(12, 8, 12, 8);
    layout->setSpacing(4);
    
    // Message text
    QLabel* messageLabel = new QLabel(text);
    messageLabel->setWordWrap(true);
    messageLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    layout->addWidget(messageLabel);
    
    // Add message indicator
    QString indicator;
    if (isEncrypted) {
        indicator = isSent ? " Sent Encrypted" : "🔒 Received Encrypted";
    } else {
        indicator = isSent ? "✉️ Original Message" : "🔓 Decrypted Message";
    }
    
    QLabel* detailsLabel = new QLabel(indicator);
    detailsLabel->setProperty("class", "details");
    layout->addWidget(detailsLabel);
    
    ui->chatLayout->addWidget(messageFrame);
    
    // Scroll to bottom
    QScrollArea* scrollArea = ui->chatScroll;
    if (scrollArea && scrollArea->verticalScrollBar()) {
        scrollArea->verticalScrollBar()->setValue(
            scrollArea->verticalScrollBar()->maximum()
        );
    }
}

QFrame* MainWindow::findLastEncryptedMessage()
{
    QFrame* lastEncrypted = nullptr;
    QLayout* layout = ui->chatLayout;
    
    for (int i = 0; i < layout->count(); ++i) {
        QWidget* widget = layout->itemAt(i)->widget();
        QFrame* frame = qobject_cast<QFrame*>(widget);
        if (frame && frame->property("encrypted").toBool()) {
            lastEncrypted = frame;
        }
    }
    
    return lastEncrypted;
}

void MainWindow::updateTime() {
    QTime currentTime = QTime::currentTime();
    ui->timeLabel->setText(currentTime.toString("h:mm"));
}
