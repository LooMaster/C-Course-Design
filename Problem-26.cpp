#include<iostream>
#include<list>
#include<Windows.h>
#include<iomanip>

using namespace std;


//����ṹ��
typedef struct
{
	int number;          //��� 
	string name;         //������
	string sex;          //�Ա�
	int phone;           //�绰����
	string unit;         //��־��λ
	int count;           //������
	int deadline;        //��������
}User;
list<User> uselist;  //list ����
list<User>::iterator use;//��������� stu��������list����


//���˵�
void menu()
{
	cout << "***********��ӭʹ����־���Ĺ���ϵͳ**********" << endl;
	cout << "*                                           *" << endl;
	cout << "*********************************************" << endl;
	cout << "*           ����������ʵ�ֶ�Ӧ����          *" << endl;
	cout << "*********************************************" << endl;
	cout << "*         0-�˳�ϵͳ                        *" << endl;
	cout << "*                                           *" << endl;
	cout << "*     �û���Ϣ��                            *" << endl;
	cout << "*         1-����¶���                      *" << endl;
	cout << "*         2-���Ҷ�����Ϣ                    *" << endl;
	cout << "*         3-��ʾ���ж����ĸ�����Ϣ          *" << endl;
	cout << "*         4-�༭��Ϣ                        *" << endl;
	cout << "*         5-ɾ����Ϣ                        *" << endl;
	cout << "*         6-ͳ����Ϣ                        *" << endl;
	cout << "*********************************************" << endl;
	cout << "                                             " << endl;
	cout << "�����빦�ܶ�Ӧ���ֺ�س�:";
}


//�Զ��庯��

//¼��
void inputUser()
{
	cout
		<< std::left << std::setw(10) << "���"
		<< std::left << std::setw(10) << "������"
		<< std::left << std::setw(10) << "�Ա�"
		<< std::left << std::setw(10) << "�绰����"
		<< std::left << std::setw(10) << "��־��λ"
		<< std::left << std::setw(10) << "������"
		<< std::left << std::setw(10) << "�������ޣ���202501��" << endl;
	cout << "����һ���س���" << endl;
	User data;
	cin >> data.number >> data.name >> data.sex >> data.phone 
	    >> data.unit >> data.count >> data.deadline;
	uselist.push_back(data);//������β������Ԫ��
	//int number;               //��� 
	//string name;              //������
	//int sex;                  //�Ա�
	//int phone;                //�绰����
	//string unit;              //��־��λ
	//int count;                //������
	//int deadline;             //��������

	return;
}

//���
void printfUser()
{
	cout
		<< std::left << std::setw(10) << "���"
		<< std::left << std::setw(10) << "������"
		<< std::left << std::setw(10) << "�Ա�"
		<< std::left << std::setw(10) << "�绰����"
		<< std::left << std::setw(10) << "��־��λ"
		<< std::left << std::setw(10) << "������"
		<< std::left << std::setw(10) << "��������" << endl;
	for (use = uselist.begin(); use != uselist.end(); use++)//���õ�����use����list����
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

//�޸�
void changeUser()
{
	string str;
	bool f = true;
	cout << "��������Ҫ�޸ĵĶ���������" << endl;
	cin >> str;
	for (use = uselist.begin(); use != uselist.end(); use++)
		if (str == (*use).name)
		{
			cout
				<< std::left << std::setw(10) << "���"
				<< std::left << std::setw(10) << "������"
				<< std::left << std::setw(10) << "�Ա�"
				<< std::left << std::setw(10) << "�绰����"
				<< std::left << std::setw(10) << "��־��λ"
				<< std::left << std::setw(10) << "������"
				<< std::left << std::setw(10) << "��������" << endl;
			cout
				<< std::left << std::setw(10) << (*use).number
				<< std::left << std::setw(10) << (*use).name
				<< std::left << std::setw(10) << (*use).sex
				<< std::left << std::setw(10) << (*use).phone
				<< std::left << std::setw(10) << (*use).unit
				<< std::left << std::setw(10) << (*use).count
				<< std::left << std::setw(10) << (*use).deadline << endl;
			cout << "*********************************************" << endl;
			cout << "�������޸ĺ���Ϣ(����һ���س�)��" << endl;

			cout
				<< std::left << std::setw(10) << "���"
				<< std::left << std::setw(10) << "������"
				<< std::left << std::setw(10) << "�Ա�"
				<< std::left << std::setw(10) << "�绰����"
				<< std::left << std::setw(10) << "��־��λ"
				<< std::left << std::setw(10) << "������"
				<< std::left << std::setw(10) << "�������ޣ���202501��" << endl;
			User data;
			cin >> data.number >> data.name >> data.sex >> data.phone >> data.unit >> data.count >> data.deadline;
			*use = data;
			cout << "�޸ĳɹ���" << endl;
			f = !f;
		}
	if (f)
		cout << "�ö�������Ϣ�����ڣ�" << endl;
	return;
}

//ɾ��
void deleteUser()
{
	string str;
	bool f = true;
	cout << "��������Ҫɾ���Ķ�����������" << endl;
	cin >> str;
	for (use = uselist.begin(); use != uselist.end(); use++)
		if (str == (*use).name)
		{
			uselist.erase(use);
			cout << "ɾ���ɹ�" << endl;
			f = !f;
			break;
		}
	if (f)
		cout << "�ö�������Ϣ�����ڣ�" << endl;
	return;
}

//����
void searchUser()
{
	int op, flag = -1;
	std::cout << "������һ�ֲ������ͣ�<1>���� <2>�Ա�  <3>��λ" << endl;
	std::cin >> op;
	if (op == 1)
	{
		cout << "�����붩������";
		string name;
		cin >> name;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (name == (*use).name)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		cout << "�������Ա�";
		string sex;
		cin >> sex;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (sex == (*use).sex)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		cout << "�����뵥λ��";
		string unit;
		cin >> unit;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (unit == (*use).unit)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		std::cout << "���������" << endl;
	std::cout << "ͳ�ƽ�����";
}

//ͳ��
void statisticsUser()
{
	int op, flag = -1;

	std::cout << "*********************************************" << std::endl;
	std::cout << "*                 ���ļ�¼ͳ��              *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << endl;
	std::cout << "������һ�ֶ��ļ�¼���ͣ�<1>ȫ��  <2>�Ա�  <3>������  <4>��������" << endl;
	std::cin >> op;
	if (op == 1)
	{
		int amount, totalcount = 0;
		float total = 0, totalprise, simpleprise = 5.5;

		cout
			<< std::left << std::setw(10) << "������"
			<< std::left << std::setw(10) << "������"
			<< std::left << std::setw(10) << "����"
			<< std::left << std::setw(10) << "ȫ��" << endl;
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
			<< std::left << std::setw(10) << "�ϼ�"
			<< std::left << std::setw(10) << totalcount
			<< std::left << std::setw(10) << " "
			<< std::left << std::setw(10) << total << endl;;
		cout << endl;
	}
	else if (op == 2)
	{
		cout << "�������Ա�";
		string sex;
		cin >> sex;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (sex == (*use).sex)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		cout << "�����붩������";
		int count;
		cin >> count;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (count == (*use).count)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		std::cout << "�����붩�����ޣ�";
		int deadline;
		std::cin >> deadline;
		for (use = uselist.begin(); use != uselist.end(); use++)
			if (deadline == (*use).deadline)
			{
				cout
					<< std::left << std::setw(10) << "���"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "�Ա�"
					<< std::left << std::setw(10) << "�绰����"
					<< std::left << std::setw(10) << "��־��λ"
					<< std::left << std::setw(10) << "������"
					<< std::left << std::setw(10) << "��������" << endl;
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
		std::cout << "���������" << endl;
	std::cout << "ͳ�ƽ�����";

}


//ѡ��
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
		cout << "************�������Ϣ��************" << endl;
		inputUser();
		break;
	case 2:
		system("cls");
		cout << "************��������Ϣ��************" << endl;
		searchUser();
		break;
	case 3:
		system("cls");
		cout << "************����ʾ��Ϣ��************" << endl;
		printfUser();
		break;
	case 4:
		system("cls");
		cout << "************���༭��Ϣ��************" << endl;
		changeUser();
		break;
	case 5:
		system("cls");
		cout << "************��ɾ����Ϣ��************" << endl;
		deleteUser();
		break;
	case 6:
		system("cls");
		cout << "************��ͳ����Ϣ��************" << endl;
		statisticsUser();
		break;
	default:
		std::cout << "�����������������" << endl;
		break;

	}
	system("pause");//�����������������ʧ
	system("cls");//��������ֹ ���˵���������

}



int main()
{
	User user1 = { 1, "С��", "��", 111, "��λ1", 1, 202501 };
	uselist.push_back(user1);
	User user2 = { 2, "С��", "Ů", 222, "��λ2", 3, 202502 };
	uselist.push_back(user2);
	User user3 = { 3, "С��", "��", 333, "��λ1", 5, 202502 };
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


