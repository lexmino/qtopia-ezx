/* ***** BEGIN LICENSE BLOCK *****  
 * Source last modified: $Id: imutex.h,v 1.4 2005/06/10 22:34:01 darrick Exp $ 
 *   
 * Portions Copyright (c) 1995-2003 RealNetworks, Inc. All Rights Reserved.  
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
/*
 *  Non-reentrant mutexes for various server platforms.
 */

#ifndef _IMUTEX_H_
#define _IMUTEX_H_

#include "hxtypes.h"
#include "hxcom.h"
#include "hxengin.h"
#include "mutex.h"

/***********************************************************************
 * IHX interface that wraps a mutex
 *
 */
class Mutex : public IHXMutex
{
public:
    Mutex();
    ~Mutex();

    STDMETHOD(QueryInterface)   (THIS_
				REFIID riid,
				void** ppvObj);
    STDMETHOD_(ULONG32,AddRef)  (THIS);
    STDMETHOD_(ULONG32,Release) (THIS);

    STDMETHOD(Lock)         (THIS);
    STDMETHOD(TryLock)      (THIS);
    STDMETHOD(Unlock)       (THIS);

private:
    ULONG32		m_ulRefCount;
    HX_MUTEX	m_Mutex;
};

#endif /* _IMUTEX_H_ */
