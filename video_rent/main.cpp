#include"header.h"

void main()
{
	int Master = 0;								// 관리자 확인
	string check;								// 시스템 선택
	vector<guest> data_;						// 고객 데이터 벡터
	vector<video> type_;						// 비디오 데이터 벡터
	guest human;								// guest 구조체
	video vd;									// video 구조체
	string ID = "";								// 아이디
	string PASS;								// 비밀번호
	pair<vector<guest>, vector<video>> dou;		// 대여, 반납에 필요. 2개의 벡터를 반환해야함(고객, 비디오)

	data_ = filecalls_guest(data_, human);		// 고객데이터 불러오기
	type_ = filecalls_video(type_, vd);			// 비디오 데이터 불러오기

	while (1)
	{
		check = "";
		while (1)
		{
			Master = 0;
			cout << " 비디오 대여 시스템" << endl << endl;
			cout << " 로그인 : 1번 \t 회원가입 : 2번 \t ID 또는 PASS 찾기 : 3번" << endl;
			cout << " 입력 :";
			cin >> check;
			while (check != "1" && check != "2" && check != "3")
			{
				cout << "다시 입력하세요" << endl;
				cout << " 입력 :";
				cin >> check;
			}
			if (check == "1")
			{
				cout << "--------------" << endl;
				cout << " ID : ";
				cin >> ID;
				cout << " PASSWORD: ";
				cin >> PASS;
				cout << "--------------" << endl;
				if (ID == "Master" && PASS == data_[0].PASS)
				{
					cout << " 관리자 계정 입니다." << endl << endl;
					Master = 1;
					break;
				}
				else if (login(data_, ID, PASS) == 1)	// 로그인
				{
					cout << " --- 로그인 성공---" << endl << endl;
					break;
				}
				else
				{
					cout << " 가입하지 않은 아이디거나, 잘못된 비밀번호 입니다." << endl;
				}
			}
			else if (check == "2")
			{
				data_ = add_user(data_, human);			// 회원가입
			}
			else
			{
				string check_fine;					// ID PASS 선택
				cout << " ID 찾기 : 1 \t 비밀번호 찾기 : 2 " << endl;
				cout << " 입력 : ";
				cin >> check_fine;
				while (check_fine != "1" && check_fine != "2")
				{
					cout << "다시 입력하세요" << endl;
					cout << " 입력 :";
					cin >> check_fine;
				}
				if (check_fine == "1")
					fineID(data_);					// ID 찾기
				else
					finePAss(data_);					// PASS 찾기							
			}
			filesave_guest(data_);		// 저장
		}
		while (1)
		{
			cout << "";
			cout << " 보기 : 1\t 검색 : 2\t 대여/반납 : 3\t 수정 : 4\t 로그아웃 : 5" << endl;
			cout << " 입력 : ";
			cin >> check;
			if (check == "1")		// 관리자 권한
			{
				if (Master == 1)
				{
					string check22;
					cout << " 고객목록 보기 : 1\t 비디오 목록 보기 : 2\n 입력 :";
					cin >> check22;
					while (check22 != "1" && check22 != "2")
					{
						cout << "다시 입력하세요" << endl;
						cout << " 입력 :";
						cin >> check22;
					}
					if (check22 == "1")							// 고객 데이터
					{
						cout << "--------------" << endl;
						output_guest(data_);
					}
					else											// 비디오 데이터					
					{
						cout << "--------------" << endl;
						output_video(type_);
					}
				}
				else												// 고객 비디오 데이터	
				{
					cout << "--------------" << endl;
					output_video(type_);
				}
				cout << "--------------" << endl;
			}
			else if (check == "2")								// 검색
			{
				cout << "--------------" << endl;
				search(data_, type_, Master);
			}
			else if (check == "3")								// 대여 / 반납
			{
				string check_r;
				cout << "--------------" << endl;
				cout << " 대여 : 1\t 반납 : 2" << endl;
				cout << " 입력 : ";
				cin >> check_r;
				while (check_r != "1" && check_r != "2")
				{
					cout << "다시 입력하세요" << endl;
					cout << " 입력 :";
					cin >> check_r;
				}
				if (check_r == "1")
				{
					dou = video_rental(data_, type_, ID);
					data_ = dou.first;
					type_ = dou.second;
				}
				else
				{
					dou = video_return(data_, type_, ID);
					data_ = dou.first;
					type_ = dou.second;

				}
				filesave_guest(data_);
				filesave_video(type_);
				cout << "--------------" << endl;
			}
			else if (check == "4")
			{
				if (Master == 1)
				{
					string aa;
					cout << " 비디오 추가 : 1\t 비디오 수정 : 2\t 비디오 삭제 : 3\t 정보 수정 : 4" << endl;
					cout << " 입력 : ";
					cin >> aa;
					while (aa != "1" && aa != "2" && aa != "3" && aa != "4")
					{
						cout << "다시 입력하세요" << endl;
						cout << " 입력 :";
						cin >> aa;
					}
					cout << "--------------" << endl;
					if (aa == "1")
					{
						type_ = add_video(type_, vd);
					}
					else if (aa == "2")
					{
						type_ = modify_video(type_);
					}
					else if (aa == "3")
					{
						type_ = delete_video(type_);
					}
					else
					{
						string qe;
						cout << " 관리자 계정입니다. 이름변경,비밀번호 변경과 금액충전만 가능합니다." << endl;
						cout << " 이름 변경 : 1\t 비밀번호 변경 : 2\t 금액 충전 : 3\t" << endl;
						cout << " 입력 : ";
						cin >> qe;
						while (qe != "1" && qe != "2" && qe != "3")
						{
							cout << " 다시 입력하세요" << endl;
							cout << " 입력 :";
							cin >> qe;
						}
						if (qe == "1")
						{
							int t = 0;
							while (1)
							{
								if (ID == data_[t].ID)
									break;
								t++;
							}
							cout << " " << data_[t].name << " -> "; cin >> data_[t].name;
							cout << " 이름 변경 완료" << endl;
						}
						else if (qe == "2")
						{
							cout << data_[0].PASS << " -> ";	cin >> data_[0].PASS;
							cout << " " << " 비밀번호 변경 완료" << endl;
						}
						else
							data_ = charge_money(data_, ID);
					}
					filesave_guest(data_);
					filesave_video(type_);
				}
				else
				{
					string na;
					cout << " 회원 정보 수정 : 1\t 금액충전 : 2\t 회원 탈퇴 : 3" << endl;
					cout << " 입력 :";
					cin >> na;
					while (na != "1" && na != "2" && na != "3")
					{
						cout << " 다시 입력하세요" << endl;
						cout << " 입력 :";
						cin >> na;
					}
					if (na == "1")
					{
						data_ = modify_user(data_, ID);
					}
					else if (na == "2")
					{
						data_ = charge_money(data_, ID);
					}
					else
					{
						data_ = delete_data_user(data_, ID);
						filesave_guest(data_);
						break;
					}
				}
				filesave_guest(data_);
				filesave_video(type_);
				cout << "--------------" << endl;
			}
			else if (check == "5")
			{
				if (ID == "Master")
				{
					string log;
					cout << " 로그아웃 : 1\t 프로그램 종료 : 2" << endl;
					cout << " 입력 : ";
					cin >> log;
					while (log != "1" && log != "2")
					{
						cout << "다시 입력하세요" << endl;
						cout << " 입력 :";
						cin >> log;
					}
					if (log == "1")
					{
						cout << " ------------------" << endl;
						cout << " l--- 로그아웃 ---l" << endl;
						cout << " ------------------" << endl;
						break;
					}
					else
					{
						cout << "---프로그램 종료---" << endl;
						exit(0);
					}
				}
				else
				{
					cout << " ------------------" << endl;
					cout << " l--- 로그아웃 ---l" << endl;
					cout << " ------------------" << endl;
					break;
				}
			}
			else
			{
			cout << "잘못 입력하였습니다." << endl; 
				cout << "--------------" << endl;
			}
		}
	}
}