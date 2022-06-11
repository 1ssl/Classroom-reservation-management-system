#include <iostream>
#include "student.h"



//默认构造
Student::Student()
{

}

//有参构造   参数：学号、姓名、密码
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化教室信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//将读取的信息放入到 容器中
		vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu()
{
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.申请预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.我的预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.所有预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.取消预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.注销登录                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//申请预约
void Student::applyOrder()
{
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.周    一                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.周    二                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    3.周    三                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    4.周    四                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    5.周    五                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.返回首页                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;

	int date = 0;  //接收日期
	int interval = 0;	//时间段
	int room = 0;   //教室编号

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
		cout << "输入有误，请重新输入" << endl;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.上    午                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.下    午                    |" << endl;
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
		cout << "输入有误，请重新输入" << endl;
	}
	// 遍历教室容量信息
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               教室            容量               |" << endl;
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
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功!审核中" << endl;

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
//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|       日期       时间       教室       状态      |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) //找到自身预约
		{
			string status = ""; // 审核状态
			string date = ""; // 日期
			//1 审核中 2 已预约 -1 预约失败 0 取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "等待审核";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "审核失败";
			}
			else
			{
				status += "预约取消";
			}
			// 处理日期 
			if (of.m_orderData[i]["date"] == "1")
			{
				date = "周一";
			}
			else if (of.m_orderData[i]["date"] == "2")
			{
				date = "周二";
			}
			else if (of.m_orderData[i]["date"] == "3")
			{
				date = "周三";
			}
			else if (of.m_orderData[i]["date"] == "4")
			{
				date = "周四";
			}
			else if (of.m_orderData[i]["date"] == "5")
			{
				date = "周五";
			}
			if (i != 0)
				cout << "|                                                  |" << endl;
			cout << "|       " << date
				<< "       " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "       " << "10" << of.m_orderData[i]["roomId"]
				<< "      " << status
				<< "    |" << endl;
		}
	}
	cout << "|--------------------------------------------------|" << endl;
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|----------------------------------------------------|" << endl;
	cout << "|                3060教室预约管理系统                |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	cout << "|    学号    姓名    日期    时间    教室    状态    |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		string status = ""; // 审核状态
		string date = ""; // 日期
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "等待审核";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核失败";
		}
		else
		{
			status += "预约取消";
		}

		// 处理日期 
		if (of.m_orderData[i]["date"] == "1")
		{
			date = "周一";
		}
		else if (of.m_orderData[i]["date"] == "2")
		{
			date = "周二";
		}
		else if (of.m_orderData[i]["date"] == "3")
		{
			date = "周三";
		}
		else if (of.m_orderData[i]["date"] == "4")
		{
			date = "周四";
		}
		else if (of.m_orderData[i]["date"] == "5")
		{
			date = "周五";
		}
		if (i != 0)
			cout << "|                                                    |" << endl;
		cout << "|    " << of.m_orderData[i]["stuId"]
			<< "    " << of.m_orderData[i]["stuName"]
			<< "    " << date
			<< "    " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
			<< "    " << "10" << of.m_orderData[i]["roomId"]
			<< "   " << status
			<< "  |" << endl;
	}
	cout << "|----------------------------------------------------|" << endl;
	system("pause");
	system("cls");

}
//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     序号     日期     时间     教室     状态     |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	int index = 1;
	//存放在最大容器中的下标编号
	vector<int>v;
	for (int i = 0; i < of.m_Size; i++)
	{
		//先判断是自身学号
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//再筛选状态  审核中或预约成功
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				string status = ""; // 审核状态
				string date = ""; // 日期
				//1 审核中 2 已预约 -1 预约失败 0 取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "等待审核";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				// 处理日期 
				if (of.m_orderData[i]["date"] == "1")
				{
					date = "周一";
				}
				else if (of.m_orderData[i]["date"] == "2")
				{
					date = "周二";
				}
				else if (of.m_orderData[i]["date"] == "3")
				{
					date = "周三";
				}
				else if (of.m_orderData[i]["date"] == "4")
				{
					date = "周四";
				}
				else if (of.m_orderData[i]["date"] == "5")
				{
					date = "周五";
				}
				if (index >= 2)
					cout << "|                                                  |" << endl;
				cout << "|      " << index++
					<< "       " << date
					<< "     " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
					<< "     " << "10" << of.m_orderData[i]["roomId"]
					<< "    " << status
					<< "   |" << endl;


			}
		}
	}
	cout << "|--------------------------------------------------|" << endl;

	cout << "请输入取消的记录，0代表返回" << endl;
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
				//取消成功
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}