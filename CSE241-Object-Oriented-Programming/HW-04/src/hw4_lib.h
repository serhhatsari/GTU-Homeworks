#ifndef HW4_LIB_H
#define HW4_LIB_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

namespace doy
{
    class DayofYearSet
    {
    public:
        class DayofYear
        {
        public:
            DayofYear();                         /* default constructer */
            DayofYear(int newDay, int newMonth); /* other constructer */

            void set_day(int otherDay);     /* set day */
            void set_month(int otherMonth); /* set month */

            int get_day() const { return day; };     /* get day */
            int get_month() const { return month; }; /* get month */

        private:
            int day;
            int month;
        };

        DayofYearSet();                      /* default constructer */
        DayofYearSet(vector<DayofYear> set); /* vector constructer */

        friend ostream &operator<<(ostream &outputStream, const DayofYearSet &set); /* overloading stream inserton */
        bool operator==(const DayofYearSet &otherSet) const;                        /* overloading equality */
        bool operator!=(const DayofYearSet &otherSet) const;                        /* ovrerloading not equality */

        DayofYearSet operator+(const DayofYearSet &other) const; /* overloading union */
        DayofYearSet operator-(const DayofYearSet &other) const; /* overloading difference */
        DayofYearSet operator^(const DayofYearSet &other) const; /* overloading intersection */
        DayofYearSet operator!();                                /* overloading complement  */
        DayofYear &operator[](int index);                        /* overloading index operator */

        DayofYear *get_dates() const { return dates; };

        void add(const DayofYear &date); /* add method */
        void remove();                   /* remove methjod */
        int size();                      /* size method */

        static int get_total_obj(); /* return total object */

        int get_dateNum() const { return date_num; };

    private:
        DayofYear *dates = nullptr;
        int date_num = 0;
        static int totalObjects;
    };
}
#endif