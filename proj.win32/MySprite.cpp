#include "MySprite.h"
#include "HelloWorldScene.h"
#include "ConstantValues.h"

MySprite*  MySprite::create(const char *pszFileName)
{
	MySprite *pobSprite = new MySprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void MySprite::onEnter()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
	spriteStatus = Status::right;
	CCSprite::onEnter();
}

void MySprite::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

CCRect MySprite::getRect()
{
	CCSize size = getTexture()->getContentSize();
	return CCRectMake(-size.width / 2, -size.height / 2, size.width, size.height);
}

Status MySprite::getSpriteStatus()
{
	return spriteStatus;
}

void MySprite::setSpriteStatus(Status s)
{
	spriteStatus = s;
}

bool MySprite::containsTouchLocation(CCTouch *touch)
{
	CCRect rc = getRect();
	CCPoint p = convertTouchToNodeSpaceAR(touch);
	return rc.containsPoint(p);
}

bool MySprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	bool bRet = false;
	if (containsTouchLocation(touch) && spriteStatus == Boat::boatStatus || spriteStatus == Status::inBoat)
	{
		bRet = true;
	}
	return bRet;

}
void MySprite::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}
void MySprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	float *p = new float[2];
	ConstantValue *constant = new ConstantValue();
	HelloWorld *hw = (HelloWorld*)CCDirector::sharedDirector()->getRunningScene()->getChildByTag(0);

	if (containsTouchLocation(touch))
	{
		int tag = this->getTag();
		if (spriteStatus == Status::inBoat)
		{
			if (Boat::boatLeft == tag)
			{
				Boat::boatLeft = 0;
			}
			else if (Boat::boatRight == tag)
			{
				Boat::boatRight = 0;
			}

			if (Boat::boatStatus == Status::right)
			{
				constant->getCoordinate("right", tag, p);
				this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(visibleSize.width + p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
				spriteStatus = Status::right;
			}
			else
			{
				constant->getCoordinate("left", tag, p);
				this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
				spriteStatus = Status::left;
			}

			Boat::numOfPersonsInBoat--;
		}
		else if (spriteStatus == Boat::boatStatus)
		{
			if (Boat::numOfPersonsInBoat < 2)
			{
				spriteStatus = Status::inBoat;
				Boat::numOfPersonsInBoat++;
				if (Boat::boatLeft == 0)
				{
					Boat::boatLeft = tag;
					if (Boat::boatStatus == Status::right)
					{
						constant->getCoordinate("right", 8, p);
						this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(visibleSize.width + p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
					}
					else
					{
						constant->getCoordinate("left", 7, p);
						this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
					}
				}
				else if (Boat::boatRight == 0)
				{
					Boat::boatRight = tag;
					if (Boat::boatStatus == Status::right)
					{
						constant->getCoordinate("right", 7, p);
						this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(visibleSize.width + p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
					}
					else
					{
						constant->getCoordinate("left", 8, p);
						this->runAction(CCSequence::create(CCMoveTo::create(1.0f, ccp(p[0] + origin.x, p[1] + origin.y)), CCCallFunc::create((CCObject*)hw, callfunc_selector(HelloWorld::spriteCallBack)), NULL));
					}
				}
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}
