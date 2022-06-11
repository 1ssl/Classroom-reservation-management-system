#include <iostream>
#include "teacher.h"

//默认构造函数
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "|--------------------------------------------------|" << endl;
	cout << "|               3060教室预约管理系统               |" << endl;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|                    1.查看预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    2.审核预约                    |" << endl;
	cout << "|                                                  |" << endl;
	cout << "|                    0.注销登录                    |" << endl;
	cout << "|--------------------------------------------------|" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
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

//审核预约
void Teacher::validOrder()
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
	cout << "|   序号   学号   姓名   日期   时间   教室   状态   |" << endl;
	cout << "|----------------------------------------------------|" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
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
			if (index >= 1)
				cout << "|                                                    |" << endl;
			cout << "|    " << ++index
				<< "     " << of.m_orderData[i]["stuId"]
				<< "   " << of.m_orderData[i]["stuName"]
				<< "   " << date
				<< "   " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "   " << "10" << of.m_orderData[i]["roomId"]
				<< "  " << status
				<< " |" << endl;
		}
	}
	cout << "|----------------------------------------------------|" << endl;
	cout << "请输入审核中的预约记录,0代表返回" << endl;
	int select = 0; //接收用户选择的预约记录
	int ret = 0;	//接收预约结果记录

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
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过的情况
					of.m_orderData[v[select - 1]]["status"] = "2";

				}
				else
				{
					//不通过
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				//更新预约记录
				of.updateOrder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}