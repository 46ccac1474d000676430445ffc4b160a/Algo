/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openFileButton;
    QPushButton *placeRoundedButton;
    QPushButton *restoreColorsButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *delaySpinBox;
    QRadioButton *deepthTrRadio;
    QRadioButton *widthTrRadio;
    QPushButton *startTraversalButton;
    QTextBrowser *outputField;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(522, 464);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
        splitter->addWidget(graphicsView);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        openFileButton = new QPushButton(frame);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));

        verticalLayout_2->addWidget(openFileButton);

        placeRoundedButton = new QPushButton(frame);
        placeRoundedButton->setObjectName(QStringLiteral("placeRoundedButton"));
        placeRoundedButton->setEnabled(false);

        verticalLayout_2->addWidget(placeRoundedButton);

        restoreColorsButton = new QPushButton(frame);
        restoreColorsButton->setObjectName(QStringLiteral("restoreColorsButton"));
        restoreColorsButton->setEnabled(false);

        verticalLayout_2->addWidget(restoreColorsButton);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        delaySpinBox = new QDoubleSpinBox(groupBox);
        delaySpinBox->setObjectName(QStringLiteral("delaySpinBox"));
        delaySpinBox->setMaximum(10);
        delaySpinBox->setSingleStep(0.25);
        delaySpinBox->setValue(1);

        horizontalLayout_2->addWidget(delaySpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        deepthTrRadio = new QRadioButton(groupBox);
        deepthTrRadio->setObjectName(QStringLiteral("deepthTrRadio"));
        deepthTrRadio->setChecked(true);

        verticalLayout->addWidget(deepthTrRadio);

        widthTrRadio = new QRadioButton(groupBox);
        widthTrRadio->setObjectName(QStringLiteral("widthTrRadio"));

        verticalLayout->addWidget(widthTrRadio);

        startTraversalButton = new QPushButton(groupBox);
        startTraversalButton->setObjectName(QStringLiteral("startTraversalButton"));
        startTraversalButton->setEnabled(false);

        verticalLayout->addWidget(startTraversalButton);


        verticalLayout_2->addWidget(groupBox);

        outputField = new QTextBrowser(frame);
        outputField->setObjectName(QStringLiteral("outputField"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outputField->sizePolicy().hasHeightForWidth());
        outputField->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(outputField);

        splitter->addWidget(frame);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        openFileButton->setText(QApplication::translate("Widget", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        placeRoundedButton->setText(QApplication::translate("Widget", "\320\222\321\213\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\277\320\276 \320\272\321\200\321\203\320\263\321\203", nullptr));
        restoreColorsButton->setText(QApplication::translate("Widget", "\320\222\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\206\320\262\320\265\321\202\320\260", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\320\236\320\261\321\205\320\276\320\264 \320\263\321\200\320\260\321\204\320\260", nullptr));
        label->setText(QApplication::translate("Widget", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260:", nullptr));
        deepthTrRadio->setText(QApplication::translate("Widget", "\320\236\320\261\321\205\320\276\320\264 \320\262 \320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));
        widthTrRadio->setText(QApplication::translate("Widget", "\320\236\320\261\321\205\320\276\320\264 \320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        startTraversalButton->setText(QApplication::translate("Widget", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\276\320\261\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
