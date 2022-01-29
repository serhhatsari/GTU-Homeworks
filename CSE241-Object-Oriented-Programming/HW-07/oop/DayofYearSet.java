package oop;

import java.util.ArrayList;

/**
 * DayofYearSet and its inner class DayofYear implementations.
 * 
 * @author Serhat Sarı  
 * @since  06-01-2022
 * 
 */

/**
 * DayofYearSet is a Java class to represent a set of DayofYear objects
 */
public class DayofYearSet {

    /**
     * DayofYear is a Java class to represent the day of the year.
     */
    public static class DayofYear {

        /**
         * Default constructer of DayofYear
         */
        public DayofYear() {
            day = 1;
            month = 1;
            // assigning default values
        }

        /**
         * DayofYear constructer that takes day and month.
         * 
         * @param newDay   day from the user input
         * @param newMonth month from the user input
         * 
         */
        public DayofYear(int newDay, int newMonth) {

            // creating array list for storing month day counts
            ArrayList<Integer> Months = new ArrayList<Integer>();
            Months.add(31);
            Months.add(28);
            Months.add(31);
            Months.add(30);
            Months.add(31);
            Months.add(30);
            Months.add(31);
            Months.add(31);
            Months.add(30);
            Months.add(31);
            Months.add(30);
            Months.add(31);

            // adding days to the arraylist

            if (newMonth > 12 || newMonth < 1) { /* check month */
                System.out.println("Constructer parameter is not valid");
                System.out.println("MONTH PARAMETER IS NOT VALID! \n");
                System.out.println("Terminating... \n");
                System.exit(0);
            } else if (newDay > Months.get(newMonth - 1) || newDay < 1) { /* check day */
                System.out.println("Constructer parameter is not valid");
                System.out.println("DAY PARAMETER IS NOT VALID!");
                System.out.println("Terminating...");
                System.exit(0);
            }
            day = newDay;
            month = newMonth;
            // assigning day and month

        }

        /**
         * Setter for day
         * 
         * @param otherDay day from the user input
         */
        public void set_day(int otherDay) {
            day = otherDay;
            // assigning
        }

        /**
         * Setter for month
         * 
         * @param otherMonth month from the user input
         */
        public void set_month(int otherMonth) {

            month = otherMonth;
        }

        /**
         * Getter for day
         * 
         * @return day of the object
         */
        public int get_day() {
            return day;
        }

        /**
         * Getter for month
         * 
         * @return month of the object
         */
        public int get_month() {
            return month;
        }

        private int day = 3;
        private int month;
    }

    /**
     * Default constructer of DayofYearSet
     */
    public DayofYearSet() {
        /* default constructer */
        date_num = 0;
    }

    /**
     * Constructor that takes a ArrayList of DayOfYear objects.
     * 
     * @param set ArrayList of DayofYear objects
     */
    public DayofYearSet(ArrayList<DayofYear> set) {

        // check set size
        if (set.size() != 0) {
            dates = new DayofYear[set.size()];

            for (int i = 0; i < set.size(); i++) {
                dates[i] = set.get(i);
            }
            // assign set to the normal array with toArray
            date_num = set.size();
        }

        totalObjects += set.size();
    }

    /**
     * ToString method to print DayofYearSet details.
     * 
     * @return DayofYearSet details
     */
    @Override
    public String toString() {
        int i;
        StringBuilder details = new StringBuilder();

        for (i = 0; i < size(); i++) { /* loop */
            details.append("DAY:" + dates[i].get_day() + " MONTH: " + dates[i].get_month() + "\n");
        }
        // printing details of the day of year set
        return details.toString();
    }

    /**
     * equals method comparing DayofYearSet objects.
     * 
     * @param otherObj other set to be compared with
     * @return boolean type
     */
    @Override
    public boolean equals(Object otherObj) {
        /* overriding equals method */
        if (otherObj == null) {
            return false;
        } else if (getClass() != otherObj.getClass()) { // check if they are the same class
            return false;
        } else {
            // check if they are equal or not
            int i, k;
            boolean check = true;
            DayofYearSet otherSet = (DayofYearSet) otherObj;
            if (date_num == otherSet.date_num) { /* check condition */
                for (i = 0; i < date_num; i++) {
                    check = true;

                    for (k = 0; k < otherSet.date_num; k++) {
                        if (dates[i].get_day() == otherSet.dates[k].get_day()) { /* check condition */
                            if (dates[i].get_month() == otherSet.dates[k].get_month()) { /* check condition */
                                check = false;
                            }
                        }
                    }

                    if (check) { /* check condition */
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
    }

    /**
     * union method to find the union of 2 sets
     * 
     * @param other other set to be union with
     * @return it will return DayofYearSet object
     */
    public DayofYearSet union(DayofYearSet other) {

        // array list to hold the months day counts
        int day, month, i;
        ArrayList<Integer> Months = new ArrayList<Integer>();
        Months.add(31);
        Months.add(28);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        // adding day numbers of montsh

        boolean check = true;

        ArrayList<DayofYear> unionSet = new ArrayList<DayofYear>();
        // create an new array list

        // find the union of 2 set
        for (month = 1; month <= 12; month++) {
            for (day = 1; day <= Months.get(month - 1); day++) {
                check = true;

                for (i = 0; i < date_num; i++) {
                    if (dates[i].get_day() == day) { /* check condition */
                        if (dates[i].get_month() == month) { /* check condition */
                            check = false;
                            unionSet.add(new DayofYear(day, month));
                            break;
                        }
                    }
                }

                if (check) { /* check condition */
                    for (i = 0; i < other.date_num; i++) {
                        if (other.dates[i].get_day() == day) { /* check condition */
                            if (other.dates[i].get_month() == month) { /* check condition */
                                unionSet.add(new DayofYear(day, month));
                                break;
                            }
                        }
                    }
                }
            }
        }
        // return an object using array list as parameter
        return new DayofYearSet(unionSet);
    }

    /**
     * difference method to find the difference of 2 sets
     * 
     * @param other other set to be difference with
     * @return it will return DayofYearSet object
     */
    public DayofYearSet difference(DayofYearSet other) {

        // array list to hold the months day counts

        int day, month, i;
        ArrayList<Integer> Months = new ArrayList<Integer>();
        Months.add(31);
        Months.add(28);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        // add number of days in monts to the arraylist
        boolean check = false, check_exists = false;
        ArrayList<DayofYear> diffSet = new ArrayList<DayofYear>();

        // find the difference of 2 set
        for (month = 1; month <= 12; month++) {
            for (day = 1; day <= Months.get(month - 1); day++) {
                check = false;
                check_exists = false;
                for (i = 0; i < date_num; i++) {
                    if (dates[i].get_day() == day) { /* check condition */
                        if (dates[i].get_month() == month) { /* check condition */
                            check = true;
                            break;
                        }
                    }
                }

                if (check) { /* check condition */
                    for (i = 0; i < other.date_num; i++) {
                        if (other.dates[i].get_day() == day) { /* check condition */
                            if (other.dates[i].get_month() == month) { /* check condition */
                                check_exists = true;
                                break;
                            }
                        }
                    }

                    if (!check_exists) { /* check condition */
                        diffSet.add(new DayofYear(day, month));
                    }
                }
            }
        }

        // return the newly created object
        return new DayofYearSet(diffSet);
    }

    /**
     * intersection method to find the intersection of 2 sets
     * 
     * @param other other set to be intersection with
     * @return it will return DayofYearSet object
     */
    public DayofYearSet intersection(DayofYearSet other) {

        int day, month, i;
        // create a new array list
        ArrayList<Integer> Months = new ArrayList<Integer>();
        Months.add(31);
        Months.add(28);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        // add day numbers to the array list

        boolean check = false, check_exists = false;
        ArrayList<DayofYear> interSet = new ArrayList<DayofYear>();

        // find the intersect of 2 set
        for (month = 1; month <= 12; month++) {
            for (day = 1; day <= Months.get(month - 1); day++) {
                check = false;
                check_exists = false;
                for (i = 0; i < date_num; i++) {
                    if (dates[i].get_day() == day) { /* check day */
                        if (dates[i].get_month() == month) { /* check month */
                            check = true;
                            break;
                        }
                    }
                }

                if (check) { /* check condition */
                    for (i = 0; i < other.date_num; i++) {
                        if (other.dates[i].get_day() == day) {
                            if (other.dates[i].get_month() == month) { /* check date */
                                check_exists = true;
                                break;
                            }
                        }
                    }

                    if (check_exists) { /* check condition */
                        interSet.add(new DayofYear(day, month));
                    }
                }
            }
        }
        // return the newly created object
        return new DayofYearSet(interSet);
    }

    /**
     * complement method to find the complement of the set
     * 
     * @return it will return DayofYearSet object
     */
    public DayofYearSet complement() {

        int day, month, i;
        // create an array list
        ArrayList<Integer> Months = new ArrayList<Integer>();
        Months.add(31);
        Months.add(28);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        Months.add(30);
        Months.add(31);
        // add day numbers to it
        boolean check = false;
        ArrayList<DayofYear> compSet = new ArrayList<DayofYear>();

        for (month = 1; month <= 12; month++) {
            for (day = 1; day <= Months.get(month - 1); day++) {
                check = false;

                for (i = 0; i < date_num; i++) {
                    if (dates[i].get_day() == day) { /* check day */
                        if (dates[i].get_month() == month) { /* check month */
                            check = true;
                            break;
                        }
                    }
                }

                if (!check) { /* check condition */
                    compSet.add(new DayofYear(day, month));
                }
            }
        }
        // return the newly created object
        return new DayofYearSet(compSet);
    }

    /**
     * Method add, adds an element to the set
     * 
     * @param newDate element from the user to be added
     */
    public void add(DayofYear newDate) {

        int i;
        // Please note that no duplicates are allowed in a set

        for (i = 0; i < date_num; i++) {

            if (dates[i].get_day() == newDate.get_day() && dates[i].get_month() == newDate.get_month()) {

                // if there is an duplicate, it wont add the new date
                return;
            }

        }

        ArrayList<DayofYear> oldDates = new ArrayList<DayofYear>();
        // create new arraylist

        for (i = 0; i < date_num; i++) {
            oldDates.add(dates[i]);
        }
        // assign old dates

        dates = new DayofYear[date_num + 1];

        for (i = 0; i < date_num; i++) {
            dates[i] = oldDates.get(i);
        }

        dates[date_num] = newDate;
        // add new date

        date_num++;
        totalObjects++;
        // incrementing date num and total objects
    }

    /**
     * Method remove, removes the last element from the set
     * 
     */
    public void remove() {

        int i;
        ArrayList<DayofYear> oldDates = new ArrayList<DayofYear>();
        // create an new array list

        if (date_num == 0) {
            System.out.println("THERE IS NO ELEMENT TO BE REMOVED!");
            System.out.println("Terminating");
            System.exit(1);
        }

        // if there is no element left, it will terminate the program

        for (i = 0; i < date_num; i++) {
            oldDates.add(dates[i]);
        }
        // adding old dates

        dates = new DayofYear[date_num - 1];
        // deleting a date
        oldDates.remove(date_num - 1);

        for (i = 0; i < date_num - 1; i++) {
            dates[i] = oldDates.get(i);
        }
        // assigning it again
        // decrementing date numb and object count
        date_num--;
        totalObjects--;
    }

    /**
     * • Method size returns the number of elements.
     * 
     * @return integer type, number of elements
     */
    public int size() {
        return date_num;
        // return the size
    }

    /**
     * static method that returns the total number of DayOfYear objects alive
     * 
     * @return integer type
     */
    public static int get_total_obj() {
        return totalObjects;
        // return the static field
    }

    // DayofYearSet class keeps its elements using a DayofYear[] data member.
    private DayofYear[] dates;

    private int date_num;

    // total number of DayOfYear objects alive
    private static int totalObjects = 0;

}