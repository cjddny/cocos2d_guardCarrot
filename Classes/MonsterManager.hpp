//
//  MonsterManager.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#ifndef MonsterManager_hpp
#define MonsterManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "MonsterSprite.hpp"

USING_NS_CC;
class MonsterManager
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    ~MonsterManager();
    MonsterManager();
    
    /**
     *  Gets the instance of FileUtils.
     */
    static MonsterManager* getInstance();
    /**
     *  Destroys the instance of FileUtils.
     */
    static void destroyInstance();

    void loadRoute(__Array* mapArr);
    
    CC_SYNTHESIZE(MonsterSprite*,_monster,Monster);
    
    Point getStartPoint();
    void startGo();
    void endGo();
protected:
    static MonsterManager* s_sharedMonsterManager;
private:
    __Array *_mapArr;
    void loadMonster();
};


#endif /* MonsterManager_hpp */
