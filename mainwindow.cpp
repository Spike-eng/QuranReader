#include "mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Quran Reader");
    setGeometry(100, 100, 1000, 700);

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    pageList = new QListWidget;
    pageList->setMaximumWidth(150);
    mainLayout->addWidget(pageList);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    mainLayout->addLayout(rightLayout);

    imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignCenter);
    rightLayout->addWidget(imageLabel);

    statusLabel = new QLabel("Select a page");
    rightLayout->addWidget(statusLabel);

    connect(pageList, &QListWidget::itemClicked, this, &MainWindow::onPageSelected);

    loadPages();
}

MainWindow::~MainWindow()
{
}

void MainWindow::loadPages()
{
    for(int i=1; i<=604; i++) {
        QListWidgetItem *item = new QListWidgetItem("Page " + QString::number(i));
        item->setData(Qt::UserRole, i);
        pageList->addItem(item);
    }
}

void MainWindow::onPageSelected()
{
    QListWidgetItem *item = pageList->currentItem();
    if (!item) return;
    int page = item->data(Qt::UserRole).toInt();
    QPixmap pixmap("../pages/page" + QString::number(page) + ".webp");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        statusLabel->setText("Page " + QString::number(page));
    } else {
        statusLabel->setText("Image not found for page " + QString::number(page));
    }
}

// In onReplyFinished, need to handle ayahs
// But since same signal, need to differentiate
// For simplicity, assume after surahs loaded, next reply is ayahs

// Actually, better to have separate manager or flag

// Let's add a flag

// In header, add bool loadingSurahs = true;

// In loadSurahs, loadingSurahs = true;

// In onReplyFinished: