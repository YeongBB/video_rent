#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

typedef struct data				//�մ� ������
{
	string name = "";			// �̸�
	int age = 0;				// ����
	string ID;					// ID
	string PASS;				// PASSWORD
	string phone = "";			// ��ȭ��ȣ
	string address = "";		// �ּ�
	string video = "";			// �뿩���� ����
	int money = 0;				// �ܾ�
}guest;

typedef struct Vvideo			// ���� ������
{
	string vname = "";			// �̸�
	int age = 0;				// ���� ����
	string gen;					// �帣
	int price = 0;				// ����
	int re = 0;					// ���� ����
}video;

// guest human;

vector<guest> filecalls_guest(vector<guest> da, guest human);				// �� ������ �ҷ�����	���� o
void filesave_guest(vector<guest> da);										// �� ������ ����		���� o
vector<video> filecalls_video(vector<video> va, video vi);					// ���� ������ �ҷ�����	���� o
void filesave_video(vector<video> vi);										// ���� ������ ����	���� o

vector<guest> charge_money(vector<guest> da, string id);					// �ݾ� ����			���� o
vector<guest> add_user(vector<guest> da, guest human);						// ȸ������			���� o
vector<guest> modify_user(vector<guest> da, string id);						// ȸ�� ����			���� o
vector<guest> delete_data(vector<guest> da);								// �����ڰ� ���� ������ ����	������� ������ �� ����o
vector<guest> delete_data_user(vector<guest> da, string ID);				// ȸ�� Ż��			���� o	

vector<video> add_video(vector<video> va, video vi);						// ���� �߰�			���� o
vector<video> delete_video(vector<video> va);								// ���� ����			���� o
vector<video> modify_video(vector<video> va);								// ���� ����			���� o

void search(vector<guest>, vector<video>, int M);							// �˻�				���� o
pair<vector<guest>, vector<video>> video_rental(vector<guest> da, vector<video> va, string id);	// ���� �뿩	���� o
pair<vector<guest>, vector<video>> video_return(vector<guest> da, vector<video> va, string id);	// ���� �ݳ�	���� o
void output_guest(vector<guest> da);										// �� ��� ���		���� o
void output_video(vector<video> va);										// ���� ���		���� o

int login(vector<guest> da, string id, string pass);						// �α���				���� o
void fineID(vector<guest> da);												// ���̵� ã��		���� o
void finePAss(vector<guest> da);											// ��й�ȣ ã��		���� o
