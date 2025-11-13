#include <bits/stdc++.h>
using namespace std;
struct student {
    string IDStudent;
    string name;
};
bool checkIDMajor(string IDStudent, string IDMajor){
    string temp = IDStudent.substr(2,3);
    return (temp == IDMajor);
}
vector<student>sortYear(vector<student>s, string IDMajor){
    vector<student>newS;
    for(int i=0;i<s.size();i++){
        if(checkIDMajor(s[i].IDStudent, IDMajor)) newS.push_back(s[i]);
    }
        
        int n=newS.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                string y1 = newS[i].IDStudent.substr(0,2);
                string y2 = newS[i].IDStudent.substr(0,2);
                
                string stt1 = newS[i].IDStudent.substr(5,3);
                
                string stt2 = newS[i].IDStudent.substr(5,3);
                
                if (y1 != y2 && y1 > y2) swap(newS[i],newS[j]);
                
                if (y1==y2 && stt1 > stt2 ) swap(newS[i],newS[j]);
        }
        return newS;
    }
    
    
}
int main ()
{
    vector<student>s = { {"22110008"}, {"22111003"}, {"22110075"},
    {"22111075"}, {"24113096"}, {"23110075"}
    
    };
    
    string IDMajor = "110";
    
    vector<student> res = sortYear(s,IDMajor);
    
    cout << "Danh sach sinh vien thuoc nganh " << IDMajor << " sau khi sap xep:\n";
    for (auto &st : res) {
        cout << st.IDStudent << " - " << st.name << endl;
    }
 
    
}
