//
//  GameMapLayer.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#ifndef GameMapLayer_hpp
#define GameMapLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class GameMapLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMapLayer);
    
    //加载地图
    void loadMap(int themeNum,int stageNum);
protected:
    
private:
    cocos2d::ui::ScrollView *contentV;
    
    void loadMonster(cocos2d::__Array* monsterArr);
};


#endif /* GameMapLayer_hpp */
