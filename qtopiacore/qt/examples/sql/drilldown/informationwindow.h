/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the example classes of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef INFORMATIONWINDOW_H
#define INFORMATIONWINDOW_H

#include <QtGui>
#include <QtSql>

//! [0]
class InformationWindow : public QDialog
{
    Q_OBJECT

public:
    InformationWindow(int id, QSqlRelationalTableModel *offices,
                      QWidget *parent = 0);

    int id();

signals:
    void imageChanged(int id, const QString &fileName);
//! [0]

//! [1]
private slots:
    void revert();
    void submit();
    void enableButtons(bool enable = true);
//! [1]

//! [2]
private:
    void createButtons();

    int locationId;
    QString displayedImage;

    QComboBox *imageFileEditor;
    QLabel *locationText;
    QLabel *countryText;
    QTextEdit *descriptionEditor;

    QPushButton *closeButton;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QDialogButtonBox *buttonBox;

    QDataWidgetMapper *mapper;
};
//! [2]

#endif