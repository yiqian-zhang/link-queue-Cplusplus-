#ifndef __NODE_H__
#define __NODE_H__

// 结点类
template <class ElemType>
struct Node 
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域

// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType item, Node<ElemType> *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
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
	f<<endl<<"航班号:"<<t.number<<endl;
	f<<"起飞时间:"<<t.takeoff<<"  "<<"起飞地点:"<<t.placedep<<endl;
	f<<"抵达时间:"<<t.arrive<<"  "<<"抵达地点:"<<t.placearr<<endl;
	f<<"座位数:"<<t.maxsize<<"  "<<"空位数:"<<t.length<<"  "<<"票价:"<<t.price<<endl;
	return f;
}

istream& operator>>(istream& f,struct Time& c){
    f>>c.year>>c.month>>c.day>>c.hour>>c.minute>>c.second;
	
    /*int cal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(c.year%4==0&&c.year%100!=0||c.year%400==0) cal[2]++;//判断是否闰年 
	
    if(c.month<1||c.month>12){cout<<endl<<"月份不符合要求，请重新输入:" ;f>>c.month;}
	int m=c.month; 
    if(c.day<1||c.day>cal[m]){cout<<endl<<"该月份没有这一天，请重新输入:" ;f>>c.day;}
	
    if(c.hour<0||c.hour>23){cout<<endl<<"时不符合要求，请重新输入:" ;f>>c.hour;}
	if(c.minute<0||c.minute>60){cout<<endl<<"分不符合要求，请重新输入:" ;f>>c.minute;}
    if(c.second<0||c.second>60){cout<<endl<<"秒不符合要求，请重新输入:" ;f>>c.second;}
	*/
    return f;
}

istream& operator>>(istream& f,struct Ticket& t){
         
	cout<<"请依次输入航班号（8个字符），起飞时间（年、月、日、时、分、秒），起飞地点（8个字符）"<<endl;
    f>>t.number>>t.takeoff>>t.placedep;
	cout<<endl<<"继续依次输入抵达时间（年、月、日、时、分、秒），抵达地点（8个字符）"<<endl;
	f>>t.arrive>>t.placearr;
	cout<<endl<<"继续依次输入座位数，空位数，票价"<<endl;
	f>>t.maxsize>>t.length>>t.price;
    
	return f;
}




  
#endif
