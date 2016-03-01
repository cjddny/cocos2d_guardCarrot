//
//  MonsterManager.cpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#include "MonsterManager.hpp"
#include "PointConvertCtrl.hpp"

MonsterManager* MonsterManager::s_sharedMonsterManager = nullptr;

MonsterManager* MonsterManager::getInstance()
{
    if (s_sharedMonsterManager == nullptr)
    {
        s_sharedMonsterManager = new (std::nothrow) MonsterManager();
        if(!s_sharedMonsterManager->init())
        {
            delete s_sharedMonsterManager;
            s_sharedMonsterManager = nullptr;
            CCLOG("ERROR: Could not init MonsterManager");
        }
    }
    return s_sharedMonsterManager;
}


void MonsterManager::destroyInstance()
{
    CC_SAFE_DELETE(s_sharedMonsterManager);
}

MonsterManager::MonsterManager(){
    loadMonster();
}


MonsterManager::~MonsterManager(){
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
}

bool MonsterManager::init()
{
    return true;
}


void MonsterManager::loadRoute(__Array* mapArr){
    _mapArr=mapArr;
    _mapArr->retain();
}

void MonsterManager::loadMonster(){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Resource/Monsters01.plist", "Resource/Monsters01.png");
    char missonName[20];
    int randomI=1+floor(rand_0_1()*2);
    sprintf(missonName,"land_nima0%d.png",randomI);
    SpriteFrame *spf=SpriteFrameCache::getInstance()->getSpriteFrameByName(missonName);
    _monster=MonsterSprite::createWithSF(spf);
    _monster->setActionName("land_nima0");
    _monster->setCurPointId(0);
}


Point MonsterManager::getStartPoint(){
    __String *firstPS=(__String*)_mapArr->getObjectAtIndex(0);
    Point firstP=PointFromString(firstPS->getCString());
    return firstP;
}


void MonsterManager::startGo(){
    long mapCount=_mapArr->count()-1;
    if (_monster->getCurPointId()<mapCount) {
        _monster->move();
        int nextId=_monster->getCurPointId()+1;
        __String *pointStr=(__String*)_mapArr->getObjectAtIndex(nextId);
        Point nextP_fake=PointFromString(pointStr->getCString());
        Point nextp_real=PointConvertCtrl::getInstance()->convertFakePoint(nextP_fake);
        log("->(%.2f,%.2f)",nextp_real.x,nextp_real.y);
//        auto callFunc = CallFunc::create(this,callfunc_selector(MonsterManager::startGo));
        auto callFunc=CallFunc::create(CC_CALLBACK_0(MonsterManager::startGo, this));
        auto moveTo = MoveTo::create(2, nextp_real);
        auto action = Sequence::create(moveTo,callFunc,NULL);
        _monster->setCurPointId(nextId);
        _monster->runAction(action);
    }else{
        _monster->stop();
        log("arrived");
    }
}

//void MonsterManager::endGo(){
//    log("next");
//    long mapCount=_mapArr->count();
//    if (_monster->getCurPointId()<mapCount) {
//        int nextId=_monster->getCurPointId()+1;
//        __String *pointStr=(__String*)_mapArr->getObjectAtIndex(nextId);
//        Point nextP_fake=PointFromString(pointStr->getCString());
//        Point nextp_real=PointConvertCtrl::getInstance()->convertFakePoint(nextP_fake);
//        //        auto callFunc = CallFunc::create(this,callfunc_selector(MonsterManager::startGo));
//        auto callFunc=CallFunc::create(CC_CALLBACK_0(MonsterManager::endGo, this));
//        auto moveTo = MoveTo::create(2, nextp_real);
//        auto action = Sequence::create(moveTo,callFunc,NULL);
//        _monster->runAction(action);
//    }else{
//        log("arrived");
//    }
//}