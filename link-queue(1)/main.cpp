#include "Assistance.h"	// ���������
#include "LinkQueue.h"	// ��������

int main(void)
{

	char c = '1';
    LinkQueue<struct Ticket> qa;
    struct Ticket t;
    //int x;

    while (c != '0')
	{
        cout << endl << "1. ���ɶ���.";
        cout << endl << "2. ��ʾ����.";
        cout << endl << "3. �����.";
        cout << endl << "4. ������.";
        cout << endl << "5. ȡ����ͷ.";
        //cout << endl << "6. Ԥ������."; 
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c)		{
			case '1':
                qa.Clear(); 
                char op;
				cout << endl << "����t:";
				do{
                     cin>>t;
                     qa.EnQueue(t);
                     cout << endl << "������������룬����n������";
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
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> t;
			    qa.EnQueue(t);
			    break;
           case '4':
			    qa.DelQueue(t);
			    cout << endl << "��ͷԪ��ֵΪ " << t << " ." << endl;
			    break;
           case '5':
			    qa.GetHead(t);
			    cout << endl << "��ͷԪ��ֵΪ " << t << " ." << endl;
			    break;
	       /*case '6':
                char* t;
                cout<<"���뺽���:";
                cin>>t;
                int l=qa.FindTicket(t);
                cout<<l;
                if(l==-1) cout<<"û�иú���"<<endl;
                if(l==-2) cout<<"û�п�λ��Ԥ��ʧ��"<<endl; 
                if(l>=0) cout<<"Ԥ���ɹ�!"<<endl<<"ʣ���λ:"<<l<<endl;*/
		}
	}

	system("PAUSE");
	return 0; 
}


