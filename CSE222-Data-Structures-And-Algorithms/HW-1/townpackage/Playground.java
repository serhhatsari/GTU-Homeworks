package townpackage;

/**
 * Playground class implementations.
 * 
 * @author Serhat Sarı
 * @since 06-03-2022
 * 
 */

/**
 * Building is a Java class to represent the buildings
 */
public class Playground extends Building implements Cloneable {

    /**
     * Default constructer of the Playground class
     */
    public Playground() {
        super();
    }

    /**
     * Constructer with parameters of the Building class
     * 
     * @param newPosition  the new position of the building
     * @param newLength    the new length of the building
     * @param newHeight    the new height of the building
     * @param newSide      the new side of the building
     * @param streetLength length of the street
     * @throws Exception throw an Exception
     */
    public Playground(int newPosition, int newLength, int newHeight, String newSide, int streetLength)
            throws Exception {
        super(newPosition, newLength, newHeight, newSide, streetLength);
    }

    /**
     * This function returns a string representation of the playground object
     * details
     * 
     * @return The toString method is overridden and returns a string representation
     *         of the playground.
     */
    @Override
    public String toString() {

        StringBuffer playgroundInfo = new StringBuffer("");

        playgroundInfo.append("\nPLAYGROUND INFO: \n");

        // return the building details
        return playgroundInfo.toString() + super.toString();

    }

    /**
     * This function checks if the current playground is equal to the other
     * playground
     * 
     * @param obj The playground object to compare against.
     * @return The boolean value of the equals method.
     */
    public boolean equals(Object obj) {

        // check whether the other object is null or not
        if (obj == null) {

            return false;

        } else if (getClass() != obj.getClass()) { // check if they are from the same class

            return false;

        } else {
            // if they are from the same class, compare them

            return super.equals(obj);

        }
    }

    /**
     * The hashCode method returns a hash code for the playground object
     * 
     * @return The hash code of the playground object.
     */
    @Override
    public int hashCode() {
        // returns a unique hash code
        return super.hashCode();
    }

    /**
     * Clone the object and return the clone
     * Deep copy is not needed
     * 
     * @return The Building object that is being cloned.
     */
    @Override
    protected Object clone() {

        // make a shallow copy of the object
        Playground copy = (Playground) super.clone();
        return copy;

    }
}
