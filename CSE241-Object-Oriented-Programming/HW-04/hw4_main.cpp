#include "hw4_lib.h"

using namespace doy;

int main()
{
    DayofYearSet fi, th, fo, el;

    DayofYearSet::DayofYear a(4, 11);
    DayofYearSet::DayofYear b(1, 7);
    DayofYearSet::DayofYear c(12, 6);
    DayofYearSet::DayofYear d(5, 4);
    DayofYearSet::DayofYear e(20, 3);

    cout << "ADD METHOD TEST 1\n";
    fo.add(a);
    fo.add(b);
    fo.add(c);
    fo.add(d);
    fo.add(e);
    cout << fo;
    
    cout << "\nREMOVE METHOD TEST\n";
    fo.remove();
    cout << fo;

    cout << "\nSIZE METHOD TEST\n";
    cout << "SIZE IS : " << fo.size() << endl;

    fi.add(c);
    fi.add(d);
    fi.add(e);

    vector<DayofYearSet::DayofYear> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    DayofYearSet se(vec); /* testing vector constructer */

    cout << " \nTOTAL OBJECT NUM TEST\n"; /* it should be 10  because we removed one of the objects*/
    cout << "Total object num " << DayofYearSet::get_total_obj() << endl;

    cout << "\nEQUALITY OPERATOR TEST \n";
    if (fi == se)
        cout << "THEY ARE EQUAL \n";
    else
        cout << "THEY ARE NOT EQUAL \n";

    cout << "\nNOT EQUALITY OPERATOR TEST \n";
    if (fi != se)
        cout << "THEY ARE NOT EQUAL \n";
    else
        cout << "THEY ARE  EQUAL \n";

    cout << "\nUNION OPERATOR TEST \n";
    th = fi + se;
    cout << th;

    cout << "\nDIFFERENCE OPERATOR TEST \n";
    th = fi - se;
    cout << th;

    cout << "\nINTERSECTION OPERATOR TEST \n";
    th = fi ^ se;
    cout << th;

    cout << "\nCOMPLEMENT OPERATOR TEST \n";
    cout << "it should be empty because of the set rules \n";
    cout << "x = a ^ !a, x = () empty \n";
    th = fi ^ !fi;
    cout << th;

    cout << "\nDE MORGAN TEST \n";
    if (!(fi + se) == (!fi ^ !se))
        cout << "DE MORGAN RULE IS CORRECT \n";
    else
        cout << "DE MORGAN RULE IS WRONG \n";

    cout << "\nPOSITION INDEX OPERATOR TEST\n";
    th = fi + se;
    for (int i = 0; i < th.get_dateNum(); i++)
    {
        cout << "Day " << th[i].get_day() << " Month " << th[i].get_month() << endl;
    }
};
