#include <iostream>
#include <cmath>

int main() {

double max_final {-1};
while (max_final<=0 || max_final != std::round(max_final)){
    std::cout << "Enter maximum grade on final exam";
    std::cin >> max_final;
}

double your_final {-1};
while (your_final < 0 || your_final > max_final) {
    std::cout << "Enter your grade on final exam";
    std::cin >> your_final;
}

double max_midterm {-1};
while (max_midterm <=0 || max_midterm != std::round(max_midterm)){
    std::cout << "Enter max grade on midterm exam";
    std::cin >> max_midterm;
}

double your_midterm {-1};
while (your_midterm <0 || your_midterm > max_midterm){
    std::cout << "Enter your grade on midterm exam";
    std::cin >> your_midterm;
}

double Pro1_max {-1};
while (Pro1_max <=0 || Pro1_max != std::round(Pro1_max)){
    std::cout << "Enter max grade on project 1";
    std::cin >> Pro1_max;
}

double Pro1 {-1};
while (Pro1 < 0 || Pro1 > Pro1_max){
    std::cout << "Enter grade for Project 1";
    std::cin >> Pro1;
}

double Pro2_max {-1};
while (Pro2_max <=0 || Pro2_max != std::round(Pro2_max)){
    std::cout << "Enter max grade on Project 2";
    std::cin >> Pro2_max;
}

double Pro2 {-1};
while (Pro2 < 0 || Pro2 > Pro2_max){
    std::cout << "Enter grade for Project 2";
    std::cin >> Pro2;
}

double Pro3_max {-1};
while (Pro3_max <=0 || Pro3_max != std::round(Pro3_max)){
    std::cout << "Enter max grade on Project 3";
    std::cin >> Pro3_max;
}

double Pro3 {-1};
while (Pro3 < 0 || Pro3 > Pro3_max){
    std::cout << "Enter your grade on Project 3";
    std::cin >> Pro3;
}

double Pro4_max {-1};
while (Pro4_max <= 0 ||Pro4_max != std::round(Pro4_max)){
    std::cout << "Enter max grade on Project 4";
    std::cin >> Pro4_max;
}

double Pro4{-1};
while(Pro4 < 0 || Pro4 > Pro4_max){
    std::cout << "Enter your grade on Project 4";
    std::cin >> Pro4;
}

double Pro5_max{-1};
while (Pro5_max <= 0 || Pro5_max != std::round(Pro5_max)){
    std::cout << "Enter max grade on Project 5";
    std::cin>> Pro5_max;
}

double Pro5{-1};
while (Pro5 < 0 || Pro5 > Pro5_max) {
    std::cout << "Enter your grade on Project 5";
    std::cin >> Pro5;
}

double F = 100 * your_final / max_final;
double M = 100 * your_midterm / max_midterm;
double P1 = 100 * Pro1 / Pro1_max;
double P2 = 100 * Pro2 / Pro2_max;
double P3 = 100 * Pro3 / Pro3_max;
double P4 = 100 * Pro4 / Pro4_max;
double P5 = 100 * Pro5 / Pro5_max;

if (M < F) M= F;
if (P1 < F) P1 = F;
if (P2 < F) P2 = F;
if (P3 < F) P3 = F;
if (P4 < F) P4 = F;
if (P5 < F) P5 = F;

double E = 0.75 * F + 0.25 * M;

double P_avg = (P1 + P2 + P3+ P4 + P5) / 5.0;

double final_result;
if (E <= 40) {
final_result = E;
} else if (E >= 60) {
final_result = (2.0 / 3.0) * E + (1.0 / 3.0) * P_avg;
} else {
double project_weight = (1.0 / 3.0) * ((E - 40.0) / 20.0);
double exam_weight = 1.0 - project_weight;
final_result = project_weight * P_avg + exam_weight * E;
}

final_result = std::round(final_result + 1e-12);

std::cout << "Final grade: " << final_result << std::endl;
return 0;
}