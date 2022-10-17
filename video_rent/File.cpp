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
			out << da[a].name << endl;		// 이름
			out << da[a].ID << endl;		// 아이디
			out << da[a].PASS << endl;		// 비밀번호
			out << da[a].age << endl;		// 나이
			out << da[a].phone << endl;	// 전화번호
			out << da[a].address << endl;	// 주소
			out << da[a].video << endl;	// 대여중인 비디오
			if (a + 1 == da.size())
				out << da[a].money << endl;// 잔액
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

	if (fp.is_open())				// Data파일이 있을때
	{
		while (!fp.eof())
		{
			getline(fp, line);
			human.name = line;				// 이름
			getline(fp, line);
			human.ID = line;					// 아이디
			getline(fp, line);
			human.PASS = line;				// 비밀번호	
			getline(fp, line);
			human.age = atoi(line.c_str());					// 나이
			getline(fp, line);
			human.phone = line;				// 전화번호
			getline(fp, line);
			human.address = line;				// 주소
			getline(fp, line);
			human.video = line;				// 대여중인 비디오
			getline(fp, line);
			human.money = atoi(line.c_str());	// 잔액
			getline(fp, line);
			da.push_back(human);
		}
	}
	else										// Data 파일이 없을때
	{
		ofstream out(filename);
		if (out.is_open())
		{
			out << "Master" << endl;		// 관리자 이름
			out << "Master" << endl;		// 관리자 아이디
			out << "0000" << endl;		// 관리자 비밀번호
			out << 129 << endl;			// 관리자 나이
			out << "" << endl;			// 관리자 전화번호
			out << "" << endl;			// 관리자 주소
			out << "" << endl;			// 관리자 대여중인 비디오			
			out << 9999999 << endl;		// 관리자 잔액		
			out << endl;
			out.close();
		}

		human.name = "Master";			// 관리자 이름
		human.ID = "Master";			// 관리자 아이디
		human.PASS = "0000";			// 관리자 비밀번호
		human.age = 129;				// 리자 나이
		human.phone = "";				// 관리자 전화번호
		human.video = "";				// 관리자 대여중인 비디오	
		human.money = 99999999;		// 관리자 잔액
		human.address = "";			// 관리자 주소
		da.push_back(human);
	}
	fp.close();
	return da;
}

// 아래는 비디오 데이터
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

	if (fp.is_open())				// Video파일이 있을때
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
	else					// vita 파일이 없을때
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