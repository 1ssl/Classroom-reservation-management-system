#include <iostream>
#include "teacher.h"

//Ĭ�Ϲ��캯��
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.�鿴ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.���ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.ע����¼                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
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

//���ԤԼ
void Teacher::validOrder()
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
	cout << "|   ���   ѧ��   ����   ����   ʱ��   ����   ״̬   |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
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
			if (index >= 1)
				cout << "|                                                    |" << endl;
			cout << "|    " << ++index
				<< "     " << of.m_orderData[i]["stuId"]
				<< "   " << of.m_orderData[i]["stuName"]
				<< "   " << date
				<< "   " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "   " << "10" << of.m_orderData[i]["roomId"]
				<< "  " << status
				<< " |" << endl;
		}
	}
	cout << "|----------------------------------------------------|" << endl;
	cout << "����������е�ԤԼ��¼,0������" << endl;
	int select = 0; //�����û�ѡ���ԤԼ��¼
	int ret = 0;	//����ԤԼ�����¼

	while (true)
	{
		cin >> select;
		if (select >= 0 || select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�������
					of.m_orderData[v[select - 1]]["status"] = "2";

				}
				else
				{
					//��ͨ��
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				//����ԤԼ��¼
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}