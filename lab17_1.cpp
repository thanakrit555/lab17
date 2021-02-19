

Butter ส่ง วันนี้ เวลา 17:24 น.
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string &filemane , vector<string> &names ,vector<int> &scores , vector<char> &grades){
    ifstream name;
    name.open("name_score.txt");
    string textline ;
    char name2[100];
    char format[]= "%[^:]:%i %i %i";

    while (getline(name,textline)){
        int a = 0 , b = 0 , c = 0;
        char text[100];
        strcpy(text,textline.c_str());
        sscanf(text,format,name2,&a,&b,&c);
        names.push_back(name2);
        int grade = a+b+c;
        scores.push_back(grade);
        grades.push_back(score2grade(grade));
    }
    name.close();
}

void getCommand(string &command , string &key){
    string text;
    cout<<"Please input your command: ";
    getline(cin,text);
    int lok = text.find_first_of(" ");
    command = text.substr(0,lok);
    key = text.substr(lok+1);

}

void searchName(vector<string> &names , vector<int> &scores, vector<char> &grades , string key){
    int n = names.size();
    int bo = 0;
    cout <<"---------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if(toUpperStr(names[i])==key){
            cout<< names[i] <<"'s score = " << scores[i] <<endl;
            cout<< names[i] <<"'s grade = " << grades[i] <<endl;
            bo=1;
        }
    }
    if (bo!=1) cout<<"Cannot found.\n";
    cout <<"---------------------------------\n";
}

void searchGrade(vector<string> &names , vector<int> &scores , vector<char> &grades, string key ){
    cout <<"---------------------------------\n";
    int n = names.size();
    char key1[100];
    int bo = 0;
    strcpy(key1,key.c_str());
    for (int i = 0; i < n; i++){
        if (grades[i]==*key1){
           cout << names[i] <<" "<<"("<<scores[i]<<")"<<endl;
        bo = 1;
        }
    }
    if (bo!=1) cout<<"Cannot found.\n";
    cout <<"---------------------------------\n";
}
int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
