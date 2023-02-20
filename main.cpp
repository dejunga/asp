#include <iostream>
#include <fstream>
#include <ranges>
#include <sstream>
#include <map>
#include <string>
#include <vector>


using namespace std;


class Motor {
public:


    std::map<long double, std::pair<long double, long double>, std::greater<>> data2;



    void get_top_keys(int n = 1) const {
        int i = 0;
        for (auto &p: data2) {
            if (i >= n) {break;}
            cout << p.first << endl;
            i++;
        }
    }


    void get_min_keys(int n = 1) {
        int i = 0;
        for (const auto &p: std::ranges::reverse_view(data2)) {
            if (i >= n) {break;}
            cout << p.first << endl;
            i++;
        }
    }






        void get_max_values(int odabir = 0) const {
        vector<long double> vektor;
        for (const auto &p: data2) {
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


    void get_min_values(int odabir = 0) const {
        vector<long double> vektor;
        for (const auto &p: data2) {
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


    void delete_by_key(long double i = 0){
    for (auto &p: data2) {
        if (p.first == i) {
            data2.erase(p.first);
            break;
        }
    }
};





    void delete_by_value(long double i = 0){
        for (auto &p: data2) {
            if (p.second.first == i) {
                data2.erase(p.first);
                break;}

            else if (p.second.second == i) {
                data2.erase(p.first);
                break;}
        }
    };



    void add_by_key(long double key, long double prvi, long double drugi){
        data2.insert({key, std::pair<long double,long double>(prvi, drugi)});
    }



    void find(long double x){
        if (auto search = data2.find(x); search != data2.end())
            std::cout << "Found " << search->first << " " << search->second.first << " " << search->second.second << '\n';
        else
            std::cout << "Not found  "<< x << endl;


    }






    };

















    int main() {

        Motor motor;

        std::ifstream file("C:/Users/j/Downloads/measures_v2.csv");
        std::string line;

        // preskace prvu liniju csv file-a
        std::getline(file, line);

        // pravi mapu
        std::map<long double, std::pair<long double, long double>, std::greater<>> data;

        //uzima prvih 500000 redaka i kreira 3 stupca
        while (std::getline(file, line) && data.size() < 500000) {
            std::istringstream iss(line);
            std::string value;
            long double col1, col2, col3;




            // delimiter je ","
            std::getline(iss, value, ',');
            col1 = std::stold(value);  // pretvara string to long double
//        std::getline(iss, value, ',');  // preskace red
            std::getline(iss, value, ',');
            col2 = std::stold(value);  // pretvara string to long double
            std::getline(iss, value, ',');
            col3 = std::stold(value);  // pretvara string to long double

            //insert to map
            data[col1] = std::make_pair(col2, col3);

        }



        //
        motor.data2 = data;

        int i = 0;


        motor.delete_by_key(150);

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



        cout << "--------------------------------" <<endl;


        motor.get_top_keys(1);

        motor.get_min_keys(1);



        motor.get_max_values(2);

        motor.get_min_values(3);

        motor.find(132.697);

//132.69683837890625

        return 0;
    }





