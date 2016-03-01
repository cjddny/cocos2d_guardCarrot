//
//  PointConvertCtrl.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#ifndef PointConvertCtrl_hpp
#define PointConvertCtrl_hpp

#include <stdio.h>

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class PointConvertCtrl
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    ~PointConvertCtrl();
    PointConvertCtrl();
    
    /**
     *  Gets the instance of FileUtils.
     */
    static PointConvertCtrl* getInstance();
    /**
     *  Destroys the instance of FileUtils.
     */
    static void destroyInstance();
    
    Point convertFakePoint(Point point);
    
protected:
    static PointConvertCtrl* s_sharedPointCtrl;
};




#endif /* PointConvertCtrl_hpp */
