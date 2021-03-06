/****************************************************************************
**
** This file is part of the Qtopia Opensource Edition Package.
**
** Copyright (C) 2008 Trolltech ASA.
**
** Contact: Qt Extended Information (info@qtextended.org)
**
** This file may be used under the terms of the GNU General Public License
** versions 2.0 as published by the Free Software Foundation and appearing
** in the file LICENSE.GPL included in the packaging of this file.
**
** Please review the following information to ensure GNU General Public
** Licensing requirements will be met:
**     http://www.fsf.org/licensing/licenses/info/GPLv2.html.
**
**
****************************************************************************/

#ifndef __QTOPIA_MEDIASERVER_QTOPIAMEDIAPROVIDER_H
#define __QTOPIA_MEDIASERVER_QTOPIAMEDIAPROVIDER_H

#include <QString>
#include <QUuid>
#include <QtopiaAbstractService>
#include <QMediaSessionRequest>

namespace mediaserver
{

class SessionManager;

class QtopiaMediaProviderPrivate;

class QtopiaMediaProvider : public QtopiaAbstractService
{
    Q_OBJECT

public:
    QtopiaMediaProvider(SessionManager* sessionManager);
    ~QtopiaMediaProvider();

public slots:
    void createSession(QString const& responseChannel,
                       QMediaSessionRequest const& request);

    void destroySession(QUuid const& id);

private:
    QtopiaMediaProviderPrivate* d;
};

}   // ns mediaserver

#endif  // __QTOPIA_MEDIASERVER_QTOPIAMEDIAPROVIDER_H

