//LeetCode 66
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
