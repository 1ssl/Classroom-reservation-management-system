#include "manager.h"




//默认构造
Manager::Manager()
{

}

//有参构造   管理员姓名 ，密码
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;
	// 初始化容器 获取到所有文件中学生老师的信息
	this->initVector();

	//初始化教室信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "教室的数量" << vCom.size();
}

//选择菜单  
void Manager::operMenu()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.添加账号                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.查看账号                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.查看教室                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.清空预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.注销登录                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//添加账号
void Manager::addPerson()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.添加学生                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.添加老师                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.返回首页                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	string fileName;   //操作文件名
	string tip;   //提示id号
	string errorTip;   //重复错误提示
	ofstream ofs;   //文件操作对象

	int select = 0;
	cin >> select; //接收用户选项

	if (select == 1)
	{
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else if (select == 2)
	{
		//添加的是教师
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
		errorTip = "职工号重复，请重新输入";
	}
	else if (select == 0)
	{
		return;
	}

	ofs.open(fileName, ios::out | ios::app);  //利用追加的方式写文件

	int id;      //学号，职工号
	string name; //姓名
	string pwd;  //密码

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;


	system("pause");
	system("cls");
	ofs.close();

	//调用容器的接口，重新获取文件中的数据
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

//查看账号
void Manager::showPerson()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.查看学生                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.查看老师                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	int select = 0;   //接收用户选择
	cin >> select;

	if (select == 1)
	{
		//查看学生
		system("cls");
		cout << "|--------------------------------------------------|" << endl;
		cout << "|               3060教室预约管理系统               |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		cout << "|         学号          姓名          密码         |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "|--------------------------------------------------|" << endl;
	}
	else
	{
		//查看老师
		system("cls");
		cout << "|--------------------------------------------------|" << endl;
		cout << "|               3060教室预约管理系统               |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		cout << "|         职工号         姓名         密码         |" << endl;
		cout << "|--------------------------------------------------|" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		cout << "|--------------------------------------------------|" << endl;
	}

	system("pause");
	system("cls");
}

//查看教室信息
void Manager::showComputer()
{
	int index = 0;
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               教室            容量               |" << endl;
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

//清空预约记录
void Manager::cleanFile()
{
	int select;
	cout << "确认(1) or 取消(0)";
	cin >> select;
	if (select == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}


//初始化容器
void Manager::initVector()
{
	//确保容器是清空的状态
	vStu.clear();
	vTea.clear();

	//读取信息  学生，老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);

	}
	cout << "当前学生数量为" << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为" << vTea.size() << endl;
	ifs.close();
}

//检测重复
//参数1 检测学号，职工号 参数2 检测类型
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//检测老师
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