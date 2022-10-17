#include"header.h"

vector<guest> add_user(vector<guest> da, guest human)					// 새로만들기 / 추가
{
	string temp;			// 정렬 문자형
	int tem = 0;			// 정렬 정수형
	cout << " 입력하세요" << endl;
	cout << "---------------------" << endl;
	cout << " 이름 : ";
	cin >> human.name;
	cout << " ID : ";
	cin >> human.ID;
	while (1)
	{
		int t = 0;
		for (int r = 0; r < da.size(); r++)
		{
			if (human.ID == da[r].ID)
				t = 1;
		}
		if (human.ID == "Master")
		{
			cout << " 이 아이디는 사용 불가합니다. 다시 입력해 주세요." << endl;
			cout << " ID : ";		
		}
		else if (t == 1)
		{
			cout << " 이미 같은 아이디가 있습니다. 다시 입력해 주세요." << endl;
			cout << " ID : ";
		}

		else
			break;
		cin >> human.ID;
	}
	cout << " 비밀번호 : ";
	cin >> human.PASS;
	cout << " 나이 : ";
	while (1)
	{
		if (scanf_s("%d", &human.age) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 나이 : ";
			rewind(stdin);
		}
		else
		{
			if (human.age > 0 && human.age < 130)
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 나이 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << " - 를 제외하고 입력해 주세요." << endl;
	cout << " 전화번호 : ";
	cin >> human.phone;
	while (atoi(human.phone.c_str()) <= 100000000 || atoi(human.phone.c_str()) >= 1199999999)		// 전화번호 010-000-0000 ~ 011~9999-9999 범위
	{
		cout << " 다시 입력하세요 " << endl;
		cout << " 전화번호 : ";
		cin >> human.phone;
	}

	getchar();
	cout << " 주소 : ";
	getline(cin, human.address);
	da.push_back(human);

	for (int t = 1; t < da.size(); t++)
	{
		for (int j = 1; j < da.size() - 1; j++)
		{
			if (da[j].name > da[j + 1].name)
			{
				temp = da[j].name;
				da[j].name = da[j + 1].name;
				da[j + 1].name = temp;

				tem = da[j].age;
				da[j].age = da[j + 1].age;
				da[j + 1].age = tem;

				temp = da[j].ID;
				da[j].ID = da[j + 1].ID;
				da[j + 1].ID = temp;

				temp = da[j].PASS;
				da[j].PASS = da[j + 1].PASS;
				da[j + 1].PASS = temp;

				temp = da[j].phone;
				da[j].phone = da[j + 1].phone;
				da[j + 1].phone = temp;

				temp = da[j].address;
				da[j].address = da[j + 1].address;
				da[j + 1].address = temp;

				temp = da[j].video;
				da[j].video = da[j + 1].video;
				da[j + 1].video = temp;

				tem = da[j].money;
				da[j].money = da[j + 1].money;
				da[j + 1].money = tem;
			}
		}
	}
	cout << "\n-----회원 가입 완료-----\n" << endl;
	return da;
}

// 아래는 고려...
vector<guest> delete_data(vector<guest> da)	// 손님 데이터 삭제		구현 0 적용 x
{
	int num = 0;
	cout << "삭제할 번호를 입력하세요\n 입력 :";
	cin >> num;
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 입렵 : ";
			rewind(stdin);
		}
		else
		{
			if (num > 0 && num <= da.size())
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
	}
	vector<guest>::iterator iter = da.begin();
	iter += (num);
	da.erase(iter);
	cout << "\n----삭제 완료----" << endl;
	return da;
}
vector<guest> delete_data_user(vector<guest> da, string ID)		// 회원 탈퇴
{
	int num = 0;
	int count = 0;
	int it = 0;
	string namea;
	while (1)
	{
		if (da[it].ID == ID)
			break;
		it++;
	}

	cout << " 탈퇴를 하실려면 회원 이름과 나이를 입력해 주세요\n";
	cout << " 이름 : ";	cin >> namea;
	cout << " 나이 : ";
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 나이 : ";
			rewind(stdin);
		}
		else
		{
			if (num > 0)
				break;
		}
	}

	if (namea == da[it].name && num == da[it].age)
	{
		vector<guest>::iterator iter = da.begin();
		iter += (it);
		da.erase(iter);
		cout << "\n---- 탈퇴 완료 ----" << endl;
	}
	else
	{
		cout << " 일치하지 않습니다. 종료합니다." << endl;
	}
	return da;
}
vector<guest> modify_user(vector<guest> da, string id)
{	
	int tem = 0;
	string temp;
	int co = 0;
	cout << "---------------------" << endl;
	while (1)
	{
		if (id == da[co].ID)
			break;
		co++;
	}
	cout << " 이름 : " << da[co].name << " -> ";	cin >> da[co].name;
	cout << " 비밀번호 : " << da[co].PASS << " -> ";	cin >> da[co].PASS;
	cout << " 나이 : " << da[co].age << " -> ";
	while (1)
	{
		if (scanf_s("%d", &da[co].age) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 나이 : " << da[co].age << " -> ";
			rewind(stdin);
		}
		else
		{
			if (da[co].age > 0 && da[co].age < 130)
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 나이 : " << da[co].age << " -> ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " 전화번호 : " << da[co].phone << " -> ";	cin >> da[co].phone;

	while (atoi(da[co].phone.c_str()) <= 100000000 || atoi(da[co].phone.c_str()) >= 1199999999)					// 전화번호
	{
		cout << " 다시 입력하세요 " << endl;
		cout << " 전화번호 : " << da[co].phone << " -> ";
		cin >> da[co].phone;
	}
	getchar();
	cout << " 주소: " << da[co].address << " -> ";	getline(cin, da[co].address);
	cout << "-----완료-----" << endl;
	for (int t = 1; t < da.size(); t++)
	{
		for (int j = 1; j < da.size() - 1; j++)
		{
			if (da[j].name > da[j + 1].name)
			{
				temp = da[j].name;
				da[j].name = da[j + 1].name;
				da[j + 1].name = temp;

				tem = da[j].age;
				da[j].age = da[j + 1].age;
				da[j + 1].age = tem;

				temp = da[j].ID;
				da[j].ID = da[j + 1].ID;
				da[j + 1].ID = temp;

				temp = da[j].PASS;
				da[j].PASS = da[j + 1].PASS;
				da[j + 1].PASS = temp;

				temp = da[j].phone;
				da[j].phone = da[j + 1].phone;
				da[j + 1].phone = temp;

				temp = da[j].address;
				da[j].address = da[j + 1].address;
				da[j + 1].address = temp;

				temp = da[j].video;
				da[j].video = da[j + 1].video;
				da[j + 1].video = temp;

				tem = da[j].money;
				da[j].money = da[j + 1].money;
				da[j + 1].money = tem;
			}
		}
	}
	return da;
}

vector<video> add_video(vector<video> va, video vi)
{
	string temp;
	int tem = 0;
	cout << " 입력하세요" << endl;
	cout << "---------------------" << endl;
	getchar();
	cout << " 제목 : ";
	getline(cin, vi.vname);
	cout << " 연령제한이 전체이용가면 1을 입력해 주세요." << endl;
	cout << " 연령제한 : ";
	while (1)
	{
		if (scanf_s("%d", &vi.age) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 연령제한 : ";
			rewind(stdin);
		}
		else if (vi.age == 1)
		{
			vi.age = 0;
			break;
		}
		else
		{
			if (vi.age > 0 && vi.age < 20)				// 0 ~ age ~ 20
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 연령제한 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " 장르 : ";
	getline(cin, vi.gen);
	cout << " 가격이 0원이면 1을 입력해 주세요." << endl;
	cout << " 가격 : ";
	while (1)
	{
		if (scanf_s("%d", &vi.price) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : ";
			rewind(stdin);
		}
		else if (vi.price == 1)
		{
			vi.price = 0;
			break;
		}
		else
		{
			if (vi.price > 0 && vi.price < 100000000)			// MAx money
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << " 개수가 0개면 10000을 입력해 주세요." << endl;;
	cout << " 개수 : ";
	while (1)
	{
		if (scanf_s("%d", &vi.re) == 0)
		{
			cout << " 1다시 입력하세요 " << endl;
			cout << " 개수 : ";
			rewind(stdin);
		}
		else if (vi.re == 10000)
		{
			vi.re = 0;
			break;
		}
		else
		{
			if (vi.re > 0 && vi.re < 10000)					// MAx 9999
				break;
			cout << " 2다시 입력하세요 " << endl;
			cout << " 개수 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	rewind(stdin);
	va.push_back(vi);
	cout << "\n-----추가완료-----\n" << endl;
	for (int t = 0; t < va.size(); t++)
	{
		for (int j = 0; j < va.size() - 1; j++)
		{
			if (va[j].vname > va[j + 1].vname)
			{
				temp = va[j].vname;
				va[j].vname = va[j + 1].vname;
				va[j + 1].vname = temp;

				tem = va[j].age;
				va[j].age = va[j + 1].age;
				va[j + 1].age = tem;

				temp = va[j].gen;
				va[j].gen = va[j + 1].gen;
				va[j + 1].gen = temp;

				tem = va[j].price;
				va[j].price = va[j + 1].price;
				va[j + 1].price = tem;

				tem = va[j].re;
				va[j].re = va[j + 1].re;
				va[j + 1].re = tem;
			}
		}
	}
	return va;
}
vector<video> delete_video(vector<video> va)	// 비디오 삭제
{
	int num = 0;
	if (va.size()==0)
	{
		cout << " 비디오가 존재하지 않습니다" << endl;
		return va;
	}
	else
	{
		for (int a = 0; a < va.size(); a++)
			cout <<" "<<a+1<<". "<< va[a].vname << endl;
	}
	cout << "삭제할 번호를 입력하세요\n 입력 :";
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 입렵 : ";
			rewind(stdin);
		}
		else
		{
			if (num > 0 && num <= va.size())
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
	}
	vector<video>::iterator iter = va.begin();
	iter += (num - 1);
	va.erase(iter);
	cout << "\n----삭제 완료----" << endl;
	return va;
}
vector<video> modify_video(vector<video> va)
{
	int viname = 0;
	string temp;
	int tem = 0;
	for (int w = 0; w < va.size(); w++)
	{
		cout << w + 1 << ". " << va[w].vname << endl;
	}

	cout << " 수정할 비디오 번호를 선택하세요";
	cout << " 입력 : ";
	while (1)
	{
		if (scanf_s("%d", &viname) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
		else
		{
			if (viname > 0 && viname <= va.size())
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	viname -= 1;
	cout << " 제목 : " << va[viname].vname << " -> ";	cin >> va[viname].vname;

	cout << " 연령제한이 전체이용가면 1을 입력해 주세요." << endl;
	cout << " 연령제한 : " << va[viname].age << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].age) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 연령제한 : ";
			rewind(stdin);
		}
		else if (va[viname].age == 1)
		{
			va[viname].age = 0;
			break;
		}
		else
		{
			if (va[viname].age > 0 && va[viname].age < 20)				// 0 ~ age ~ 20
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 연령제한 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " 가격이 0이면  1을 입력해 주세요." << endl;
	cout << " 가격 : " << va[viname].price << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].price) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : " << va[viname].price << " -> ";
			rewind(stdin);
		}
		else if (va[viname].price == 1)
		{
			va[viname].price = 0;
			break;
		}
		else
		{
			if (va[viname].price > 0 && va[viname].price < 100000000)				// 0 ~ age ~ 20
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : " << va[viname].price << " -> ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " 개수가 0개면 10000을 입력해 주세요." << endl;
	cout << " 개수 : " << va[viname].re << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].re) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 개수 : ";
			rewind(stdin);
		}
		else if (va[viname].re == 1000)
		{
			va[viname].re = 0;
			break;
		}
		else
		{
			if (va[viname].re > 0 && va[viname].re < 9999)					// MAx 9999
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	rewind(stdin);
	for (int t = 0; t < va.size(); t++)
	{
		for (int j = 0; j < va.size() - 1; j++)
		{
			if (va[j].vname > va[j + 1].vname)
			{
				temp = va[j].vname;
				va[j].vname = va[j + 1].vname;
				va[j + 1].vname = temp;

				tem = va[j].age;
				va[j].age = va[j + 1].age;
				va[j + 1].age = tem;

				temp = va[j].gen;
				va[j].gen = va[j + 1].gen;
				va[j + 1].gen = temp;

				tem = va[j].price;
				va[j].price = va[j + 1].price;
				va[j + 1].price = tem;

				tem = va[j].re;
				va[j ].re = va[j + 1].re;
				va[j + 1].re = tem;
			}
		}
	}
	return va;
}