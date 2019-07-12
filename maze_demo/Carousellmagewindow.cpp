#include "Carousellmagewindow.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QButtonGroup>
#include "common_value.h"
CarouselImageWindow::CarouselImageWindow(QWidget *parent)
    : QWidget(parent)
    , m_currentDrawImageIndx(0)
{

    this->setProperty("ImageOpacity", 1.0);


    m_opacityAnimation = new QPropertyAnimation(this, "ImageOpacity");

    m_opacityAnimation->setDuration(1500);


    m_opacityAnimation->setStartValue(1.0);
    m_opacityAnimation->setEndValue(0.0);

    connect(m_opacityAnimation, SIGNAL(valueChanged(const QVariant&)), this, SLOT(update()));

    connect(&m_imageChangeTimer, SIGNAL(timeout()), this, SLOT(onImageChangeTimeout()));

    this->setFixedSize(QSize(WINDOW_SIZE, WINDOW_SIZE));

    this->setWindowFlags(Qt::FramelessWindowHint);
}

CarouselImageWindow::~CarouselImageWindow()
{

}

void CarouselImageWindow::initChangeImageButton()
{

    QButtonGroup* changeButtonGroup = new QButtonGroup;
    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addStretch();
    for (int i = 0; i < m_imageFileNameList.count(); i++)
    {
        QPushButton* pButton = new QPushButton;
        pButton->setStyleSheet("border:2px groove gray;"
                               "border-radius:10px;"
                               "padding:2px 4px;");
        pButton->setFixedSize(QSize(16, 16));
        pButton->setCheckable(true);
        pButton->setStyleSheet("QPushButton{border-image:url(:/Resources/select1.png);}\
                                QPushButton:checked{border-image:url(:/Resources/select2.png);}");
        changeButtonGroup->addButton(pButton, i);
        m_pButtonChangeImageList.append(pButton);
        hLayout->addWidget(pButton);
    }
    hLayout->addStretch();
    hLayout->setSpacing(10);
    hLayout->setMargin(0);

    connect(changeButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(onImageSwitchButtonClicked(int)));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(hLayout);
    mainLayout->setContentsMargins(0, 0, 0, 20);
}

void CarouselImageWindow::setImageList(QStringList imageFileNameList)
{
    m_imageFileNameList = imageFileNameList;
}

void CarouselImageWindow::addImage(QString imageFileName)
{
    m_imageFileNameList.append(imageFileName);
}

void CarouselImageWindow::startPlay()
{

    initChangeImageButton();
    if (m_imageFileNameList.count() == 1)
    {
        m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
    }
    else if (m_imageFileNameList.count() > 1)
    {
        m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
        m_currentPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
        m_imageChangeTimer.start(2000);
        update();
    }
}

void CarouselImageWindow::onImageChangeTimeout()
{

    m_currentPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
    m_currentDrawImageIndx++;
    if (m_currentDrawImageIndx >= m_imageFileNameList.count())
    {
        m_currentDrawImageIndx = 0;
    }
    m_nextPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));

    m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);


    m_opacityAnimation->start();
}

void CarouselImageWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect imageRect = this->rect();


    if (m_imageFileNameList.isEmpty())
    {
        QPixmap backPixmap = QPixmap(":/Resources/CarouselImageBack.png");
        painter.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }

    else if (m_imageFileNameList.count() == 1)
    {
        QPixmap backPixmap = QPixmap(m_imageFileNameList.first());
        painter.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }

    else if (m_imageFileNameList.count() > 1)
    {
        float imageOpacity = this->property("ImageOpacity").toFloat();
        painter.setOpacity(1);
        painter.drawPixmap(imageRect, m_nextPixmap.scaled(imageRect.size()));
        painter.setOpacity(imageOpacity);
        painter.drawPixmap(imageRect, m_currentPixmap.scaled(imageRect.size()));
    }
}

void CarouselImageWindow::onImageSwitchButtonClicked(int buttonId)
{
    m_currentDrawImageIndx = buttonId - 1;
    if (m_currentDrawImageIndx == -1)
    {
        m_currentDrawImageIndx = m_imageFileNameList.count() - 1;
    }

    onImageChangeTimeout();
    m_imageChangeTimer.start(2000);
    update();
}

void CarouselImageWindow::mousePressEvent(QMouseEvent* event)
{

    qDebug() << m_currentDrawImageIndx;
    return __super::mousePressEvent(event);
}
