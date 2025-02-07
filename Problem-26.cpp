#include<iostream>
#include<list>
#include<Windows.h>
#include<iomanip>

using namespace std;


//定义结构体
typedef struct
{
	int number;          //编号 
	string name;         //订户名
	string sex;          //性别
	int phone;           //电话号码
	string unit;         //杂志单位
	int count;           //订阅数
	int deadline;        //订阅期限
}User;
list<User> uselist;  //list 容器
list<User>::iterator use;//定义迭代器 stu用来遍历list容器


//主菜单
void menu()
{
	cout << "***********欢迎使用杂志订阅管理系统**********" << endl;
	cout << "*                                           *" << endl;
	cout << "*********************************************" << endl;
	cout << "*           输入数字以实现对应功能          *" << endl;
	cout << "*********************************************" << endl;
	cout << "*         0-退出系统                        *" << endl;
	cout << "*                                           *" << endl;
	cout << "*     用户信息：                            *" << endl;
	cout << "*         1-添加新订户                      *" << endl;
	cout << "*         2-查找订户信息                    *" << endl;
	cout << "*         3-显示所有订户的个人信息          *" << endl;
	cout << "*         4-编辑信息                        *" << endl;
	cout << "*         5-删除信息                        *" << endl;
	cout << "*         6-统计信息                        *" << endl;
	cout << "*********************************************" << endl;
	cout << "                                             " << endl;
	cout << "请输入功能对应数字后回车:";
}


//自定义函数

//录入
void inputUser()
{
	cout
		<< std::left << std::setw(10) << "编号"
		<< std::left << std::setw(10) << "订户名"
		<< std::left << std::setw(10) << "性别"
		<< std::left << std::setw(10) << "电话号码"
		<< std::left << std::setw(10) << "杂志单位"
		<< std::left << std::setw(10) << "订阅数"
		<< std::left << std::setw(10) << "订阅期限（例202501）" << endl;
	cout << "输入一项后回车：" << endl;
	User data;
	cin >> data.number >> data.name >> data.sex >> data.phone 
	    >> data.unit >> data.count >> data.deadline;
	uselist.push_back(data);//在容器尾部插入元素
	//int number;               //编号 
	//string name;              //订户名
	//int sex;                  //性别
	//int phone;                //电话号码
	//string unit;              //杂志单位
	//int count;                //订阅数
	//int deadline;             //订阅期限

	return;
}

//浏览
void printfUser()
{
	cout
		<< std::left << std::setw(10) << "编号"
		<< std::left << std::setw(10) << "订户名"
		<< std::left << std::setw(10) << "性别"
		<< std::left << std::setw(10) << "电话号码"
		<< std::left << std::setw(10) << "杂志单位"
		<< std::left << std::setw(10) << "订阅数"
		<< std::left << std::setw(10) << "订阅期限" << endl;
	for (use = uselist.begin(); use != uselist.end(); use++)//利用迭代器use遍历list容器
	{
		cout
			<< std::left << std::setw(10) << (*use).number
			<< std::left << std::setw(10) << (*use).name
			<< std::left << std::setw(10) << (*use).sex
			<< std::left << std::setw(10) << (*use).phone
			<< std::left << std::setw(10) << (*use).unit
			<< std::left << std::setw(10) << (*use).count
			<< std::left << std::setw(10) << (*use).deadline << endl;

	}
}

//修改
void changeUser()
{
	string str;
	bool f = true;
	cout << "请输入需要修改的订户的姓名" << endl;
	cin >> str;
	for (use = uselist.begin(); use != uselist.end(); use++)
		if (str == (*use).name)
		{
			cout
				<< std::left << std::setw(10) << "编号"
				<< std::left << std::setw(10) << "订户名"
				<< std::left << std::setw(10) << "性别"
				<< std::left << std::setw(10) << "电话号码"
				<< std::left << std::setw(10) << "杂志单位"
				<< std::left << std::setw(10) << "订阅数"
				<< std::left << std::setw(10) << "订阅期限" << endl;
			cout
				<< std::left << std::setw(10) << (*use).number
				<< std::left << std::setw(10) << (*use).name
				<< std::left << std::setw(10) << (*use).sex
				<< std::left << std::setw(10) << (*use).phone
				<< std::left << std::setw(10) << (*use).unit
				<< std::left << std::setw(10) << (*use).count
				<< std::left << std::setw(10) << (*use).deadline << endl;
			cout << "*********************************************" << endl;
			cout << "请输入修改后信息(输入一项后回车)：" << endl;

			cout
				<< std::left << std::setw(10) << "编号"
				<< std::left << std::setw(10) << "订户名"
				<< std::left << std::setw(10) << "性别"
				<< std::left << std::setw(10) << "电话号码"
				<< std::left << std::setw(10) << "杂志单位"
				<< std::left << std::setw(10) << "订阅数"
				<< std::left << std::setw(10) << "订阅期限（例202501）" << endl;
			User data;
			cin >> data.number >> data.name >> data.sex >> data.phone >> data.unit >> data.count >> data.deadline;
			*use = data;
			cout << "修改成功！" << endl;
			f = !f;
		}
	if (f)
		cout << "该订户的信息不存在！" << endl;
	return;
}

//删除
void deleteUser()
{
	string str;
	bool f = true;
	cout << "请输入需要删除的订户的姓名：" << endl;
	cin >> str;
	for (use = uselist.begin(); use != uselist.end(); use++)
		if (str == (*use).name)
		{
			uselist.erase(use);
			cout << "删除成功" << endl;
			f = !f;
			break;
		}
	if (f)
		cout << "该订户的信息不存在！" << endl;
	return;
}

//查找
void searchUser()
{
	int op, flag = -1;
	std::cout << "请输入一种查找类型：<1>姓名 <2>性别  <3>单位" << endl;
	std::cin >> op;
	if (op == 1)
	{
		cout << "请输入订户名：";
		string name;
		cin >> name;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (name == (*use).name)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}

	}
	else if (op == 2)
	{
		cout << "请输入性别：";
		string sex;
		cin >> sex;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (sex == (*use).sex)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}
	}
	else if (op == 3)
	{
		cout << "请输入单位：";
		string unit;
		cin >> unit;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (unit == (*use).unit)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}
	}

	else if (flag == -1)
		std::cout << "【输入错误】" << endl;
	std::cout << "统计结束！";
}

//统计
void statisticsUser()
{
	int op, flag = -1;

	std::cout << "*********************************************" << std::endl;
	std::cout << "*                 订阅记录统计              *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << endl;
	std::cout << "请输入一种订阅记录类型：<1>全额  <2>性别  <3>订阅数  <4>订阅期限" << endl;
	std::cin >> op;
	if (op == 1)
	{
		int amount, totalcount = 0;
		float total = 0, totalprise, simpleprise = 5.5;

		cout
			<< std::left << std::setw(10) << "订户名"
			<< std::left << std::setw(10) << "订阅数"
			<< std::left << std::setw(10) << "单价"
			<< std::left << std::setw(10) << "全额" << endl;
		for (use = uselist.begin(); use != uselist.end(); use++)
		{
			amount = (*use).count;
			totalprise = simpleprise * amount;

			cout
				<< std::left << std::setw(10) << (*use).name
				<< std::left << std::setw(10) << (*use).count
				<< std::left << std::setw(10) << simpleprise
				<< std::left << std::setw(10) << totalprise << endl;
			totalcount += (*use).count;
			total += totalprise;
		}
		cout
			<< std::left << std::setw(10) << "合计"
			<< std::left << std::setw(10) << totalcount
			<< std::left << std::setw(10) << " "
			<< std::left << std::setw(10) << total << endl;;
		cout << endl;
	}
	else if (op == 2)
	{
		cout << "请输入性别：";
		string sex;
		cin >> sex;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (sex == (*use).sex)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}
	}
	else if (op == 3)
	{
		cout << "请输入订阅数：";
		int count;
		cin >> count;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (count == (*use).count)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}
	}

	else if (op == 4)
	{
		std::cout << "请输入订阅期限：";
		int deadline;
		std::cin >> deadline;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (deadline == (*use).deadline)
			{
				cout
					<< std::left << std::setw(10) << "编号"
					<< std::left << std::setw(10) << "订户名"
					<< std::left << std::setw(10) << "性别"
					<< std::left << std::setw(10) << "电话号码"
					<< std::left << std::setw(10) << "杂志单位"
					<< std::left << std::setw(10) << "订阅数"
					<< std::left << std::setw(10) << "订阅期限" << endl;
				cout
					<< std::left << std::setw(10) << (*use).number
					<< std::left << std::setw(10) << (*use).name
					<< std::left << std::setw(10) << (*use).sex
					<< std::left << std::setw(10) << (*use).phone
					<< std::left << std::setw(10) << (*use).unit
					<< std::left << std::setw(10) << (*use).count
					<< std::left << std::setw(10) << (*use).deadline << endl;
			}
	}

	else if (flag == -1)
		std::cout << "【输入错误】" << endl;
	std::cout << "统计结束！";

}


//选择
void keydown()
{
	int choice{ 0 };
	cin >> choice;
	switch (choice) {
	case 0:
		exit(0);
		break;
	case 1:
		system("cls");
		cout << "************【添加信息】************" << endl;
		inputUser();
		break;
	case 2:
		system("cls");
		cout << "************【查找信息】************" << endl;
		searchUser();
		break;
	case 3:
		system("cls");
		cout << "************【显示信息】************" << endl;
		printfUser();
		break;
	case 4:
		system("cls");
		cout << "************【编辑信息】************" << endl;
		changeUser();
		break;
	case 5:
		system("cls");
		cout << "************【删除信息】************" << endl;
		deleteUser();
		break;
	case 6:
		system("cls");
		cout << "************【统计信息】************" << endl;
		statisticsUser();
		break;
	default:
		std::cout << "【功能数字输入错误】" << endl;
		break;

	}
	system("pause");//按任意键继续，不消失
	system("cls");//清屏，防止 主菜单连续出现

}



int main()
{
	User user1 = { 1, "小明", "男", 111, "单位1", 1, 202501 };
	uselist.push_back(user1);
	User user2 = { 2, "小红", "女", 222, "单位2", 3, 202502 };
	uselist.push_back(user2);
	User user3 = { 3, "小李", "男", 333, "单位1", 5, 202502 };
	uselist.push_back(user3);

	while (1)
	{
		system("cls");
		menu();
		keydown();
	}
	system("pause");
	return 0;
}


