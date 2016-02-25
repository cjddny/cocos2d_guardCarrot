//
//  MissonScene.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/25.
//
//

#ifndef MissonScene_hpp
#define MissonScene_hpp

#include <stdio.h>
#include "ui/CocosGUI.h"

class MissonScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MissonScene);
    
protected:
    
private:
private:
    void backHome(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void helpAction(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif /* MissonScene_hpp */
