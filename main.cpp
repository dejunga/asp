#include <iostream>
#include <fstream>
#include <ranges>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Motor {
private:


public:

    std::map<long double, std::pair<long double, long double>, std::greater<>> data2;


    void get_top_keys(int n = 1) {
        int i = 0;
        for (auto &p: data2) {
            if (i >= n) {
                break;
            }
            cout << p.first << endl;
            std::cout << std::endl;
            i++;
        }
    }


    void get_min_keys(int n = 1) {
        int i = 0;
        for (auto &p: std::ranges::reverse_view(data2)) {
            if (i >= n) {
                break;
            }
            cout << p.first << endl;
            std::cout << std::endl;
            i++;
        }
    }


    void get_max_values(int n = 1, int odabir = 0) {
        vector<long double> vektor;
        int i = 0;
        for (auto &p: data2) {
            if (odabir == 2) {
                vektor.push_back(p.second.first);
            }

            if (odabir == 3) {
                vektor.push_back(p.second.second);
            }
        }

        std::sort(vektor.begin(), vektor.end());

        cout << vektor.back() << endl;

    }


    void get_min_values(int n = 1, int odabir = 0) {
        vector<long double> vektor;
        int i = 0;
        for (auto &p: data2) {
            if (odabir == 2) {
                vektor.push_back(p.second.first);
            }

            if (odabir == 3) {
                vektor.push_back(p.second.second);
            }
        }

        std::sort(vektor.begin(), vektor.end());

        cout << vektor.front() << endl;

    }


    void delete_by_key(long double odabir = 0){
    for (auto &p: data2) {
        if (p.first == odabir) {
            data2.erase(p.first);
            break;
        }
    }
};





    void delete_by_value(long double odabir = 0){
        for (auto &p: data2) {
            if (p.second.first == odabir) {
                data2.erase(p.first);
                break;
            }

            else if (p.second.second == odabir) {
                data2.erase(p.first);
                break;
            }
        }
    };



    void add_by_key(long double key, long double prvi, long double drugi){
        data2.insert({key, std::pair<long double,long double>(prvi, drugi)});
    }






    };

















    int main() {



        Motor motor;


//    Motor::get_top_values(data, 3);





        std::ifstream file("C:/Users/j/Downloads/measures_v2.csv");
        std::string line;

        // Skip the first line
        std::getline(file, line);

        // Create the map
        std::map<long double, std::pair<long double, long double>, std::greater<>> data;

        while (std::getline(file, line) && data.size() < 500000) {
            std::istringstream iss(line);
            std::string value;
            long double col1, col2, col3;




// Parse the line using ',' as the delimiter
            std::getline(iss, value, ',');
            col1 = std::stold(value);  // Convert string to long double
//        std::getline(iss, value, ',');  // Skip the second column
            std::getline(iss, value, ',');
            col2 = std::stold(value);  // Convert string to long double
//        std::getline(iss, value, ',');  // Skip the fourth column
            std::getline(iss, value, ',');
            col3 = std::stold(value);  // Convert string to long double

            // Insert the data into the map
            data[col1] = std::make_pair(col2, col3);

        }




        motor.data2 = data;
        int i = 0;


        motor.delete_by_key(132.69683837890625);
        cout << endl;

        motor.add_by_key(150,20,25);


        // Print out the data in the map
        for (const auto &pair: motor.data2) {
            if (i >= 10) {
                break;
            }
            std::cout << pair.first << ": (" << pair.second.first << ", " << pair.second.second << ")\n";
            i++;
        }



        cout << "------------------" <<endl;


        motor.get_top_keys(1);

        motor.get_min_keys(1);



        motor.get_max_values(1,2);

        motor.get_max_values(1,3);



        return 0;
    }



    // TODO : napraviti jos metodu koja ima funkciju find(u mapi) i trazi poseban/zadani key / value i printa ga

    //