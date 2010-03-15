/********************************************************************
**                Image Component Library (ICL)                    **
**                                                                 **
** Copyright (C) 2006-2010 Neuroinformatics, CITEC                 **
**                         University of Bielefeld                 **
**                Contact: nivision@techfak.uni-bielefeld.de       **
**                Website: www.iclcv.org                           **
**                                                                 **
** File   : include/ICLQt/FloatHandle.h                            **
** Module : ICLQt                                                  **
** Authors: Christof Elbrechter                                    **
**                                                                 **
**                                                                 **
** Commercial License                                              **
** ICL can be used commercially, please refer to our website       **
** www.iclcv.org for more details.                                 **
**                                                                 **
** GNU General Public License Usage                                **
** Alternatively, this file may be used under the terms of the     **
** GNU General Public License version 3.0 as published by the      **
** Free Software Foundation and appearing in the file LICENSE.GPL  **
** included in the packaging of this file.  Please review the      **
** following information to ensure the GNU General Public License  **
** version 3.0 requirements will be met:                           **
** http://www.gnu.org/copyleft/gpl.html.                           **
**                                                                 **
*********************************************************************/

#ifndef ICL_FLOAT_HANDLE_H
#define ICL_FLOAT_HANDLE_H

#include <ICLQt/GUIHandle.h>
/** \cond */
class QLineEdit;
/** \endcond */

namespace icl{
  
  /// Class for handling "float" textfield components \ingroup HANDLES
  class FloatHandle : public GUIHandle<QLineEdit> {
    public:
    
    /// Create an empty handle
    FloatHandle(){}
    
    /// Create a new FloatHandel
    FloatHandle(QLineEdit *le, GUIWidget *w):GUIHandle<QLineEdit>(le,w){}
    
    /// make the associated text field show a float
    void operator=(float f);
    
    /// returns the current text as float
    float getValue() const;
  };
}

#endif
