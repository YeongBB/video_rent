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
		cout << "고객검색 : 1\t 비디오 검색 : 2\t 검색 종료 : 3" << endl;
		cout << " 입력 : ";
		cin >> input;
		while (input != "1" && input != "2" && input != "3")
		{
			cout << " 다시 입력하세요" << endl;
			cout << " 입력 :";
			cin >> input;
		}

		if (input == "1")
		{
			cout << " 검색할 고객 이름을 입력하세요 : ";
			cin >> guestname;
			for (int q = 0; q < da.size(); q++)
			{
				if (guestname == da[q].name)
				{	
					cout << " ----------------------" << endl;
					cout << " 이름 : " << da[q].name << endl;
					cout << " 나이 : " << da[q].age << endl;
					cout << " 전화번호 : " << da[q].phone << endl;
					cout << " 주소 : " << da[q].address << endl;
					cout << " 대여중인 비디오 : " << da[q].video << endl;
					cout << " 잔액 : " << da[q].money << endl << endl;
					count++;
				}
			}
			if (count > 0)
				cout << " " << count << "개의 검색결과가 있습니다" << endl;
			else
				cout << " 검색결과 : 없음 " << endl;
			cout << " ----------------------" << endl;

		}
		else if (input == "2")
		{
			count = 0;
			search_ == "";
			cout << " 제목 검색 : 1\t 장르 검색 : 2\n " << endl;
			cout << " 입력 : ";
			cin >> input;
			while (input != "1" && input != "2")
			{
				cout << " 다시 입력하세요" << endl;
				cout << " 입력 :";
				cin >> input;
			}
			if (input == "1")
			{
				cout << " 검색할 비디오 이름을 입력하세요 : ";
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
					cout << " " << count << "개의 검색결과가 있습니다" << endl;
					cout << " ----------------------" << endl;
				}
				else
					cout << " 검색결과 : 없음 " << endl;
			}
			else
			{
				cout << " 검색할 장르를 입력하세요. \n 입력 :";
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
					cout << " " << count << "개의 검색결과가 있습니다" << endl;
					cout << " ----------------------" << endl;
				}
				else
					cout << " 검색결과 : 없음 " << endl;
			}
		}
		else
		{
			cout << " -- 검색 종료 --" << endl;
			return;
		}
	}
	else
	{
		count = 0;
		cout << " 제목 검색 : 1\t 장르 검색 : 2\n " << endl;
		cout << " 입력 : ";
		cin >> input;
		while (input != "1" && input != "2")
		{
			cout << " 다시 입력하세요" << endl;
			cout << " 입력 :";
			cin >> input;
		}
		if (input == "1")
		{
			cout << " 검색할 비디오 이름을 입력하세요 : ";
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
				cout << " " << count << "개의 검색결과가 있습니다" << endl;
				cout << " ----------------------" << endl;
			}
			else
				cout << " 검색결과 : 없음 " << endl;
		}
		else
		{
			cout << " 검색할 장르를 입력하세요. \n 입력 :";
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
				cout << " " << count << "개의 검색결과가 있습니다" << endl;
				cout << " ----------------------" << endl;
			}
			else
				cout << " 검색결과 : 없음 " << endl;
		}

	}
	while (getchar() != '\n');
}

void output_guest(vector<guest> da)
{
	int count = 0;
	if (da.size() == 1)
		{
			cout << " 고객 목록이 없습니다" << endl;
			return;
		}
	for (int h = 1; h < da.size(); h++)
	{			
		cout << " - " << h  << " - " << endl;
		cout << " 이름 : " << da[h].name << endl;
		cout << " 나이 : " << da[h].age << endl;
		cout << " 아이디 : " << da[h].ID << endl;
		cout << " 비밀번호 : " << da[h].PASS << endl;
		cout << " 전화번호 : " << da[h].phone << endl;
		cout << " 주소 : " << da[h].address << endl;
		cout << " 대여중인 비디오 : " << da[h].video << endl;
		cout << " 잔액 : " << da[h].money << endl;
		cout << endl;
	}
}
void output_video(vector<video> va)
{	
	int count = 0;
	if (va.size() == 0)
	{
		cout << " 비디오 목록이 없습니다" << endl;
		return;
	}
	for (int h = 0; h < va.size(); h++)
	{	
		cout << " - " << h + 1 << " - " << endl;
		cout << " 제목 : " << va[h].vname << endl;
		cout << " 장르 : " << va[h].gen << endl;
		cout << " 연령제한 : " << va[h].age << endl;
		cout << " 가격 : " << va[h].price << endl;
		cout << " 잔량 : " << va[h].re << endl;
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

	cout << " 충전 금액을 입력하세요." << endl;
	cout << " 입력 : ";
	while (1)
	{
		if (scanf_s("%d", &chmo) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : ";
			rewind(stdin);
		}
		else
		{
			if (chmo > 0 && chmo < 100000000)			// MAx money
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 가격 : ";
			rewind(stdin);
		}
	}
	da[co].money += chmo;
	cout << " 충전 완료" << endl;
	cout << " 현재 금액 : " << da[co].money << endl;
	cout << "---------------------" << endl;
	return da;
}
pair<vector<guest>, vector<video>> video_rental(vector<guest> da, vector<video> va, string id)
{
	int co = 0;
	int vd = 0;
	if (va.size() == 0)
	{
		cout << " 비디오가 존재하지 않습니다" << endl;
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
		cout << " 이미 대여중인 비디오가 있습니다" << endl << endl;
		return { da,va };
	}
	cout << "--------------" << endl;
	for (int g = 0; g < va.size(); g++)
		cout << " " << g + 1 << ". " << va[g].vname << ". " << endl;
	cout << "--------------" << endl;
	cout << " 빌릴 비디오를 선택하세요( 번호 ) :";
	while (1)
	{
		if (scanf_s("%d", &vd) == 0)
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
		else
		{
			if (vd > 0 && vd <= va.size())
				break;
			cout << " 다시 입력하세요 " << endl;
			cout << " 입력 : ";
			rewind(stdin);
		}
	}
	while (getchar() != '\n');
	cout << "--------------" << endl;
	vd -= 1;
	if (va[vd].re == 0)
	{
		cout << "남은 비디오 재고가 없습니다" << endl;
		return { da,va };
	}
	else if (da[co].age - va[vd].age < 0)
	{
		cout << " 연령 불가" << endl;
		return { da,va };
	}
	else if (da[co].money - va[vd].price >= 0)
	{
		da[co].video = va[vd].vname;
		da[co].money -= va[vd].price;
		va[vd].re -= 1;
		cout << " --비디오 대여 완료--" << endl;
	}
	else
		cout << " 잔액이 부족합니다. 충전해 주세요( 충전 : 수정 -> 금액 충전 )" << endl;

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
		cout << " 대여중인 비디오는 없습니다." << endl;
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
	cout << " -- 반납 완료 -- " << endl << endl;
	return { da,va };
}