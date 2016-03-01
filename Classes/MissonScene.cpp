//
//  MissonScene.cpp
//  LuoBoGuard
//
//  Created by jwill on 16/2/25.
//
//

#include "MissonScene.hpp"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.hpp"

USING_NS_CC;
using namespace ui;
using namespace cocostudio::timeline;

#define kMissonNum 9

Scene* MissonScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MissonScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MissonScene::init()
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
    
    auto rootNode = CSLoader::createNode("MissonSelect.csb");
    addChild(rootNode);
        
    Button *backBtn=(Button*)rootNode->getChildByName("back_Btn");
    backBtn->addTouchEventListener(CC_CALLBACK_2(MissonScene::backHome,this));
    
    Button *helpBtn=(Button*)rootNode->getChildByName("help_Btn");
    helpBtn->addTouchEventListener(CC_CALLBACK_2(MissonScene::helpAction,this));

    
    //init misson   cache 析构的时候记得释放
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Resource/stages_theme1.plist", "Resource/stages_theme1.png");
    for (int i=0; i<kMissonNum; i++) {
        char missonName[20];
        sprintf(missonName, "ss_map0%d.png",i+1);
        log("cur misson :%s",missonName);
        SpriteFrame *spf=SpriteFrameCache::getInstance()->getSpriteFrameByName(missonName);
        auto missonSprite=Sprite::createWithSpriteFrame(spf);
        spriteVec.pushBack(missonSprite);
    }
    
    missonSelect=PageView::create();
    missonSelect->removeAllPages(); //清除所有页
    missonSelect->setContentSize(Size(506,334));
    missonSelect->setAnchorPoint(Vec2(0.5, 0.5));
    missonSelect->setPosition(Vec2(960/2,640/2));
    missonSelect->setClippingEnabled(false);
//    missonSelect->setTouchEnabled(true);
//    missonSelect->setSwallowTouches(false);
//    missonSelect->setIndicatorEnabled(true);

    int i=0;
    for (auto missonSprite : spriteVec) {
        i++;
        Layout *wp=Layout::create();
        missonSprite->setAnchorPoint(Vec2(0, 0));
        wp->addChild(missonSprite);
        Size size=Size(506, 334);
        wp->setContentSize(size);
        wp->setTag(1000+i);
        missonSelect->addPage(wp);
//        wp->setPropagateTouchEvents(true);
//        wp->addTouchEventListener(CC_CALLBACK_2(MissonScene::itemEvent, this));
    }
    
    this->addChild(missonSelect);
    missonSelect->addEventListener(CC_CALLBACK_2(MissonScene::pageViewEvt, this));
//    missonSelect->addEventListenerPageView(this, pagevieweventselector(MissonScene::pageViewEvent));
    missonSelect->addTouchEventListener(CC_CALLBACK_2(MissonScene::pageEvent, this));
    
    return true;
}


void MissonScene::backHome(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
    switch (type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
        {
            log("touch began");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::MOVED:
        {
            log("touch moved");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::ENDED:
        {
            log("back home");
            Director::getInstance()->popScene();
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
        {
            log("touch canceled");
            break;
        }
        default:
            break;
    }
}

void MissonScene::helpAction(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
    switch (type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
        {
            log("touch began");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::MOVED:
        {
            log("touch moved");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::ENDED:
        {
            log("help home");
            missonSelect->scrollToPage(3);
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
        {
            log("touch canceled");
            break;
        }
        default:
            break;
    }
}

void MissonScene::pageEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
    switch (type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
        {
            log("touch began");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::MOVED:
        {
            log("touch moved");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::ENDED:
        {
            
            log("choose one: misson %zd",missonSelect->getCurrentPageIndex());
            auto mainGame=GameScene::createScene(1,missonSelect->getCurrentPageIndex());
            Director::getInstance()->pushScene(mainGame);
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
        {
            log("touch canceled");
            break;
        }
        default:
            break;
    }
}


void MissonScene::itemEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
    switch (type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
        {
            log("touch began");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::MOVED:
        {
            log("touch moved");
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::ENDED:
        {
            
            log("choose one: misson %zd",missonSelect->getCurrentPageIndex());
            auto mainGame=GameScene::createScene(1,missonSelect->getCurrentPageIndex());
            Director::getInstance()->pushScene(mainGame);
            break;
        }
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
        {
            log("touch canceled");
            break;
        }
        default:
            break;
    }
}


void MissonScene::pageViewEvt(Ref *pSender, PageView::EventType type)
{
    log("scroll");
    switch (type)
    {
        case PageView::EventType::TURNING:
        {
        }
    }
}


