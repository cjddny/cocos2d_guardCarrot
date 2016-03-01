//
//  GameMapLayer.cpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/26.
//
//

#include "GameMapLayer.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MonsterManager.hpp"
#include "PointConvertCtrl.hpp"

USING_NS_CC;
using namespace ui;

using namespace cocostudio::timeline;

// on "init" you need to initialize your instance
bool GameMapLayer::init()
{
    /**  you can create scene with following comment code instead of using csb file.
     // 1. super init first
     if ( !Layer::init() )
     {
     return false;
     }
     
     Size visibleSize = Director::getInstance()->getVisibleSize();
     Vec2 origin = Director::getInstance()->getVisibleOrigin();
     
     /////////////////////////////
     // 2. add a menu item with "X" image, which is clicked to quit the program
     //    you may modify it.
     
     // add a "close" icon to exit the progress. it's an autorelease object
     auto closeItem = MenuItemImage::create(
     "CloseNormal.png",
     "CloseSelected.png",
     CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
     
     closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
     origin.y + closeItem->getContentSize().height/2));
     
     // create menu, it's an autorelease object
     auto menu = Menu::create(closeItem, NULL);
     menu->setPosition(Vec2::ZERO);
     this->addChild(menu, 1);
     
     /////////////////////////////
     // 3. add your codes below...
     
     // add a label shows "Hello World"
     // create and initialize a label
     
     auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
     
     // position the label on the center of the screen
     label->setPosition(Vec2(origin.x + visibleSize.width/2,
     origin.y + visibleSize.height - label->getContentSize().height));
     
     // add the label as a child to this layer
     this->addChild(label, 1);
     
     // add "HelloWorld" splash screen"
     auto sprite = Sprite::create("HelloWorld.png");
     
     // position the sprite on the center of the screen
     sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     // add the sprite as a child to this layer
     this->addChild(sprite, 0);
     **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    contentV=ScrollView::create();
//    contentV->setContentSize(visibleSize);
//    contentV->setInnerContainerSize(Size(2048,2048));
//    addChild(contentV);
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    auto bgMap=Sprite::create("Resource/Theme6/bottom_num_hd.png");
////    auto bgMap=Sprite::create("HelloWorld.png");
//    bgMap->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
//    addChild(bgMap);

    
    return true;
}

//加载地图
void GameMapLayer::loadMap(int themeNum,int stageNum){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto bgMap=Sprite::create("Resource/Theme6/BG0/BG1-hd.png",Rect(0, 0, visibleSize.width, visibleSize.height));
    bgMap->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

    __Dictionary *pDictionary=(CCDictionary*)CCDictionary::createWithContentsOfFile("Resource/Theme6/BG6/route.plist");
    __String *offStr=(__String*)pDictionary->objectForKey("offset");
    __Array *roadArr=(__Array*)pDictionary->objectForKey("road");
    
    float contentH=480;
    float offset=offStr->floatValue();
    auto contentMap=Sprite::create("Resource/Theme6/BG6/BG-hd.png",Rect(0, 0, visibleSize.width, contentH+offset));
    contentMap->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-offset));
    
    bgMap->addChild(contentMap);
    addChild(bgMap);
    
    loadMonster(roadArr);
}

//加载怪
void GameMapLayer::loadMonster(__Array* monsterArr){
    MonsterManager::getInstance()->loadRoute(monsterArr);
    
    Point fakeP=MonsterManager::getInstance()->getStartPoint();
    Point realP=PointConvertCtrl::getInstance()->convertFakePoint(fakeP);
    log("x:%f,y:%f",realP.x,realP.y);
    
    Sprite *tempS=MonsterManager::getInstance()->getMonster();
    tempS->setPosition(realP);
    addChild(tempS);

    MonsterManager::getInstance()->startGo();
}


