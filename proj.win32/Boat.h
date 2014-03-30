#ifndef __BOAT__H__
#define __BOAT__H__

#include "cocos2d.h"
#include "ConstantValues.h"
using namespace cocos2d;

enum Status
{
	left, right, inBoat
};

class Boat :public CCSprite, public CCTouchDelegate
{
public:
	static Boat*  create(const char *pszFileName);
	    
    //添加触屏委托，重新此方法
    virtual void onEnter();
    //移除监听事件，防止内存溢出
    virtual void   onExit();


    
    //触屏响应重写这三个方法
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//拖动
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开;
	
	bool isTouchedGo(CCTouch *touch);//是否按下GO按钮

	static int boatLeft;
	static int boatRight;
	static int numOfPersonsInBoat;
	static Status boatStatus;
};

#endif