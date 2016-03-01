//
//  GameScene.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameMapLayer.hpp"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(int themeNum,int stageNum);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void loadMap(int themeNum,int stageNum);
    
protected:
    
private:
    GameMapLayer *mapLayer;
};


#endif /* GameScene_hpp */
