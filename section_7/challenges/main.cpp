#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> v1, v2;
    
    v1.push_back(10);
    v1.push_back(20);
    cout << "v1 size: " << v1.size() << endl;
    cout << v1.at(0) << ", " << v1.at(1) << endl << endl;
    
    v2.push_back(100);
    v2.push_back(200);
    cout << "v2 size: " << v2.size() << endl;
    cout << v2.at(0) << ", " << v2.at(1) << endl << endl;
    
    vector<vector<int>> v_2d;
    v_2d.push_back(v1);
    v_2d.push_back(v2);
    cout << v_2d.at(0).at(0) << ", " << v_2d.at(0).at(1) << " | " << v_2d.at(1).at(0) << ", " << v_2d.at(1).at(1) << endl << endl; 
    
    v1.at(0) = 1000;
    cout << v_2d.at(0).at(0) << ", " << v_2d.at(0).at(1) << " | " << v_2d.at(1).at(0) << ", " << v_2d.at(1).at(1) << endl;
    cout << v1.at(0) << ", " << v1.at(1) << endl;
    cout << "v_2d made a copy of v1, so changing v1 has no effect on v_2d.\n" << endl;
    
	return 0;
}
