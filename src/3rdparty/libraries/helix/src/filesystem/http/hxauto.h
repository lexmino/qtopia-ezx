/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: hxauto.h,v 1.3 2007/07/06 20:48:08 jfinnecy Exp $
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

#ifndef _HXAUTO_H_
#define _HXAUTO_H_

/*
 * Forward declarations of some interfaces defined herein.
 */
typedef _INTERFACE  IHXHTTPAutoStream IHXHTTPAutoStream;
typedef _INTERFACE  IHXFileAutoStream IHXFileAutoStream;


/****************************************************************************
 * 
 *  Interface:
 * 
 *	IHXHTTPAutoStream
 * 
 *  Purpose:
 * 
 *	Provides routines for configuring file save after a download.
 * 
 *  IID_IHXHTTPAutoStream:
 *  	{60B68AF1-09F0-11d3-8B57-00902742C8A7}
 *	
 * 
 */

DEFINE_GUID(IID_IHXHTTPAutoStream, 0x60b68af1, 0x9f0, 0x11d3, 0x8b, 0x57, 0x0, 0x90, 0x27, 0x42, 0xc8, 0xa7);


#undef  INTERFACE
#define INTERFACE   IHXHTTPAutoStream

DECLARE_INTERFACE(IHXHTTPAutoStream)
{
    STDMETHOD(QueryInterface )( REFIID riid, void** ppvObj ) PURE;
    STDMETHOD_( ULONG32,AddRef )() PURE;
    STDMETHOD_( ULONG32,Release )() PURE;

    /************************************************************************
     *	Method:
     *	    IHXAutoStream::SetDestinationFile
     *
     *	Purpose:
     *		Sets the destination file for the next HTTPFileObject that
     *		is instantiated.
     *
     */
    STDMETHOD_( void, SetDestinationFile) ( THIS_ const char *pFilename ) PURE;

};




/****************************************************************************
 * 
 *  Interface:
 * 
 *	IHXHTTPAutoStream
 * 
 *  Purpose:
 * 
 *	Configures a file object to save itself to persistent store
 * 
 *  IID_IHXHTTPAutoStream:
 *  	{E3594C61-0B5D-11d3-8B57-00902742C8A7}
 *	
 * 
 */

DEFINE_GUID(IID_IHXFileAutoStream, 0xe3594c61, 0xb5d, 0x11d3, 0x8b, 0x57, 0x0, 0x90, 0x27, 0x42, 0xc8, 0xa7);


#undef  INTERFACE
#define INTERFACE   IHXFileAutoStream

DECLARE_INTERFACE(IHXFileAutoStream)
{
    STDMETHOD(QueryInterface )( REFIID riid, void** ppvObj ) PURE;
    STDMETHOD_( ULONG32,AddRef )() PURE;
    STDMETHOD_( ULONG32,Release )() PURE;

    /************************************************************************
     *	Method:
     *	    IHXFileAutoStream::SetDestinationFile
     *
     *	Purpose:
     *		Sets the destination file for the HTTPFileObject
     *
     */
    STDMETHOD_( void, SetDestinationFile) ( THIS_ const char *pFilename ) PURE;

};



#endif //_HXAUTO_H_