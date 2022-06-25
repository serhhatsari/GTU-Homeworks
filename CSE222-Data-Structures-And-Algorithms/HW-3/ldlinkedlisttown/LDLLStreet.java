package ldlinkedlisttown;

import townbuildings.*;

import java.util.Iterator;
import java.util.ListIterator;

/**
 * LDLLStreet class implementations.
 * 
 * @author Serhat Sarı
 * @since 20-03-2022
 * 
 */

/**
 * LDLLStreet is a Java class to represent the list of buildings
 */
public class LDLLStreet implements Cloneable {

    private int numOfAllBuildings = 0;

    private int remainingLength;

    private int LDLLStreetLength;

    private LDLinkedList<Building> allBuildings = new LDLinkedList<>();

    /**
     * Default constructer of the LDLLStreet class
     */
    public LDLLStreet() {
        // set default values
        LDLLStreetLength = 50;
        remainingLength = 50;
        allBuildings = new LDLinkedList<>();
    }

    /**
     * Constructer with parameters of the LDLLStreet class
     * 
     * @param userLength the new length of the LDLLStreet
     * @throws Exception throw an Exception
     */
    public LDLLStreet(int userLength) throws Exception {
        setLength(userLength);
        allBuildings = new LDLinkedList<>();
    }

    /**
     * Return the length of the LDLLStreet
     * 
     * @return The length of the LDLLStreet.
     */
    public int getLength() {
        return LDLLStreetLength;
    }

    /**
     * Set the length of the LDLLStreet
     * 
     * @param userLength The length of the LDLLStreet that user wants to create.
     */
    private void setLength(int userLength) throws Exception {

        if (userLength < 1) {
            throw new Exception();
        }
        // set values
        LDLLStreetLength = userLength;
        remainingLength = userLength * 2;
    }

    /**
     * Returns the number of buildings in the LDLLStreet
     * 
     * @return The number of buildings in the LDLLStreet.
     */
    public int getNumOfBuildings() {
        return numOfAllBuildings;
    }

    /**
     * Adds a building to the LDLLStreet
     * 
     * @param newBuilding The building that you want to add to the LDLLStreet.
     */
    public void addBuilding(Building newBuilding) {

        // check for conflict
        if (checkConflict(newBuilding)) {
            System.out.println("\n\nThere is another building on that location. COULDNT ADD THE BUILDING. ");
            return;
        }

        // Adding new building to the LDLLStreet
        allBuildings.add(newBuilding);

        System.out.println("\nBUILDING HAS BEEN ADDED TO LDLLStreet.");

        // increment the building count
        numOfAllBuildings++;

        // recalculate the remaining length of the street
        remainingLength = remainingLength - newBuilding.getLength();

    }

    /**
     * Check if the new building is in conflicting with any of the existing
     * buildings
     * 
     * @param newBuilding The building that you want to add to the city.
     * @return The method returns a boolean value.
     */
    private Boolean checkConflict(Building newBuilding) {

        ListIterator<Building> it = allBuildings.listIterator();

        while (it.hasNext()) {
            Building currentBuilding = it.next();

            if (newBuilding.getSide().equals(currentBuilding.getSide())) {
                // check if they are on the same side
                if (newBuilding.getPosition() >= currentBuilding.getPosition()) {
                    // check position
                    if (newBuilding
                            .getPosition() <= (currentBuilding.getPosition()
                                    + currentBuilding.getLength())) {
                        return true;
                    }
                } else if ((newBuilding.getPosition() + newBuilding.getLength()) >= currentBuilding
                        .getPosition()) {
                    // check position
                    if ((newBuilding.getPosition() + newBuilding.getLength()) <= (currentBuilding.getPosition()
                            + currentBuilding.getLength())) {
                        return true;
                    }
                }

            }

        }

        return false;

    }

    /**
     * Given an index, delete the building at that index
     * 
     * @param index The index of the building to be deleted.
     */
    public void deleteBuilding(int index) {

        // recalculate the remaining length
        remainingLength = remainingLength + allBuildings.get(index - 1).getLength();

        // removing the building from the street
        allBuildings.remove(index - 1);

        System.out.println("\nBUILDING HAS BEEN DELETED.");

        // decrement the building count
        numOfAllBuildings--;

    }

    /**
     * This function focuses on a building in the LDLLStreet
     * 
     * @param index the index of the building that you want to focus on.
     */
    public void focusBuilding(int index) {

        Iterator it = allBuildings.listIterator(index - 1);

        Building currentBuilding = (Building) it.next();

        // check for the correct building
        if (currentBuilding instanceof House) {
            // if it is house, print its details
            House house = (House) currentBuilding;
            System.out.println("\nFocusing on house:");
            System.out.println("Owner of the house: " + house.getOwner());

        } else if (currentBuilding instanceof Office) {
            // if it is office, print its details
            Office office = (Office) currentBuilding;
            System.out.println("\nFocusing on office:");
            System.out.println("Job type of the office: " + office.getJobType());

        } else if (currentBuilding instanceof Market) {
            // if it is market, print its details
            Market market = (Market) currentBuilding;
            System.out.println("\nFocusing on market:");
            System.out.println("Closing time of the market: " + market.getClosingTime());

        } else if (currentBuilding instanceof Playground) {
            // if it is playground, print its details
            Playground playground = (Playground) currentBuilding;
            System.out.println("\nFocusing on playground:");
            System.out.println("Length of the playground: " + playground.getLength());
        }

    }

    /**
     * Prints out the position of all buildings in the city
     */
    public void printBuildingPositions() {

        Iterator it = allBuildings.iterator();

        System.out.println("\nLIST OF BUILDINGS");

        int i = 1;

        while (it.hasNext()) {

            Building currentBuilding = (Building) it.next();

            if (currentBuilding instanceof House) {
                // print the location of house
                House house = (House) currentBuilding;
                System.out.print(i + ": Type = House, LDLLStreet Side = " + house.getSide());
                System.out.println(", Position = " + house.getPosition());

            } else if (currentBuilding instanceof Office) {
                // print the location of office
                Office office = (Office) currentBuilding;
                System.out.print(i + ": Type = Office, LDLLStreet Side = " + office.getSide());
                System.out.println(", Position = " + office.getPosition());

            } else if (currentBuilding instanceof Market) {
                // print the location of market
                Market market = (Market) currentBuilding;
                System.out.print(i + ": Type = Market, LDLLStreet Side = " + market.getSide());
                System.out.println(", Position = " + market.getPosition());

            } else if (currentBuilding instanceof Playground) {
                // print the location of playground
                Playground playground = (Playground) currentBuilding;
                System.out.print(i + ": Type = Playground, LDLLStreet Side = " + playground.getSide());
                System.out.println(", Position = " + playground.getPosition());
            }
            i++;
        }
    }

    /**
     * Prints the remaining length of the LDLLStreet
     */
    public void printRemainingLength() {
        System.out.println("\n\nRemaining Length: " + remainingLength);

    }

    /**
     * Prints the total lengths of all the markets, houses, and offices
     */
    public void printTotalLengths() {

        int i;
        int marketTotalLength = 0;
        int houseTotalLength = 0;
        int officeTotalLength = 0;

        Iterator it = allBuildings.iterator();

        while (it.hasNext()) {

            Building currentBuilding = (Building) it.next();

            if (currentBuilding instanceof House) {
                // calculate the total lengths of house

                House house = (House) currentBuilding;
                houseTotalLength += house.getLength();

            } else if (currentBuilding instanceof Office) {
                // calculate the total lengths of office

                Office office = (Office) currentBuilding;
                officeTotalLength += office.getLength();

            } else if (currentBuilding instanceof Market) {
                // calculate the total lengths of market

                Market market = (Market) currentBuilding;
                marketTotalLength += market.getLength();
            }
        }

        System.out.println("\n\nTOTAL LENGTHS");
        System.out.println("Total Length of Markets: " + marketTotalLength);
        System.out.println("Total Length of Houses: " + houseTotalLength);
        System.out.println("Total Length of Offices: " + officeTotalLength);
    }

    /**
     * Prints the number of playgrounds and the ratio of playgrounds to the
     * LDLLStreet
     * length
     */
    public void printPlaygroundInfo() {

        int i, numOfPlaygrounds = 0;
        int totalPlaygroundLengths = 0;
        double ratioOfPlaygrounds = 0.0;

        Iterator it = allBuildings.iterator();

        while (it.hasNext()) {

            Building currentBuilding = (Building) it.next();

            if (currentBuilding instanceof Playground) {
                // calculate the number of playgrounds
                numOfPlaygrounds++;
                totalPlaygroundLengths += currentBuilding.getLength();
            }
        }

        // calculate the ratio of playgrounds to the LDLLStreet length
        ratioOfPlaygrounds = totalPlaygroundLengths / (double) (LDLLStreetLength * 2);

        System.out.println("\n\nNumber of playgrounds: " + numOfPlaygrounds);
        System.out.println("Ratio of lenth of playgrounds in the LDLLStreet: " + ratioOfPlaygrounds);

    }

    /**
     * This function prints the skyline silhouette of the LDLLStreet
     */
    public void printLDLLStreet() {

        int i, k, j, maxHeight;
        int positionArray[] = new int[numOfAllBuildings];
        int lengthArray[] = new int[numOfAllBuildings];
        int heightArray[] = new int[numOfAllBuildings];
        Boolean check = false;

        System.out.print("\nSkyline silhouette of the LDLLStreet\n\n");

        if (numOfAllBuildings == 0) {
            // check if there is any building on the LDLLStreet
            for (i = 0; i < LDLLStreetLength; i++) {
                System.out.print("#");
            }
            return;
        }

        for (i = 0; i < numOfAllBuildings; i++) {
            // get the position of the buildings
            positionArray[i] = allBuildings.get(i).getPosition();
            lengthArray[i] = allBuildings.get(i).getLength();
            heightArray[i] = allBuildings.get(i).getHeight();
        }

        maxHeight = heightArray[0];

        for (i = 0; i < numOfAllBuildings; i++) {
            // find the heighest building on the LDLLStreet and get the height value
            if (heightArray[i] > maxHeight)
                maxHeight = heightArray[i];
        }

        for (i = maxHeight; i > 0; i--) {
            // iterate until the max height

            for (k = 0; k < LDLLStreetLength; k++) {
                // iterate until the LDLLStreet length

                for (j = 0; j < numOfAllBuildings; j++) {
                    // iterate all buildings on the LDLLStreet

                    if (i < heightArray[j]) {
                        // check for height
                        if (k == positionArray[j] || (k == (positionArray[j] + lengthArray[j]))) {
                            // check position of the building
                            check = false;
                            for (int z = 0; z < numOfAllBuildings; z++) {
                                // checking if there is any conflict
                                if (z != j) {

                                    if (i < heightArray[z]) {

                                        if (k > positionArray[z] && k < (positionArray[z] + lengthArray[z])) {

                                            check = true;

                                        }

                                        else if ((k == (positionArray[j] + lengthArray[j])) && k == positionArray[z]) {
                                            check = true;
                                        }

                                        else if (k == positionArray[j] && k == (positionArray[z] + lengthArray[z])) {
                                            check = true;
                                        }
                                    }
                                }
                            }

                            if (!check) {
                                System.out.print("*");
                                break;
                            }

                        }

                    } else if (i == heightArray[j]) {
                        // check if height is equal to iterator
                        if (k >= positionArray[j] && k <= (positionArray[j] + lengthArray[j])) {
                            // check for the position
                            check = false;

                            for (int z = 0; z < numOfAllBuildings; z++) {
                                // iterate all buildings on the LDLLStreet
                                if (z != j) {
                                    if (i < heightArray[z]) {

                                        if (k > positionArray[z] && k < (positionArray[z] + lengthArray[z])) {
                                            // check for the conflict of the buildings
                                            check = true;
                                            break;
                                        }

                                        if (k == positionArray[z]) {

                                            check = true;
                                            break;
                                        }

                                        if (k == (positionArray[z] + lengthArray[z])) {

                                            check = true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (!check) {
                                System.out.print("*");
                                break;
                            }
                        }
                    }
                }
                if (numOfAllBuildings == j) {
                    System.out.print(" ");
                }

            }
            System.out.print("\n");
        }

        for (i = 0; i < LDLLStreetLength; i++) {
            System.out.print("#");
        }

    }

    /**
     * Prints the details of the building
     */
    public void printBuildingsDetails() {

        if (numOfAllBuildings == 0) {
            System.out.println("\n\nTHERE IS NO BUILDING TO DISPLAY!");
            return;
        }

        System.out.println(toString());

    }

    /**
     * This function returns a string representation of the LDLLStreet object
     * details
     * 
     * @return The toString method is overridden and returns a string representation
     *         of the LDLLStreet.
     */
    @Override
    public String toString() {

        StringBuffer LDLLStreetInfo = new StringBuffer();

        Iterator it = allBuildings.iterator();

        int i = 1;

        while (it.hasNext()) {

            Building currentBuilding = (Building) it.next();

            if (currentBuilding instanceof House) {
                // store the details of house to print
                House house = (House) currentBuilding;
                LDLLStreetInfo.append("\n" + i + ".BUILDING:\n");
                LDLLStreetInfo.append(house.toString());

            } else if (currentBuilding instanceof Office) {
                // store the details of office to print
                Office office = (Office) currentBuilding;
                LDLLStreetInfo.append("\n" + i + ".BUILDING:\n");
                LDLLStreetInfo.append(office.toString());

            } else if (currentBuilding instanceof Market) {
                // store the details of market to print
                Market market = (Market) currentBuilding;
                LDLLStreetInfo.append("\n" + i + ".BUILDING:\n");
                LDLLStreetInfo.append(market.toString());

            } else if (currentBuilding instanceof Playground) {
                // store the details of playground to print
                Playground playground = (Playground) currentBuilding;
                LDLLStreetInfo.append("\n" + i + ".BUILDING\n");
                LDLLStreetInfo.append(playground.toString());

            }
            i++;
        }

        // print the details of LDLLStreet
        return LDLLStreetInfo.toString();

    }

    /**
     * This function checks if the current LDLLStreet is equal to the other
     * LDLLStreet
     * 
     * @param obj The LDLLStreet object to compare against.
     * @return The boolean value of the equals method.
     */
    public boolean equals(Object obj) {

        boolean isFound;
        LDLLStreet otherLDLLStreet = (LDLLStreet) obj;
        Iterator it = allBuildings.iterator();

        // check whether the other object is null or not
        if (obj == null) {

            return false;

        } else if (getClass() != obj.getClass()) { // check if they are from the same class

            return false;

        }

        else if (numOfAllBuildings != otherLDLLStreet.numOfAllBuildings) {
            // check if they contain same number of buildings
            return false;
        }

        else if (this == obj) {
            // check if they are sam or not
            return true;
        }

        while (it.hasNext()) {

            Building currentBuilding = (Building) it.next();

            // check if they have same kind of buildings

            isFound = false;

            Iterator otherIt = otherLDLLStreet.allBuildings.iterator();

            while (it.hasNext()) {

                Building otherBuilding = (Building) otherIt.next();

                if (currentBuilding instanceof House) {
                    // check for house
                    if (otherBuilding instanceof House) {

                        House ourHouse = (House) currentBuilding;
                        House otherHouse = (House) otherBuilding;

                        if (ourHouse.equals(otherHouse)) {
                            isFound = true;
                        }

                    }

                } else if (currentBuilding instanceof Office) {
                    // check for office
                    if (otherBuilding instanceof Office) {

                        Office ourOffice = (Office) currentBuilding;
                        Office otherOffice = (Office) otherBuilding;

                        if (ourOffice.equals(otherOffice)) {
                            isFound = true;
                        }

                    }

                } else if (currentBuilding instanceof Market) {
                    // check for market
                    if (otherBuilding instanceof Market) {

                        Market ourMarket = (Market) currentBuilding;
                        Market otherMarket = (Market) otherBuilding;

                        if (ourMarket.equals(otherMarket)) {
                            isFound = true;
                        }

                    }

                } else if (currentBuilding instanceof Playground) {
                    // check for playground
                    if (otherBuilding instanceof Playground) {

                        Playground ourPlayground = (Playground) currentBuilding;
                        Playground otherPlayground = (Playground) otherBuilding;

                        if (ourPlayground.equals(otherPlayground)) {
                            isFound = true;
                        }

                    }

                }

            }

            if (!isFound) {
                return false;
            }

        }

        return true;

    }

    /**
     * The hashCode method returns a unique hash code for the LDLLStreet object
     * 
     * @return The hash code of the LDLLStreet object.
     */
    @Override
    public int hashCode() {
        // return a unique hash code
        return LDLLStreetLength * numOfAllBuildings * remainingLength;
    }

    /**
     * Clone the object and return the clone.
     * Deep copy is done
     * 
     * @return The LDLLStreet object that is being cloned.
     */
    @Override
    protected Object clone() {
        int i;
        try {
            // make a deep copy
            LDLLStreet copy = (LDLLStreet) super.clone();
            for (i = 0; i < numOfAllBuildings; i++) {
                copy.allBuildings.add((Building) allBuildings.get(i).clone());
            }

            return copy;

        } catch (CloneNotSupportedException e) {

            return null;

        }

    }
}