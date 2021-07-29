int PalinArray(int arr[], int n)
{ //add code here.

  for (int i = 0; i < n; i++) {
    int ans = 0;
    int temp = arr[i];
    while (temp > 0) {
      int r = temp % 10;
      temp /= 10;
      ans = (ans * 10) + r;
    }
    if (ans != arr[i]) {
      return 0;
    }
  }
  return 1;
}