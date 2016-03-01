//
//  PointConvertCtrl.cpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#include "PointConvertCtrl.hpp"
#define kStepSize 80

PointConvertCtrl* PointConvertCtrl::s_sharedPointCtrl = nullptr;

PointConvertCtrl* PointConvertCtrl::getInstance()
{
    if (s_sharedPointCtrl == nullptr)
    {
        s_sharedPointCtrl = new (std::nothrow) PointConvertCtrl();
        if(!s_sharedPointCtrl->init())
        {
            delete s_sharedPointCtrl;
            s_sharedPointCtrl = nullptr;
            CCLOG("ERROR: Could not init PointConvertCtrl");
        }
    }
    return s_sharedPointCtrl;
}


void PointConvertCtrl::destroyInstance()
{
    CC_SAFE_DELETE(s_sharedPointCtrl);
}

PointConvertCtrl::PointConvertCtrl(){
    
}


PointConvertCtrl::~PointConvertCtrl(){
    
}

bool PointConvertCtrl::init()
{
    return true;
}


Point PointConvertCtrl::convertFakePoint(Point point){
    Point realPoint=Point(point.x*kStepSize+kStepSize/2,point.y*kStepSize+kStepSize/2);
    return realPoint;
}
