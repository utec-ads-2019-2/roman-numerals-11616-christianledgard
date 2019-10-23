#include <iostream>

using namespace std;

int romanToNumber(char ch){
    switch(ch){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int main() {

    string line;

    long numerosAlgebraicos[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    std::string numerosRomanos[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

    while(cin >> line){
        long resultadoNumerico = 0;
        string resultadoRomano = "";

        if(isalpha(line[0])){
            for (int i = 0; i < line.size(); ++i) {
                if(romanToNumber(line[i+1])>romanToNumber(line[i]))
                    resultadoNumerico -= romanToNumber(line[i]);
                else
                    resultadoNumerico += romanToNumber(line[i]);
            }
            cout << resultadoNumerico << endl;
        }else{
            long numero = stol(line);

            int i=12;
            while(numero>0){
                long divicion = numero/numerosAlgebraicos[i];
                numero = numero%numerosAlgebraicos[i];
                while(divicion--){
                    resultadoRomano += numerosRomanos[i];
                }
                --i;
            }
            cout << resultadoRomano << endl;

        }
    }

    return 0;
}