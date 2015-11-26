// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Film;
class Video{
public:
	Video(int id_, int type_): id(id_), type(type_){}
	Video(): id(-1), type(-1){}
	virtual ~Video() = 0;
	virtual Video* getNext() = 0;

//private:
	vector<Video*> list;
	int id;
	int type;
};
Video:: ~Video(){}
//Video* Video::getNext(){
//	return list[0];
//}
class TV: public Video{
public:
	TV(int id_, int type_) :Video(id_, type_){
		num = 0;
	}
	TV(){}
	Video* getNext();
	int num;
};

Video* TV::getNext(){
	if (list.size()==0)
	{
		return NULL;
	}
	return list[0];
}

class Film : public Video{
public:
	Film(int id_, int type_) :Video(id_, type_){
		num1 = 2.5;
	}
	Film(){}
	Video* getNext();
	float num1;
};

Video* Film::getNext(){
	if (list.size() == 0)
		return NULL;
	return list[0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	Video* V1 = new TV(1, 0);
	Video* V2 = new Film(2, 1);
	Film* f1 = new Film(3, 1);
	V2->list.push_back(f1);
	Film* f2 = (Film*)V2->getNext();
	cout << f2->id << f2->type << f2->num1<<endl;

	Film* v3 = new Film(5, 1);
	V1->list.push_back(v3);
	TV* t1 = (TV*)V1->getNext();
	cout << t1->id << " " << t1->type << " " << t1->num;
	return 0;
}

