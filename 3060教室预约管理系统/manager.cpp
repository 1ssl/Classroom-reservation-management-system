#include "manager.h"




//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���   ����Ա���� ������
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;
	// ��ʼ������ ��ȡ�������ļ���ѧ����ʦ����Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "���ҵ�����" << vCom.size();
}

//ѡ��˵�  
void Manager::operMenu()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.����˺�                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.�鿴�˺�                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.�鿴����                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.���ԤԼ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.ע����¼                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//����˺�
void Manager::addPerson()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.���ѧ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.�����ʦ                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.������ҳ                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	string fileName;   //�����ļ���
	string tip;   //��ʾid��
	string errorTip;   //�ظ�������ʾ
	ofstream ofs;   //�ļ���������

	int select = 0;
	cin >> select; //�����û�ѡ��

	if (select == 1)
	{
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
		errorTip = "ѧ���ظ�������������";
	}
	else if (select == 2)
	{
		//��ӵ��ǽ�ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����";
		errorTip = "ְ�����ظ�������������";
	}
	else if (select == 0)
	{
		return;
	}

	ofs.open(fileName, ios::out | ios::app);  //����׷�ӵķ�ʽд�ļ�

	int id;      //ѧ�ţ�ְ����
	string name; //����
	string pwd;  //����

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;


	system("pause");
	system("cls");
	ofs.close();

	//���������Ľӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "|         " << s.m_Id << "          " << s.m_Name << "          " << s.m_Pwd << "         |" << endl;
}

void printTeacher(Teacher& t)
{
	cout << "|         " << t.m_EmpId << "         " << t.m_Name << "         " << t.m_Pwd << "         |" << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.�鿴ѧ��                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.�鿴��ʦ                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	int select = 0;   //�����û�ѡ��
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		system("cls");
		cout << "|--------------------------------------------------|" << endl;
		cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		cout << "|         ѧ��          ����          ����         |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "|--------------------------------------------------|" << endl;
	}
	else
	{
		//�鿴��ʦ
		system("cls");
		cout << "|--------------------------------------------------|" << endl;
		cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		cout << "|         ְ����         ����         ����         |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		cout << "|--------------------------------------------------|" << endl;
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	int index = 0;
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060����ԤԼ����ϵͳ               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               ����            ����               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		if (index++ >= 1)
			cout << "|                                                  |" << endl;
		cout << "|               " << it->m_ComId << "             " << it->m_MaxNum << "                |" << endl;
	}
	cout << "|--------------------------------------------------|" << endl;
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	int select;
	cout << "ȷ��(1) or ȡ��(0)";
	cin >> select;
	if (select == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


//��ʼ������
void Manager::initVector()
{
	//ȷ����������յ�״̬
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ  ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);

	}
	cout << "��ǰѧ������Ϊ" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vTea.size() << endl;
	ifs.close();
}

//����ظ�
//����1 ���ѧ�ţ�ְ���� ����2 �������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if ((*it).m_Id == id)
			{
				return true;
			}
		}

	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}