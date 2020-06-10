// ekz.cpp: определяет точку входа для приложения.
//

#include "dot.h"
#include "dot_space.h"
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <cmath>
#include <future>


using namespace std;

mutex m;

bool dot_sort(const Dot& lhs, const Dot& rhs) {

	float lhsDist = sqrtf(pow(lhs.get_x(), 2) + pow(lhs.get_y(), 2));
	float rhsDist = sqrtf(pow(rhs.get_x(), 2) + pow(rhs.get_y(), 2));
	return lhsDist < rhsDist;
}

void printVec(const std::vector<Dot> &vec) {
	for (size_t i = 0; i < vec.size();++i) {
		m.lock();
		vec[i].print();
		m.unlock();
	}
}

Dot findAvg(std::vector<Dot> vec) {
	float avg = 0;
	for (size_t i = 0; i < vec.size();++i) {
		avg += sqrtf(powf(vec[i].get_x(), 2) + powf(vec[i].get_y(), 2));
	}
	avg/vec.size();

	std::sort(vec.begin(), vec.end(), dot_sort);
	int parity = vec.size() % 2;
	int index = vec.size() / 2;
	if (parity) {
		index += 1;
	}
	else {
		float lhsDist = sqrtf(pow(vec[index].get_x(), 2) + pow(vec[index].get_y(), 2));
		float rhsDist = sqrtf(pow(vec[index+1].get_x(), 2) + pow(vec[index+1].get_y(), 2));
		index = abs(lhsDist - avg) < abs(rhsDist - avg) ? index : index + 1;
	}
	return vec[index];

}



int main()
{
	Dot d(3.223,5);
	d.print();

	try {
		cin >> d;
	}
	catch (const Except& ex) {
		std::cerr << ex.what() << endl;
	}
	cout << d;

	Dot_space ds(3, 5, 6);
	ds.print();

	std::vector<Dot*> vec;
	vec.push_back(&d);
	vec.push_back(&ds);
	vec[0]->print();
	vec[1]->print();

	cout << "not virtual" << endl;
	Dot_not_virtual dn(3, 5);
	Dot_space_not_virtual dns(1, 2, 6);
	vec.clear();

	//Со статическим полиморфизмом у нас не получится запихнуть в вектор объекты
	/*vec.push_back(&dn);
	vec.push_back(&dns)*/
	
	std::vector<Dot_space*> spaceVec;
	spaceVec.push_back(new Dot_space (1,2, 40));
	spaceVec.push_back(new Dot_space(1, 1, 1));
	spaceVec.push_back(new Dot_space(5, 0, 0));

	//std::sort(spaceVec.begin(), spaceVec.end());

	for (size_t i = 0; i < spaceVec.size(); ++i) {
		spaceVec[i]->print();
	}
	cout << "parallel" << endl << endl;


	std::vector<Dot> flatVec;
	flatVec.push_back(Dot(3, 5));
	flatVec.push_back(Dot(1, 2));
	flatVec.push_back(Dot(5, 5));
	flatVec.push_back(Dot(8, 0));
	flatVec.push_back(Dot(0, 0));
	flatVec.push_back(Dot(3, 5));

	std::vector<Dot> flatVec2;
	flatVec2.push_back(Dot(2, 2));
	flatVec2.push_back(Dot(1, 2));
	flatVec2.push_back(Dot(3, 5));
	flatVec2.push_back(Dot(2, 0));
	flatVec2.push_back(Dot(1, 1));
	flatVec2.push_back(Dot(3, 5));


	std::thread t1(printVec,std::cref(flatVec));
	std::thread t2(printVec,std::cref(flatVec2));


	t1.join();
	t2.join();


	 
	
	/*std::thread t3(findAvg, std::cref(flatVec));
	std::thread t4(findAvg, std::cref(flatVec2));*/

	//std::future<float> res1(std::async(std::launch::async, findAvg, flatVec));
	cout << "AVG: ";
	findAvg(flatVec).print();
	cout << "flatvec1" << endl;
	for (size_t i = 0; i < flatVec.size(); ++i) {
		cout << "flatvec[" << i << "] = " << flatVec[i] << endl;
	}



	return 0;
}
