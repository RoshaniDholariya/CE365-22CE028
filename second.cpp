#include<iostream>

using namespace std;

void validString(int n,char symbol[],int state,int initialState,int m,int a_state[],int transition_table[][100],string input){

int current=initialState;

for(char ch: input){
    bool validString=false;

    for(int i=0;i<n;i++){
        if(ch==symbol[i]){
            validString=true;
            current=transition_table[current][i];
        }
    }
    if(!validString){
        cout<<"Invalid String";
        return;
    }
}
for(int i=0;i<m;i++){
    if(current=a_state[i]){
        cout<<"valid string";
        return;
    }
}

}

int main(){
     int n;
     cout<<" Enter No of input Symbol"<<endl;
     cin>>n;
     char symbol[n];
     cout<<"enter input symbol"<<endl;
     for(int i=0;i<n;i++){
        cin>>symbol[i];
     }
     cout<<"input symbol "<<endl;
     for(int i=0;i<n;i++){
        cout<<symbol[i];
     }
     int state;
     cout<<" Enter No of state"<<endl;
     cin>>state;

     int initialState;
     cout<<"Enter initial state"<<endl;
     cin>>initialState;

     int m;
     cout<<" Enter No of accepting state"<<endl;
     cin>>m;
     int a_state[m];
     cout<<"enter accepting state"<<endl;
     for(int i=0;i<m;i++){
        cin>>a_state[i];
     }
     cout<<"accepting state ";
     for(int i=0;i<m;i++){
        cout<<a_state[i];
     }
     int transition_table[state][100];
      cout<<endl<<"transition table"<<endl;
       for(int i=0;i<state;i++){
        for(int j=0;j<n;j++){
            cout<<i+1<<" to "<<symbol[j]<<"->";
            cin>>transition_table[i+1][j];
            cout<<endl;
        }
       }
    string input;
    cout<<"Enter input string ";
    cin>>input;
    validString(n,symbol,state,initialState,m,a_state,transition_table,input);

    return 0;
}
