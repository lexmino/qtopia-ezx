# 
#  ***** BEGIN LICENSE BLOCK *****  
#   
#  Source last modified: $Id: err.py,v 1.3 2006/04/24 23:34:02 jfinnecy Exp $ 
#   
#  Copyright Notices: 
#   
#  Portions Copyright (c) 1995-2006 RealNetworks, Inc. All Rights Reserved. 
#   
#  Patent Notices: This file may contain technology protected by one or  
#  more of the patents listed at www.helixcommunity.org 
#   
#  1.   The contents of this file, and the files included with this file, 
#  are protected by copyright controlled by RealNetworks and its  
#  licensors, and made available by RealNetworks subject to the current  
#  version of the RealNetworks Public Source License (the "RPSL")  
#  available at  * http://www.helixcommunity.org/content/rpsl unless  
#  you have licensed the file under the current version of the  
#  RealNetworks Community Source License (the "RCSL") available at 
#  http://www.helixcommunity.org/content/rcsl, in which case the RCSL 
#  will apply.  You may also obtain the license terms directly from 
#  RealNetworks.  You may not use this file except in compliance with 
#  the RPSL or, if you have a valid RCSL with RealNetworks applicable 
#  to this file, the RCSL.  Please see the applicable RPSL or RCSL for 
#  the rights, obligations and limitations governing use of the 
#  contents of the file. 
#   
#  2.  Alternatively, the contents of this file may be used under the 
#  terms of the GNU General Public License Version 2 (the 
#  "GPL") in which case the provisions of the GPL are applicable 
#  instead of those above.  Please note that RealNetworks and its  
#  licensors disclaim any implied patent license under the GPL.   
#  If you wish to allow use of your version of this file only under  
#  the terms of the GPL, and not to allow others 
#  to use your version of this file under the terms of either the RPSL 
#  or RCSL, indicate your decision by deleting Paragraph 1 above 
#  and replace them with the notice and other provisions required by 
#  the GPL. If you do not delete Paragraph 1 above, a recipient may 
#  use your version of this file under the terms of any one of the 
#  RPSL, the RCSL or the GPL. 
#   
#  This file is part of the Helix DNA Technology.  RealNetworks is the 
#  developer of the Original Code and owns the copyrights in the 
#  portions it created.   Copying, including reproducing, storing,  
#  adapting or translating, any or all of this material other than  
#  pursuant to the license terms referred to above requires the prior  
#  written consent of RealNetworks and its licensors 
#   
#  This file, and the files included with this file, is distributed 
#  and made available by RealNetworks on an 'AS IS' basis, WITHOUT  
#  WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS  
#  AND ITS LICENSORS HEREBY DISCLAIM  ALL SUCH WARRANTIES, INCLUDING  
#  WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS  
#  FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. 
#   
#  Technology Compatibility Kit Test Suite(s) Location:  
#     http://www.helixcommunity.org/content/tck 
#   
# Contributor(s):
# 
# ***** END LICENSE BLOCK *****
# 
"""Error class for the build system.  This shares a common API with err.py
in the master build server, and the build server because some of the python
modules are shared between them."""

import string
import traceback

error = "Build System Error"

linelength=73

def simple_linebreak(text):
    ret = []
    while text:
        if len(text) < linelength:
            ret.append(text)
            break
        i = string.rfind(text," ",0,linelength)
        if i != -1:
            ret.append(text[:i])
            text=text[i+1:]
        else:
            ret.append(text[:linelength])
            text=text[linelength:]
    return ret

def fancy_linebreak(text):
    ret = []
    for block in string.split(text,"\n"):
        ret.extend(simple_linebreak(block))
    return ret
    

class Error:
    """Generic error class for build system errors.  Catch this for
    standard fatal errors."""
    
    def __init__(self):
        self.text = "Default error text, not much help."
        self.traceback_list = []

    def __str__(self):
        return self.text

    def Set(self, text):
        """Set the error text."""
        self.text = text
            
    def Text(self):
        """Returns the error text."""
        global fancy_linebreak

        list = [
            "--- Build System Error ------------------------------------"]

        list.extend(fancy_linebreak(self.text))

        list.append(
            "-----------------------------------------------------------")

        if self.traceback_list:
            list = list + [
                "--- Python Traceback --------------------------------------",
                ] + self.traceback_list + [
                
                "-----------------------------------------------------------"]

        return string.join(list, "\n") + "\n"

    def SetTraceback(self, einfo):
        """Set the traceback for the error.  It must be invoked with
        sys.exc_info() as its argument to get the traceback in the
        correct stack frame."""
        
        self.traceback_list.append("------------------------------------")
        for line in traceback.format_exception(einfo[0], einfo[1], einfo[2]):
            ## strip out ending newline
            self.traceback_list.append(line[:-1])
            
