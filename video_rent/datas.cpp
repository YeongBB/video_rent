#include"header.h"

vector<guest> add_user(vector<guest> da, guest human)					// ���θ���� / �߰�
{
	string temp;			// ���� ������
	int tem = 0;			// ���� ������
	cout << " �Է��ϼ���" << endl;
	cout << "---------------------" << endl;
	cout << " �̸� : ";
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
			cout << " �� ���̵�� ��� �Ұ��մϴ�. �ٽ� �Է��� �ּ���." << endl;
			cout << " ID : ";		
		}
		else if (t == 1)
		{
			cout << " �̹� ���� ���̵� �ֽ��ϴ�. �ٽ� �Է��� �ּ���." << endl;
			cout << " ID : ";
		}

		else
			break;
		cin >> human.ID;
	}
	cout << " ��й�ȣ : ";
	cin >> human.PASS;
	cout << " ���� : ";
	while (1)
	{
		if (scanf_s("%d", &human.age) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
		else
		{
			if (human.age > 0 && human.age < 130)
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << " - �� �����ϰ� �Է��� �ּ���." << endl;
	cout << " ��ȭ��ȣ : ";
	cin >> human.phone;
	while (atoi(human.phone.c_str()) <= 100000000 || atoi(human.phone.c_str()) >= 1199999999)		// ��ȭ��ȣ 010-000-0000 ~ 011~9999-9999 ����
	{
		cout << " �ٽ� �Է��ϼ��� " << endl;
		cout << " ��ȭ��ȣ : ";
		cin >> human.phone;
	}

	getchar();
	cout << " �ּ� : ";
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
	cout << "\n-----ȸ�� ���� �Ϸ�-----\n" << endl;
	return da;
}

// �Ʒ��� ���...
vector<guest> delete_data(vector<guest> da)	// �մ� ������ ����		���� 0 ���� x
{
	int num = 0;
	cout << "������ ��ȣ�� �Է��ϼ���\n �Է� :";
	cin >> num;
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
		else
		{
			if (num > 0 && num <= da.size())
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
	}
	vector<guest>::iterator iter = da.begin();
	iter += (num);
	da.erase(iter);
	cout << "\n----���� �Ϸ�----" << endl;
	return da;
}
vector<guest> delete_data_user(vector<guest> da, string ID)		// ȸ�� Ż��
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

	cout << " Ż�� �ϽǷ��� ȸ�� �̸��� ���̸� �Է��� �ּ���\n";
	cout << " �̸� : ";	cin >> namea;
	cout << " ���� : ";
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
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
		cout << "\n---- Ż�� �Ϸ� ----" << endl;
	}
	else
	{
		cout << " ��ġ���� �ʽ��ϴ�. �����մϴ�." << endl;
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
	cout << " �̸� : " << da[co].name << " -> ";	cin >> da[co].name;
	cout << " ��й�ȣ : " << da[co].PASS << " -> ";	cin >> da[co].PASS;
	cout << " ���� : " << da[co].age << " -> ";
	while (1)
	{
		if (scanf_s("%d", &da[co].age) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : " << da[co].age << " -> ";
			rewind(stdin);
		}
		else
		{
			if (da[co].age > 0 && da[co].age < 130)
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : " << da[co].age << " -> ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " ��ȭ��ȣ : " << da[co].phone << " -> ";	cin >> da[co].phone;

	while (atoi(da[co].phone.c_str()) <= 100000000 || atoi(da[co].phone.c_str()) >= 1199999999)					// ��ȭ��ȣ
	{
		cout << " �ٽ� �Է��ϼ��� " << endl;
		cout << " ��ȭ��ȣ : " << da[co].phone << " -> ";
		cin >> da[co].phone;
	}
	getchar();
	cout << " �ּ�: " << da[co].address << " -> ";	getline(cin, da[co].address);
	cout << "-----�Ϸ�-----" << endl;
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
	cout << " �Է��ϼ���" << endl;
	cout << "---------------------" << endl;
	getchar();
	cout << " ���� : ";
	getline(cin, vi.vname);
	cout << " ���������� ��ü�̿밡�� 1�� �Է��� �ּ���." << endl;
	cout << " �������� : ";
	while (1)
	{
		if (scanf_s("%d", &vi.age) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �������� : ";
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �������� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " �帣 : ";
	getline(cin, vi.gen);
	cout << " ������ 0���̸� 1�� �Է��� �ּ���." << endl;
	cout << " ���� : ";
	while (1)
	{
		if (scanf_s("%d", &vi.price) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << " ������ 0���� 10000�� �Է��� �ּ���." << endl;;
	cout << " ���� : ";
	while (1)
	{
		if (scanf_s("%d", &vi.re) == 0)
		{
			cout << " 1�ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
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
			cout << " 2�ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	rewind(stdin);
	va.push_back(vi);
	cout << "\n-----�߰��Ϸ�-----\n" << endl;
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
vector<video> delete_video(vector<video> va)	// ���� ����
{
	int num = 0;
	if (va.size()==0)
	{
		cout << " ������ �������� �ʽ��ϴ�" << endl;
		return va;
	}
	else
	{
		for (int a = 0; a < va.size(); a++)
			cout <<" "<<a+1<<". "<< va[a].vname << endl;
	}
	cout << "������ ��ȣ�� �Է��ϼ���\n �Է� :";
	while (1)
	{
		if (scanf_s("%d", &num) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
		else
		{
			if (num > 0 && num <= va.size())
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
	}
	vector<video>::iterator iter = va.begin();
	iter += (num - 1);
	va.erase(iter);
	cout << "\n----���� �Ϸ�----" << endl;
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

	cout << " ������ ���� ��ȣ�� �����ϼ���";
	cout << " �Է� : ";
	while (1)
	{
		if (scanf_s("%d", &viname) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
		else
		{
			if (viname > 0 && viname <= va.size())
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	viname -= 1;
	cout << " ���� : " << va[viname].vname << " -> ";	cin >> va[viname].vname;

	cout << " ���������� ��ü�̿밡�� 1�� �Է��� �ּ���." << endl;
	cout << " �������� : " << va[viname].age << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].age) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �������� : ";
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �������� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " ������ 0�̸�  1�� �Է��� �ּ���." << endl;
	cout << " ���� : " << va[viname].price << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].price) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : " << va[viname].price << " -> ";
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : " << va[viname].price << " -> ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');

	cout << " ������ 0���� 10000�� �Է��� �ּ���." << endl;
	cout << " ���� : " << va[viname].re << " -> ";
	while (1)
	{
		if (scanf_s("%d", &va[viname].re) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
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
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
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