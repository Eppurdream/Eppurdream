#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> vec;
	for (int i = 0; i < nums.size(); i++)
	{
		
		for (int j = 0; j < nums.size(); j++)
		{
			if (i == j) j++;
			if (nums[i] + nums[j] == target)
			{
				vec.emplace_back(i);
				vec.emplace_back(j);
				return vec;
			}
		}
	}
	return vec;
}

int main()
{
	vector<int> v = { 3,2,4 };
	vector<int> nv = twoSum(v, 6);
	cout << nv[0] << ", " << nv[1];
}
