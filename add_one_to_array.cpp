//Question 66 from leetcode: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
vector<int> plusOne(vector<int>& digits) {
  int carry=1;
  int n = digits.size();
  for(int i = n-1;i>=0;i--){
    int temp=digits[i];
    digits[i]=(digits[i]+carry)%10;
    carry= (temp+carry)/10;
  }
  if(carry==0){
    return digits;
  }
  digits.push_back(0);
  digits[0]=1;
  return digits; 
}
