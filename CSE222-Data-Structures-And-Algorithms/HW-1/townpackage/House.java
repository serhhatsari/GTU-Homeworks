package townpackage;
/**
 *House class implementations.
 * 
 * @author Serhat Sarı  
 * @since  06-03-2022
 * 
 */

/**
 * House is a Java class to represent the houses
 */
public class House extends Building implements Cloneable {

    private int numberOfRooms;

    private String color;

    private String owner;

    /**
     * Default constructer of the house class
     * 
     */
    public House() {
        super();
        // set default values
        numberOfRooms = 2;
        color = "Red";
        owner = "Serhat SARI";
    }

    /**
     * Constructer with parameters of the House class
     * 
     * @param newPosition   the new position of the house
     * @param newLength     the new length of the house
     * @param newHeight     the new height of the house
     * @param newSide       the new side of the house
     * @param streetLength  length of the street
     * @param newNumofRooms number of rooms of the house
     * @param newColor      color of the house
     * @param newOwner      owner of the house
     * @throws Exception throw an Exception
     */
    public House(int newPosition, int newLength, int newHeight, String newSide, int newNumofRooms, String newColor,
            String newOwner, int streetLength) throws Exception {

        super(newPosition, newLength, newHeight, newSide, streetLength);
        // set values
        setNumberOfRooms(newNumofRooms);
        setColor(newColor);
        setOwner(newOwner);
    }

    /**
     * Returns the number of rooms in the house
     * 
     * @return The number of rooms in the house.
     */
    public int getNumberOfRooms() {
        return numberOfRooms;
    }

    /**
     * Set the number of rooms in the house
     * 
     * @param numOfRooms The number of rooms in the house.
     * @throws Exception throw an Exception
     */
    public void setNumberOfRooms(int numOfRooms) throws Exception {

        if (numOfRooms < 1) { // check negativity
            throw new Exception();
        }
        numberOfRooms = numOfRooms;
    }

    /**
     * Returns the color of the house
     * 
     * @return The color of the house.
     */
    public String getColor() {
        return color;
    }

    /**
     * It sets the color of the house.
     * 
     * @param newColor The new color to house.
     */
    public void setColor(String newColor) {
        color = newColor;
    }

    /**
     * Returns the owner of the house
     * 
     * @return The owner of the house.
     */
    public String getOwner() {
        return owner;
    }

    /**
     * It sets the owner of the house.
     * 
     * @param newOwner The new owner of the house.
     */
    public void setOwner(String newOwner) {
        owner = newOwner;
    }

    /**
     * This function returns a string representation of the house object details
     * 
     * @return The toString method is overridden and returns a string representation
     *         of the house.
     */
    @Override
    public String toString() {

        StringBuffer houseHeadline = new StringBuffer("");
        StringBuffer houseInfo = new StringBuffer("");

        houseHeadline.append("\nHOUSE INFO: \n");

        houseInfo.append("Number of Rooms: " + numberOfRooms + "\n");
        houseInfo.append("Color: " + color + "\n");
        houseInfo.append("Owner: " + owner + "\n");

        // return house details
        return houseHeadline.toString() + super.toString() + houseInfo.toString();
    }

    /**
     * This function checks if the current house is equal to the other house
     * 
     * @param obj The house object to compare against.
     * @return The boolean value of the equals method.
     */
    @Override
    public boolean equals(Object obj) {

        House otherHouse = (House) obj;

        // check whether the other object is null or not
        if (obj == null) {
            return false;
        } else if (getClass() != obj.getClass()) { // check if they are from the same class
            return false;
        } else {
            // if they are from the same class, compare them
            return (super.equals(obj) && numberOfRooms == otherHouse.numberOfRooms && color.equals(otherHouse.color)
                    && owner.equals(otherHouse.owner));

        }
    }

    /**
     * The hashCode method returns a hash code for the house object
     * 
     * @return The hash code of the house object.
     */
    @Override
    public int hashCode() {
        // return a unique hash code
        return super.hashCode() * numberOfRooms * color.hashCode() * owner.hashCode();
    }

    /**
     * Clone the object and return the copy.
     * Deep copy is not needed
     * 
     * @return The House object that is being cloned.
     */
    @Override
    public Object clone() {

        // make a shallow copy
        House copy = (House) super.clone();
        return copy;

    }

}
