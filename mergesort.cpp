//Code to implement Merge Sort algorithm
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& left, vector <int>& right, vector<int>& num) {
    int i=0;
    int j=0;
    int k=0;
    while (i<left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            num[k]=left[i];
            i++;k++;
        } else {
            num[k]=right[j];
            j++;k++;
        }
    }
    while (i<left.size()) {
        num[k]=left[i];
        i++;k++;
    }
    
    while (j<right.size()) {
        num[k]=right[j];
        j++;k++;
    }
}

void mergesort (vector<int>& num) {
    int n = num.size();
    if (n<2) {
        return;
    }
    int mid = n/2;
    vector<int> left;
    vector<int> right;
    
    for (int i=0;i<mid;i++) {
        left.push_back(num[i]);
    }
    for (int j=0;j<n-mid;j++) {
        right.push_back(num[mid+j]);   
    }
    mergesort(left);
    mergesort(right);
    merge(left,right,num);
}

int main()
{
    vector<int> comp{2,9,1,7,3,6,8,4};
    mergesort(comp);
    for (int i=0;i<comp.size();i++) {
        cout <<comp[i]<<endl;
    }
    return 0;
}
