#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "teacher.h"
#include "student.h"
#include <algorithm>
#include "classRoom.h"



class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���   ����Ա���� ������
	Manager(string name, string pwd);

	//ѡ��˵�  
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�
	//����1 ���ѧ�ţ�ְ���� ����2 �������
	bool checkRepeat(int id, int type);


	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;
};