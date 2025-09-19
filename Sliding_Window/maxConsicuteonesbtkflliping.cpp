int longestSubSeg(vector<int> &arr, int n, int k)
{
  // Write your code here.

  int start = 0;
  int end = 0;
  int maxlength = 0;
  int count = 0;
  while (start < n)
  {
    if (count != k && arr[start] == 0)
    {
      count++;
    }

    if (count == k)
    {
      maxlength = max(maxlength, right - left + 1);
      left = right + 1;
      count = 0;
    }

    right++;
  }
  return maxlength;
}
