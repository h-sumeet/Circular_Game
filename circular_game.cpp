#include <iostream>
#include <vector>

using namespace std;

void find_winner(vector<int> &person, vector<int> time, int person_index, int time_index){
    int n = person.size();
    int m = time.size();
    if (n == 1 or time_index == m){
        return;
    }

    person_index = (person_index + time[time_index] - 1) % n;
    person.erase(person.begin() + person_index);
    find_winner(person, time, person_index, time_index + 1);
}

int main(){
    cout << "Enter the Number of peoples" << endl;
    int n;
    cin >> n;
    vector<int> person;
    for (int i = 1; i <= n; i++){
        person.push_back(i);
    }
    cout << "Enter the Numbers of moves" << endl;
    int moves;
    cin >> moves;
    cout << "Enter the time stamps" << endl;
    vector<int> time(moves);
    for (int i = 0; i < moves; i++){
        cin >> time[i];
    }
    bool flag = true;
    if (moves >= n){
        cout << "No ones win" << endl;
        flag = false;
    }

    if (flag){
        cout << "The winner is: " << endl;
        find_winner(person, time, 0, 0);
        for (int i = 0; i < person.size(); i++)
        {
            cout << person[i] << endl;
        }
    }
    return 0;
}