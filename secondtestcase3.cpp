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
            break;
        }
    }
    if(!validString){
        cout<<"Invalid String"<<endl;
        return;
    }
}
for(int i=0;i<m;i++){
    if(current==a_state[i]){
        cout<<"valid string"<<endl;
        return;
    }
}
cout<<"Invalid String"<<endl;
}

int main(){
     int n;
     cout<<" Enter No of input Symbol"<<endl;
     cin>>n;
     char symbol[36]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
     //char s='a';
     //cout<<"enter input symbol"<<endl;
     //for(int i=0;i<n;i++){
       // symbol[i]=s;
       // s++;
     //}
//for(int i=0;i<n;i++){
      //  cout<<symbol[i]<<" ";
     //}
     cout<<"input symbol "<<endl;
     for(int i=0;i<36;i++){
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
     int transition_table[state + 1][100];
    cout << "Transition table : " << endl;
    for (int i = 1; i <= state; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            cout << i << " to " << symbol[j] << " -> ";
            if(i == 1)
            {
                if (symbol[j] >= 'a' && symbol[j] <= 'z')
                {
                    transition_table[i][j] = 2;
                    cout<<transition_table[i][j];
                }
                else
                {
                    transition_table[i][j] = 3;
                    cout<<transition_table[i][j];
                }
            }
            else
            {
                transition_table[i][j] = i;
                cout<<transition_table[i][j];
            }
            cout<<endl;
        }
    }
    cout<<endl;
    while (true)
    {
        string input;
        cout << "Input String (type 'exit' to stop): ";
        cin >> input;

        if (input == "exit")
        {
            cout << "Exiting program." << endl;
            break;
        }

        validString(n, symbol, state, initialState, m, a_state, transition_table,input);
    }


    return 0;
}
