#include "DataTypes.h"

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;
void DataTypesExample::run()
{
    cout<<"sizeof int: "<<sizeof(int)<<endl
    <<"sizeof char: "<<sizeof(char)<<endl
         <<"sizeof float: "<<sizeof(float)<<endl
         <<"sizeof double: "<<sizeof(double)<<endl
         <<"sizeof bool: "<<sizeof(bool)<<endl;


    int i = 67;
    cout<<"i: "<<i<<endl;
    cout<<"i: "<<(char)i<<endl;

    char ii = 67;
    char iii = 'D';
    int ij = (int)iii;
    cout<<"ii: "<<ii<<endl;
    cout<<"iii: "<<iii<<endl;
    cout<<"ij: "<<ij<<endl;

    // Demonstrates common fundamental and library types. Types tell the
    // compiler how values are represented and which operations are valid.
    // Basic syntax: type variable{value};
    int itemCount{3};
    double temperatureCelsius{21.5};
    bool isReady{true};
    char grade{'A'};
    std::string topic{"good girl"};

    std::cout << topic << ": count=" << itemCount
              << ", temperature=" << temperatureCelsius
              << ", ready=" << std::boolalpha << isReady
              << ", grade=" << grade << '\n';

    // sizeof reports bytes, not a universal fixed size for every platform.
    // Common mistake: assuming int or long has the same size everywhere.
    // Good practice: use a type whose meaning fits the value; use fixed-width
    // types from <cstdint> when a specific integer width is required.
    const std::size_t integerBytes{sizeof(itemCount)};
    std::cout << "int occupies " << integerBytes << " byte(s) here.\n";//4

    const size_t tempBytes{sizeof(temperatureCelsius)};//8
    cout<<"temperatureCelsius occupies "<<tempBytes<<endl;

    cout<<"isready occupies "<<sizeof(isReady)<<endl;//1
    cout<<"grade occupies "<<sizeof(grade)<<endl;//1
    cout<<"topic occupies "<<sizeof(topic)<<endl;//32
    cout<<"topic occupies "<<topic.length()<<endl;//32
    string ira = "g";
    char ira1[] = {'i', 'r', 'a', '\0'};

    cout<<"ira occupies "<<ira.length()<<endl;
    cout<<"ira1 occupies "<<sizeof(ira1)<<endl;//11




    // Expected output (the int size line can vary by platform):
    // Data types: count=3, temperature=21.5, ready=true, grade=A
    // int occupies 4 byte(s) here.
}
