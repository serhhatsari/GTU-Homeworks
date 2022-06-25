package arraylisttown;

import java.util.Scanner;

import townbuildings.Building;
import townbuildings.House;
import townbuildings.Market;
import townbuildings.Office;
import townbuildings.Playground;

public class TestALStreet {

    public static void testALTown() throws Exception {

        testConstructers();
        testEditMode();
        testViewMode();
        testOverriddenMethods();
        testExceptions();
    }

    public static void testConstructers() throws Exception {

        System.out.println("----------TESTING--------");
        System.out.println("\n  1:TESTING CONSTRUCTERS\n");

        System.out.println("1.1: Testing Default Constructers\n");
        System.out.println("Testing the Default constructer of the Building Class");
        Building defaultBuilding = new Building();
        System.out.println("Default constructer of the building class has worked correctly.\n");

        System.out.println("Testing the Default constructer of the House Class");
        House defaultHouse = new House();
        System.out.println("Default constructer of the house class has worked correctly.\n");

        System.out.println("Testing the Default constructer of the Office Class");
        Office defaultOffice = new Office();
        System.out.println("Default constructer of the office class has worked correctly.\n");

        System.out.println("Testing the Default constructer of the Market Class");
        Market defaultMarket = new Market();
        System.out.println("Default constructer of the market class has worked correctly.\n");

        System.out.println("Testing the Default constructer of the Playground Class");
        Playground defaultPlayground = new Playground();
        System.out.println("Default constructer of the playground class has worked correctly.\n");

        System.out.println("Testing the Default constructer of the ALStreet Class");
        ALStreet defaultALStreet = new ALStreet();
        System.out.println("Default constructer of the ALStreet class has worked correctly.\n");

        System.out.println("\n1.2: Testing Parameterized Constructers\n");
        System.out.println("Testing the Parameterized constructer of the Building Class");
        Building paramBuilding = new Building(1, 10, 15, "Left", 100);
        System.out.println("Parameterized constructer of the building class has worked correctly.\n");

        System.out.println("Testing the Parameterized constructer of the House Class");
        House paramHouse = new House(1, 10, 15, "Right", 3, "Yellow", "Serhat", 100);
        System.out.println("Parameterized constructer of the house class has worked correctly.\n");

        System.out.println("Testing the Parameterized constructer of the Office Class");
        Office paramOffice = new Office(1, 10, 15, "Right", "Software", "Burak", 100);
        System.out.println("Parameterized constructer of the office class has worked correctly.\n");

        System.out.println("Testing the Parameterized constructer of the Market Class");
        Market paramMarket = new Market(1, 10, 15, "Right", "09:30", "21:30", "Hasan", 100);
        System.out.println("Parameterized constructer of the market class has worked correctly.\n");

        System.out.println("Testing the Parameterized constructer of the Playground Class");
        Playground paramPlayground = new Playground(1, 10, 15, "Left", 100);
        System.out.println("Parameterized constructer of the playground class has worked correctly.\n");

        System.out.println("Testing the Parameterized constructer of the ALStreet Class");
        ALStreet paramALStreet = new ALStreet(100);
        System.out.println("Parameterized constructer of the ALStreet class has worked correctly.\n");

    }

    public static void testEditMode() throws Exception {

        System.out.println("\n\n  2:TESTING EDIT MODE\n\n");
        System.out.println("2.1 TESTING ADD MODE");

        System.out.println("Lets create an ALStreet, then add all kind of buildings on it");
        ALStreet testALStreet = new ALStreet(50);

        System.out.println("\n2.1.1: Lets add a house to the ALStreet");
        testALStreet.addBuilding(new House(1, 10, 15, "Right", 3, "Yellow", "Yusuf", 50));
        System.out.println("\nWe added a house to the ALStreet.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the ALStreet");
        testALStreet.printBuildingsDetails();
        testALStreet.printALStreet();
        System.out.println("\n\n*As it can be seen, house has been added to ALStreet.");

        System.out.println("\n2.1.2: Lets add a market to the ALStreet");
        testALStreet.addBuilding(new Market(5, 12, 10, "Left", "09:30", "21:30", "Ahmet", 50));
        System.out.println("\nWe added a market to the ALStreet.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the ALStreet");
        testALStreet.printBuildingsDetails();
        testALStreet.printALStreet();
        System.out.println("\n\n*As it can be seen, market has been added to ALStreet.");

        System.out.println("\n2.1.3: Lets add a office to the ALStreet");
        testALStreet.addBuilding(new Office(12, 12, 7, "Right", "Software", "Akif", 50));
        System.out.println("\nWe added a office to the ALStreet.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the ALStreet");
        testALStreet.printBuildingsDetails();
        testALStreet.printALStreet();
        System.out.println("\n\n*As it can be seen, office has been added to ALStreet.");

        System.out.println("\n2.1.4: Lets add a playground to the ALStreet");
        testALStreet.addBuilding(new Playground(20, 10, 5, "Left", 50));
        System.out.println("\nWe added a playground to the ALStreet.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the ALStreet");
        testALStreet.printBuildingsDetails();
        testALStreet.printALStreet();
        System.out.println("\n\n*As it can be seen, playground has been added to ALStreet.");

        System.out.println("\n\n2.2 TESTING DELETE MODE");

        System.out.println("\nLets delete some of the buildings on the ALStreet");

        System.out.println("First, lets see the list of buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets delete the first building in the list\n");
        System.out.println("\nBEFORE deleting the first building:");
        testALStreet.printALStreet();
        System.out.println("\n\nAFTER deleting the first building:");
        testALStreet.deleteBuilding(1);
        testALStreet.printALStreet();
        System.out.println("\n\nAs you can see, we deleted the first building correctly.");

        System.out.println("\n\nLets delete one more building");
        System.out.println("First, lets see the list of buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets delete the second building in the list\n");
        System.out.println("\nBEFORE deleting the second building:");
        testALStreet.printALStreet();
        System.out.println("\n\nAFTER deleting the second building:");
        testALStreet.deleteBuilding(2);
        testALStreet.printALStreet();
        System.out.println("\n\nAs you can see, we deleted the second building correctly.");

    }

    public static void testViewMode() throws Exception {
        System.out.println("\n\n  3:TESTING VIEW MODE and FOCUS\n");
        System.out.println("Lets create a new ALStreet with length 50 and add some buildings on it");

        ALStreet testALStreet = new ALStreet(50);

        testALStreet.addBuilding(new House(10, 6, 15, "Right", 3, "Yellow", "Yusuf", 50));
        testALStreet.addBuilding(new Market(2, 12, 10, "Left", "09:30", "21:30", "Ahmet", 50));
        testALStreet.addBuilding(new Office(18, 12, 5, "Right", "Software", "Akif", 50));
        testALStreet.addBuilding(new Playground(20, 10, 18, "Left", 50));

        System.out.println("\nWe add 4 buildings to the ALStreet, lets test the methods\n");

        System.out.println("\n3.1: Testing displaying the list of buildings on the ALStreet.");
        testALStreet.printBuildingsDetails();
        System.out.println("\nAs you can see, the details of the buildings are displayed.\n");

        System.out
                .println("\n\n3.2: Testing displaying the number and ratio of lenth of playgrounds in the ALStreet.");
        testALStreet.printPlaygroundInfo();
        System.out.println(
                "\nAs you can see, the the number and ratio of lenth of playgrounds in the ALStreet are displayed.\n");

        System.out
                .println("\n\n3.3: Testing the total length of ALStreet occupied by the markets, houses or offices.");
        testALStreet.printTotalLengths();
        System.out.println(
                "\nAs you can see, the total length of ALStreet occupied by the markets, houses or offices are displayed.\n");

        System.out.println("\n3.4: Testing displaying the total remaining length of lands on the ALStreet.");
        testALStreet.printRemainingLength();
        System.out.println("\nALStreet's length was 50, considering both sides, it means 100br.");
        System.out.println(
                "We used the 40br of the ALStreet (12 br for house, 12 br for market, 10 br for playground, 6 br for house)");
        System.out.println("As you can see, remaining length is 60br.");

        System.out.println("\n\n3.5: Testing the skyline silhouette of the ALStreet.");
        testALStreet.printALStreet();
        System.out.println(
                "\nAs you can see, the skyline silhouette of the ALStreet İS displayed.\n");

        System.out.println("\n\nTESTING THE FOCUS MODE");
        System.out.println("\nLets test the focus mode with house");
        System.out.println("First, lets see the list of the buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets focus on the first building");
        testALStreet.focusBuilding(1);
        System.out.println("As you can see, we focused on the first building.");

        System.out.println("\nLets test the focus mode with market");
        System.out.println("First, lets see the list of the buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets focus on the second building");
        testALStreet.focusBuilding(2);
        System.out.println("As you can see, we focused on the second building.");

        System.out.println("\nLets test the focus mode with office");
        System.out.println("First, lets see the list of the buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets focus on the third building");
        testALStreet.focusBuilding(3);
        System.out.println("As you can see, we focused on the third building.");

        System.out.println("\nLets test the focus mode with market");
        System.out.println("First, lets see the list of the buildings");
        testALStreet.printBuildingPositions();
        System.out.println("\nLets focus on the fourth building");
        testALStreet.focusBuilding(4);
        System.out.println("As you can see, we focus on the fourth building.");

    }

    public static void testOverriddenMethods() throws Exception {

        System.out.println("\n\n  4:TESTING OVERRIDEN METHODS\n");

        System.out.println("\n4.1: TESTING .toString() METHOD");
        System.out.println("4.1.1: Lets create a house object and test toString method with it");
        House testHouse = new House(1, 5, 5, "Left", 3, "Yellow", "Ersel", 50);
        System.out.println(testHouse);
        System.out.println("\n As you can see, toString method of House class worked correctly.");

        System.out.println("4.1.2: Lets create a office object and test toString method with it");
        Office testOffice = new Office(1, 12, 7, "Right", "Software", "Akif", 50);
        System.out.println(testOffice);
        System.out.println("\n As you can see, toString method of office class worked correctly.");

        System.out.println("\n4.2: TESTING .equals() METHOD");
        House house1 = new House(1, 5, 5, "Left", 3, "Yellow", "Ersel", 50);
        House house2 = new House(1, 5, 5, "Left", 3, "Yellow", "Ersel", 50);
        System.out.println("4.2.1: Lets create a 2 house with the same values.");
        System.out.println("Lets print the details of these 2 houses with toString");
        System.out.println("House 1:\n" + house1);
        System.out.println("House 2:\n" + house2);
        System.out.println("Lets check equality of these 2 houses with .equals method");
        if (house1.equals(house2)) {
            System.out.println("HOUSES ARE EQUAL.");
        } else {
            System.out.println("HOUSES ARE NOT EQUAL.");
        }
        System.out.println("\nAs you can see, houses are equal.");
        System.out.println("That means .equals method works correctly.");

        House house3 = new House(3, 5, 12, "Right", 5, "Red", "Bilge", 50);
        House house4 = new House(1, 5, 5, "Left", 3, "Yellow", "Ersel", 50);
        System.out.println("4.2.1: Lets create a 2 house with different values.");
        System.out.println("Lets print the details of these 2 houses with toString");
        System.out.println("House 1:\n" + house3);
        System.out.println("House 2:\n" + house4);
        System.out.println("Lets check equality of these 2 houses with .equals method");
        if (house3.equals(house4)) {
            System.out.println("HOUSES ARE EQUAL.");
        } else {
            System.out.println("HOUSES ARE NOT EQUAL.");
        }
        System.out.println("\nAs you can see, houses are NOT equal, because values of the houses are different.");
        System.out.println("That means .equals method works correctly.");

        System.out.println("\n4.3: TESTING .hashCode() METHOD");
        System.out.println("\nLets create 2 house objects and print their hashCodes");
        House house5 = new House(1, 3, 2, "Right", 3, "Yellow", "Bilge", 50);
        House house6 = new House(1, 5, 5, "Left", 3, "Yellow", "Rümeysa", 50);
        System.out.println("Hashcode of the first house: " + house5.hashCode());
        System.out.println("Hashcode of the second house: " + house6.hashCode());

        System.out.println("\n4.4: TESTING .clone() METHOD");
        System.out.println("\nLets test clone method with house object");
        House house7 = new House(1, 3, 2, "Right", 3, "Yellow", "Bilge", 50);
        House house8 = (House) house7.clone();
        System.out.println("\nClone method worked correctly.");

    }

    public static void testExceptions() throws Exception {
        System.out.println("\n\n  5:TESTING EXCEPTIONS\n");

        System.out.println("\nLets test what happens if we try give negative value for the length of the ALStreet");
        try {
            ALStreet testALStreet = new ALStreet(-5);
        } catch (Exception e) {
            System.out.println("As you can see, exception has been thrown");

        }

        System.out.println("\nLets test what happens if we try to give negative value to position");
        Market testMarket = new Market();
        try {
            testMarket.setPosition(-5, 50);
        } catch (Exception e) {
            System.out.println("As you can see, exception has been thrown");

        }

        System.out.println("\nLets test what happens if we try to give negative value to length");
        Market testMarket1 = new Market();
        try {
            testMarket1.setLength(-5, 50);
        } catch (Exception e) {
            System.out.println("As you can see, exception has been thrown");

        }

        System.out.println("\nLets test what happens if we try to give negative value to height");
        Market testMarket2 = new Market();
        try {
            testMarket1.setHeight(-5);
        } catch (Exception e) {
            System.out.println("As you can see, exception has been thrown");

        }

    }

}
