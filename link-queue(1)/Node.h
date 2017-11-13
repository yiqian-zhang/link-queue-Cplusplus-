#ifndef __NODE_H__
#define __NODE_H__

// �����
template <class ElemType>
struct Node 
{
// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType> *next;		// ָ����

// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType item, Node<ElemType> *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
Node<ElemType>::Node()
// �������������ָ����Ϊ�յĽ��
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// �������������һ��������Ϊitem��ָ����Ϊlink�Ľ��
{
   data = item;
   next = link;
}

struct Time
{
       int year;
       int month;
       int day;
       int hour;
       int minute;
       int second;
       };
struct Ticket
{
       char number[10];
       struct Time takeoff;
       char placedep[10];
       struct Time arrive;
       char placearr[10];
       int maxsize;
       int length;
       double price;
       };
     
/*bool operator!=(const struct Car& c1,const struct Car& c2){
	if (strcmp(c1.number,c2.number)==0)
		return false;
	else return true;
}*/
ostream& operator<<(ostream& f,const struct Time& c){
	f<<c.year<<"  "<<c.month<<"  "<<c.day<<"  "<<c.hour<<"  "<<c.minute<<"  "<<c.second<<endl;
	return f;
}

ostream& operator<<(ostream& f,const struct Ticket& t){
	f<<endl<<"�����:"<<t.number<<endl;
	f<<"���ʱ��:"<<t.takeoff<<"  "<<"��ɵص�:"<<t.placedep<<endl;
	f<<"�ִ�ʱ��:"<<t.arrive<<"  "<<"�ִ�ص�:"<<t.placearr<<endl;
	f<<"��λ��:"<<t.maxsize<<"  "<<"��λ��:"<<t.length<<"  "<<"Ʊ��:"<<t.price<<endl;
	return f;
}

istream& operator>>(istream& f,struct Time& c){
    f>>c.year>>c.month>>c.day>>c.hour>>c.minute>>c.second;
	
    /*int cal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(c.year%4==0&&c.year%100!=0||c.year%400==0) cal[2]++;//�ж��Ƿ����� 
	
    if(c.month<1||c.month>12){cout<<endl<<"�·ݲ�����Ҫ������������:" ;f>>c.month;}
	int m=c.month; 
    if(c.day<1||c.day>cal[m]){cout<<endl<<"���·�û����һ�죬����������:" ;f>>c.day;}
	
    if(c.hour<0||c.hour>23){cout<<endl<<"ʱ������Ҫ������������:" ;f>>c.hour;}
	if(c.minute<0||c.minute>60){cout<<endl<<"�ֲ�����Ҫ������������:" ;f>>c.minute;}
    if(c.second<0||c.second>60){cout<<endl<<"�벻����Ҫ������������:" ;f>>c.second;}
	*/
    return f;
}

istream& operator>>(istream& f,struct Ticket& t){
         
	cout<<"���������뺽��ţ�8���ַ��������ʱ�䣨�ꡢ�¡��ա�ʱ���֡��룩����ɵص㣨8���ַ���"<<endl;
    f>>t.number>>t.takeoff>>t.placedep;
	cout<<endl<<"������������ִ�ʱ�䣨�ꡢ�¡��ա�ʱ���֡��룩���ִ�ص㣨8���ַ���"<<endl;
	f>>t.arrive>>t.placearr;
	cout<<endl<<"��������������λ������λ����Ʊ��"<<endl;
	f>>t.maxsize>>t.length>>t.price;
    
	return f;
}




  
#endif
