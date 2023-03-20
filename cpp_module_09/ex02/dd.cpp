#include "PmergeMe.hpp"

std::list<int>	insertionSortList(std::list<int> arr) {
	int tmp;

	for (int i = 1; i < arr.size(); i++) {
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

std::list<int>	mergeSortList(std::list<int> arr, int start, int end) {
	if (end - start < 5)
		return insertionSortList(arr);

	int	mid = (end + start) / 2;	
	std::list<int>	arrLeft;
	std::list<int>	arrRight;

	for (int i = 0; i < mid; i++)
		arrLeft.push_back(arr[i]);
	for (int i = mid; i < end; i++)
		arrRight.push_back(arr[i]);
	arrLeft = mergeSortList(arrLeft, 0, arrLeft.size());
	arrRight = mergeSortList(arrRight, 0, arrRight.size());

	std::list<int>	mergedArr;
	int	l = 0, r = 0;

	while (l < arrLeft.size() && r < arrRight.size()) {
		if (arrLeft[l] < arrRight[r])
			mergedArr.push_back(arrLeft[l++]);
		else
			mergedArr.push_back(arrRight[r++]);
	}
	for (; l < arrLeft.size(); l++)
		mergedArr.push_back(arrLeft[l]);
	for (; r < arrRight.size(); r++)
		mergedArr.push_back(arrRight[r]);
	return mergedArr;
}
