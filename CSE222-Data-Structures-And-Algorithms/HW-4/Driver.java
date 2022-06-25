/**
 * An example java program to get the index of nth occurrence of a substring in
 * a String using Java
 */
public class Driver {

    public static void main(String[] args) {

        testFirstQuestion();
        testSecondQuestion();
        testThirdQuestion();
        testFifthQuestion();
    }

    public static void testFirstQuestion() {
        int index;

        System.out.println("FIRST QUESTION TEST CASES\n");
        System.out.println("FQ TEST CASE 1");
        System.out.println("Bigger String: kabateba");
        System.out.println("Smaller String: ba");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("kabateba", "ba", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 2");
        System.out.println("Bigger String: serhatsari");
        System.out.println("Smaller String: hat");
        System.out.println("Occurence Number: 1");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("serhatsari", "hat", 1);
        System.out.println("Result:");
        System.out.println("1.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 3");
        System.out.println("Bigger String: sedebedese");
        System.out.println("Smaller String: kal");
        System.out.println("Occurence Number: 1");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("sedebedese", "kal", 1);
        System.out.println("Result:");
        System.out.println("1.th occurence is at the " + index + ".index");
        System.out.println("kal doesnt exist in the bigger str so it will return -1");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 4");
        System.out.println("Bigger String: adadad");
        System.out.println("Smaller String: ada");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("adadadada", "ada", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 5");
        System.out.println("Bigger String: favasistancanasistan");
        System.out.println("Smaller String: asistan");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("favasistancanasistan", "as", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 6");
        System.out.println("Bigger String: se");
        System.out.println("Smaller String: se");
        System.out.println("Occurence Number: 1");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("se", "se", 1);
        System.out.println("Result:");
        System.out.println("1.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 7");
        System.out.println("Bigger String: sedakedakhedak");
        System.out.println("Smaller String: dak");
        System.out.println("Occurence Number: 4");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("sedakedakhedak", "dak", 4);
        System.out.println("Result:");
        System.out.println("4.th occurence is at the " + index + ".index");
        System.out.println("dak exist in the bigger string 3 times");
        System.out.println("But user ask for the 4.th occurence which does not exist");
        System.out.println("So it will return -1");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 8");
        System.out.println("Bigger String: tanpa");
        System.out.println("Smaller String: pa");
        System.out.println("Occurence Number: 1");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("tanpa", "pa", 1);
        System.out.println("Result:");
        System.out.println("1.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 9");
        System.out.println("Bigger String: adaladpalnalkalral");
        System.out.println("Smaller String: al");
        System.out.println("Occurence Number: 5");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("adaladpalnalkalral", "al", 5);
        System.out.println("Result:");
        System.out.println("5.th occurence is at the " + index + ".index");
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 10");
        System.out.println("Bigger String: ");
        System.out.println("Smaller String: someinp");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("", "someinp", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because bigger string is empty");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 11");
        System.out.println("Bigger String: somestr");
        System.out.println("Smaller String: ");
        index = FirstQuestion.searchOccurences("somestr", "", 2);
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because smaller string is empty");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 12");
        System.out.println("Bigger String: ");
        System.out.println("Smaller String: ");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("", "", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because both strings are empty!");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 13");
        System.out.println("Bigger String: null");
        System.out.println("Smaller String: somestr");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences(null, "somestr", 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because bigger string is null!");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 14");
        System.out.println("Bigger String: somestr");
        System.out.println("Smaller String: null");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences("somestr", null, 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because smaller string is null!");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 15");
        System.out.println("Bigger String: null");
        System.out.println("Smaller String: null");
        System.out.println("Occurence Number: 2");
        System.out.println("Lets test this case! ");
        index = FirstQuestion.searchOccurences(null, null, 2);
        System.out.println("Result:");
        System.out.println("2.th occurence is at the " + index + ".index");
        System.out.println("It returns -1 because both strings are null!");
        System.out.println("So it is correct!");
        System.out.println("********************************\n\n");

    }

    public static void testSecondQuestion() {
        int numOfItems = 0;
        int[] sortedArray = { 1, 3, 4, 6, 8, 12, 14, 16, 17, 19, 22, 23, 27, 30, 35, 42 };

        System.out.println("\n\nSECOND QUESTION TEST CASES\n");

        System.out.println("SQ TEST CASE 1");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 3");
        System.out.println("Upper Bound: 10");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 3, 10);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 2");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 1");
        System.out.println("Upper Bound: 12");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 1, 12);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 3");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 3");
        System.out.println("Upper Bound: 3");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 3, 3);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 4");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: -10");
        System.out.println("Upper Bound: -2");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, -10, -2);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 5");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: -5");
        System.out.println("Upper Bound: 5");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, -5, 5);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 6");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 32");
        System.out.println("Upper Bound: 34");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 32, 34);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 7");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 32");
        System.out.println("Upper Bound: 35");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 32, 35);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 8");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 14");
        System.out.println("Upper Bound: 23");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 14, 23);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 9");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: 1");
        System.out.println("Upper Bound: 42");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, 1, 42);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 10");
        System.out.println("Sorted Array");
        for (int i : sortedArray)
            System.out.print(i + " ");
        System.out.println("\nLower Bound: -12");
        System.out.println("Upper Bound: 50");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(sortedArray, -12, 50);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("As you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("SQ TEST CASE 11");
        System.out.println("Sorted Array");
        System.out.println("null array");
        System.out.println("Lower Bound: 3");
        System.out.println("Upper Bound: 5");
        System.out.println("Lets test this case! ");
        numOfItems = SecondQuestion.findInterval(null, 3, 5);
        System.out.println("Result:");
        System.out.println("Number of items between boundaries:  " + numOfItems);
        System.out.println("Result is 0 because our array is null.");
        System.out.println("********************************\n\n");

    }

    public static void testThirdQuestion() {
        System.out.println("\n\nTHIRD QUESTION TEST CASES\n");
        int[] unsortedArray = { 2, 2, 4, 3, 3, 2, 5, 4, 3, 6, 1, 3, 5, 3, 4, 4, 1, 7, 9, 12, 21, 18, 3, 3, 5, 6, 7 };
        int[] emptyArray = {};
        int[] nullArray = null;

        System.out.println("TQ TEST CASE 1");
        System.out.println("Unsorted Array");
        for (int i : unsortedArray)
            System.out.print(i + " ");
        System.out.println("\nTarget: 8");
        System.out.println("Lets test this case! ");
        System.out.println("Subarray/s that the sum of its/theirs items is equal to the target: \n");
        ThirdQuestion.findSubs(unsortedArray, 8);
        System.out.println("\nAs you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("TQ TEST CASE 2");
        System.out.println("Unsorted Array");
        for (int i : unsortedArray)
            System.out.print(i + " ");
        System.out.println("\nTarget: 9");
        System.out.println("Lets test this case! ");
        System.out.println("Subarray/s that the sum of its/theirs items is equal to the target: \n");
        ThirdQuestion.findSubs(unsortedArray, 9);
        System.out.println("\nAs you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("TQ TEST CASE 3");
        System.out.println("Unsorted Array");
        for (int i : unsortedArray)
            System.out.print(i + " ");
        System.out.println("\nTarget: 14");
        System.out.println("Lets test this case! ");
        System.out.println("Subarray/s that the sum of its/theirs items is equal to the target: \n");
        ThirdQuestion.findSubs(unsortedArray, 21);
        System.out.println("\nAs you can see, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("TQ TEST CASE 4");
        System.out.println("Unsorted Array");
        for (int i : emptyArray)
            System.out.print(i + " ");
        System.out.println("\nTarget: 3");
        System.out.println("Lets test this case! ");
        System.out.println("Subarray/s that the sum of its/theirs items is equal to the target: \n");
        ThirdQuestion.findSubs(emptyArray, 21);
        System.out.println("Array is empty, thats why there is no subarrays!");
        System.out.println("\nSo, it is correct!");
        System.out.println("********************************\n\n");

        System.out.println("TQ TEST CASE 5");
        System.out.println("Unsorted Array");
        System.out.print("Array is null");
        System.out.println("\nTarget: 4");
        System.out.println("Lets test this case! ");
        System.out.println("Subarray/s that the sum of its/theirs items is equal to the target: \n");
        ThirdQuestion.findSubs(nullArray, 21);
        System.out.println("Array is null, thats why there is no subarrays!");
        System.out.println("\nSo, it is correct!");
        System.out.println("********************************\n\n");

    }

    public static void testFifthQuestion() {
        System.out.println("\n\nFIFTH QUESTION TEST CASES\n");

        System.out.println("FQ TEST CASE 1");
        System.out.println("Lets create 1-D array of empty blocks of length 6. ");
        int[] array1 = { 1, 2, 3, 5, 6 };
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array1);
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 2");
        System.out.println("Lets create 1-D array of empty blocks of length 7. ");
        int[] array2 = { 1, 2, 3, 5, 6, 7 };
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array2);
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 3");
        System.out.println("Lets create 1-D array of empty blocks of length 8. ");
        int[] array3 = { 1, 2, 3, 5, 6, 7, 8 };
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array3);
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 4");
        System.out.println("Lets create 1-D array of empty blocks of length 2. ");
        int[] array4 = { 1, 2 };
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array4);
        System.out.println("Length is 2, thats why there is no configurations");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 5");
        System.out.println("Lets create an empty array. ");
        int[] array5 = {};
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array5);
        System.out.println("Array is empty, thats why there is no configurations");
        System.out.println("********************************\n\n");

        System.out.println("FQ TEST CASE 6");
        System.out.println("Lets create an null array. ");
        int[] array6 = null;
        System.out.println("Lets print the all possible configurations: ");
        FifthQuestion.findPossibleConfigs(array6);
        System.out.println("Array is null, thats why there is no configurations");
        System.out.println("********************************\n\n");

    }

}
