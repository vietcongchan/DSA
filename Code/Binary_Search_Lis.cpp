#include <iostream>
using namespace std;

int Binary_search(int a[], int left, int right, int x){
    int mid = (left + right) / 2;
    if (left > right) return -1;
    if (a[mid] == x) return mid;
        else {
            if (a[mid] < x) left = mid + 1;
                else right = mid - 1;
            return Binary_search(a, left, right, x);
        }
}

void print_result(int a[], int left, int right) {
    for (left; left <= right; left++) cout << a[left] << " ";
    cout << endl;
}

int main() {
    int n, k;
    cout << "N = ";
    cin >> n;
    int a[n+1],s[n+1];
    for (int i = 1; i <= n; i++) a[i] = i;
    s[1] = a[1]; s[0] = 0;
    for (int i = 2; i <= n; i++) s[i] = s[i-1] + a[i];
    cout << "s = ";
    cin >> k;
    for (int i = 1; i <= n; i++) {
        if (s[i] == k) print_result(a, 1, i);
        if (s[i] > k) {
            int left = Binary_search(s, 1, n, s[i] - k);
            if (left != -1 && i - left > 1) print_result(a, left + 1, i);
        }
    }
}
