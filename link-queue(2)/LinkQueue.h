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
// �������������һ���ն���
{
	rear = NULL;	
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
// ������������ٶ���
{
	Clear();
    //delete front;		
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const
// ������������ض��г���			 
{
    Node<ElemType> *p ;
    //Node<ElemType> *q = rear->next;
	int count = 0;		// ��ʼ�������� 
	for (p = rear->next; p != rear; p = p->next)
		count++;		
	if(rear!=NULL) count++;
	return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return rear == NULL;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear() 
// �����������ն���
{   
    if(rear!=NULL)
    {
	    Node<ElemType> *p = rear->next;
        while (p != rear)	
        {	// ����ɾ�������е�Ԫ�ؽ��
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
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
    Node<ElemType> *p;
	for (p = rear->next; p != rear; p = p->next)
	// �Զ���ÿ��Ԫ�ص��ú���(*visit)���� 
		(*Visit)(p->data);
	if(rear!=NULL) (*Visit)(p->data);
}


template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	// ���зǿ�
		Node<ElemType> *p = rear->next;	// ָ�����ͷ��
		e = p->data;						// ��e���ض�ͷԪ��
		rear->next = p->next;				// frontָ����һԪ��
		if (rear == p)	// ����ǰ������ֻ��һ��Ԫ�أ����Ӻ�Ϊ�ն���
			rear = NULL;
		delete p;							// �ͷų��ӵ�Ԫ�ؽ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	            // ���зǿ�
		e = rear->next->data;		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
// ������������ϵͳ�ռ䲻��������OVER_FLOW,
//	�������Ԫ��eΪ�µĶ�β������SUCCESS
{   if(!IsEmpty())
    {
	    Node<ElemType> *p,*q=rear->next; 
        p = new Node<ElemType>(e);	        // ����һ���½��
        if (p) { 
                 rear->next = p;
                 p->next=q;	                // ���½����ڶ�β
	             rear = rear->next;				// rearָ���¶�β
	             return SUCCESS;
         }
        else                               //ϵͳ�ռ䲻��������OVER_FLOW 
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
// ����������ɶ���q�����¶���--���ƹ��캯��
{
    Node<ElemType> *p;                                        
	rear = new Node<ElemType>;	// ���ɶ���ͷ���
	for (p = q.rear->next; p != rear; p = p->next)
	// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
		EnQueue(p->data);
	EnQueue(p->data);
}

template<class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator =(const LinkQueue<ElemType> &q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{   Node<ElemType> *p;
	if (&q != this)	{
		Clear();       //���ԭ�ж��� 
		for (p = q.rear->next; p != NULL; p = p->next)
		// ȡq����ÿ��Ԫ�ص�ֵ,�����ڵ�ǰ������������в���
			EnQueue(p->data);
		EnQueue(p->data);
	}
	return *this;
}

#endif
