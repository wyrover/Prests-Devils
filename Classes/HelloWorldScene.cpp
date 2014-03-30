#include "HelloWorldScene.h"
#include "proj.win32\MySprite.h"
#include "proj.win32\Boat.h"
#include "proj.win32\ConstantValues.h"
#include "proj.win32\GameOverScene.h"

USING_NS_CC;

int HelloWorld::leftP = 0;
int HelloWorld::leftD = 0;
int HelloWorld::rightP = 3;
int HelloWorld::rightD = 3;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	time = 60.0f;

	this->setTouchEnabled(true);
	leftP = 0;
	leftD = 0;
	rightP = 3;
	rightD = 3;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCMenuItemImage *pHelpItem = CCMenuItemImage::create(
										"/img/help.png",
										"/img/help_selected.png",
										this,
										menu_selector(HelloWorld::helpCallBack));
	pHelpItem->setPosition(ccp(visibleSize.width - 20 + origin.x, visibleSize.height - pHelpItem->getContentSize().height / 2 - 5 + origin.y));

	// create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, pHelpItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);



    /////////////////////////////
    // 3. add your codes below...

	Boat *boat = Boat::create("/img/boat.png");
	boat->setPosition(ccp(visibleSize.width 
		- 200 + origin.x, 60 + origin.y));
	boat->setTag(7);
	this->addChild(boat, 1);
		
	MySprite *prests[3];
	for (int i = 0; i < 3; i++)
	{
		prests[i] = MySprite::create("/img/prests.png");
		prests[i]->setPosition(ccp(visibleSize.width - 130 + i * 25 + origin.x , 105 + origin.y));
		prests[i]->setFlipX(true);
		prests[i]->setTag(i+1);
		this->addChild(prests[i], 1);
	}

	MySprite *devils[3];
	for (int i = 0; i < 3; i++)
	{
		devils[i] = MySprite::create("/img/devils.png");
		devils[i]->setPosition(ccp(visibleSize.width - 60 + i * 25 + origin.x, 105 + origin.y));
		devils[i]->setFlipX(true);
		devils[i]->setTag(i + 4);
		this->addChild(devils[i], 1);
	}

	CCLabelBMFont *lbLife = CCLabelBMFont::create("59", "font09.fnt");
	lbLife->setAnchorPoint(ccp(0, 1));
	lbLife->setScale(0.6f);
	lbLife->setPosition(ccp(visibleSize.width - 70 + origin.x, visibleSize.height - 1 + origin.y));
	this->addChild(lbLife, 1, 15);
	this->schedule(schedule_selector(HelloWorld::timeCallBack), 1.0f);


    // add background image
    CCSprite* pSprite = CCSprite::create("/img/background.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
	this->setTag(0);
    return true;
}

void HelloWorld::timeCallBack(float dt)
{
	time -= dt;
	if (time < 1)
	{
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Lose :[");
		CCDirector::sharedDirector()->replaceScene(gameOverScene); 
	}
	char time_str[20];
	sprintf(time_str, "%d", (int)time);
	CCLabelBMFont *label1 = (CCLabelBMFont *)this->getChildByTag(15);
	label1->setString(time_str);
}


void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}


bool HelloWorld::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
	return true;
}

void HelloWorld::ccTouchMoved(CCTouch *touch, CCEvent *event)
{

}

void HelloWorld::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
}

void HelloWorld::boatCallBack()
{
	if (Boat::boatStatus == Status::left)
	{
		if (Boat::boatLeft != 0)
		{
			if (Boat::boatLeft > 0 && Boat::boatLeft < 4)
			{
				HelloWorld::rightP--;
				HelloWorld::leftP++;
			}
			else if (Boat::boatLeft > 3 && Boat::boatLeft < 7)
			{
				HelloWorld::rightD--;
				HelloWorld::leftD++;
			}
		}
		if (Boat::boatRight != 0)
		{
			if (Boat::boatRight > 0 && Boat::boatRight < 4)
			{
				HelloWorld::rightP--;
				HelloWorld::leftP++;
			}
			else if (Boat::boatRight > 3 && Boat::boatRight < 7)
			{
				HelloWorld::rightD--;
				HelloWorld::leftD++;
			}
		}
	}
	else
	{
		if (Boat::boatLeft != 0)
		{
			if (Boat::boatLeft > 0 && Boat::boatLeft < 4)
			{
				HelloWorld::leftP--;
				HelloWorld::rightP++;
			}
			else if (Boat::boatLeft > 3 && Boat::boatLeft < 7)
			{
				HelloWorld::leftD--;
				HelloWorld::rightD++;
			}
		}
		if (Boat::boatRight != 0)
		{
			if (Boat::boatRight > 0 && Boat::boatRight < 4)
			{
				HelloWorld::leftP--;
				HelloWorld::rightP++;
			}
			else if (Boat::boatRight > 3 && Boat::boatRight < 7)
			{
				HelloWorld::leftD--;
				HelloWorld::rightD++;
			}
		}
	}

	if (leftD != 0 && leftP != 0 && leftD > leftP)
	{
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Lose :[");
		CCDirector::sharedDirector()->replaceScene(gameOverScene);  
	}
	else if (rightP != 0 && rightD != 0 && rightD > rightP)
	{
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Lose :[");
		CCDirector::sharedDirector()->replaceScene(gameOverScene);  
	}
}

void HelloWorld::spriteCallBack()
{
	if (rightP == 0 && rightD == 0 && leftP == 3 && leftD == 3 && Boat::boatLeft == 0 && Boat::boatRight == 0)
	{
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Win!");
		CCDirector::sharedDirector()->replaceScene(gameOverScene);
	}
}


void HelloWorld::helpCallBack(CCObject* pSender)
{
	CCMessageBox("1、河的两岸，都不要让牧师（白衣服）的数量小于魔鬼（红色）的数量\n2、船只能在有人的情况下才能走，最多两个人\n3、将左岸的六个用船运到右岸，你就赢了", "提示");
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
