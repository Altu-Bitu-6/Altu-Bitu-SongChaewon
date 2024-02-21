#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int initial_weight, initial_metabolism, metabolism_change_threshold;
    cin >> initial_weight >> initial_metabolism >> metabolism_change_threshold;

    int diet_duration, diet_energy_intake, diet_energy_expenditure;
    cin >> diet_duration >> diet_energy_intake >> diet_energy_expenditure;

    int weight_without_yoyo = initial_weight;
    int metabolism_without_yoyo = initial_metabolism;

    int weight_with_yoyo = initial_weight;
    int metabolism_with_yoyo = initial_metabolism;

    for (int day = 1; day <= diet_duration; ++day) {
 
        weight_without_yoyo += diet_energy_intake - (initial_metabolism + diet_energy_expenditure); // 체중 변화 

        weight_with_yoyo += diet_energy_intake - (metabolism_with_yoyo + diet_energy_expenditure); // 기초대사량 변화 반영

        if (abs(diet_energy_intake - (metabolism_with_yoyo + diet_energy_expenditure)) > metabolism_change_threshold) {
            metabolism_with_yoyo += floor((diet_energy_intake - (metabolism_with_yoyo + diet_energy_expenditure)) / 2.0);
        } // 기초대사량 변화 
    }

    if (weight_without_yoyo <= 0 || initial_metabolism <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight_without_yoyo << " " << initial_metabolism << "\n";
    }

    if (weight_with_yoyo <= 0 || metabolism_with_yoyo <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight_with_yoyo << " " << metabolism_with_yoyo << " ";
        if (initial_metabolism - metabolism_with_yoyo > 0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }

    return 0;
}
