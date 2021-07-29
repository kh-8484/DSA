void func(Node *root, vector<int> &path, int k) {
	if (!root) return;

	path.push_back(root->data);
	func(root->left, path, k);
	func(root->right, path, k);

	int sum = 0;

	for (int i = path.size() - 1; i >= 0; i--) {
		sum += path[i];
		if (sum == k) {
			for (int j = i; j < path.size(); j++) {
				cout << path[j] << " ";
			}
			cout << endl;
		}
	}
	path.pop_back();
}




int main() {
	vector<int> path;
	func(root, path, k);
}