#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

typedef struct data				//손님 데이터
{
	string name = "";			// 이름
	int age = 0;				// 나이
	string ID;					// ID
	string PASS;				// PASSWORD
	string phone = "";			// 전화번호
	string address = "";		// 주소
	string video = "";			// 대여중인 비디오
	int money = 0;				// 잔액
}guest;

typedef struct Vvideo			// 비디오 데이터
{
	string vname = "";			// 이름
	int age = 0;				// 연령 제한
	string gen;					// 장르
	int price = 0;				// 가격
	int re = 0;					// 비디오 개수
}video;

// guest human;

vector<guest> filecalls_guest(vector<guest> da, guest human);				// 고객 데이터 불러오기	구현 o
void filesave_guest(vector<guest> da);										// 고객 데이터 저장		구현 o
vector<video> filecalls_video(vector<video> va, video vi);					// 비디오 데이터 불러오기	구현 o
void filesave_video(vector<video> vi);										// 비디오 데이터 저장	구현 o

vector<guest> charge_money(vector<guest> da, string id);					// 금액 충전			구현 o
vector<guest> add_user(vector<guest> da, guest human);						// 회원가입			구현 o
vector<guest> modify_user(vector<guest> da, string id);						// 회원 수정			구현 o
vector<guest> delete_data(vector<guest> da);								// 관리자가 유저 데이터 삭제	사용할지 안할지 모름 구현o
vector<guest> delete_data_user(vector<guest> da, string ID);				// 회원 탈퇴			구현 o	

vector<video> add_video(vector<video> va, video vi);						// 비디오 추가			구현 o
vector<video> delete_video(vector<video> va);								// 비디오 제거			구현 o
vector<video> modify_video(vector<video> va);								// 비디오 수정			구현 o

void search(vector<guest>, vector<video>, int M);							// 검색				구현 o
pair<vector<guest>, vector<video>> video_rental(vector<guest> da, vector<video> va, string id);	// 비디오 대여	구현 o
pair<vector<guest>, vector<video>> video_return(vector<guest> da, vector<video> va, string id);	// 비디오 반납	구현 o
void output_guest(vector<guest> da);										// 고객 목록 출력		구현 o
void output_video(vector<video> va);										// 비디오 출력		구현 o

int login(vector<guest> da, string id, string pass);						// 로그인				구현 o
void fineID(vector<guest> da);												// 아이디 찾기		구현 o
void finePAss(vector<guest> da);											// 비밀번호 찾기		구현 o
