/* ***** BEGIN LICENSE BLOCK *****  
 * Source last modified: $Id: allowance_mgr.h,v 1.6 2005/04/26 03:55:13 jc Exp $ 
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

#ifndef _ALLOWANCE_MGR_H_
#define _ALLOWANCE_MGR_H_

#include "hxcom.h"
#include "hxauth.h"
#include "hxallow.h"
#include "proc.h"

class AllowanceMgr : public IHXPlayerConnectionAdviseSink,
                     public IHXPlayerConnectionResponse
{
public:
    STDMETHOD        (QueryInterface)    (THIS_ REFIID riid, void** ppvObj) PURE;
    STDMETHOD_        (ULONG32, AddRef)   (THIS) PURE;
    STDMETHOD_        (ULONG32, Release)  (THIS) PURE;
    STDMETHOD        (AllowanceMgrDone)  (THIS) PURE;

    AllowanceMgr(Process* pProc, 
                 IHXPlayerConnectionAdviseSink* pPCAdviseSink);


    // *** IHXPlayerConnectionAdviseSink methods *** //

    STDMETHOD (OnConnection)            (THIS_ IHXPlayerConnectionResponse* pResponse) PURE;
    STDMETHOD (SetPlayerController) (THIS_ IHXPlayerController* pPlayerController) PURE;
    STDMETHOD (SetRegistryID)       (THIS_ UINT32 ulPlayerRegistryID) PURE;
    STDMETHOD (OnURL)                    (THIS_ IHXRequest* pRequest) PURE;
    STDMETHOD (OnBegin)                    (THIS) PURE;
    STDMETHOD (OnPause)                    (THIS) PURE;
    STDMETHOD (OnStop)                    (THIS) PURE;
    STDMETHOD (OnDone)                    (THIS) PURE;

    void      SetMidBox                (BOOL bIsMidBox);
    BOOL      IsPlaybackAllowed        ();
    BOOL      IsActive () { return m_bIsActive; }
    void      SetIsActive(BOOL bactive) { m_bIsActive = bactive; }

    STDMETHOD (OnConnectionDone)    (THIS_ HX_RESULT status) PURE;
    STDMETHOD (OnURLDone)            (THIS_ HX_RESULT status) PURE;
    STDMETHOD (OnBeginDone)            (THIS_ HX_RESULT status) PURE;
    STDMETHOD (OnStopDone)            (THIS_ HX_RESULT status) PURE;
    STDMETHOD (OnPauseDone)            (THIS_ HX_RESULT status) PURE;

    // added as part of Startup Optimization work
    STDMETHOD_ (void, PrintDebugInfo)  (THIS_) PURE;
    STDMETHOD_ (BOOL, AcceptMountPoint)  (THIS_ const char* pszMountPoint,
                                                INT32 uLen) PURE;

protected:
    virtual ~AllowanceMgr() {};

    LONG32                          m_lRefCount;
    Process*                        m_pProc;
    IHXPlayerConnectionAdviseSink*  m_pPCAdviseSink;
    BOOL                            m_bIsMidBox;
    BOOL                            m_bPlaybackAllowed;
    BOOL                            m_bIsActive;
};

#endif // _ALLOWANCE_MGR_H_
