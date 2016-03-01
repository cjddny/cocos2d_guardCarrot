//
//  MonsterSprite.hpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#ifndef MonsterSprite_hpp
#define MonsterSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MonsterSprite : public Sprite{
public:
    MonsterSprite();
    ~MonsterSprite();
    static MonsterSprite* createWithSF(SpriteFrame *spriteFrame);
    void move();
    void stop();
//    void moveByPosList(Vector<PosBase*> posList);
    void setAnimation(__String *oneAnimation,__String *twoAnimation);
private:
    CC_SYNTHESIZE(int,_curPointId,CurPointId);
    CC_SYNTHESIZE(int,_curId,CurId);
    CC_SYNTHESIZE(int,_curLife,CurLife);
    CC_SYNTHESIZE(bool,_isAlive,IsAlive);
    CC_SYNTHESIZE(__String,_actionName,ActionName);
//    CC_SYNTHESIZE(float,_showTime,ShowTime);
    
    Repeat *moveAction;
};/**/

#endif /* MonsterSprite_hpp */
