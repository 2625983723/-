#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

class person
{
public:
	person(string name, int _score)
	{
		this->name  = name;
		this->_score = _score;
	}
	string name;
	int _score;


};

void creatperson(vector<person>& v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameseed[i];

		int score = 0;
		person p(name, score);
		v.push_back(p);
	}
}


void setscore(vector<person>& v)
{
	for (vector<person>::iterator itr = v.begin(); itr != v.end(); itr++)
	{
		deque<int>d;
		for (int i = 0; i < 5; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		cout << "选手:" << itr->name << "打分:"<<endl;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			cout << *it<<endl;
		}

		//取最高分和最低分
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0; 
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += (*it);
		}
		int result = sum / d.size();
		itr->_score = result;
	}
}

int main()
{
	//创建存放容器
	vector<person> v;
	
	creatperson(v);
	//vector<person>::iterator itr = v.begin();
	//for (itr ; itr != v.end() ;itr++)
	//{
	//	cout << itr->name << " " << itr->_score << endl;
	//}
	setscore(v);

}