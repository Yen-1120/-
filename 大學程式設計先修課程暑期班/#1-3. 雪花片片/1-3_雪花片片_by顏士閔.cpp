#include<iostream>

using namespace std;

string add(string a, string b) {
    int carry = 0;
    string result = "";
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}

string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";
    string result = "0";
    for (int i = b.size() - 1; i >= 0; i--) {
        int digit = b[i] - '0';
        string temp = "";
        int carry = 0;
        for (int j = a.size() - 1; j >= 0; j--) {
            int product = (a[j] - '0') * digit + carry;
            temp = char(product % 10 + '0') + temp;
            carry = product / 10;
        }
        if (carry > 0) temp = char(carry + '0') + temp;
        for (int k = 0; k < b.size() - 1 - i; k++) {
            temp += '0';
        }
        result = add(result, temp);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    string out = "0", now = "1";

    for (int i = 0; i < n; i++) {
        out = add(out, now);
        now = multiply(now, "4");
    }

    cout << out;

}