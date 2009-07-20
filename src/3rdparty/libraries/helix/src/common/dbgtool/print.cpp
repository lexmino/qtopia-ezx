/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: print.cpp,v 1.5 2008/01/18 04:12:08 vkathuria Exp $
 * 
 * Portions Copyright (c) 1995-2004 RealNetworks, Inc. All Rights Reserved.
 * 
 * The contents of this file, and the files included with this file,
 * are subject to the current version of the RealNetworks Public
 * Source License (the "RPSL") available at
 * http://www.helixcommunity.org/content/rpsl unless you have licensed
 * the file under the current version of the RealNetworks Community
 * Source License (the "RCSL") available at
 * http://www.helixcommunity.org/content/rcsl, in which case the RCSL
 * will apply. You may also obtain the license terms directly from
 * RealNetworks.  You may not use this file except in compliance with
 * the RPSL or, if you have a valid RCSL with RealNetworks applicable
 * to this file, the RCSL.  Please see the applicable RPSL or RCSL for
 * the rights, obligations and limitations governing use of the
 * contents of the file.
 * 
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 (the
 * "GPL") in which case the provisions of the GPL are applicable
 * instead of those above. If you wish to allow use of your version of
 * this file only under the terms of the GPL, and not to allow others
 * to use your version of this file under the terms of either the RPSL
 * or RCSL, indicate your decision by deleting the provisions above
 * and replace them with the notice and other provisions required by
 * the GPL. If you do not delete the provisions above, a recipient may
 * use your version of this file under the terms of any one of the
 * RPSL, the RCSL or the GPL.
 * 
 * This file is part of the Helix DNA Technology. RealNetworks is the
 * developer of the Original Code and owns the copyrights in the
 * portions it created.
 * 
 * This file, and the files included with this file, is distributed
 * and made available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS
 * ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
 * 
 * Technology Compatibility Kit Test Suite(s) Location:
 *    http://www.helixcommunity.org/content/tck
 * 
 * Contributor(s):
 * 
 * ***** END LICENSE BLOCK ***** */

#ifdef _BREW

#ifdef AEE_SIMULATOR
#define _WIN32
#endif

#include "AEEStdlib.h"
#include "hlxclib/stdio.h"

#ifdef AEE_SIMULATOR
#undef _WIN32
#endif

#else //_BREW
#include <stdarg.h>
#include <stdio.h>
#endif
#include "print.h"
#ifdef WIN32_PLATFORM_PSPC
#include "hlxosstr.h"
#include <winbase.h>
#endif

int print2stdout(const char* pFmt, ...)
{
    va_list args;
    
    va_start(args, pFmt);

#ifdef WIN32_PLATFORM_PSPC
    char szMessage[512];
    int ret = vsprintf(szMessage, pFmt, args);
    OutputDebugString(OS_STRING(szMessage));
#else
    int ret = vfprintf(stdout, pFmt, args);
#endif

    va_end(args);

    return ret;
}

int print2stderr(const char* pFmt, ...)
{
    va_list args;
    
    va_start(args, pFmt);

#ifdef WIN32_PLATFORM_PSPC
    char szMessage[512];
    int ret = vsprintf(szMessage, pFmt, args);
    OutputDebugString(OS_STRING(szMessage));
#else
    int ret = vfprintf(stderr, pFmt, args);
#endif

    va_end(args);

    return ret;
}