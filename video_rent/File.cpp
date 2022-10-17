#include"header.h"
#include<direct.h>
void filesave_guest(vector<guest> da)
{
	string filename = "C:\\Temp\\Data.txt";
	ofstream out(filename);
	if (out.is_open())
	{
		for (int a = 0; a < da.size(); a++)
		{
			out << da[a].name << endl;		// �̸�
			out << da[a].ID << endl;		// ���̵�
			out << da[a].PASS << endl;		// ��й�ȣ
			out << da[a].age << endl;		// ����
			out << da[a].phone << endl;	// ��ȭ��ȣ
			out << da[a].address << endl;	// �ּ�
			out << da[a].video << endl;	// �뿩���� ����
			if (a + 1 == da.size())
				out << da[a].money << endl;// �ܾ�
			else
			{
				out << da[a].money << endl;
				out << endl;
			}
		}
	}
	out.close();
}
vector<guest> filecalls_guest(vector<guest> da, guest human)
{
	string folder = "C:\\Temp";
	ifstream fp;
	string filename = "C:\\Temp\\Data.txt";
	string line;
	fp.open(filename);
	_mkdir(folder.c_str());

	if (fp.is_open())				// Data������ ������
	{
		while (!fp.eof())
		{
			getline(fp, line);
			human.name = line;				// �̸�
			getline(fp, line);
			human.ID = line;					// ���̵�
			getline(fp, line);
			human.PASS = line;				// ��й�ȣ	
			getline(fp, line);
			human.age = atoi(line.c_str());					// ����
			getline(fp, line);
			human.phone = line;				// ��ȭ��ȣ
			getline(fp, line);
			human.address = line;				// �ּ�
			getline(fp, line);
			human.video = line;				// �뿩���� ����
			getline(fp, line);
			human.money = atoi(line.c_str());	// �ܾ�
			getline(fp, line);
			da.push_back(human);
		}
	}
	else										// Data ������ ������
	{
		ofstream out(filename);
		if (out.is_open())
		{
			out << "Master" << endl;		// ������ �̸�
			out << "Master" << endl;		// ������ ���̵�
			out << "0000" << endl;		// ������ ��й�ȣ
			out << 129 << endl;			// ������ ����
			out << "" << endl;			// ������ ��ȭ��ȣ
			out << "" << endl;			// ������ �ּ�
			out << "" << endl;			// ������ �뿩���� ����			
			out << 9999999 << endl;		// ������ �ܾ�		
			out << endl;
			out.close();
		}

		human.name = "Master";			// ������ �̸�
		human.ID = "Master";			// ������ ���̵�
		human.PASS = "0000";			// ������ ��й�ȣ
		human.age = 129;				// ���� ����
		human.phone = "";				// ������ ��ȭ��ȣ
		human.video = "";				// ������ �뿩���� ����	
		human.money = 99999999;		// ������ �ܾ�
		human.address = "";			// ������ �ּ�
		da.push_back(human);
	}
	fp.close();
	return da;
}

// �Ʒ��� ���� ������
void filesave_video(vector<video> vi)
{
	string filename = "C:\\Temp\\Video.txt";
	ofstream out(filename);

	if (out.is_open())
	{
		for (int a = 0; a < vi.size(); a++)
		{
			out << vi[a].vname << endl;
			out << vi[a].age << endl;
			out << vi[a].gen << endl;
			out << vi[a].price << endl;
			if (a + 1 == vi.size())
				out << vi[a].re << endl;
			else
			{
				out << vi[a].re << endl;
				out << endl;
			}
		}
	}
	out.close();
}
vector<video> filecalls_video(vector<video> va, video vi)
{
	ifstream fp;
	string filename = "C:\\Temp\\Video.txt";
	string line;
	fp.open(filename);

	if (fp.is_open())				// Video������ ������
	{
		while (!fp.eof())
		{	
			getline(fp, line);
			if (line == "")
				break;
			vi.vname = line;
			getline(fp, line);
			vi.age = atoi(line.c_str());
			getline(fp, line);
			vi.gen = line;
			getline(fp, line);
			vi.price = atoi(line.c_str());
			getline(fp, line);
			vi.re = atoi(line.c_str());
			getline(fp, line);
			va.push_back(vi);
		}
	}
	else					// vita ������ ������
	{
		ofstream out(filename);
		if (out.is_open())
		{	
			
		}
		out.close();
	}
	fp.close();
	return va;
}