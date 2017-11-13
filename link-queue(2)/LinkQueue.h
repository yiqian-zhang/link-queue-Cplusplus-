#ifndef __LK_QUEUE_H__
#define __LK_QUEUE_H__

#include "Node.h"			



template<class ElemType>
class LinkQueue 
{
protected:

	Node<ElemType> *rear;					

public:
	LinkQueue();								
	virtual ~LinkQueue();						
	int GetLength() const;								 
	bool IsEmpty() const;							
	void Clear();								
	void Traverse(void (*Visit)(const ElemType &)) const ;	
	Status DelQueue(ElemType &e);				     
	Status GetHead(ElemType &e) const;			     
	Status EnQueue(const ElemType e);			    
	LinkQueue(const LinkQueue<ElemType> &q);		
	LinkQueue<ElemType> &operator =(const LinkQueue<ElemType> &q);
};



template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
// 操作结果：构造一个空队列
{
	rear = NULL;	
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
// 操作结果：销毁队列
{
	Clear();
    //delete front;		
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const
// 操作结果：返回队列长度			 
{
    Node<ElemType> *p ;
    //Node<ElemType> *q = rear->next;
	int count = 0;		// 初始化计数器 
	for (p = rear->next; p != rear; p = p->next)
		count++;		
	if(rear!=NULL) count++;
	return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
// 操作结果：如队列为空，则返回true，否则返回false
{
   return rear == NULL;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() 
// 操作结果：清空队列
{   
    if(rear!=NULL)
    {
	    Node<ElemType> *p = rear->next;
        while (p != rear)	
        {	// 依次删除队列中的元素结点
        rear->next = p->next;
		delete p;        
		p = rear->next;
        }
	    delete p;
        rear = NULL;
    }	
}

template <class ElemType>
void LinkQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const 
// 操作结果：依次对队列的每个元素调用函数(*visit)
{
    Node<ElemType> *p;
	for (p = rear->next; p != rear; p = p->next)
	// 对队列每个元素调用函数(*visit)访问 
		(*Visit)(p->data);
	if(rear!=NULL) (*Visit)(p->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e)
// 操作结果：如果队列非空，那么删除队头元素，并用e返回其值，函数返回SUCCESS,
//	否则函数返回UNDER_FLOW，
{
	if (!IsEmpty()) 	{	// 队列非空
		Node<ElemType> *p = rear->next;	// 指向队列头素
		e = p->data;						// 用e返回队头元素
		rear->next = p->next;				// front指向下一元素
		if (rear == p)	// 出队前队列中只有一个元素，出队后为空队列
			rear = NULL;
		delete p;							// 释放出队的元素结点
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType &e) const
// 操作结果：如果队列非空，那么用e返回队头元素，函数返回SUCCESS,
//	否则函数返回UNDER_FLOW，
{
	if (!IsEmpty()) 	{	            // 队列非空
		e = rear->next->data;		// 用e返回队头元素
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
// 操作结果：如果系统空间不够，返回OVER_FLOW,
//	否则插入元素e为新的队尾，返回SUCCESS
{   if(!IsEmpty())
    {
	    Node<ElemType> *p,*q=rear->next; 
        p = new Node<ElemType>(e);	        // 生成一个新结点
        if (p) { 
                 rear->next = p;
                 p->next=q;	                // 将新结点加在队尾
	             rear = rear->next;				// rear指向新队尾
	             return SUCCESS;
         }
        else                               //系统空间不够，返回OVER_FLOW 
		return OVER_FLOW;  
    } 
    else
    {
        Node<ElemType> *p= new Node<ElemType>(e);
        rear=p;
        rear->next=p; 
        return SUCCESS;
    } 
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &q)
// 操作结果：由队列q构造新队列--复制构造函数
{
    Node<ElemType> *p;                                        
	rear = new Node<ElemType>;	// 生成队列头结点
	for (p = q.rear->next; p != rear; p = p->next)
	// 取q队列每个元素的值,将其在当前队列中作入队列操作
		EnQueue(p->data);
	EnQueue(p->data);
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator =(const LinkQueue<ElemType> &q)
// 操作结果：将队列q赋值给当前队列--赋值语句重载
{   Node<ElemType> *p;
	if (&q != this)	{
		Clear();       //清除原有队列 
		for (p = q.rear->next; p != NULL; p = p->next)
		// 取q队列每个元素的值,将其在当前队列中作入队列操作
			EnQueue(p->data);
		EnQueue(p->data);
	}
	return *this;
}

#endif
