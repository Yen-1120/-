#include <iostream>
#include <string.h>
using namespace std;

long long int PROGRAM(long long int total);
long long int IF();
long long int ELSE();
int END_IF();
void input();
string com;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        input();
        printf("%lld\n", PROGRAM(0));
    }
}

long long int PROGRAM(long long int total){
    int mode;
    if(com == "IF"){
        total = IF() + ELSE();
        mode = END_IF();
        if(mode == 1){
            total *= PROGRAM(0);
            return total;
        }
        else if(mode == 2){
            return total;
        }
    }
    else if(com == "ENDPROGRAM"){
        return 1;
    }
}

long long int IF(){
    input();
    if(com == "IF"){
        return PROGRAM(0);
    }
    else if(com == "ELSE"){
        return 1;
    }
}

long long int ELSE(){
    input();
    if(com == "IF"){
        return PROGRAM(0);
    }
    else if(com == "END_IF"){
        return 1;
    }
}

int END_IF(){
    input();
    if(com == "IF"){
        return 1;
    }
    else if(com == "ELSE" || com == "END_IF" || com == "ENDPROGRAM"){
        return 2;
    }
}

void input(){
    do{
        cin >> com;
    } while (com != "IF" && com != "ELSE" && com != "END_IF" && com != "ENDPROGRAM");
}