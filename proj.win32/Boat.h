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
	    
    //��Ӵ���ί�У����´˷���
    virtual void onEnter();
    //�Ƴ������¼�����ֹ�ڴ����
    virtual void   onExit();


    
    //������Ӧ��д����������
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//����
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//�϶�
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//�ɿ�;
	
	bool isTouchedGo(CCTouch *touch);//�Ƿ���GO��ť

	static int boatLeft;
	static int boatRight;
	static int numOfPersonsInBoat;
	static Status boatStatus;
};

#endif