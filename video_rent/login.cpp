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
	cout << " 이름을 입력하세요 : ";
	cin >> name;
	cout << " 전화번호를 입력하세요( - 제외) :";
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
		cout << " 이름 또는 전화번호가 일치하지 않습니다." << endl << endl;
}
void finePAss(vector<guest> da)
{
	string name;			// 이름
	string ID;			// 아이디	
	int count = 0;
	cout << " 이름을 입력하세요 : ";
	cin >> name;
	cout << " ID를 입력하세요 :";
	cin >> ID;
	if (ID == "Master")
	{
		cout << "Master 계정은 프로그램 제작자에게 문의주세요" << endl;
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
		cout << " 이름 또는 아이디가 일치하지 않습니다." << endl << endl;
}