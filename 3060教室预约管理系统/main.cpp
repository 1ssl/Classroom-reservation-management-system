#include <iostream>
#include <string>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//�������Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//�������ָ��תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;

		if (select == 1) //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			//ע��
			delete manager;   //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;   //�����û�ѡ��

		cin >> select;
		if (select == 1) //�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)  //���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;   //�����û�ѡ��
		if (select == 1)   //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)    //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)     //�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)     //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			//ע����¼
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//login in ��¼����
//����1 �����ļ���
//����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		//ѧ�����
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId; //���ļ��ж�ȡ��id��
		string fName;   //���ļ��л�ȡ������
		string fPwd;    //���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//���뵽ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;
			}
		}

	}

	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;      //���ڽ����û���ѡ��
	while (true)
	{
		cout << "|--------------------------------------------------|" << endl;
		cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		cout << "|                    1.ѧ������                    |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|                    2.��    ʦ                    |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|                    3.�� �� Ա                    |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|                    0.�˳�ϵͳ                    |" << endl;
		cout << "|--------------------------------------------------|" << endl;

		cin >> select;    //�����û�ѡ��

		switch (select)   //�����û�ѡ�� ʵ�ֲ�ͬ�ӿ�
		{
		case 1:    //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:    //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:    //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:    //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}