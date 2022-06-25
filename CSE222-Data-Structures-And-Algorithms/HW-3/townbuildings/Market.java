package townbuildings;

/**
 * LDLLStreet class implementations.
 * 
 * @author Serhat Sarı
 * @since 20-03-2022
 * 
 */

/**
 * Market is a Java class to represent the markets
 */
public class Market extends Building {

   private String owner;

   private String closingTime;

   private String openingTime;

   /**
    * Default Constructer of the House class
    * 
    */
   public Market() {

      super();
      // set default values
      closingTime = "09:00";
      openingTime = "21:00";
      owner = "SERHAT SARI";

   }

   /**
    * Constructer with parameters of the Market class
    * 
    * @param newPosition    the new position of the market
    * @param newLength      the new length of the market
    * @param newHeight      the new height of the market
    * @param newSide        the new side of the market
    * @param streetLength   length of the street
    * @param newOpeningTime opening time of the market
    * @param newClosingTime closing time of the market
    * @param newOwner       new owner of the market
    * @throws Exception throw an Exception
    */
   public Market(int newPosition, int newLength, int newHeight, String newSide, String newOpeningTime,
         String newClosingTime, String newOwner, int streetLength) throws Exception {

      super(newPosition, newLength, newHeight, newSide, streetLength);
      // set values
      setOpeningTime(newOpeningTime);
      setClosingTime(newClosingTime);
      setOwner(newOwner);

   }

   /**
    * Returns the owner of the market
    * 
    * @return The owner of the market.
    */
   public String getOwner() {
      return owner;
   }

   /**
    * It sets the owner of the market.
    * 
    * @param newOwner The new owner of the market.
    */
   public void setOwner(String newOwner) {
      owner = newOwner;
   }

   /**
    * Returns the closing time of the market
    * 
    * @return The closing time of the market.
    */
   public String getClosingTime() {
      return closingTime;
   }

   /**
    * It sets the closing time of the market.
    * 
    * @param newClosingTime The new closing time for the market.
    * @throws Exception throw an Exception
    */
   public void setClosingTime(String newClosingTime) throws Exception {

      if (newClosingTime.length() != 5 || newClosingTime.charAt(2) != ':') {
         throw new Exception();
      }
      String[] timeParts = newClosingTime.split(":");

      if (Integer.parseInt(timeParts[0]) < 1 || Integer.parseInt(timeParts[0]) > 24) {
         throw new Exception();
      } else if (Integer.parseInt(timeParts[1]) < 0 || Integer.parseInt(timeParts[1]) > 59) {
         throw new Exception();
      }

      closingTime = newClosingTime;
   }

   /**
    * Returns the opening time of the market
    * 
    * @return Opening time of the market
    */
   public String getOpeningTime() {
      return openingTime;
   }

   /**
    * It sets the opening time of the market.
    * 
    * @param newOpeningTime The new opening time for the market.
    * @throws Exception throw an Exception
    */
   public void setOpeningTime(String newOpeningTime) throws Exception {

      if (newOpeningTime.length() != 5 || newOpeningTime.charAt(2) != ':') {
         throw new Exception();
      }
      String[] timeParts = newOpeningTime.split(":");

      if (Integer.parseInt(timeParts[0]) < 1 || Integer.parseInt(timeParts[0]) > 24) {
         throw new Exception();
      } else if (Integer.parseInt(timeParts[1]) < 0 || Integer.parseInt(timeParts[1]) > 59) {
         throw new Exception();
      }

      openingTime = newOpeningTime;
   }

   /**
    * This function returns a string representation of the market object details
    * 
    * @return The toString method is overridden and returns a string representation
    *         of the market.
    */
   @Override
   public String toString() {

      StringBuffer marketHeadline = new StringBuffer("");
      StringBuffer marketInfo = new StringBuffer("");

      marketHeadline.append("\nMARKET INFO: \n");

      marketInfo.append("Opening Time: " + openingTime + "\n");
      marketInfo.append("Closing Time: " + closingTime + "\n");
      marketInfo.append("Owner: " + owner + "\n");

      // return market details
      return marketHeadline.toString() + super.toString() + marketInfo.toString();

   }

   /**
    * This function checks if the current market is equal to the other market
    * 
    * @param obj The market object to compare against.
    * @return The boolean value of the equals method.
    */
   @Override
   public boolean equals(Object obj) {

      Market otherMarket = (Market) obj;

      // check whether the other object is null or not
      if (obj == null) {

         return false;

      } else if (getClass() != obj.getClass()) { // check if they are from the same class

         return false;

      } else {

         // if they are from the same class, compare them
         return super.equals(obj) && owner.equals(otherMarket.getOwner())
               && closingTime.equals(otherMarket.closingTime)
               && openingTime.equals(otherMarket.openingTime);
      }

   }

   /**
    * The hashCode method returns a hash code for the market object
    * 
    * @return The hash code of the market object.
    */
   @Override
   public int hashCode() {
      // return a unique hashcode
      return super.hashCode() * closingTime.hashCode() * openingTime.hashCode() * owner.hashCode();
   }

   /**
    * Clone the object and return the clone.
    * Deep copy is not needed
    * 
    * @return The Building object that is being cloned.
    */
   @Override
   public Object clone() {
      // make a shallow copy
      Market copy = (Market) super.clone();
      return copy;

   }

}
