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
	    
    //��Ӵ���ί�У����´˷���
    virtual void onEnter();
    //�Ƴ������¼�����ֹ�ڴ����
    virtual void   onExit();


    
    //������Ӧ��д����������
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//����
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//�϶�
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//�ɿ�;

	void setSpriteStatus(Status s);
	Status getSpriteStatus();
	
private:
	Status spriteStatus;
};

#endif