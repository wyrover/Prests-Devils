#include "Boat.h"
#include "HelloWorldScene.h"

int Boat::boatLeft = 0;
int Boat::boatRight = 0;
int Boat::numOfPersonsInBoat = 0;
Status Boat::boatStatus = Status::right;

Boat*  Boat::create(const char *pszFileName)
{
	Boat *pobSprite = new Boat();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void Boat::onEnter()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
	boatLeft = 0;
	boatRight = 0;
	numOfPersonsInBoat = 0;
	boatStatus = Status::right;
	CCSprite::onEnter();
}

void Boat::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

bool Boat::isTouchedGo(CCTouch *touch)
{
	CCPoint p = touch->getLocation();
	return p.x > 210 && p.x < 255 && p.y > 250 && p.y < 280;
}

bool Boat::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	bool bRet = false;
	if (isTouchedGo(touch) && (numOfPersonsInBoat > 0))
	{
		bRet = true;
	}
	return bRet;
}
void Boat::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}
void Boat::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	if (isTouchedGo(touch))
	{
		float dir;
		if (Boat::boatStatus == Status::right)
		{
			dir = -80.0f;
			Boat::boatStatus = Status::left;
		}
		else
		{
			dir = 80.0f;
			Boat::boatStatus = Status::right;
		}
		CCMoveBy *moveBy = CCMoveBy::create(1.0f, ccp(dir, 0));

		HelloWorld *hw = (HelloWorld*)CCDirector::sharedDirector()->getRunningScene()->getChildByTag(0);
		if (boatLeft != 0 && boatRight != 0)
		{
			CCSprite *p_left1 = (CCSprite*)hw->getChildByTag(boatLeft);
			CCSprite *p_right1 = (CCSprite*)hw->getChildByTag(boatRight);
			p_right1->runAction(CCSequence::create(moveBy, NULL));
			p_left1->runAction(CCSequence::create((CCMoveBy*)moveBy->copy()->autorelease(), NULL));
			this->runAction(CCSequence::create((CCMoveBy*)moveBy->copy()->autorelease(), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::boatCallBack)), NULL));
		}
		else if (boatRight != 0)
		{
			CCSprite *p_right2 = (CCSprite*)hw->getChildByTag(boatRight);
			p_right2->runAction(CCSequence::create(moveBy, NULL));
			this->runAction(CCSequence::create((CCMoveBy*)moveBy->copy()->autorelease(), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::boatCallBack)), NULL));
		}
		else if (boatLeft != 0)
		{
			CCSprite *p_left2 = (CCSprite*)hw->getChildByTag(boatLeft);
			p_left2->runAction(CCSequence::create(moveBy, NULL));
			this->runAction(CCSequence::create((CCMoveBy*)moveBy->copy()->autorelease(), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::boatCallBack)), NULL));
		}
	}
}