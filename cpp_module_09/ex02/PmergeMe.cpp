#include "PmergeMe.hpp"

std::vector<int>	insertionSortVector(std::vector<int> arr) {
	int tmp;

	for (int i = 1; i < (int)arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	return arr;
}

std::vector<int>	mergeSortVector(std::vector<int> arr, int start, int end) {
	if (end - start < 5)
		return insertionSortVector(arr);

	int	mid = (end + start) / 2;	
	std::vector<int>	arrLeft;
	std::vector<int>	arrRight;

	for (int i = 0; i < mid; i++)
		arrLeft.push_back(arr[i]);
	for (int i = mid; i < end; i++)
		arrRight.push_back(arr[i]);
	arrLeft = mergeSortVector(arrLeft, 0, arrLeft.size());
	arrRight = mergeSortVector(arrRight, 0, arrRight.size());

	std::vector<int>	mergedArr;
	int	l = 0, r = 0;

	while (l < (int)arrLeft.size() && r < (int)arrRight.size()) {
		if (arrLeft[l] < arrRight[r])
			mergedArr.push_back(arrLeft[l++]);
		else
			mergedArr.push_back(arrRight[r++]);
	}
	for (; l < (int)arrLeft.size(); l++)
		mergedArr.push_back(arrLeft[l]);
	for (; r < (int)arrRight.size(); r++)
		mergedArr.push_back(arrRight[r]);
	return mergedArr;
}

std::list<int>	insertionSortList(std::list<int> arr) {
	int tmp;

	for (std::list<int>::iterator iter1 = arr.begin(); iter1 != arr.end(); iter1++) {
		for (std::list<int>::iterator iter2 = iter1; iter2 != arr.begin(); iter2--) {
			if (*(std::prev(iter2)) > *iter2) {
				tmp = *iter2;
				*iter2 = *(std::prev(iter2));
				*(std::prev(iter2)) = tmp;
			}
		}
	}
	return arr;
}

std::list<int>	mergeSortList(std::list<int> arr, int start, int end) {
	if (end - start < 5)
		return insertionSortList(arr);

	int	mid = (end + start) / 2;	
	std::list<int>	arrLeft;
	std::list<int>	arrRight;

	while ((int)arrLeft.size() < mid) {
		arrLeft.push_back(arr.front());
		arr.pop_front();
	}
	while ((int)arrRight.size() < end - mid) {
		arrRight.push_back(arr.front());
		arr.pop_front();
	}
	arrLeft = mergeSortList(arrLeft, 0, arrLeft.size());
	arrRight = mergeSortList(arrRight, 0, arrRight.size());

	std::list<int>	mergedArr;

	while (arrLeft.size() && arrRight.size()) {
		if (arrLeft.front() < arrRight.front()) {
			mergedArr.push_back(arrLeft.front());
			arrLeft.pop_front();
		}
		else {
			mergedArr.push_back(arrRight.front());
			arrRight.pop_front();
		}
	}
	while (arrLeft.size()) {
		mergedArr.push_back(arrLeft.front());
		arrLeft.pop_front();
	}
	while (arrRight.size()) {
		mergedArr.push_back(arrRight.front());
		arrRight.pop_front();
	}
	return mergedArr;
}
