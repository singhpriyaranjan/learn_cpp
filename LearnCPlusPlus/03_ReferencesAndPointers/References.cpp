#include "References.h"

#include <iostream>
#include <cstring>

using namespace std;
void ReferencesExample::addBonus(int& score) const
{
    score += 10;
}

void ReferencesExample::run()
{
    // Demonstrates an lvalue reference, an alias for an existing object.
    // References let a function modify a caller's value without copying it.
    // Syntax: type& alias{existing_object};
    int score{40};
    int& scoreAlias{score};
    scoreAlias += 5;
    addBonus(score);
    std::cout << "Score after updates through aliases: " << score << '\n';

    // A reference must be initialized and cannot be reseated. Both updates
    // affect one int. Do not return a reference to a local variable.
    // Expected output: Score after updates through aliases: 55.
    char* ptr = "hello";

    cout<<ptr<<endl;

    cout<<"strlen(ptr): "<<strlen(ptr)<<endl;
    int max_len = strlen(ptr);

    for(std::size_t i = 0; i< max_len; i++)
    {
        cout<<*ptr;
        ptr++;
    }

    int original = 10;
    cout<<"original: "<<original<<endl;
    int& ref = original;
    int* pOriginal = &original;

    cout<<"ref: "<<ref<<endl;
    ref = 20;
    cout<<"original: "<<original<<endl;
    cout<<"ref: "<<ref<<endl;
    cout<<"pOriginal: "<<pOriginal<<endl;
    cout<<"*pOriginal: "<<*pOriginal<<endl;
    ref++;
    original++;
    pOriginal++;
    cout<<"original: "<<original<<endl;
    cout<<"ref: "<<ref<<endl;
    cout<<"pOriginal: "<<pOriginal<<endl;
    cout<<"*pOriginal: "<<*pOriginal<<endl;

    int& refPOrginalValue = *pOriginal;
    int*& refPOrginal = pOriginal;

    refPOrginal++;
    pOriginal++;
    cout<<"refPOrginal: "<<refPOrginal<<endl;
    cout<<"*pOriginal: "<<*pOriginal<<endl;
    cout<<"refPOrginalValue: "<<refPOrginalValue<<endl;


}
