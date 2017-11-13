#include "Assistance.h"	// 辅助软件包
#include "LinkQueue.h"	// 链队列类

int main(void)
{

	char c = '1';
    LinkQueue<struct Ticket> qa;
    struct Ticket t;
    //int x;

    while (c != '0')
	{
        cout << endl << "1. 生成队列.";
        cout << endl << "2. 显示队列.";
        cout << endl << "3. 入队列.";
        cout << endl << "4. 出队列.";
        cout << endl << "5. 取队列头.";
        //cout << endl << "6. 预定航班."; 
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~5):";
		cin >> c;
		switch (c)		{
			case '1':
                qa.Clear(); 
                char op;
				cout << endl << "输入t:";
				do{
                     cin>>t;
                     qa.EnQueue(t);
                     cout << endl << "任意键继续输入，输入n结束。";
                     cin >> op;
                }while(op!='n');
				/*while (x != 0)	{
					qa.EnQueue(x);
					cin >> x;
				}*/
				break;
	       case '2':
				cout << endl;
			    qa.Traverse(Write<struct Ticket>);
				break;
		   case '3':
			    cout << endl << "输入元素值:";
			    cin >> t;
			    qa.EnQueue(t);
			    break;
           case '4':
			    qa.DelQueue(t);
			    cout << endl << "队头元素值为 " << t << " ." << endl;
			    break;
           case '5':
			    qa.GetHead(t);
			    cout << endl << "队头元素值为 " << t << " ." << endl;
			    break;
	       /*case '6':
                char* t;
                cout<<"输入航班号:";
                cin>>t;
                int l=qa.FindTicket(t);
                cout<<l;
                if(l==-1) cout<<"没有该航班"<<endl;
                if(l==-2) cout<<"没有空位，预定失败"<<endl; 
                if(l>=0) cout<<"预订成功!"<<endl<<"剩余空位:"<<l<<endl;*/
		}
	}

	system("PAUSE");
	return 0; 
}


