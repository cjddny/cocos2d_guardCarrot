//
//  MonsterSprite.cpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#include "MonsterSprite.hpp"
USING_NS_CC;

MonsterSprite::MonsterSprite(){
    
}

MonsterSprite::~MonsterSprite(){
    
}

MonsterSprite* MonsterSprite::createWithSF(SpriteFrame *spriteFrame){
    MonsterSprite*sprite = new MonsterSprite();
    if(sprite
       && sprite->initWithSpriteFrame(spriteFrame))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

void MonsterSprite::move(){
    auto animation=Animation::create();
    __String *anStr1=_actionName.clone();
    __String *anStr2=_actionName.clone();
    anStr1->append("1.png");
    anStr2->append("2.png");
    SpriteFrame *spf1=SpriteFrameCache::getInstance()->getSpriteFrameByName(anStr1->getCString());
    SpriteFrame *spf2=SpriteFrameCache::getInstance()->getSpriteFrameByName(anStr2->getCString());

    animation->addSpriteFrame(spf1);
    animation->addSpriteFrame(spf2);
    animation->setDelayPerUnit(0.5f);
    animation->setRestoreOriginalFrame(true);
    
    auto moveAc= Animate::create(animation);
    
    moveAction=Repeat::create(moveAc, 100);
    this->runAction(moveAction);

}

void MonsterSprite::stop(){
    this->stopAllActions();
}

void setAnimation(__String *oneAnimation,__String *twoAnimation){

}

