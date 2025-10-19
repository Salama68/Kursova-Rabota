#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int size;
    cout << "Въведете размерността на желания от вас масив: ";
    cin >> size;
    if(size>30 || size<1){
        while(size>30 || size<1){
            cout << endl << "Вашият масив не може да се състои от повече от 30 елемента! Моля, въведете размерност не по-голяма от 30: ";
            cin >> size;
        }
    }
    int A[size];
    cout << endl << "Въведете елементите на желания от вас масив: " << endl;
    for(int i=0;i<size;i++){
        cin >> A[i];
    }

    cout << "\n\n#-------------------------------------------------------------------------------------------------------------------------#\n\n" << endl;
    cout << "  Функции: " << endl;
    cout << "\n1) Създаване на нов Масив AK само от четните по стойност елементи и определяне на средно-аретмитичната им стойност." << endl;
    cout << "2) Презаписване на масива в нов масив AS и сортиране на новият масив в низходящ ред." << endl;
    cout << "3) Извеждане на екрана информация за съответния масив с пояснителен текст." << endl;
    cout << "\n\n#-------------------------------------------------------------------------------------------------------------------------#" << endl;
    int functionIndex;
    int AS[size];
    int evenCount = 0;
    vector<int> AK;
    cout << "Изберете номер на функция: " << endl;
    cin >> functionIndex;
    switch (functionIndex){
        case 1:{
            double avg;
            double sum = 0;
            AK.clear();
            for(int i = 0; i<size; i++){
                if(A[i]%2==0){
                    AK.push_back(A[i]);
                    sum += A[i];
                }
            }
            evenCount = AK.size();
            if(evenCount > 0) avg = sum/(evenCount);
            else avg = 0;
            if(evenCount > 0){
                cout << "\nСредно-аритметична стойност на четните елементи: " << avg << endl;
            }
            else cout << "\nНяма четни елементи!" << endl;
        }
        break;
        case 2:{
            int counter = 0;
            for(int i = 0; i<size; i++){
                AS[counter] = A[i];
            }
            sort(AS,AS+size,greater<int>());
        }
        break;
        case 3:{
            int choice;
            cout << "\nКой масив искате да изведете?\n";
            cout << "1) A (оригиналният масив)\n";
            cout << "2) AK (масив с четните елементи)\n";
            cout << "3) AS (сортиран масив в низходящ ред)\n";
            cout << "Избор: ";
            cin >> choice;
            switch(choice){
                case 1:
                    cout << "\nМасив A: ";
                    for(int i = 0; i < size; i++){
                        cout << A[i] << " ";
                    }
                break;
                case 2:
                    if(evenCount == 0){
                    cout << "\nМасив AK е празен (няма четни елементи)!\n";
                    } 
                    else {
                        cout << "\nМасив AK: ";
                        for(int i = 0; i < evenCount; i++){
                            cout << AK[i] << " ";
                        }
                    }
                break;
                case 3:
                    cout << "\nМасив AS: ";
                    for(int i = 0; i < size; i++){
                        cout << AS[i] << " ";
                    }
                break;
                default:
                    cout << "Невалиден избор!" << endl;
                break;
            }   
        }
        break;
        default:{
            cout << "Невалиден номер!" << endl;
        }
        break;
    }

    return 0;
}
