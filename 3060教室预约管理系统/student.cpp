#include <iostream>
#include "student.h"



//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���   ������ѧ�š�����������
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//����ȡ����Ϣ���뵽 ������
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.����ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.�ҵ�ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.����ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.ȡ��ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.ע����¼                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.��    һ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.��    ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.��    ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.��    ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    5.��    ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.������ҳ                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	int date = 0;  //��������
	int interval = 0;	//ʱ���
	int room = 0;   //���ұ��

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		if (date == 0) {
			system("cls");
			return;
		}
		cout << "������������������" << endl;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.��    ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.��    ��                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		if (interval == 0) {
			system("cls");
			return;
		}
		cout << "������������������" << endl;
	}
	// ��������������Ϣ
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               ����            ����               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << "|               " << vCom[i].m_ComId << "             " << vCom[i].m_MaxNum << "                |" << endl;
		if (i < vCom.size() - 1)
			cout << "|                                                  |" << endl;
	}
	cout << "|--------------------------------------------------|" << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 4)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ�!�����" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|       ����       ʱ��       ����       ״̬      |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) //�ҵ�����ԤԼ
		{
			string status = ""; // ���״̬
			string date = ""; // ����
			//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�ȴ����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���ʧ��";
			}
			else
			{
				status += "ԤԼȡ��";
			}
			// �������� 
			if (of.m_orderData[i]["date"] == "1")
			{
				date = "��һ";
			}
			else if (of.m_orderData[i]["date"] == "2")
			{
				date = "�ܶ�";
			}
			else if (of.m_orderData[i]["date"] == "3")
			{
				date = "����";
			}
			else if (of.m_orderData[i]["date"] == "4")
			{
				date = "����";
			}
			else if (of.m_orderData[i]["date"] == "5")
			{
				date = "����";
			}
			if (i != 0)
				cout << "|                                                  |" << endl;
			cout << "|       " << date
				<< "       " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "       " << "10" << of.m_orderData[i]["roomId"]
				<< "      " << status
				<< "    |" << endl;
		}
	}
	cout << "|--------------------------------------------------|" << endl;
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|----------------------------------------------------|" << endl;
	cout << "|                3060����ԤԼ����ϵͳ                |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|    ѧ��    ����    ����    ʱ��    ����    ״̬    |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		string status = ""; // ���״̬
		string date = ""; // ����
		//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�ȴ����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���ʧ��";
		}
		else
		{
			status += "ԤԼȡ��";
		}

		// �������� 
		if (of.m_orderData[i]["date"] == "1")
		{
			date = "��һ";
		}
		else if (of.m_orderData[i]["date"] == "2")
		{
			date = "�ܶ�";
		}
		else if (of.m_orderData[i]["date"] == "3")
		{
			date = "����";
		}
		else if (of.m_orderData[i]["date"] == "4")
		{
			date = "����";
		}
		else if (of.m_orderData[i]["date"] == "5")
		{
			date = "����";
		}
		if (i != 0)
			cout << "|                                                    |" << endl;
		cout << "|    " << of.m_orderData[i]["stuId"]
			<< "    " << of.m_orderData[i]["stuName"]
			<< "    " << date
			<< "    " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
			<< "    " << "10" << of.m_orderData[i]["roomId"]
			<< "   " << status
			<< "  |" << endl;
	}
	cout << "|----------------------------------------------------|" << endl;
	system("pause");
	system("cls");

}
//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     ���     ����     ʱ��     ����     ״̬     |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	int index = 1;
	//�������������е��±���
	vector<int>v;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж�������ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//��ɸѡ״̬  ����л�ԤԼ�ɹ�
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				string status = ""; // ���״̬
				string date = ""; // ����
				//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�ȴ����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				// �������� 
				if (of.m_orderData[i]["date"] == "1")
				{
					date = "��һ";
				}
				else if (of.m_orderData[i]["date"] == "2")
				{
					date = "�ܶ�";
				}
				else if (of.m_orderData[i]["date"] == "3")
				{
					date = "����";
				}
				else if (of.m_orderData[i]["date"] == "4")
				{
					date = "����";
				}
				else if (of.m_orderData[i]["date"] == "5")
				{
					date = "����";
				}
				if (index >= 2)
					cout << "|                                                  |" << endl;
				cout << "|      " << index++
					<< "       " << date
					<< "     " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
					<< "     " << "10" << of.m_orderData[i]["roomId"]
					<< "    " << status
					<< "   |" << endl;


			}
		}
	}
	cout << "|--------------------------------------------------|" << endl;

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				//ȡ���ɹ�
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}