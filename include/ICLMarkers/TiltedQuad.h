/********************************************************************
**                Image Component Library (ICL)                    **
**                                                                 **
** Copyright (C) 2006-2012 CITEC, University of Bielefeld          **
**                         Neuroinformatics Group                  **
** Website: www.iclcv.org and                                      **
**          http://opensource.cit-ec.de/projects/icl               **
**                                                                 **
** File   : include/ICLMarkers/TiltedQuad.h                        **
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
** The development of this software was supported by the           **
** Excellence Cluster EXC 277 Cognitive Interaction Technology.    **
** The Excellence Cluster EXC 277 is a grant of the Deutsche       **
** Forschungsgemeinschaft (DFG) in the context of the German       **
** Excellence Initiative.                                          **
**                                                                 **
*********************************************************************/

#pragma once

#include <ICLUtils/Point32f.h>
#include <ICLBlob/ImageRegion.h>
#include <algorithm>

namespace icl{
  

  /// Utility class that represents a tilted quad in an image
  /** A tilted quad is represented by It's for corner points
      The class provides access to these points using the index
      operator
  */
  class TiltedQuad{
    
    /// list of points (usually sorted in clock-wise order)
    Point32f ps[4];
    
    /// associated image region
    ImageRegion region;

    public:

    /// creates a null-instance
    inline TiltedQuad():region(0){}
    
    /// creates a TiltedQuad instance with given 4 corners and given ImageRegion
    inline TiltedQuad(const Point32f &a, const Point32f &b, 
                      const Point32f &c, const Point32f &d, 
                      const ImageRegion r): region(r){
      ps[0]=a; ps[1]=b; ps[2]=c; ps[3]=d; 
    }
    
    /// creates a TiltedQuad instance with given 4D array of points and image region
    inline TiltedQuad(const Point32f *ps, ImageRegion r): region(r){
      std::copy(ps,ps+4,this->ps);
    }
      
    /// accesses the i-th corner point
    inline Point32f &operator[](int i){ return ps[i]; }
      
    /// accesses the i-th corner point (const)
    inline const Point32f &operator[](int i) const{ return ps[i]; }
    
    /// returns the associated image region (always const)
    ImageRegion getRegion() const { return region; }
    
    /// sets the image region (this is usually not used explicitly)
    void setRegion(ImageRegion region){ this->region = region; }
    
    /// returns whether the image region had been set before
    operator bool() const { return region; }
    
    /// returns the internal Point-data pointer
    const Point32f *data() const { return ps; }
  };
}


