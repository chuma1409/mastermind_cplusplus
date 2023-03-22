#include <iostream>
#include <string>         // std::string
#include <locale>
#include <regex>

using namespace std;

string codeGenerator(){
    srand(time(0));
    string saver = "";
    int num;
    for(int i =0;i<4;i++){
        num = 1 + (rand()%8)+1;
        saver +=to_string(num);
    }
    return saver;
}

string inputValidator(){
    string guess;
    cout<<"Enter your code: ";
    cin>>guess;
    while(!regex_match(guess,regex("[1-8]{4}"))){
        cout<<"Please enter exactly 4 digits."<<endl;
        inputValidator();
        break;
    }
        return guess;
}

int checkCorrectness(string codeGen, string guess){
    int corrDigits = 0;
    for(int i = 0; i < codeGen.length();i++){
        if(codeGen.find(guess[i]) != string::npos){
            corrDigits++;
        }  
    }
    return corrDigits;
}
int checkCorrPlace(string codeGen, string guess){
    int corrPlace = 0;
    for(int i = 0; i < codeGen.length();i++){
        if (codeGen[i]==guess[i]){
            corrPlace++;
        }
    }
    return corrPlace;
}

int main(){
    cout<<"4-Digit randomly generated code has been created."<<endl;
    string code = codeGenerator();
    // cout<<code;
    int turns = 10;
    while(turns>0){
        string guessed = inputValidator();
        int digits = checkCorrectness(code,guessed);
        int place = checkCorrPlace(code,guessed);
        cout<<"Correct number of Digits : "<<digits<<endl;
        cout<<"Coreect number of Digits in Correct Place : "<<place<<endl;
        turns--;
        int equalStr = code.compare(guessed);
        if(equalStr == 0){
            cout<<"Congradulations!, you got it RIGHT!."<<endl;
            break;
        }
        cout<<"turns left: "<<turns<<endl;
        if (turns == 0){
            cout<<"You are out of guesses!"<<endl;
        }
    }
    cout<<"The code was: "<<code<<endl;
    
    return 0;  
}
