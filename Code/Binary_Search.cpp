#include <iostream>
#include <algorithm>

using namespace std;

bool search_binary(int a[], int left, int right, int k, int &res) {
    int mid = (left + right) / 2;
    if (left > right) return false;
    if (a[mid] == k) {
        res = mid;
        return true;
    } else {
        if (a[mid] < k) left = mid + 1;
        if (a[mid] > k) right = mid - 1;
        return search_binary(a, left, right, k, res);
    }
}
bool check_greater(int a[], int n) {
    if (n == 1) return true;
    if (a[n - 1] > a[n]) return false;
    return check_greater(a, n - 1);
}

int main() {
    int n, k, pos;
    cout << "Enter N: ";
    cin >> n;
    int a[n+1];
    cout << "Input Array: \n";
    for (int i = 1; i <= n; i++){
        cout << "A[" << i << "] = ";
        cin >> a[i];
    }
    if (check_greater(a, n)) cout << "Array Valid!! continue\n";
        else {
            cout << "Array need to sort";
            return 0;
        };
    cout << "enter k: ";
    cin >> k;
    if (search_binary(a, 1, n, k, pos)) {
        cout << "Position of " << k << " : " << pos;
    } else cout << "Not found " << k << " in Array !";
    return 0;
}

