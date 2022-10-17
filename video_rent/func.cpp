#include"header.h"

void search(vector<guest> da, vector<video> va, int M)
{
	string input;
	int count = 0;
	string guestname;
	string search_;

	if (M == 1)
	{
		count = 0;
		cout << "���˻� : 1\t ���� �˻� : 2\t �˻� ���� : 3" << endl;
		cout << " �Է� : ";
		cin >> input;
		while (input != "1" && input != "2" && input != "3")
		{
			cout << " �ٽ� �Է��ϼ���" << endl;
			cout << " �Է� :";
			cin >> input;
		}

		if (input == "1")
		{
			cout << " �˻��� �� �̸��� �Է��ϼ��� : ";
			cin >> guestname;
			for (int q = 0; q < da.size(); q++)
			{
				if (guestname == da[q].name)
				{	
					cout << " ----------------------" << endl;
					cout << " �̸� : " << da[q].name << endl;
					cout << " ���� : " << da[q].age << endl;
					cout << " ��ȭ��ȣ : " << da[q].phone << endl;
					cout << " �ּ� : " << da[q].address << endl;
					cout << " �뿩���� ���� : " << da[q].video << endl;
					cout << " �ܾ� : " << da[q].money << endl << endl;
					count++;
				}
			}
			if (count > 0)
				cout << " " << count << "���� �˻������ �ֽ��ϴ�" << endl;
			else
				cout << " �˻���� : ���� " << endl;
			cout << " ----------------------" << endl;

		}
		else if (input == "2")
		{
			count = 0;
			search_ == "";
			cout << " ���� �˻� : 1\t �帣 �˻� : 2\n " << endl;
			cout << " �Է� : ";
			cin >> input;
			while (input != "1" && input != "2")
			{
				cout << " �ٽ� �Է��ϼ���" << endl;
				cout << " �Է� :";
				cin >> input;
			}
			if (input == "1")
			{
				cout << " �˻��� ���� �̸��� �Է��ϼ��� : ";
				cin >> search_;
				cout << " ----------------------" << endl;
				for (int b = 0; b < va.size(); b++)
				{
					if (va[b].vname.find(search_) != string::npos)
					{
						cout << " " << b + 1 << ".	 " << va[b].vname << endl;
						count++;
					}
				}
				if (count > 0)
				{
					cout << " ----------------------" << endl;
					cout << " " << count << "���� �˻������ �ֽ��ϴ�" << endl;
					cout << " ----------------------" << endl;
				}
				else
					cout << " �˻���� : ���� " << endl;
			}
			else
			{
				cout << " �˻��� �帣�� �Է��ϼ���. \n �Է� :";
				cin >> search_;
				cout << " ----------------------" << endl;
				for (int b = 0; b < va.size(); b++)
				{
					if (va[b].gen.find(search_) != string::npos)
					{
						cout << " " << b + 1 << ". " << va[b].vname << endl;
						count++;
					}
				}
				if (count > 0)
				{
					cout << " ----------------------" << endl;
					cout << " " << count << "���� �˻������ �ֽ��ϴ�" << endl;
					cout << " ----------------------" << endl;
				}
				else
					cout << " �˻���� : ���� " << endl;
			}
		}
		else
		{
			cout << " -- �˻� ���� --" << endl;
			return;
		}
	}
	else
	{
		count = 0;
		cout << " ���� �˻� : 1\t �帣 �˻� : 2\n " << endl;
		cout << " �Է� : ";
		cin >> input;
		while (input != "1" && input != "2")
		{
			cout << " �ٽ� �Է��ϼ���" << endl;
			cout << " �Է� :";
			cin >> input;
		}
		if (input == "1")
		{
			cout << " �˻��� ���� �̸��� �Է��ϼ��� : ";
			cin >> search_;
			cout << " ----------------------" << endl;
			for (int b = 0; b < va.size(); b++)
			{
				if (va[b].vname.find(search_) != string::npos)
				{
					cout << " " << b + 1 << ".	 " << va[b].vname << endl;
					count++;
				}
			}
			if (count > 0)
			{	
				cout << " ----------------------" << endl;
				cout << " " << count << "���� �˻������ �ֽ��ϴ�" << endl;
				cout << " ----------------------" << endl;
			}
			else
				cout << " �˻���� : ���� " << endl;
		}
		else
		{
			cout << " �˻��� �帣�� �Է��ϼ���. \n �Է� :";
			cin >> search_;
			cout << " ----------------------" << endl;
			for (int b = 0; b < va.size(); b++)
			{
				if (va[b].gen.find(search_) != string::npos)
				{
					cout << " " << b + 1 << ". " << va[b].vname << endl;
					count++;
				}
			}
			if (count > 0)
			{
				cout << " " << count << "���� �˻������ �ֽ��ϴ�" << endl;
				cout << " ----------------------" << endl;
			}
			else
				cout << " �˻���� : ���� " << endl;
		}

	}
	while (getchar() != '\n');
}

void output_guest(vector<guest> da)
{
	int count = 0;
	if (da.size() == 1)
		{
			cout << " �� ����� �����ϴ�" << endl;
			return;
		}
	for (int h = 1; h < da.size(); h++)
	{			
		cout << " - " << h  << " - " << endl;
		cout << " �̸� : " << da[h].name << endl;
		cout << " ���� : " << da[h].age << endl;
		cout << " ���̵� : " << da[h].ID << endl;
		cout << " ��й�ȣ : " << da[h].PASS << endl;
		cout << " ��ȭ��ȣ : " << da[h].phone << endl;
		cout << " �ּ� : " << da[h].address << endl;
		cout << " �뿩���� ���� : " << da[h].video << endl;
		cout << " �ܾ� : " << da[h].money << endl;
		cout << endl;
	}
}
void output_video(vector<video> va)
{	
	int count = 0;
	if (va.size() == 0)
	{
		cout << " ���� ����� �����ϴ�" << endl;
		return;
	}
	for (int h = 0; h < va.size(); h++)
	{	
		cout << " - " << h + 1 << " - " << endl;
		cout << " ���� : " << va[h].vname << endl;
		cout << " �帣 : " << va[h].gen << endl;
		cout << " �������� : " << va[h].age << endl;
		cout << " ���� : " << va[h].price << endl;
		cout << " �ܷ� : " << va[h].re << endl;
		cout << endl;
	}
}
vector<guest> charge_money(vector<guest> da, string id)
{
	int co = 0;
	int chmo = 0;
	while (1)
	{
		if (da[co].ID == id)
			break;
		co++;
	}

	cout << " ���� �ݾ��� �Է��ϼ���." << endl;
	cout << " �Է� : ";
	while (1)
	{
		if (scanf_s("%d", &chmo) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
		else
		{
			if (chmo > 0 && chmo < 100000000)			// MAx money
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " ���� : ";
			rewind(stdin);
		}
	}
	da[co].money += chmo;
	cout << " ���� �Ϸ�" << endl;
	cout << " ���� �ݾ� : " << da[co].money << endl;
	cout << "---------------------" << endl;
	return da;
}
pair<vector<guest>, vector<video>> video_rental(vector<guest> da, vector<video> va, string id)
{
	int co = 0;
	int vd = 0;
	if (va.size() == 0)
	{
		cout << " ������ �������� �ʽ��ϴ�" << endl;
		return { da,va };
	}
	while (1)
	{
		if (da[co].ID == id)
			break;
		co++;
	}
	if (da[co].video != "")
	{
		cout << " �̹� �뿩���� ������ �ֽ��ϴ�" << endl << endl;
		return { da,va };
	}
	cout << "--------------" << endl;
	for (int g = 0; g < va.size(); g++)
		cout << " " << g + 1 << ". " << va[g].vname << ". " << endl;
	cout << "--------------" << endl;
	cout << " ���� ������ �����ϼ���( ��ȣ ) :";
	while (1)
	{
		if (scanf_s("%d", &vd) == 0)
		{
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
		else
		{
			if (vd > 0 && vd <= va.size())
				break;
			cout << " �ٽ� �Է��ϼ��� " << endl;
			cout << " �Է� : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << "--------------" << endl;
	vd -= 1;
	if (va[vd].re == 0)
	{
		cout << "���� ���� ��� �����ϴ�" << endl;
		return { da,va };
	}
	else if (da[co].age - va[vd].age < 0)
	{
		cout << " ���� �Ұ�" << endl;
		return { da,va };
	}
	else if (da[co].money - va[vd].price >= 0)
	{
		da[co].video = va[vd].vname;
		da[co].money -= va[vd].price;
		va[vd].re -= 1;
		cout << " --���� �뿩 �Ϸ�--" << endl;
	}
	else
		cout << " �ܾ��� �����մϴ�. ������ �ּ���( ���� : ���� -> �ݾ� ���� )" << endl;

	return { da,va };
}
pair<vector<guest>, vector<video>>  video_return(vector<guest> da, vector<video> va, string id)
{
	int co = 0;
	int vd = 0;
	while (1)
	{
		if (da[co].ID == id)
			break;
		co++;
	}
	if (da[co].video == "")
	{
		cout << " �뿩���� ������ �����ϴ�." << endl;
		return{ da,va };
	}

	while (1)
	{
		if (va[vd].vname == da[co].video)
		{
			da[co].video = "";
			va[vd].re += 1;
			break;
		}
		vd++;
	}
	cout << " -- �ݳ� �Ϸ� -- " << endl << endl;
	return { da,va };
}