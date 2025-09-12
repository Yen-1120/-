#include<iostream>
#include<queue>

using namespace std;

queue<string> programs;

long long int PROGRAM();

void IF(long long int& count)
{
    string temp = programs.front();

    // IF 後面只會接 IF、ELSE
    if (temp == "IF") {
        count += PROGRAM();
    } else {
        programs.pop();
        count += 1;
    }
    return;
}

void ELSE(long long int& count)
{
    string temp = programs.front();

    // ELSE 後面只會接 IF、END_IF
    if (temp == "IF") {
        count += PROGRAM();
    } else {
        programs.pop();
        count += 1;
    }
    return;
}

void END_IF(long long int& count)
{
    string temp = programs.front();

    // END_IF 後面"只"會接 IF、ENDPROGRAM(還有 ELSE ！)(其實還有 END_IF)
    if (temp == "IF") {
        count *= PROGRAM();
    } else { // ELSE、END_IF 和 ENDPROGRAM
        programs.pop();
    }
    return;
}

long long int PROGRAM()
{
    string temp = programs.front();
    programs.pop();

    // 一個程式的開頭可能是 IF、ENDPROGRAM
    if (temp == "IF") {
        long long int count = 0;
        IF(count);
        ELSE(count);
        END_IF(count);
        return count;
        // 最簡短的程式(一整套處理)
    } else {
        return 1;
    }
}

int main()
{
    int n, t;
    cin >> n;

    t = n;
    while (t > 0) {
        string temp;
        cin >> temp;
        if (temp == "IF" || temp == "ELSE" || temp == "END_IF" || temp == "ENDPROGRAM") {
            programs.push(temp);
            if (temp == "ENDPROGRAM") {
                t--;
            }
        }
    }

    t = n;
    while (t > 0) {
        cout << PROGRAM() << endl;
        t--;
    }

    return 0;
}