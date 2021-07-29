// using Sort
int findLongestConseqSubseq(int arr[], int n)
{
	//Your code here
	sort(arr, arr + n);
	int currentStreak = 1, longestStreak = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			if (arr[i] == arr[i - 1] + 1) {
				currentStreak += 1;
			}
			else {
				longestStreak = max(longestStreak, currentStreak);
				currentStreak = 1;
			}
		}
	}

	return max(currentStreak, longestStreak);
}

// using set

int findLongestConseqSubseq(int arr[], int n)
{
	//Your code here
	set<int> hashSet;
	for (int i = 0; i < n; i++) {
		hashSet.insert(arr[i]);
	}
	int longestStreak = 0;
	for (int i = 0; i < n; i++) {
		if (!hashSet.count(arr[i] - 1)) {
			int currentNum = num;
			int currentStreak = 1;

			while (hashSet.count(currentNum + 1)) {
				currentNum += 1;
				currentStreak += 1;
			}

			longestStreak = max(longestStreak, currentStreak);

		}

	}

	return longestStreak;
}