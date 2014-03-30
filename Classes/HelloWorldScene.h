#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);


	virtual void registerWithTouchDispatcher();

    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//拖动
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开;


	void boatCallBack();
	void spriteCallBack();
	void timeCallBack(float dt);
	void helpCallBack(CCObject* pSender);

	static int leftP;
	static int leftD;
	static int rightP;
	static int rightD;

private:
	float time;
};

#endif // __HELLOWORLD_SCENE_H__
