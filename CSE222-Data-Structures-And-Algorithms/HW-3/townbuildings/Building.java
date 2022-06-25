package townbuildings;
/**
 * LDLLStreet class implementations.
 * 
 * @author Serhat Sarı
 * @since 20-03-2022
 * 
 */

/**
 * Building is a Java class to represent a building properties
 */
public class Building implements Cloneable {

   private int position;

   private int length;

   private int height;

   private String side;

   /**
    * Default constructer of the Building class
    */
   public Building() {
      // set default values
      position = 1;
      length = 10;
      height = 15;
      side = "Left";
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

   public Building(int newPosition, int newLength, int newHeight, String newSide, int streetLength) throws Exception {
      // set values
      setPosition(newPosition, streetLength);
      setLength(newLength, streetLength);
      setHeight(newHeight);
      setSide(newSide);

   }

   /**
    * Returns the position of the building
    * 
    * @return The position of the building.
    */
   public int getPosition() {
      return position;
   }

   /**
    * Set the position of the building to a new position
    * 
    * @param newPosition  the new position of the building on the street.
    * @param streetLength the length of the street
    * @throws Exception throw an Exception
    */
   public void setPosition(int newPosition, int streetLength) throws Exception {

      if (newPosition < 1 || newPosition > streetLength) {
         throw new Exception();
      }
      position = newPosition;

   }

   /**
    * Returns the length of the building
    * 
    * @return The length of the building.
    */
   public int getLength() {
      return length;
   }

   /**
    * The function takes two parameters, a new length and a street length.
    * It checks if the length is valid.
    * If it is, it sets the length of the building to the new length.
    * If it isn't, it throws an exception
    * 
    * @param newLength    the length of the building
    * @param streetLength the length of the street
    * @throws Exception throw an Exception
    */
   public void setLength(int newLength, int streetLength) throws Exception {

      if (newLength < 1 || newLength > streetLength) {
         throw new Exception();
      }
      length = newLength;
   }

   /**
    * Returns the height of the building
    * 
    * @return The height of the building.
    */
   public int getHeight() {
      return height;
   }

   /**
    * Set the height of the building
    * 
    * @param newHeight The new height of the building.
    * @throws Exception throw an Exception
    */
   public void setHeight(int newHeight) throws Exception {
      if (newHeight < 1) {
         throw new Exception();
      }
      height = newHeight;
   }

   /**
    * Returns the side of the building
    * 
    * @return The side of the building in String format (Left or Right).
    */
   public String getSide() {
      return side;
   }

   /**
    * It sets the side of the building
    * 
    * @param newSide The new value of the side (Left or Right).
    */
   public void setSide(String newSide) {
      side = newSide;
   }

   /**
    * This function returns a string representation of the building object details
    * 
    * @return The toString method is overridden and returns a string representation
    *         of the building.
    */
   @Override
   public String toString() {

      StringBuffer buildingInfo = new StringBuffer("");

      buildingInfo.append("Position: " + position + "\n");
      buildingInfo.append("Length: " + length + "\n");
      buildingInfo.append("Height: " + height + "\n");
      buildingInfo.append("Street Side: " + side + "\n");

      // return building details
      return buildingInfo.toString();

   }

   /**
    * This function checks if the current building is equal to the other building
    * 
    * @param obj The object to compare against.
    * @return The boolean value of the equals method.
    */
   @Override
   public boolean equals(Object obj) {

      Building otherBuilding = (Building) obj;

      // check whether the other object is null or not
      if (obj == null) {

         return false;

      } else if (getClass() != obj.getClass()) { // check if they are from the same class

         return false;

      } else {
         // if they are from the same class, compare them
         return (position == otherBuilding.getPosition() && length == otherBuilding.getLength())
               && (height == otherBuilding.getHeight() && side.equals(otherBuilding.side));
      }

   }

   /**
    * The hashCode method returns a hash code for the building object
    * 
    * @return The hash code of the building object.
    */
   @Override
   public int hashCode() {
      // return a unique hash Code
      return position * length * height * side.hashCode();
   }

   /**
    * Clone the object and return the clone.
    * Deep copy is not needed
    * 
    * @return The Building object that is being cloned.
    */
   @Override
   public Object clone() {
      try {
         // make a shallow copy
         Building copy = (Building) super.clone();
         return copy;

      } catch (CloneNotSupportedException e) {

         return null;

      }

   }
}
