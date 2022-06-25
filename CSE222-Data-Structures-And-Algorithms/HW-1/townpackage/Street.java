package townpackage;

/**
 * Street class implementations.
 * 
 * @author Serhat Sarı
 * @since 06-03-2022
 * 
 */

/**
 * Street is a Java class to represent the list of buildings
 */
public class Street implements Cloneable {

    private int numOfAllBuildings = 0;

    private int remainingLength;

    private int streetLength;

    private Building allBuildings[];

    /**
     * Default constructer of the Street class
     */
    public Street() {
        // set default values
        streetLength = 50;
        remainingLength = 50;
    }

    /**
     * Constructer with parameters of the Street class
     * 
     * @param userLength the new length of the street
     * @throws Exception throw an Exception
     */
    public Street(int userLength) throws Exception {

        setLength(userLength);
    }

    /**
     * Return the length of the street
     * 
     * @return The length of the street.
     */
    public int getLength() {
        return streetLength;
    }

    /**
     * Set the length of the street
     * 
     * @param userLength The length of the street that user wants to create.
     */
    private void setLength(int userLength) throws Exception {

        if (userLength < 1) {
            throw new Exception();
        }
        // set values
        streetLength = userLength;
        remainingLength = userLength * 2;
    }

    /**
     * Returns the number of buildings in the street
     * 
     * @return The number of buildings in the street.
     */
    public int getNumOfBuildings() {
        return numOfAllBuildings;
    }

    /**
     * Adds a building to the street
     * 
     * @param newBuilding The building that you want to add to the street.
     */
    public void addBuilding(Building newBuilding) {

        // check for conflict
        if (checkConflict(newBuilding)) {
            System.out.println("\n\nThere is another building on that location. COULDNT ADD THE BUILDING. ");
            return;
        }

        Building[] temp = new Building[numOfAllBuildings + 1];
        int i;

        for (i = 0; i < numOfAllBuildings; ++i) {

            temp[i] = allBuildings[i];
        }

        System.out.println("\nBUILDING HAS BEEN ADDED TO STREET.");

        // adding new building to the street
        allBuildings = temp;

        allBuildings[numOfAllBuildings] = newBuilding;

        numOfAllBuildings++;

        remainingLength = remainingLength - newBuilding.getLength();

    }

    /**
     * Check if the new building is in conflict with any of the existing buildings
     * 
     * @param newBuilding The building that you want to add to the city.
     * @return The method returns a boolean value.
     */
    private Boolean checkConflict(Building newBuilding) {

        int i;

        for (i = 0; i < numOfAllBuildings; i++) {
            // check all buildings

            if (newBuilding.getSide().equals(allBuildings[i].getSide())) {
                // check if they are on the same side
                if (newBuilding.getPosition() >= allBuildings[i].getPosition()) {
                    // check position
                    if (newBuilding
                            .getPosition() <= (allBuildings[i].getPosition() + allBuildings[i].getLength())) {
                        return true;
                    }
                } else if ((newBuilding.getPosition() + newBuilding.getLength()) >= allBuildings[i].getPosition()) {
                    // check position
                    if ((newBuilding.getPosition() + newBuilding.getLength()) <= (allBuildings[i].getPosition()
                            + allBuildings[i].getLength())) {
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

        Building[] temp = new Building[numOfAllBuildings - 1];
        int i, k;

        for (i = 0, k = 0; i < numOfAllBuildings; ++i) {
            // iterate all buildings
            if (i != (index - 1)) {
                // check for the building to be deleted
                temp[k] = allBuildings[i];
                k++;
            }
        }

        System.out.println("\nBUILDING HAS BEEN DELETED.");
        // set other values
        remainingLength = remainingLength + allBuildings[index - 1].getLength();

        allBuildings = temp;

        numOfAllBuildings--;

    }

    /**
     * This function focuses on a building in the street
     * 
     * @param index the index of the building that you want to focus on.
     */
    public void focusBuilding(int index) {

        int i;

        for (i = 0; i < numOfAllBuildings; i++) {
            // iterate all buildings
            if (i == (index - 1)) {
                // check for the correct building
                if (allBuildings[i] instanceof House) {
                    // if it is house, print its details
                    House house = (House) allBuildings[i];
                    System.out.println("\nFocusing on house:");
                    System.out.println("Owner of the house: " + house.getOwner());

                } else if (allBuildings[i] instanceof Office) {
                    // if it is office, print its details
                    Office office = (Office) allBuildings[i];
                    System.out.println("\nFocusing on office:");
                    System.out.println("Job type of the office: " + office.getJobType());

                } else if (allBuildings[i] instanceof Market) {
                    // if it is market, print its details
                    Market market = (Market) allBuildings[i];
                    System.out.println("\nFocusing on market:");
                    System.out.println("Closing time of the market: " + market.getClosingTime());

                } else if (allBuildings[i] instanceof Playground) {
                    // if it is playground, print its details
                    Playground playground = (Playground) allBuildings[i];
                    System.out.println("\nFocusing on playground:");
                    System.out.println("Length of the playground: " + playground.getLength());
                }
            }
        }

    }

    /**
     * Prints out the position of all buildings in the city
     */
    public void printBuildingPositions() {

        int i;
        System.out.println("\nLIST OF BUILDINGS");
        for (i = 0; i < numOfAllBuildings; i++) {

            if (allBuildings[i] instanceof House) {
                // print the location of house
                House house = (House) allBuildings[i];
                System.out.print((i + 1) + ": Type = House, Street Side = " + house.getSide());
                System.out.println(", Position = " + house.getPosition());

            } else if (allBuildings[i] instanceof Office) {
                // print the location of office
                Office office = (Office) allBuildings[i];
                System.out.print((i + 1) + ": Type = Office, Street Side = " + office.getSide());
                System.out.println(", Position = " + office.getPosition());

            } else if (allBuildings[i] instanceof Market) {
                // print the location of market
                Market market = (Market) allBuildings[i];
                System.out.print((i + 1) + ": Type = Market, Street Side = " + market.getSide());
                System.out.println(", Position = " + market.getPosition());

            } else if (allBuildings[i] instanceof Playground) {
                // print the location of playground
                Playground playground = (Playground) allBuildings[i];
                System.out.print((i + 1) + ": Type = Playground, Street Side = " + playground.getSide());
                System.out.println(", Position = " + playground.getPosition());
            }
        }

    }

    /**
     * Prints the remaining length of the street
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

        for (i = 0; i < numOfAllBuildings; i++) {
            // calculate the total lengths

            if (allBuildings[i] instanceof House) {
                // calculate the total lengths of house

                House house = (House) allBuildings[i];
                houseTotalLength += house.getLength();

            } else if (allBuildings[i] instanceof Office) {
                // calculate the total lengths of office

                Office office = (Office) allBuildings[i];
                officeTotalLength += office.getLength();

            } else if (allBuildings[i] instanceof Market) {
                // calculate the total lengths of market

                Market market = (Market) allBuildings[i];
                marketTotalLength += market.getLength();
            }
        }
        System.out.println("\n\nTOTAL LENGTHS");
        System.out.println("Total Length of Markets: " + marketTotalLength);
        System.out.println("Total Length of Houses: " + houseTotalLength);
        System.out.println("Total Length of Offices: " + officeTotalLength);
    }

    /**
     * Prints the number of playgrounds and the ratio of playgrounds to the street
     * length
     */
    public void printPlaygroundInfo() {

        int i, numOfPlaygrounds = 0;
        int totalPlaygroundLengths = 0;
        double ratioOfPlaygrounds = 0.0;

        for (i = 0; i < numOfAllBuildings; ++i) {
            if (allBuildings[i] instanceof Playground) {
                // calculate the number of playgrounds
                numOfPlaygrounds++;
                totalPlaygroundLengths += allBuildings[i].getLength();
            }
        }

        // calculate the ratio of playgrounds to the street length
        ratioOfPlaygrounds = totalPlaygroundLengths / (double) (streetLength * 2);

        System.out.println("\n\nNumber of playgrounds: " + numOfPlaygrounds);
        System.out.println("Ratio of lenth of playgrounds in the street: " + ratioOfPlaygrounds);

    }

    /**
     * This function prints the skyline silhouette of the street
     */
    public void printStreet() {

        int i, k, j, maxHeight;
        int positionArray[] = new int[numOfAllBuildings];
        int lengthArray[] = new int[numOfAllBuildings];
        int heightArray[] = new int[numOfAllBuildings];
        Boolean check = false;

        System.out.print("\nSkyline silhouette of the street\n\n");

        if (numOfAllBuildings == 0) {
            // check if there is any building on the street
            for (i = 0; i < streetLength; i++) {
                System.out.print("#");
            }
            return;
        }

        for (i = 0; i < numOfAllBuildings; i++) {
            // get the position of the buildings
            positionArray[i] = allBuildings[i].getPosition();
            lengthArray[i] = allBuildings[i].getLength();
            heightArray[i] = allBuildings[i].getHeight();
        }

        maxHeight = heightArray[0];

        for (i = 0; i < numOfAllBuildings; i++) {
            // find the heighest building on the street and get the height value
            if (heightArray[i] > maxHeight)
                maxHeight = heightArray[i];
        }

        for (i = maxHeight; i > 0; i--) {
            // iterate until the max height

            for (k = 0; k < streetLength; k++) {
                // iterate until the street length

                for (j = 0; j < numOfAllBuildings; j++) {
                    // iterate all buildings on the street

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
                                // iterate all buildings on the street
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

        for (i = 0; i < streetLength; i++) {
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
     * This function returns a string representation of the street object details
     * 
     * @return The toString method is overridden and returns a string representation
     *         of the street.
     */
    @Override
    public String toString() {

        int i;
        StringBuffer streetInfo = new StringBuffer();

        for (i = 0; i < numOfAllBuildings; i++) {

            if (allBuildings[i] instanceof House) {
                // store the details of house to print
                House house = (House) allBuildings[i];
                streetInfo.append("\n" + (i + 1) + ".BUILDING:\n");
                streetInfo.append(house.toString());

            } else if (allBuildings[i] instanceof Office) {
                // store the details of office to print
                Office office = (Office) allBuildings[i];
                streetInfo.append("\n" + (i + 1) + ".BUILDING:\n");
                streetInfo.append(office.toString());

            } else if (allBuildings[i] instanceof Market) {
                // store the details of market to print
                Market market = (Market) allBuildings[i];
                streetInfo.append("\n" + (i + 1) + ".BUILDING:\n");
                streetInfo.append(market.toString());

            } else if (allBuildings[i] instanceof Playground) {
                // store the details of playground to print
                Playground playground = (Playground) allBuildings[i];
                streetInfo.append("\n" + (i + 1) + ".BUILDING\n");
                streetInfo.append(playground.toString());

            }
        }

        // print the details of street
        return streetInfo.toString();

    }

    /**
     * This function checks if the current street is equal to the other street
     * 
     * @param obj The street object to compare against.
     * @return The boolean value of the equals method.
     */
    public boolean equals(Object obj) {
        int i, k;
        boolean isFound;

        Street otherStreet = (Street) obj;

        // check whether the other object is null or not
        if (obj == null) {

            return false;

        } else if (getClass() != obj.getClass()) { // check if they are from the same class

            return false;

        }

        else if (numOfAllBuildings != otherStreet.numOfAllBuildings) {
            // check if they contain same number of buildings
            return false;
        }

        else if (this == obj) {
            // check if they are sam or not
            return true;
        }

        for (i = 0; i < numOfAllBuildings; i++) {
            // check if they have same kind of buildings

            isFound = false;

            for (k = 0; k < otherStreet.numOfAllBuildings; k++) {

                if (allBuildings[i] instanceof House) {
                    // check for house
                    if (otherStreet.allBuildings[k] instanceof House) {

                        House ourHouse = (House) allBuildings[i];
                        House otherHouse = (House) otherStreet.allBuildings[k];

                        if (ourHouse.equals(otherHouse)) {
                            isFound = true;
                        }

                    }

                } else if (allBuildings[i] instanceof Office) {
                    // check for office
                    if (otherStreet.allBuildings[k] instanceof Office) {

                        Office ourOffice = (Office) allBuildings[i];
                        Office otherOffice = (Office) otherStreet.allBuildings[k];

                        if (ourOffice.equals(otherOffice)) {
                            isFound = true;
                        }

                    }

                } else if (allBuildings[i] instanceof Market) {
                    // check for market
                    if (otherStreet.allBuildings[k] instanceof Market) {

                        Market ourMarket = (Market) allBuildings[i];
                        Market otherMarket = (Market) otherStreet.allBuildings[k];

                        if (ourMarket.equals(otherMarket)) {
                            isFound = true;
                        }

                    }

                } else if (allBuildings[i] instanceof Playground) {
                    // check for playground
                    if (otherStreet.allBuildings[k] instanceof Playground) {

                        Playground ourPlayground = (Playground) allBuildings[i];
                        Playground otherPlayground = (Playground) otherStreet.allBuildings[k];

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
     * The hashCode method returns a unique hash code for the street object
     * 
     * @return The hash code of the street object.
     */
    @Override
    public int hashCode() {
        // return a unique hash code
        return streetLength * numOfAllBuildings * remainingLength;
    }

    /**
     * Clone the object and return the clone.
     * Deep copy is done
     * 
     * @return The Street object that is being cloned.
     */
    @Override
    protected Object clone() {
        int i;
        try {
            // make a deep copy
            Street copy = (Street) super.clone();
            for (i = 0; i < numOfAllBuildings; i++) {
                copy.allBuildings[i] = (Building) allBuildings[i].clone();
            }

            return copy;

        } catch (CloneNotSupportedException e) {

            return null;

        }

    }
}
