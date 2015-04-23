

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

void displayFlights(Graph&);

int main() {
    Graph airportGrid;
    ifstream input;
    string fileName;
    string airportAbbr = "";
 
    cout << "Enter in a file name: ";
    cin >> fileName;
    input.open(fileName);
    if(input.fail())
    {
        cout << "Failed to open file " << fileName << ". Terminating program." << endl;
        input.close();
        system("pause");
        return 1;
    }
    airportGrid.readFile(input);
    airportGrid.sort();
    airportGrid.buildGraph();
    displayFlights(airportGrid);
    do{
        cout << "\nEnter in the abbreviation from the source airport to display the Best Price Report (Type quit to exit): ";
        cin >> airportAbbr;
        if(airportAbbr != "quit")
        {
	       airportGrid.shortestPath(airportAbbr);
		   airportGrid.printPrice(airportAbbr);
        }
    }while(airportAbbr != "quit");
    input.close();
    system("pause");
    return 0;
}

void displayFlights(Graph& flights)
{
    cout << "Direct\tFlights" << endl;
    cout << "Source\tDest\tMileage\tCost\n------\t----\t-------\t----" << endl;
    flights.printAirports();
}