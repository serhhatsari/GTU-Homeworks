import java.util.ArrayList;
import oop.*;

import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Driver {
    public static void main(String args[]) {

        /* TESTING DAYOFYEARSET DEFAULT CONSTRUCTER */

        System.out.println("TESTING DayofYearSet default constructer");
        System.out.println("Lets create a DayofYearSet object named defConstructer");
        DayofYearSet defConstructer = new DayofYearSet();

        System.out.println("DayofYearSet default constructer worked!");

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DAYOFYEAR CONSTRUCTER */
        System.out.println("TESTING DayofYear constructer");
        System.out.println("Lets create a DayofYear object named newDate(3,4)");
        DayofYearSet.DayofYear newDate = new DayofYearSet.DayofYear(3, 4);
        System.out.println("Lets print the content of the DayofYear Object");
        System.out.println("Day: " + newDate.get_day() + " Month: " + newDate.get_month());
        System.out.println("DayofYear default constructer worked!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING CONSTRUCTER THAT TAKES ArrayList of DayOfYear objects */
        System.out.println("TESTING constructer that takes ArrayList of DayOfYear objects");
        System.out.println("First lets create 2 DayOfYear object");

        DayofYearSet.DayofYear arrDate1 = new DayofYearSet.DayofYear(3, 5);
        DayofYearSet.DayofYear arrDate2 = new DayofYearSet.DayofYear(7, 6);

        System.out.println("Then, lets create an ArrayList named arr that takes DayofYear objects");

        ArrayList<DayofYearSet.DayofYear> arr = new ArrayList<DayofYearSet.DayofYear>();
        arr.add(arrDate1);
        arr.add(arrDate2);

        System.out.println(
                "After that, lets create a DayofYearSet object named arrListConstructer using our arraylist named arr as arguman");
        DayofYearSet arrListConstructer = new DayofYearSet(arr);

        System.out.println("Lets print the content of the object we created");
        System.out.println(arrListConstructer.toString());
        System.out.println("CONSTRUCTER THAT TAKES ArrayList of DayOfYear objects WORKED");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* LETS CREATE AN OBJECT TO USE */

        System.out.println("Now , we will create a DayofYearSet object named doy1");
        System.out.println("And we will try the DayofYearSet methods with this object");

        DayofYearSet doy1 = new DayofYearSet();

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING add METHOD */
        System.out.println("TESTING add method with 2 new elements");
        System.out.println("BEFORE using add method:");
        System.out.println(doy1);
        System.out.println("AFTER using add method ");
        DayofYearSet.DayofYear date1 = new DayofYearSet.DayofYear(3, 5);
        DayofYearSet.DayofYear date2 = new DayofYearSet.DayofYear(7, 6);
        doy1.add(date1);
        doy1.add(date2);
        System.out.println(doy1);

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING add METHOD 2 */
        System.out.println("TESTING add method one more time with 2 new elements");
        System.out.println("BEFORE using add method:");
        System.out.println(doy1);
        System.out.println("AFTER using add method");
        DayofYearSet.DayofYear date3 = new DayofYearSet.DayofYear(5, 7);
        DayofYearSet.DayofYear date4 = new DayofYearSet.DayofYear(9, 1);
        doy1.add(date3);
        doy1.add(date4);
        System.out.println(doy1);

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING size METHOD after add methods */
        System.out.println("TESTING size method after add methods");
        System.out.println("Size of the DayofYearSet: " + doy1.size());
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING remove METHOD 1 */
        System.out.println("TESTING  remove method, remove method removes the last element");
        System.out.println("BEFORE using remove method:");
        System.out.println(doy1);
        System.out.println("AFTER using remove method");
        doy1.remove();
        System.out.println(doy1);

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING remove METHOD one more time */
        System.out.println("TESTING remove method one more time, remove method removes the last elements");
        System.out.println("BEFORE using remove method:");
        System.out.println(doy1);
        System.out.println("AFTER using remove method");
        doy1.remove();
        System.out.println(doy1);

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING size METHOD one more time */
        System.out.println("TESTING size method after remove methods");
        System.out.println("Size of the DayofYearSet: " + doy1.size());
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /*
         * TESTING static method that returns the total number of DayOfYear objects
         * alive in all the
         * sets.
         */
        System.out.print("TESTING static method that returns the total");
        System.out.println("number of DayOfYear objects alive in all the  sets.");

        System.out.println("So far, we have created 3 DayofYearSet objects");
        System.out.println(" OBJECT NAME -> SIZE");
        System.out.println("1) defConstructer -> " + defConstructer.size());
        System.out.println("2) arrListConstructer -> " + arrListConstructer.size());
        System.out.println("3) doy1 -> " + doy1.size());

        System.out.println("As you can see, we have 4 DayOfYear objects in all our DayofYearSet objects");
        System.out.println("Lets see what will static method return");
        System.out.println("Total Number of DayOfYear objects alive: " + DayofYearSet.get_total_obj());
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING toString METHOD */
        System.out.println("TESTING toString method");
        System.out.println("printing details with toString: ");
        System.out.println(doy1.toString());
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING equals METHOD */
        System.out.println("TESTING equals method");
        System.out.println("Lets create a DayofYearSet object named obj1");
        DayofYearSet obj1 = new DayofYearSet();
        DayofYearSet.DayofYear date5 = new DayofYearSet.DayofYear(9, 3);
        DayofYearSet.DayofYear date6 = new DayofYearSet.DayofYear(2, 2);
        DayofYearSet.DayofYear date7 = new DayofYearSet.DayofYear(6, 9);
        System.out.println("Lets add some dates to it");
        obj1.add(date5);
        obj1.add(date6);
        obj1.add(date7);
        System.out.println("Lets print the content of obj1");
        System.out.println(obj1);
        System.out.println("Now, lets create a another DayofYearSet object named obj2");
        DayofYearSet obj2 = new DayofYearSet();
        System.out.println("Lets add the same dates to it");
        obj2.add(date7);
        obj2.add(date6);
        obj2.add(date5);
        System.out.println("Lets print the content of obj2");
        System.out.println(obj2);
        System.out.println("Now lets check if they are equal or not");
        if (obj1.equals(obj2)) {
            System.out.println("RESULT: obj1 and obj2 are equal regardless of the keeping order.!");
        } else {
            System.out.println("RESULT: obj1 and obj2 are NOT equal!");
        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING equals METHOD */
        System.out.println("TESTING equals method one more time");
        System.out.println("Lets create a DayofYearSet object named obj3");
        DayofYearSet obj3 = new DayofYearSet();
        DayofYearSet.DayofYear date8 = new DayofYearSet.DayofYear(5, 3);
        DayofYearSet.DayofYear date9 = new DayofYearSet.DayofYear(8, 7);
        DayofYearSet.DayofYear date10 = new DayofYearSet.DayofYear(2, 3);
        DayofYearSet.DayofYear date11 = new DayofYearSet.DayofYear(1, 1);
        DayofYearSet.DayofYear date12 = new DayofYearSet.DayofYear(6, 3);
        System.out.println("Lets add some dates to it");
        obj3.add(date8);
        obj3.add(date9);
        obj3.add(date10);

        System.out.println("Lets print the content of obj3");
        System.out.println(obj3);
        System.out.println("Now, lets create a another DayofYearSet object named obj4");
        DayofYearSet obj4 = new DayofYearSet();

        System.out.println("Lets add the same dates to it");
        obj4.add(date11);
        obj4.add(date12);
        obj4.add(date8);
        System.out.println("Lets print the content of obj4");
        System.out.println(obj4);

        System.out.println("Now lets check if they are equal or not");
        if (obj3.equals(obj4)) {
            System.out.println("RESULT: obj3 and obj4 are equal regardless of the keeping order.!");
        } else {
            System.out.println("RESULT: obj3 and obj4 are NOT equal!");
        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /*
         * TESTING static method that returns the total number of DayOfYear objects
         * alive in all the
         * sets.
         */
        System.out.print("TESTING static method that returns the total");
        System.out.println("number of DayOfYear objects alive in all the  sets.");

        System.out.println("So far, we have created 7 DayofYearSet objects");
        System.out.println(" OBJECT NAME -> SIZE");
        System.out.println("1) defConstructer -> " + defConstructer.size());
        System.out.println("2) arrListConstructer -> " + arrListConstructer.size());
        System.out.println("3) doy1 -> " + doy1.size());
        System.out.println("4) obj1 -> " + obj1.size());
        System.out.println("5) obj2 -> " + obj2.size());
        System.out.println("6) obj3 -> " + obj3.size());
        System.out.println("7) obj4 -> " + obj4.size());
        System.out.println("As you can see, we have 16 DayOfYear objects in all our DayofYearSet objects");
        System.out.println("Lets see what will static method return");
        System.out.println("Total Number of DayOfYear objects alive: " + DayofYearSet.get_total_obj());
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING union method */
        System.out.println("TESTING UNION method FOR THE FIRST TIME: ");
        System.out.println("Lets create a DayofYearSet object named set1");

        DayofYearSet set1 = new DayofYearSet();

        DayofYearSet.DayofYear date13 = new DayofYearSet.DayofYear(3, 2);
        DayofYearSet.DayofYear date14 = new DayofYearSet.DayofYear(3, 6);
        DayofYearSet.DayofYear date15 = new DayofYearSet.DayofYear(4, 7);

        set1.add(date13);
        set1.add(date14);
        set1.add(date15);
        System.out.println("Lets print the content of set1");
        System.out.println(set1);

        System.out.println("Now, lets create another DayofYearSet object named set2");
        DayofYearSet set2 = new DayofYearSet();

        System.out.println("Lets add some dates to set2");
        DayofYearSet.DayofYear date16 = new DayofYearSet.DayofYear(2, 4);
        DayofYearSet.DayofYear date17 = new DayofYearSet.DayofYear(1, 1);

        set2.add(date16);
        set2.add(date17);
        System.out.println("Lets print the content of set2");
        System.out.println(set2);

        System.out.println("Finally, create an DayofYearSet object named set3");

        DayofYearSet set3;
        System.out.println("Then, lets take the union of set1 and set2");
        System.out.println("And assign the returned value to the set3");
        set3 = set1.union(set2);

        System.out.println("Lets print the content of set3");
        System.out.println(set3);
        System.out.println("As you can see, union is worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING union method */
        System.out.println("TESTING UNION method ONE MORE TIME: ");
        System.out.println("Lets create a DayofYearSet object named set4");

        DayofYearSet set4 = new DayofYearSet();

        DayofYearSet.DayofYear date18 = new DayofYearSet.DayofYear(7, 3);
        DayofYearSet.DayofYear date19 = new DayofYearSet.DayofYear(2, 8);

        set4.add(date18);
        set4.add(date19);

        System.out.println("Lets print the content of set4");
        System.out.println(set4);

        System.out.println("Now, lets create another DayofYearSet object named set5");
        DayofYearSet set5 = new DayofYearSet();

        System.out.println("Lets add some dates to set5");

        DayofYearSet.DayofYear date20 = new DayofYearSet.DayofYear(10, 9);
        DayofYearSet.DayofYear date21 = new DayofYearSet.DayofYear(7, 3);

        set5.add(date20);
        set5.add(date21);

        System.out.println("Lets print the content of set5");
        System.out.println(set5);

        System.out.println("Finally, create an DayofYearSet object named set6");

        DayofYearSet set6;
        System.out.println("Then, lets take the union of set4 and set5");
        System.out.println("And assign the returned value to the set6");
        set6 = set4.union(set5);

        System.out.println("Lets print the content of set6");
        System.out.println(set6);
        System.out.println("*Common elements only added once, thats why we have 3 elements in set6");
        System.out.println("As you can see, union is worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING difference method */
        System.out.println("TESTING DIFFERENCE method FOR THE FIRST TIME: ");
        System.out.println("Lets create a DayofYearSet object named set7");

        DayofYearSet set7 = new DayofYearSet();

        DayofYearSet.DayofYear date22 = new DayofYearSet.DayofYear(2, 4);
        DayofYearSet.DayofYear date23 = new DayofYearSet.DayofYear(3, 6);
        DayofYearSet.DayofYear date24 = new DayofYearSet.DayofYear(4, 7);

        set7.add(date22);
        set7.add(date23);
        set7.add(date24);
        System.out.println("Lets print the content of set7");
        System.out.println(set7);

        System.out.println("Now, lets create another DayofYearSet object named set8");
        DayofYearSet set8 = new DayofYearSet();

        System.out.println("Lets add some dates to set8");
        DayofYearSet.DayofYear date25 = new DayofYearSet.DayofYear(2, 4);
        DayofYearSet.DayofYear date26 = new DayofYearSet.DayofYear(1, 1);

        set8.add(date25);
        set8.add(date26);
        System.out.println("Lets print the content of set8");
        System.out.println(set8);

        System.out.println("Finally, create an DayofYearSet object named set9");
        DayofYearSet set9;

        System.out.println("Then, lets take the difference of set7 and set8");
        System.out.println("And assign the returned value to the set9");
        set9 = set7.difference(set8);

        System.out.println("Lets print the content of set9");
        System.out.println(set9);
        System.out.println("As you can see, difference method is worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING difference method */
        System.out.println("TESTING DIFFERENCE method ONE MORE TIME: ");
        System.out.println("Lets create a DayofYearSet object named set10");

        DayofYearSet set10 = new DayofYearSet();

        DayofYearSet.DayofYear date27 = new DayofYearSet.DayofYear(7, 8);
        DayofYearSet.DayofYear date28 = new DayofYearSet.DayofYear(10, 9);

        set10.add(date27);
        set10.add(date28);

        System.out.println("Lets print the content of set10");
        System.out.println(set10);

        System.out.println("Now, lets create another DayofYearSet object named set11");
        DayofYearSet set11 = new DayofYearSet();

        System.out.println("Lets add some dates to set11");

        DayofYearSet.DayofYear date29 = new DayofYearSet.DayofYear(10, 9);
        DayofYearSet.DayofYear date30 = new DayofYearSet.DayofYear(7, 3);

        set11.add(date29);
        set11.add(date30);

        System.out.println("Lets print the content of set11");
        System.out.println(set11);

        System.out.println("Finally, create an DayofYearSet object named set12");

        DayofYearSet set12;
        System.out.println("Then, lets take the difference of set10 and set11");
        System.out.println("And assign the returned value to the set12");
        set12 = set10.difference(set11);

        System.out.println("Lets print the content of set12");
        System.out.println(set12);
        System.out.println("As you can see, difference method is worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING intersection method */
        System.out.println("TESTING INTERSECTION method FOR THE FIRST TIME: ");
        System.out.println("Lets create a DayofYearSet object named set13");

        DayofYearSet set13 = new DayofYearSet();

        DayofYearSet.DayofYear date31 = new DayofYearSet.DayofYear(2, 4);
        DayofYearSet.DayofYear date32 = new DayofYearSet.DayofYear(3, 6);
        DayofYearSet.DayofYear date33 = new DayofYearSet.DayofYear(4, 7);

        set13.add(date31);
        set13.add(date32);
        set13.add(date33);
        System.out.println("Lets print the content of set13");
        System.out.println(set13);

        System.out.println("Now, lets create another DayofYearSet object named set14");
        DayofYearSet set14 = new DayofYearSet();

        System.out.println("Lets add some dates to set14");
        DayofYearSet.DayofYear date34 = new DayofYearSet.DayofYear(2, 4);
        DayofYearSet.DayofYear date35 = new DayofYearSet.DayofYear(4, 7);

        set14.add(date34);
        set14.add(date35);
        System.out.println("Lets print the content of set14");
        System.out.println(set14);

        System.out.println("Finally, create an DayofYearSet object named set15");
        DayofYearSet set15;

        System.out.println("Then, lets take the intersection of set13 and set14");
        System.out.println("And assign the returned value to the set15");
        set15 = set13.intersection(set14);

        System.out.println("Lets print the content of set15");
        System.out.println(set15);
        System.out.println("As you can see, intersection method is worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING INTERSECTION method */
        System.out.println("TESTING INTERSECTION method ONE MORE TIME: ");
        System.out.println("Lets create a DayofYearSet object named set16");

        DayofYearSet set16 = new DayofYearSet();

        DayofYearSet.DayofYear date36 = new DayofYearSet.DayofYear(9, 1);
        DayofYearSet.DayofYear date37 = new DayofYearSet.DayofYear(6, 6);

        set16.add(date36);
        set16.add(date37);

        System.out.println("Lets print the content of set16");
        System.out.println(set16);

        System.out.println("Now, lets create another DayofYearSet object named set17");
        DayofYearSet set17 = new DayofYearSet();

        System.out.println("Lets add some dates to set17");

        DayofYearSet.DayofYear date38 = new DayofYearSet.DayofYear(6, 6);
        DayofYearSet.DayofYear date39 = new DayofYearSet.DayofYear(11, 3);

        set17.add(date38);
        set17.add(date39);

        System.out.println("Lets print the content of set17");
        System.out.println(set17);

        System.out.println("Finally, create an DayofYearSet object named set18");

        DayofYearSet set18;
        System.out.println("Then, lets take the difference of set16 and set17");
        System.out.println("And assign the returned value to the set18");
        set18 = set16.intersection(set17);

        System.out.println("Lets print the content of set18");
        System.out.println(set18);
        System.out.println("As you can see, intersection method worked correctly!");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING COMPLEMENT method */
        System.out.println("TESTING COMPLEMENT method: ");
        System.out.println("Lets create a DayofYearSet object named set19");

        DayofYearSet set19 = new DayofYearSet();

        System.out.println("Lets add some dates to set19");
        DayofYearSet.DayofYear date40 = new DayofYearSet.DayofYear(9, 1);
        DayofYearSet.DayofYear date41 = new DayofYearSet.DayofYear(6, 6);

        set19.add(date40);
        set19.add(date41);
        System.out.println("Lets print the content of set19");
        System.out.println(set19);
        System.out.println("Now, we will use set rules to prove that our complement method is working");
        System.out.println("Rule: let there be a set named a and b");
        System.out.println("If we say: b = a ^ !a ");
        System.out.println("b must be empty. because there is no common element of the set a and set !a \n");
        System.out.println("Lets create another DayofYearSet object named set20");
        DayofYearSet set20 = new DayofYearSet();
        System.out.println("If we say set20 = set19.intersect( set19.complement() )");
        System.out.println("Which means set20 = set19 ^ !set19");
        System.out.println("So, size of the set20 must be zero");
        System.out.println("Now, lets assign the result to the set20 \n");
        set20 = set19.intersection(set19.complement());
        System.out.println("Size of the set20 is: " + set20.size());
        System.out.println("As you can see, complement method worked correctly");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING COMPLEMENT method */
        System.out.println("TESTING COMPLEMENT method ONE MORE TIME: ");
        System.out.println("Lets create a DayofYearSet object named set21");

        DayofYearSet set21 = new DayofYearSet();

        System.out.println("Lets add some dates to set21");
        DayofYearSet.DayofYear date42 = new DayofYearSet.DayofYear(3, 6);
        DayofYearSet.DayofYear date43 = new DayofYearSet.DayofYear(8, 2);
        DayofYearSet.DayofYear date44 = new DayofYearSet.DayofYear(1, 3);

        set21.add(date42);
        set21.add(date43);
        set21.add(date44);
        System.out.println("Lets print the content of set21");
        System.out.println(set21);
        System.out.println("Now, we will use set rules to prove that our complement method is working");
        System.out.println("Rule: let there be a set named a and b");
        System.out.println("If we say: b = a ^ !a ");
        System.out.println("b must be empty. because there is no common element of the set a and set !a \n");
        System.out.println("Lets create another DayofYearSet object named set22");
        DayofYearSet set22 = new DayofYearSet();
        System.out.println("If we say set22 = set21.intersect( set21.complement() )");
        System.out.println("Which means set22 = set21 ^ !set21");
        System.out.println("So, size of the set22 must be zero");
        System.out.println("Now, lets assign the result to the set22 \n");
        set22 = set21.intersection(set21.complement());
        System.out.println("Size of the set22 is: " + set22.size());
        System.out.println("As you can see, complement method worked correctly");
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DE MORGAN RULE, 1 */
        System.out.println("Lets de morgan rule with the DayofYearSet objects we have created so far");
        System.out.println("1. DeMorgan Test");
        System.out.println("Lets test de morgan with the objects: set1 and set2");
        System.out.println("De Morgan Rule says !(s1 + s2) == !s1 ^ !s2 ");
        System.out.println("Testing De Morgan with set1 and set2");
        if ((set1.union(set2)).complement().equals((set1.complement()).intersection(set2.complement()))) {
            System.out.println("DE MORGAN RULE APPLIES FOR : set1 and set2");
        } else {
            System.out.println("DE MORGAN RULE DOESNT APPLY");

        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DE MORGAN RULE, 2 */
        System.out.println("Lets de morgan rule with the DayofYearSet objects we have created so far");
        System.out.println("2. DeMorgan Test");
        System.out.println("Lets test de morgan with the objects: set3 and set4");
        System.out.println("De Morgan Rule says !(s1 + s2) == !s1 ^ !s2 ");
        System.out.println("Testing De Morgan with set3 and set4");
        if ((set3.union(set4)).complement().equals((set3.complement()).intersection(set4.complement()))) {
            System.out.println("DE MORGAN RULE APPLIES FOR : set3 and set4");
        } else {
            System.out.println("DE MORGAN RULE DOESNT APPLY");

        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DE MORGAN RULE, 3 */
        System.out.println("Lets de morgan rule with the DayofYearSet objects we have created so far");
        System.out.println("3. DeMorgan Test");
        System.out.println("Lets test de morgan with the objects: set5 and set6");
        System.out.println("De Morgan Rule says !(s1 + s2) == !s1 ^ !s2 ");
        System.out.println("Testing De Morgan with set5 and set6");
        if ((set5.union(set6)).complement().equals((set5.complement()).intersection(set6.complement()))) {
            System.out.println("DE MORGAN RULE APPLIES FOR : set5 and set6");
        } else {
            System.out.println("DE MORGAN RULE DOESNT APPLY");

        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DE MORGAN RULE, 4 */
        System.out.println("Lets de morgan rule with the DayofYearSet objects we have created so far");
        System.out.println("4. DeMorgan Test");
        System.out.println("Lets test de morgan with the objects: set7 and set8");
        System.out.println("De Morgan Rule says !(s1 + s2) == !s1 ^ !s2 ");
        System.out.println("Testing De Morgan with set7 and set8");
        if ((set7.union(set8)).complement().equals((set7.complement()).intersection(set8.complement()))) {
            System.out.println("DE MORGAN RULE APPLIES FOR : set7 and set8");
        } else {
            System.out.println("DE MORGAN RULE DOESNT APPLY");

        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* TESTING DE MORGAN RULE, 5 */
        System.out.println("Lets de morgan rule with the DayofYearSet objects we have created so far");
        System.out.println("5. DeMorgan Test");
        System.out.println("Lets test de morgan with the objects: set9 and set10");
        System.out.println("De Morgan Rule says !(s1 + s2) == !s1 ^ !s2 ");
        System.out.println("Testing De Morgan with set9 and set10");
        if ((set9.union(set10)).complement().equals((set9.complement()).intersection(set10.complement()))) {
            System.out.println("DE MORGAN RULE APPLIES FOR : set9 and set10");
        } else {
            System.out.println("DE MORGAN RULE DOESNT APPLY");

        }
        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

        /* PRINTING SOME SETS */
        System.out.println("In pdf it says: Writes some sets to text files");
        System.out.println("So, i will write set1 ,set2 and set3 to the txt file named sets.txt");

        PrintWriter printwriter;
        try {
            printwriter = new PrintWriter("sets.txt");

            printwriter.println("SET1:");
            printwriter.println(set1);

            printwriter.println("SET2: ");
            printwriter.println(set2);

            printwriter.println("SET3: ");
            printwriter.println(set3);

            printwriter.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
        }

        System.out.println("\n*  *  *  *  *  *  *  *  *  *  *  * *\n");

    }

}
