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

#ifndef __DESKTOP_AUDIO_PLUGIN_H__
#define __DESKTOP_AUDIO_PLUGIN_H__

#include <QAudioStatePlugin>

class DesktopAudioPluginPrivate;

class DesktopAudioPlugin : public QAudioStatePlugin
{
    Q_OBJECT

public:
    explicit DesktopAudioPlugin(QObject *parent = 0);
    ~DesktopAudioPlugin();

    virtual QList<QAudioState *> statesProvided() const;

private:
    DesktopAudioPluginPrivate *m_data;
};

#endif
