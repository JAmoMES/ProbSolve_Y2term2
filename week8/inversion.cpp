#include <iostream>

using namespace std;

int arr[100000];
long long inversion = 0;

void merge_sort(int left, int right){
//    cout << left << " " << right << "\n";
    if (left >= right)
        return ;
    int mid = left + (right-left)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int nl = mid - left +1,l[nl];
    int nr = right - mid,r[nl];
    for (int i=0;i<nl;i++)
        l[i] = arr[left+i];
    for (int i=0;i<nr;i++)
        r[i] = arr[mid + 1 +i];
    int i=0,j=0,k=left;
    while(i < nl && j < nr)
        if (l[i]<r[j])
            arr[k++] = l[i++];
        else {
            inversion += nl - i;
            arr[k++] = r[j++];
        }
    while(i < nl)
        arr[k++] = l[i++];
    while(j < nr)
        arr[k++] = r[j++];
}

int main(){
    int n;
    cin >> n;
    for(int i =0 ;i<n ;i++){
        cin >> arr[i];
    }
    merge_sort(0,n-1);
//    for(int i =0 ;i<n ;i++){
//        cout << arr[i] << " ";
//    }
    cout << inversion;
    return 0;
}