#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(vector<vector<int>> jobs);

int main() {
	
	vector<vector<int>> a = {
		{0, 1}, {1, 1},{2, 1},{3, 1}, {4, 1}
	};

	cout << solution(a) << endl;
	return 0;
}

class CPU {
public:
	int Start;
	int Time;
	CPU(int Start, int Time) {
		this->Start = Start;
		this->Time = Time;
	}
};

bool operator<(const CPU &a, const CPU &b) {
	return a.Time < b.Time;
}
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int Count = jobs.size();
	vector<CPU> MyCPU;
	for (int i = 0; i < Count; i++)
		MyCPU.push_back(CPU(jobs[i][0], jobs[i][1]));
	sort(MyCPU.begin(), MyCPU.end());


	int CurTime = 0;		//����ð�
	int CPUTimeSum = 0;		//�� CPU�� �۾��� �ð���

	vector<CPU>::iterator iter = MyCPU.begin();
	while (MyCPU.size() != 0) {
		if ((*iter).Start <= CurTime) {		//�����պ��� ������ ��� - ���� ���
			CurTime += (*iter).Time;
			CPUTimeSum += (CurTime - (*iter).Start);
			MyCPU.erase(iter);
			iter = MyCPU.begin();
		}
		else {
			iter++;
			if (iter == MyCPU.end()) {
				CurTime += 1;
				iter = MyCPU.begin();
			}
		}
		
	}


	answer = CPUTimeSum / Count;
	return answer;
}