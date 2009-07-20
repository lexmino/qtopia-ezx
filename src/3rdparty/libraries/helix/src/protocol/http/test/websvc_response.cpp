/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: websvc_response.cpp,v 1.4 2007/07/13 17:56:04 gwright Exp $
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

#include "websvc_response.h"
#include "websvc_test.h"
#include "hxbuffer.h"


HLXHttpTestResponse::HLXHttpTestResponse(HLXWebServicesTest* pTest,
                                         const char*         szPostBody)
{
    m_pTest = pTest;
    m_strPostBody = szPostBody;
}

HLXHttpTestResponse::~HLXHttpTestResponse()
{
}

BEGIN_INTERFACE_LIST_NOCREATE(HLXHttpTestResponse)
    INTERFACE_LIST_ENTRY(IID_IHXHttpResponse, IHXHttpResponse)
    INTERFACE_LIST_ENTRY(IID_IHXHttpResponse2, IHXHttpResponse2)
END_INTERFACE_LIST

STDMETHODIMP
HLXHttpTestResponse::OnHeaders (IHXValues* pHeaders)
{
    return HXR_OK;
}

STDMETHODIMP
HLXHttpTestResponse::OnDataReceived(IHXBuffer* pBuffer)
{
    UINT32 nLen = pBuffer->GetSize();
    const char* pData = (const char*)pBuffer->GetBuffer();

    // XXXRGG: ideally be more efficient here...
    m_strResponseBody += CHXString(pData, nLen);

    return HXR_OK;
}

STDMETHODIMP
HLXHttpTestResponse::OnGetDone(HXBOOL bSuccess)
{
    m_pTest->m_bTestCompleted = true;
    
    return HXR_OK;
}

STDMETHODIMP
HLXHttpTestResponse::GetPostData(REF(IHXBuffer*) pBuffer)
{
    UINT32 nLength;
    UCHAR* pData;
    HX_RESULT res = HXR_OK;
    CHXBuffer* pBufferObj = new CHXBuffer;
    
    res = pBufferObj->QueryInterface(IID_IHXBuffer,
                                     (void**)&pBuffer);
    if(SUCCEEDED(res))
    {
        nLength = m_strPostBody.GetLength();
        pData = (UCHAR*) m_strPostBody.GetBuffer(nLength);
    
        pBuffer->SetSize(nLength);
        pBuffer->Set(pData, nLength);
    }
    
    return res;
}

STDMETHODIMP
HLXHttpTestResponse::InitPost(void)
{
    return HXR_OK;
}

STDMETHODIMP
HLXHttpTestResponse::SetDataType(UINT16 nDataType)
{
    return HXR_OK;
}

STDMETHODIMP
HLXHttpTestResponse::SetHeaders(IHXValues* pHeaders)
{
    return HXR_OK;
}

const char*
HLXHttpTestResponse::GetResponseBody(void)
{
    return (const char*) m_strResponseBody;
}