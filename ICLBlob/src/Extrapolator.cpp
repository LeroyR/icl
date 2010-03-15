/********************************************************************
**                Image Component Library (ICL)                    **
**                                                                 **
** Copyright (C) 2006-2010 Neuroinformatics, CITEC                 **
**                         University of Bielefeld                 **
**                Contact: nivision@techfak.uni-bielefeld.de       **
**                Website: www.iclcv.org                           **
**                                                                 **
** File   : ICLBlob/src/Extrapolator.cpp                           **
** Module : ICLBlob                                                **
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

#include <ICLBlob/Extrapolator.h>
#include <stdio.h>
namespace icl{

  //s(t+1) = s(t) + dt v(t) + (dt)²/2 a(t)
  //v(t+1) = v(t) + dt a(t)  empirisch!
  //a(t+1) = a(t)            empirisch!
  
  template<class valueType,class timeType>
  valueType Extrapolator<valueType,timeType>::predict(valueType x2, valueType x1){
    // {{{ open

    return valueType(x1 + x1 - x2);
  }

  // }}}
  
  template<class valueType, class timeType>
  valueType Extrapolator<valueType,timeType>::predict(valueType x3, valueType x2, valueType x1){
    // {{{ open
    valueType v1 = x1-x2;
    valueType a = v1-( x2-x3 );//v1-v2
    //    printf("prediciton for %d %d %d --> %d \n",(int)x3,(int)x2,(int)x1,(int)(x1 + v1 +  a/2.0));
    return valueType(x1 + v1 +  a/2.0);
  }

  // }}}

  template<class valueType, class timeType>
  valueType Extrapolator<valueType,timeType>::predict(valueType x2, timeType t2, valueType x1, timeType t1, timeType t){
    // {{{ open

    timeType dt1 = t1 - t2;
    timeType dt0 = t - t1;
    valueType v1 = (x1-x2)/dt1;
    return valueType(x1 + dt0*v1);
  }

  // }}}
  
  template<class valueType, class timeType>
  valueType Extrapolator<valueType,timeType>::predict(valueType x3, timeType t3, valueType x2, timeType t2, valueType x1, timeType t1, timeType t){
    // {{{ open

    timeType dt2 = t2 - t3;
    timeType dt1 = t1 - t2;
    timeType dt0 = t - t1;
    valueType v2 = (x2-x3)/dt2;  
    valueType v1 = (x1-x2)/dt1;
    valueType a = (v1-v2)/((dt1+dt2)/2);
    return valueType(x1 + dt0*v1 + (dt0*dt0)/2.0 * a);
 
  }

  // }}}
  
  template<class valueType, class timeType>
  valueType Extrapolator<valueType,timeType>::predict(int n, valueType *xs, timeType *ts, timeType t){
    // {{{ opem
    if(n == 0) return 0;
    if(n == 1) return *xs;
    if(ts){
      if(n == 2){
        return predict(xs[0],ts[0],xs[1],ts[1],t);
      }else{  // 3
        return predict(xs[0],ts[0],xs[1],ts[1],xs[2],ts[2],t);
      }
    }else{
      if(n == 2){
        return predict(xs[0],xs[1]);
      }else{
        return predict(xs[0],xs[1],xs[2]);
      }
    }
  } 

  // }}}

  template class Extrapolator<icl32s,int>;
  template class Extrapolator<icl32f,long int>;
  template class Extrapolator<icl32f,int>;
  template class Extrapolator<icl32f,icl32f>;
  template class Extrapolator<icl64f,long int>;
  template class Extrapolator<icl64f,int>;
  template class Extrapolator<icl64f,icl32f>;
}
