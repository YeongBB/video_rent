#include"header.h"

int login(vector<guest> da, string id, string pass)
{
	for (int h = 0; h < da.size(); h++)
	{
		if (id == da[h].ID && pass == da[h].PASS)
			return 1;
	}
	return 0;
}

void fineID(vector<guest> da)
{
	string name;
	string phone;
	int count = 0;
	cout << " �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << " ��ȭ��ȣ�� �Է��ϼ���( - ����) :";
	cin >> phone;
	for (int h = 1; h < da.size(); h++)
	{
		if (name == da[h].name && phone == da[h].phone)
		{
			cout << "ID : " << da[h].ID << endl << endl;
			count++;
		}
	}
	if (count == 0)
		cout << " �̸� �Ǵ� ��ȭ��ȣ�� ��ġ���� �ʽ��ϴ�." << endl << endl;
}
void finePAss(vector<guest> da)
{
	string name;			// �̸�
	string ID;			// ���̵�	
	int count = 0;
	cout << " �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << " ID�� �Է��ϼ��� :";
	cin >> ID;
	if (ID == "Master")
	{
		cout << "Master ������ ���α׷� �����ڿ��� �����ּ���" << endl;
		return;
	}
	for (int h = 1; h < da.size(); h++)
	{
		if (name == da[h].name && ID == da[h].ID)
		{
			cout << " PASS : " << da[h].PASS << endl;
			count++;
		}
	}
	if (count == 0)
		cout << " �̸� �Ǵ� ���̵� ��ġ���� �ʽ��ϴ�." << endl << endl;
}