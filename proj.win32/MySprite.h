#ifndef __MYSPRITE__H__
#define __MYSPRITE__H__

#include "cocos2d.h"
#include "Boat.h"
using namespace cocos2d;


class MySprite :public CCSprite, public CCTouchDelegate
{
public:
	static MySprite*  create(const char *pszFileName);
    CCRect getRect();
	bool containsTouchLocation(CCTouch *touch);
	    
    //添加触屏委托，重新此方法
    virtual void onEnter();
    //移除监听事件，防止内存溢出
    virtual void   onExit();


    
    //触屏响应重写这三个方法
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//拖动
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开;

	void setSpriteStatus(Status s);
	Status getSpriteStatus();
	
private:
	Status spriteStatus;
};

#endif