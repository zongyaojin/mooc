#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct City {
    string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    string name;
    vector<City> cities;
};

struct Tours {
    string title;
    vector<Country> countries;
};

Tours createData();

int main()
{
    Tours tours = createData();
    string ruler{"-----------------------------------------------------------------"};
   
    cout << setw(45) << tours.title << "\n" << ruler << endl;
    
    cout << setw(15) << left << "Country"
         << setw(20) << left << "City" 
         << setw(15) << right << "Population" 
         << setw(15) << right << "Price" << endl;
    cout << ruler << endl;
    
    for(auto country : tours.countries) {
        cout << setw(15) << left << country.name;
        bool first_row = true;
        for(auto city : country.cities) {
            if (first_row) {
                cout << setw(20) << left << city.name;
                first_row = false;
            } else {
                cout << setw(15) << "" << setw(20) << left << city.name;
            }
            cout << setw(15) << right << city.population 
                 << setw(15) << right << city.cost << endl;
        }
        cout << ruler << endl;
    }

    cout << endl << endl;
    return 0;
}

Tours createData() {
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };
    return tours;
}
