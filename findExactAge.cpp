#include <iostream>
#include <sstream>
#include <ctime>
#include <string>


void findAge(int current_date, int current_month, int current_year,
             int birth_date, int birth_month, int birth_year){

                int months[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};

            
                if (birth_date > current_date) {
                    current_date = current_date + months[birth_month - 1];
                    current_month = current_month - 1; 
                }

                if (birth_month > current_month) {
                    current_year = current_year - 1;
                    current_month = current_month + 12;
                }

                int calculated_date = current_date - birth_date;
                int calculated_month = current_month - birth_month;
                int calculated_year = current_year - birth_year;

                printf("Present age\nYears: %d  Months: %d  Days: %d\n", calculated_year, calculated_month, calculated_date);
             }

        
             int main(){
                std::cout << "Please enter in a date, format m/d/yyyy\n";
                std:: string date;
                getline(std::cin, date); 

                std::istringstream ss(date);
                std::string token;
                
                int birth_info[10] = {};
                int i = 0;
                while (getline(ss, token, '/')){
                    i++;
                    birth_info[i] = (stoi(token));
                }

                int birth_month = birth_info[1];
                int birth_date = birth_info[2];
                int birth_year = birth_info[3];

                time_t now = time(0);
                tm* current_time = localtime(&now);
                int current_year = 1900 + current_time->tm_year;
                int current_month = 1 + current_time->tm_mon;
                int current_date = current_time->tm_mday;

                findAge(current_date, current_month, current_year, birth_date, birth_month, birth_year);
                
             }