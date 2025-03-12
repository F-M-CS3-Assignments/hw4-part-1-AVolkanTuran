
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!

	//Test 3
	values = {5};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {5};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

	//Test 4
	values = {2, 3, 5, 7, 11};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet4(ans.begin(), ans.end());
	soln = {2};
	first = (answerSet4 == soln);
	soln = {11};
	second = (answerSet4 == soln);
	assert(first || second);

	//Test 5
	values = {1, 2, 4, 8, 16, 32, 64, 128};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {1, 2, 4, 8, 16, 32, 64, 128};
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln);

	//Test 6
	values = {5, 10, 15, 20, 25};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {5, 10, 20};
	set<int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

	//Test 7
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {};
	set<int> answerSet7(ans.begin(), ans.end());
	assert(answerSet7 == soln);

	//Test 8
	values = {6, 6, 6, 6, 6, 6, 6, 6};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {6, 6, 6, 6, 6, 6, 6, 6};
	set<int> answerSet8(ans.begin(), ans.end());
	assert(answerSet8 == soln);

	//Test 9
	values = {6, 18, 90, 7, 56, 101};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {6, 18, 90};
	set<int> answerSet9(ans.begin(), ans.end());
	assert(answerSet9 == soln);

	return 0;
}
