#include <iostream>
#include <string>
#include<ctime>
using namespace std;

void greet(){
    cout<<"========== WORDLE ========== \n";
}

void check_letter(string answer,string codeword,bool correct_position[]){
    int count=0;
    for(int i=0;i<4;i++){
        if(correct_position[i]){
            continue;               // if the position is correct it'll skip this itteration(i)
        }
        for(int j=0;j<4;j++){

            if (answer[i] == codeword[j] && !correct_position[j]){
                count++;
            }
        }
    }
    cout<<"\033[33m"<<count<<"\033[37m"<<endl;      // covert white --> yellow --> white
}


void check_position(string answer,string codeword,bool correct_position[]){
    int count=0;
    for(int i=0;i<4;i++){
        if(answer[i]==codeword[i]){
            count++;
            correct_position[i]=true;           // will return true to that particular itteration which is declared false in main
        }
    }
    cout<<"\033[32m"<<count<<"\033[37m"<<endl;          // covert white --> green --> white
}



// void display(string answer){
//     cout<<"| "<<answer[0]<<" | "<<answer[1]<<" | "<<answer[2]<<" | "<<answer[3]<<" | ";
// }

// void display(string answer){
//     cout<<"| ";
//     cin>>answer[0];
//     cout<<" | ";
//     cin>>answer[1];
//     cout<<" | ";
//     cin>>answer[2];
//     cout<<" | ";
//     cin>>answer[3];
//     cout<<" | ";
// }

void display(const string answer) {
    cout << "| ";
    for (char ch : answer) {
        cout << ch << " | ";
    }
    cout << endl;
}

int main()
{
    string word[]={"hard","cave","wave","push","back","call","blue","maze", "card", "lamp", "book", "sand", "cake", "moon", "star", "wind", "game"};
    srand(time(NULL));
    int word_num = rand()%17;
    string codeword = word[word_num];       // for index no. of which word to be choosen for codeword
    string answer;          // for input of user guess
    int attempts=0;
    int max_attempts=6;

    greet();

while(attempts<max_attempts){
    cout << "Attempt " << attempts + 1 << " of " << max_attempts << endl;
    cout<<"Enter a 4-letter guess:";
    cin>>answer;

        if(answer.length() != 4){
            continue;
        }
        bool correct_position[4]={false,false,false,false};

        display(answer);
        check_position(answer,codeword,correct_position);
        check_letter(answer,codeword,correct_position);

        attempts++;
    if(answer==codeword){
         cout << "Congratulations! You've guessed the word correctly: " << codeword << endl;
         break;
    }
    else if(attempts == max_attempts){
        cout<<"Oops you ran out of attempts!!! Correct word is "<<codeword<<endl;
        break;
    }
}
    return 0;
}
