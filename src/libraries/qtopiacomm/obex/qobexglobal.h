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
#ifndef __QOBEXGLOBAL_H__
#define __QOBEXGLOBAL_H__


#include <qglobal.h>
#include <qplugin.h>

#ifdef QTOPIA_OBEX
#   include <qtopiaglobal.h>
#else
#   ifndef QTOPIA_AUTOTEST_EXPORT
#       define QTOPIA_AUTOTEST_EXPORT
#   endif
#endif


#if defined(QT_VISIBILITY_AVAILABLE)
#   define QTOPIAOBEX_EXPORT __attribute__((visibility("default")))
#else
#   define QTOPIAOBEX_EXPORT
#endif


#endif
