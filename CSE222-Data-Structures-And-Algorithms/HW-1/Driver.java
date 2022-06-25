import java.util.Scanner;

import townpackage.Building;
import townpackage.House;
import townpackage.Market;
import townpackage.Office;
import townpackage.Playground;
import townpackage.Street;

public class Driver {

    

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

        System.out.println("Testing the Default constructer of the Street Class");
        Street defaultStreet = new Street();
        System.out.println("Default constructer of the street class has worked correctly.\n");

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

        System.out.println("Testing the Parameterized constructer of the Street Class");
        Street paramStreet = new Street(100);
        System.out.println("Parameterized constructer of the street class has worked correctly.\n");

    }

    public static void testEditMode() throws Exception {

        System.out.println("\n\n  2:TESTING EDIT MODE\n\n");
        System.out.println("2.1 TESTING ADD MODE");

        System.out.println("Lets create an street, then add all kind of buildings on it");
        Street testStreet = new Street(50);

        System.out.println("\n2.1.1: Lets add a house to the street");
        testStreet.addBuilding(new House(1, 10, 15, "Right", 3, "Yellow", "Yusuf", 50));
        System.out.println("\nWe added a house to the street.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the street");
        testStreet.printBuildingsDetails();
        testStreet.printStreet();
        System.out.println("\n\n*As it can be seen, house has been added to street.");

        System.out.println("\n2.1.2: Lets add a market to the street");
        testStreet.addBuilding(new Market(5, 12, 10, "Left", "09:30", "21:30", "Ahmet", 50));
        System.out.println("\nWe added a market to the street.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the street");
        testStreet.printBuildingsDetails();
        testStreet.printStreet();
        System.out.println("\n\n*As it can be seen, market has been added to street.");

        System.out.println("\n2.1.3: Lets add a office to the street");
        testStreet.addBuilding(new Office(12, 12, 7, "Right", "Software", "Akif", 50));
        System.out.println("\nWe added a office to the street.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the street");
        testStreet.printBuildingsDetails();
        testStreet.printStreet();
        System.out.println("\n\n*As it can be seen, office has been added to street.");

        System.out.println("\n2.1.4: Lets add a playground to the street");
        testStreet.addBuilding(new Playground(20, 10, 5, "Left", 50));
        System.out.println("\nWe added a playground to the street.");
        System.out.println("Lets display the list of the buildings and skyline silhouette of the street");
        testStreet.printBuildingsDetails();
        testStreet.printStreet();
        System.out.println("\n\n*As it can be seen, playground has been added to street.");

        System.out.println("\n\n2.2 TESTING DELETE MODE");

        System.out.println("\nLets delete some of the buildings on the street");

        System.out.println("First, lets see the list of buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets delete the first building in the list\n");
        System.out.println("\nBEFORE deleting the first building:");
        testStreet.printStreet();
        System.out.println("\n\nAFTER deleting the first building:");
        testStreet.deleteBuilding(1);
        testStreet.printStreet();
        System.out.println("\n\nAs you can see, we deleted the first building correctly.");

        System.out.println("\n\nLets delete one more building");
        System.out.println("First, lets see the list of buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets delete the second building in the list\n");
        System.out.println("\nBEFORE deleting the second building:");
        testStreet.printStreet();
        System.out.println("\n\nAFTER deleting the second building:");
        testStreet.deleteBuilding(2);
        testStreet.printStreet();
        System.out.println("\n\nAs you can see, we deleted the second building correctly.");

    }

    public static void testViewMode() throws Exception {
        System.out.println("\n\n  3:TESTING VIEW MODE and FOCUS\n");
        System.out.println("Lets create a new street with length 50 and add some buildings on it");

        Street testStreet = new Street(50);

        testStreet.addBuilding(new House(10, 6, 15, "Right", 3, "Yellow", "Yusuf", 50));
        testStreet.addBuilding(new Market(2, 12, 10, "Left", "09:30", "21:30", "Ahmet", 50));
        testStreet.addBuilding(new Office(18, 12, 5, "Right", "Software", "Akif", 50));
        testStreet.addBuilding(new Playground(20, 10, 18, "Left", 50));

        System.out.println("\nWe add 4 buildings to the street, lets test the methods\n");

        System.out.println("\n3.1: Testing displaying the list of buildings on the street.");
        testStreet.printBuildingsDetails();
        System.out.println("\nAs you can see, the details of the buildings are displayed.\n");

        System.out.println("\n\n3.2: Testing displaying the number and ratio of lenth of playgrounds in the street.");
        testStreet.printPlaygroundInfo();
        System.out.println(
                "\nAs you can see, the the number and ratio of lenth of playgrounds in the street are displayed.\n");

        System.out.println("\n\n3.3: Testing the total length of street occupied by the markets, houses or offices.");
        testStreet.printTotalLengths();
        System.out.println(
                "\nAs you can see, the total length of street occupied by the markets, houses or offices are displayed.\n");

        System.out.println("\n3.4: Testing displaying the total remaining length of lands on the street.");
        testStreet.printRemainingLength();
        System.out.println("\nStreet's length was 50, considering both sides, it means 100br.");
        System.out.println(
                "We used the 40br of the street (12 br for house, 12 br for market, 10 br for playground, 6 br for house)");
        System.out.println("As you can see, remaining length is 60br.");

        System.out.println("\n\n3.5: Testing the skyline silhouette of the street.");
        testStreet.printStreet();
        System.out.println(
                "\nAs you can see, the skyline silhouette of the street İS displayed.\n");

        System.out.println("\n\nTESTING THE FOCUS MODE");
        System.out.println("\nLets test the focus mode with house");
        System.out.println("First, lets see the list of the buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets focus on the first building");
        testStreet.focusBuilding(1);
        System.out.println("As you can see, we focused on the first building.");

        System.out.println("\nLets test the focus mode with market");
        System.out.println("First, lets see the list of the buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets focus on the second building");
        testStreet.focusBuilding(2);
        System.out.println("As you can see, we focused on the second building.");

        System.out.println("\nLets test the focus mode with office");
        System.out.println("First, lets see the list of the buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets focus on the third building");
        testStreet.focusBuilding(3);
        System.out.println("As you can see, we focused on the third building.");

        System.out.println("\nLets test the focus mode with market");
        System.out.println("First, lets see the list of the buildings");
        testStreet.printBuildingPositions();
        System.out.println("\nLets focus on the fourth building");
        testStreet.focusBuilding(4);
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
        if (house1.equals(house2)) {
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

        System.out.println("\nLets test what happens if we try give negative value for the length of the street");
        try {
            Street testStreet = new Street(-5);
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

    public static void interactiveMenu() {
        int streetLengthInput = 0, mainMenuInput = 0;
        int editMenuInput = 0, buildingTypeInput = 0;
        int deleteBuildingIndex = 0, viewMenuInput = 0, focusBuildingIndex = 0;
        Boolean check = true;
        Scanner scanObj = new Scanner(System.in);
        Street mainStreet = new Street();
        
        System.out.println("\n\nCITY PLANNING SOFTWARE");

        check = true;
        while (check) {

            try {
                System.out.print("Enter the length of the street you want to create: ");
                streetLengthInput = scanObj.nextInt();
                mainStreet = new Street(streetLengthInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\nYOUR INPUT IS NOT VALID. ENTER AN POSITIVE INTEGER PLEASE!\n");

            }

        }

        while (true) {

            check = true;
            while (check) {

                try {
                    mainMenu();
                    mainMenuInput = scanObj.nextInt();

                    if (mainMenuInput < 1 || mainMenuInput > 4) {
                        throw new Exception();
                    }

                    check = false;

                } catch (Exception e) {
                    scanObj.nextLine();
                    System.out.println("\nYOUR INPUT IS WRONG. ENTER AN INTEGER BETWEEN 1-4 PLEASE!");
                }

            }

            if (mainMenuInput == 1) {

                check = true;
                while (check) {

                    try {

                        editMenu();
                        editMenuInput = scanObj.nextInt();

                        if (editMenuInput < 1 || editMenuInput > 3) {
                            throw new Exception();
                        }

                        check = false;

                    } catch (Exception e) {
                        scanObj.nextLine();
                        System.out.println("\nYOUR INPUT IS WRONG. ENTER AN INTEGER 1 or 2 PLEASE!");
                    }

                }

                if (editMenuInput == 1) {

                    check = true;
                    while (check) {

                        try {

                            buildingTypesMenu();
                            buildingTypeInput = scanObj.nextInt();

                            if (buildingTypeInput < 1 || buildingTypeInput > 5) {
                                throw new Exception();
                            }

                            check = false;

                        } catch (Exception e) {
                            scanObj.nextLine();
                            System.out.println("\nYOUR INPUT IS WRONG. ENTER AN INTEGER BETWEEN 1-5 PLEASE!");
                        }

                    }

                    switch (buildingTypeInput) {
                        case 1:
                            addHouseToStreet(mainStreet);
                            break;
                        case 2:
                            addOfficeToStreet(mainStreet);
                            break;
                        case 3:
                            addMarketToStreet(mainStreet);
                            break;
                        case 4:
                            addPlaygroundToStreet(mainStreet);
                            break;
                        case 5:
                            System.out.println("\nADDING BUILDING HAS CANCELLED.");
                            break;
                    }

                }

                else if (editMenuInput == 2) {

                    if (mainStreet.getNumOfBuildings() == 0) {
                        System.out.print("\n! THERE IS NO BUILDING TO BE DELETED !\n");

                    } else {

                        check = true;
                        while (check) {

                            try {

                                mainStreet.printBuildingPositions();
                                System.out.print("\nEnter the number of the building to delete: ");
                                deleteBuildingIndex = scanObj.nextInt();

                                if (deleteBuildingIndex < 1 || deleteBuildingIndex > mainStreet.getNumOfBuildings()) {
                                    throw new Exception();
                                }

                                check = false;

                            } catch (Exception e) {
                                scanObj.nextLine();
                                System.out.println("\nYOUR INPUT IS WRONG. ENTER THE NUMBER OF THE BUILDING!");
                                System.out.println("For example, 1: Type = House, Street Side = Left, Position = 20");
                                System.out.println("If you want to delete this building, enter 1");

                            }

                        }

                        mainStreet.deleteBuilding(deleteBuildingIndex);

                    }
                } else if (editMenuInput == 3) {
                    System.out.println("\n\nExited from edit menu.");
                }
            }

            else if (mainMenuInput == 2) {

                check = true;
                while (check) {

                    try {
                        viewMenu();
                        viewMenuInput = scanObj.nextInt();
                        if (viewMenuInput < 1 || viewMenuInput > 6) {
                            throw new Exception();
                        }

                        check = false;

                    } catch (Exception e) {
                        scanObj.nextLine();
                        System.out.println("\nYOUR INPUT IS WRONG. ENTER AN INTEGER BETWEEN 1-6 PLEASE!");
                    }

                }

                switch (viewMenuInput) {
                    case 1:
                        mainStreet.printRemainingLength();
                        break;
                    case 2:
                        mainStreet.printBuildingsDetails();
                        break;
                    case 3:
                        mainStreet.printPlaygroundInfo();
                        break;
                    case 4:
                        mainStreet.printTotalLengths();
                        break;
                    case 5:
                        mainStreet.printStreet();
                        break;
                    case 6:
                        System.out.println("\nExited from view menu.");
                        break;
                }

            }

            else if (mainMenuInput == 3) {

                if (mainStreet.getNumOfBuildings() == 0) {
                    System.out.print("\n! THERE IS NO BUILDING TO FOCUS ON !\n");

                } else {

                    check = true;
                    while (check) {

                        try {

                            mainStreet.printBuildingPositions();
                            System.out.print("\nWhich building do you want to focus on: ");
                            focusBuildingIndex = scanObj.nextInt();

                            if (focusBuildingIndex < 1 || focusBuildingIndex > mainStreet.getNumOfBuildings()) {
                                throw new Exception();
                            }

                            check = false;

                        } catch (Exception e) {
                            scanObj.nextLine();
                            System.out.println("\nYOUR INPUT IS WRONG. ENTER THE NUMBER OF THE BUILDING!");
                            System.out.println("For example, 1: Type = House, Street Side = Left, Position = 20");
                            System.out.println("If you want to focus on this building, enter 1");
                        }

                    }

                    mainStreet.focusBuilding(focusBuildingIndex);

                }

            }

            else if (mainMenuInput == 4) {
                System.out.print("\n\nTerminating the program...\n\n");
                return;
            }
        }
    }

    public static void mainMenu() {
        System.out.println("\n\nMAIN MENU");
        System.out.println("1: Edit Mode");
        System.out.println("2: View Mode");
        System.out.println("3: Focus BUilding");
        System.out.println("4: Exit Program");
        System.out.print("Enter your input (1-4): ");
    }

    public static void editMenu() {
        System.out.println("\n\nEDIT MENU");
        System.out.println("1: Add Building");
        System.out.println("2: Delete Building");
        System.out.println("3: Exit Edit Menu");
        System.out.print("What do you wanna do (1-3): ");
    }

    public static void viewMenu() {

        System.out.println("\n\nVIEW MENU");
        System.out.println("1: Display the total remaining length of lands on the street");
        System.out.println("2: Display the list of buildings on the street");
        System.out.println("3: Display the number and ratio of lenth of playgrounds in the street.");
        System.out.println("4: Calculate the total length of street occupied by the markets, houses or offices.");
        System.out.println("5: Display the skyline silhouette of the street");
        System.out.println("6: Exit View Menu");
        System.out.print("What do you wanna do (1-6): ");

    }

    public static void buildingTypesMenu() {
        System.out.println("\n\nBUILDING TYPES");
        System.out.println("1- House");
        System.out.println("2- Office");
        System.out.println("3- Market");
        System.out.println("4- Playground");
        System.out.println("5- Cancel adding building");
        System.out.print("Which building you want to add to your street(1-4): ");
    }

    public static void addHouseToStreet(Street street) {

        int positionInput, lengthInput, heightInput, numOfRoomInput, sideInput;
        String colorInput, ownerInput;
        Boolean check;
        Scanner scanObj = new Scanner(System.in);
        House userHouse = new House();

        check = true;
        while (check) {

            try {

                System.out.print("\n\n");
                System.out.print("Enter the position of the house: ");
                positionInput = scanObj.nextInt();
                userHouse.setPosition(positionInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "]PLEASE!");

            }
        }

        check = true;
        while (check) {

            try {

                System.out.print("\nEnter the length of the house: ");
                lengthInput = scanObj.nextInt();
                userHouse.setLength(lengthInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the height of the house: ");
                heightInput = scanObj.nextInt();
                userHouse.setHeight(heightInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN POSITIVE INTEGER PLEASE!");

            }
        }

        check = true;
        while (check) {

            try {
                System.out.println("\n1: Left Side");
                System.out.println("2: Right Side");
                System.out.print("Which side of the street do you wanna add to house (1,2):");

                sideInput = scanObj.nextInt();
                if (sideInput == 1)
                    userHouse.setSide("Left");
                else if (sideInput == 2)
                    userHouse.setSide("Right");
                else
                    throw new Exception();
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER 1 or 2 please!\n");

            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the number of rooms of the house: ");
                numOfRoomInput = scanObj.nextInt();
                userHouse.setNumberOfRooms(numOfRoomInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER A POSITIVE INTEGER PLEASE!");

            }
        }

        scanObj.nextLine();

        System.out.print("\nEnter the color of the house: ");
        colorInput = scanObj.nextLine();
        userHouse.setColor(colorInput);

        System.out.print("\nEnter the owner of the house: ");
        ownerInput = scanObj.nextLine();
        userHouse.setOwner(ownerInput);

        street.addBuilding(userHouse);

    }

    public static void addOfficeToStreet(Street street) {

        int positionInput, lengthInput, heightInput, sideInput;
        String jobType, ownerInput;
        Boolean check;
        Scanner scanObj = new Scanner(System.in);
        Office userOffice = new Office();

        check = true;
        while (check) {

            try {

                System.out.print("\n\n");
                System.out.print("Enter the position of the office: ");
                positionInput = scanObj.nextInt();
                userOffice.setPosition(positionInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {

                System.out.print("\nEnter the length of the office: ");
                lengthInput = scanObj.nextInt();
                userOffice.setLength(lengthInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the height of the office: ");
                heightInput = scanObj.nextInt();
                userOffice.setHeight(heightInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER A POSITIVE INTEGER PLEASE!");

            }
        }

        check = true;
        while (check) {

            try {
                System.out.println("\n1: Left Side");
                System.out.println("2: Right Side");
                System.out.print("Which side of the street do you wanna add to office (1,2):");

                sideInput = scanObj.nextInt();
                if (sideInput == 1)
                    userOffice.setSide("Left");
                else if (sideInput == 2)
                    userOffice.setSide("Right");
                else
                    throw new Exception();
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER 1 or 2 please!");

            }
        }

        scanObj.nextLine();

        System.out.print("\nEnter the color of the office: ");
        jobType = scanObj.nextLine();
        userOffice.setJobType(jobType);

        System.out.print("\nEnter the owner of the office: ");
        ownerInput = scanObj.nextLine();
        userOffice.setOwner(ownerInput);

        street.addBuilding(userOffice);

    }

    public static void addMarketToStreet(Street street) {

        int positionInput, lengthInput, heightInput, sideInput;
        String ownerInput, openingTime, closingTime;
        Boolean check;
        Scanner scanObj = new Scanner(System.in);
        Market userMarket = new Market();

        check = true;
        while (check) {

            try {

                System.out.print("\n\n");
                System.out.print("Enter the position of the market: ");
                positionInput = scanObj.nextInt();
                userMarket.setPosition(positionInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {

                System.out.print("\nEnter the length of the market: ");
                lengthInput = scanObj.nextInt();
                userMarket.setLength(lengthInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the height of the market: ");
                heightInput = scanObj.nextInt();
                userMarket.setHeight(heightInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER A POSITIVE INTEGER PLEASE!");

            }
        }

        check = true;
        while (check) {

            try {
                System.out.println("\n1: Left Side");
                System.out.println("2: Right Side");
                System.out.print("Which side of the street do you wanna add to market (1,2):");

                sideInput = scanObj.nextInt();
                if (sideInput == 1)
                    userMarket.setSide("Left");
                else if (sideInput == 2)
                    userMarket.setSide("Right");
                else
                    throw new Exception();
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER 1 or 2 please!");

            }
        }

        scanObj.nextLine();

        check = true;
        while (check) {

            try {

                System.out.print("\nEnter the opening time of the market: ");
                openingTime = scanObj.next();
                userMarket.setOpeningTime(openingTime);
                check = false;
            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println(
                        "\nYOUR INPUT IS NOT VALID. ENTER TIME IN HH:MM FORMAT PLEASE like 21:30 , 09:10 etc.!");
            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the closing time of the market: ");
                closingTime = scanObj.next();
                userMarket.setClosingTime(closingTime);
                check = false;
            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println(
                        "\n\nYOUR INPUT IS NOT VALID. ENTER TIME IN HH:MM FORMAT PLEASE like 21:30 , 09:10 etc.!");

            }
        }

        scanObj.nextLine();

        System.out.print("\nEnter the owner of the market: ");
        ownerInput = scanObj.nextLine();
        userMarket.setOwner(ownerInput);

        street.addBuilding(userMarket);

    }

    public static void addPlaygroundToStreet(Street street) {

        int positionInput, lengthInput, heightInput, sideInput;
        Boolean check;
        Scanner scanObj = new Scanner(System.in);
        Playground userPlayground = new Playground();

        check = true;
        while (check) {

            try {

                System.out.print("\n\n");
                System.out.print("Enter the position of the playground: ");
                positionInput = scanObj.nextInt();
                userPlayground.setPosition(positionInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {

                System.out.print("\nEnter the length of the playground: ");
                lengthInput = scanObj.nextInt();
                userPlayground.setLength(lengthInput, street.getLength());
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\n\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER BETWEEN [1 - " + street.getLength()
                        + "] PLEASE!");
            }
        }

        check = true;
        while (check) {

            try {
                System.out.print("\nEnter the height of the playground: ");
                heightInput = scanObj.nextInt();
                userPlayground.setHeight(heightInput);
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\nYOUR INPUT IS NOT VALID. ENTER A POSITIVE INTEGER PLEASE!\n");

            }
        }

        check = true;
        while (check) {

            try {
                System.out.println("\n1: Left Side");
                System.out.println("2: Right Side");
                System.out.print("Which side of the street do you wanna add to playground (1,2):");

                sideInput = scanObj.nextInt();
                if (sideInput == 1)
                    userPlayground.setSide("Left");
                else if (sideInput == 2)
                    userPlayground.setSide("Right");
                else
                    throw new Exception();
                check = false;

            } catch (Exception e) {

                scanObj.nextLine();
                System.out.println("\nYOUR INPUT IS NOT VALID. ENTER AN INTEGER 1 or 2 please!\n");

            }
        }

        street.addBuilding(userPlayground);

    }

    public static void main(String[] args) throws Exception {
        testConstructers();
        testEditMode();
        testViewMode();
        testOverriddenMethods();
        testExceptions();
        interactiveMenu();
    }
}
