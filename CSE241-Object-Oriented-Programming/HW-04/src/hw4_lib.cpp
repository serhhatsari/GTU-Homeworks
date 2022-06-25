#include "hw4_lib.h"

namespace doy
{
    int DayofYearSet::totalObjects = 0;

    DayofYearSet::DayofYearSet(){};
    /* default constructer */
    DayofYearSet::DayofYearSet(vector<DayofYear> set)
    {
        /* this constructer will take a vector */
        /* and assign it to dates pointer array */
        int i;
        if (set.size() != 0)
        {
            dates = new DayofYear[set.size()];

            for (i = 0; i < set.size(); i++)
            {
                dates[i].set_day(set[i].get_day());
                dates[i].set_month(set[i].get_month());
            }

            date_num = set.size();
        }

        totalObjects += set.size();
    };

    DayofYearSet::DayofYear::DayofYear(){};
    /* default day of year constructer */

    DayofYearSet::DayofYear::DayofYear(int newDay, int newMonth)
    {

        /* day of year class constructer */
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (newMonth > 12 || newMonth < 1)
        { /* check month */
            cerr << "Constructer parameter is not valid \n";
            cerr << "MONTH PARAMETER IS NOT VALID! \n";
            cerr << "Terminating... \n";
            exit(1);
        }
        else if (newDay > Months[newMonth - 1] || newDay < 1)
        { /* check day */
            cerr << "Constructer parameter is not valid \n";
            cerr << "DAY PARAMETER IS NOT VALID! \n";
            cerr << "Terminating... \n";
            exit(1);
        }
        day = newDay;
        month = newMonth;
    };

    void DayofYearSet::DayofYear::set_day(int otherDay)
    {
        /* day of year class set day */
        day = otherDay;
    };

    void DayofYearSet::DayofYear::set_month(int otherMonth)
    {
        /* day of year class set month */
        if (otherMonth > 12 || otherMonth < 1)
        { /* check condition */
            cerr << "MONTH PARAMETER IS NOT VALID! \n";
            cerr << "Terminating... \n";
            exit(1);
        }

        month = otherMonth;
    };

    ostream &operator<<(ostream &outputStream, const DayofYearSet &set)
    {

        /* overloading stream insertion operator */
        int i;
        ofstream out_file("output.txt");

        for (i = 0; i < set.get_dateNum(); i++)
        { /* loop */
            outputStream << "DAY:" << set.get_dates()[i].get_day() << " MONTH: " << set.get_dates()[i].get_month() << endl;
        }

        for (i = 0; i < set.get_dateNum(); i++)
        {
            out_file << "DAY:" << set.get_dates()[i].get_day() << " MONTH: " << set.get_dates()[i].get_month() << endl;
        }

        return outputStream;
    };

    bool DayofYearSet::operator==(const DayofYearSet &otherSet) const
    {

        /* overloading equality operator */
        int i;
        decltype(i) k;
        bool check = true;
        if (date_num == otherSet.date_num)
        { /* check condition */
            for (i = 0; i < date_num; i++)
            {
                check = true;

                for (k = 0; k < otherSet.date_num; k++)
                {
                    if (dates[i].get_day() == otherSet.dates[k].get_day())
                    { /* check condition */
                        if (dates[i].get_month() == otherSet.dates[k].get_month())
                        { /* check condition */
                            check = false;
                        }
                    }
                }

                if (check)
                { /* check condition */
                    return false;
                }
            }
            return true;
        }
        return false;
    };

    bool DayofYearSet::operator!=(const DayofYearSet &otherSet) const
    {
        /* overloading not equality operator */
        int i;
        auto k = 0;
        bool check = true;
        if (date_num == otherSet.date_num)
        { /* check condition */
            for (i = 0; i < date_num; i++)
            {
                check = true;

                for (k = 0; k < otherSet.date_num; k++)
                {
                    if (dates[i].get_day() == otherSet.dates[k].get_day())
                    { /* check condition */
                        if (dates[i].get_month() == otherSet.dates[k].get_month())
                        { /* check condition */
                            check = false;
                        }
                    }
                }

                if (check)
                {
                    return true;
                }
            }
            return false;
        }
        return true;
    };

    DayofYearSet DayofYearSet::operator+(const DayofYearSet &other) const
    {
        /* overloading union operator */
        int day, month, i, k;
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool check = true;
        vector<DayofYear> unionSet;

        for (month = 1; month <= 12; month++)
        {
            for (day = 1; day <= Months[month - 1]; day++)
            {
                check = true;

                for (i = 0; i < date_num; i++)
                {
                    if (dates[i].get_day() == day)
                    { /* check condition */
                        if (dates[i].get_month() == month)
                        { /* check condition */
                            check = false;
                            unionSet.push_back(DayofYear(day, month));
                            break;
                        }
                    }
                }

                if (check)
                { /* check condition */
                    for (i = 0; i < other.date_num; i++)
                    {
                        if (other.dates[i].get_day() == day)
                        { /* check condition */
                            if (other.dates[i].get_month() == month)
                            { /* check condition */
                                unionSet.push_back(DayofYear(day, month));
                                break;
                            }
                        }
                    }
                }
            }
        }

        return DayofYearSet(unionSet);
    };

    DayofYearSet DayofYearSet::operator-(const DayofYearSet &other) const
    {
        /* overloading difference operator */

        int day, month, i, k;
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool check = false, check_exists = false;
        vector<DayofYear> diffSet;

        for (month = 1; month <= 12; month++)
        {
            for (day = 1; day <= Months[month - 1]; day++)
            {
                check = false;
                check_exists = false;
                for (i = 0; i < date_num; i++)
                {
                    if (dates[i].get_day() == day)
                    { /* check condition */
                        if (dates[i].get_month() == month)
                        { /* check condition */
                            check = true;
                            break;
                        }
                    }
                }

                if (check)
                { /* check condition */
                    for (i = 0; i < other.date_num; i++)
                    {
                        if (other.dates[i].get_day() == day)
                        { /* check condition */
                            if (other.dates[i].get_month() == month)
                            { /* check condition */
                                check_exists = true;
                                break;
                            }
                        }
                    }

                    if (!check_exists)
                    { /* check condition */
                        diffSet.push_back(DayofYear(day, month));
                    }
                }
            }
        }

        return DayofYearSet(diffSet);
    };

    DayofYearSet DayofYearSet::operator^(const DayofYearSet &other) const
    {
        /* overloading intersection operator */
        int day, month, i, k;
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool check = false, check_exists = false;
        vector<DayofYear> interSet;

        for (month = 1; month <= 12; month++)
        {
            for (day = 1; day <= Months[month - 1]; day++)
            {
                check = false;
                check_exists = false;
                for (i = 0; i < date_num; i++)
                {
                    if (dates[i].get_day() == day)
                    { /* check day */
                        if (dates[i].get_month() == month)
                        { /* check month */
                            check = true;
                            break;
                        }
                    }
                }

                if (check)
                { /* check condition */
                    for (i = 0; i < other.date_num; i++)
                    {
                        if (other.dates[i].get_day() == day)
                        {
                            if (other.dates[i].get_month() == month)
                            { /* check date */
                                check_exists = true;
                                break;
                            }
                        }
                    }

                    if (check_exists)
                    { /* check condition */
                        interSet.push_back(DayofYear(day, month));
                    }
                }
            }
        }

        return DayofYearSet(interSet);
    };

    DayofYearSet DayofYearSet::operator!()
    {
        /* overloading complement operator */
        int day, month, i, k;
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool check = false;
        vector<DayofYear> compSet;

        for (month = 1; month <= 12; month++)
        {
            for (day = 1; day <= Months[month - 1]; day++)
            {
                check = false;

                for (i = 0; i < date_num; i++)
                {
                    if (dates[i].get_day() == day)
                    { /* check day */
                        if (dates[i].get_month() == month)
                        { /* check month */
                            check = true;
                            break;
                        }
                    }
                }

                if (!check)
                { /* check condition */
                    compSet.push_back(DayofYear(day, month));
                }
            }
        }

        return DayofYearSet(compSet);
    };

    DayofYearSet::DayofYear &DayofYearSet::operator[](int index)
    {
        /* overloading position index operator */
        if (index < 0 || index >= date_num)
        { /* check condition */
            cerr << "THERE IS NO ELEMENT IN THAT INDEX! \n";
            cerr << "Terminating... \n";
            exit(1);
        }

        return dates[index];
    };

    void DayofYearSet::add(const DayofYear &date)
    {
        /* add method addes one object */
        int i;
        vector<DayofYear> oldDates;
        vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (date.get_month() > 12 || date.get_month() < 1)
        { /* check condition */
            cerr << "Could not add the new element \n";
            cerr << "MONTH VALUE IS NOT VALID! \n";
            cerr << "Terminating... \n";
            exit(1);
        }
        else if (date.get_day() > Months[date.get_month() - 1] || date.get_day() < 1)
        { /* check condition */
            cerr << "Could not add the new element \n";
            cerr << "DAY VALUE IS NOT VALID! \n";
            cerr << "Terminating... \n";
            exit(1);
        }

        for (i = 0; i < date_num; i++)
        {
            if (dates[i].get_day() == date.get_day())
            { /* check day */
                if (dates[i].get_month() == date.get_month())
                { /* check month */
                    cout << "DATE DUPLICATE!" << endl;
                    cout << "Terminating..." << endl;
                    exit(1);
                }
            }
        }

        for (i = 0; i < date_num; i++)
        {
            oldDates.push_back(dates[i]);
        }

        dates = new DayofYear[date_num + 1];

        for (i = 0; i < date_num; i++)
        {
            dates[i] = oldDates[i];
        }

        dates[date_num] = date;

        date_num++;
        totalObjects++;
    };

    void DayofYearSet::remove()
    {
        /* remove method delete the last element of the array */
        int i;
        vector<DayofYear> oldDates;

        if (date_num == 0)
        { /* check condition */
            cerr << "THERE IS NO ELEMENT TO BE REMOVED! \n";
            cerr << "Terminating... \n";
            exit(1);
        }

        for (i = 0; i < date_num; i++)
        {
            oldDates.push_back(dates[i]);
        }

        dates = new DayofYear[date_num - 1];

        oldDates.pop_back();

        for (i = 0; i < date_num - 1; i++)
        {
            dates[i] = oldDates[i];
        }

        date_num--;
        totalObjects--;
    }

    int DayofYearSet::size()
    {
        /* it returns the number of dates in the object */
        return date_num;
    };

    int DayofYearSet::get_total_obj()
    {
        /* static total object num */
        return totalObjects;
    }

}