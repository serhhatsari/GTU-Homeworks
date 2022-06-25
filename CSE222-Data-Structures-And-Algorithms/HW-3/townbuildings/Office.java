package townbuildings;

/**
 * LDLLStreet class implementations.
 * 
 * @author Serhat Sarı
 * @since 20-03-2022
 * 
 */

/**
 * Office is a Java class to represent the offices
 */
public class Office extends Building {

   private String jobType;

   private String owner;

   /**
    * Default constructer of the house class
    * 
    */
   public Office() {

      super();
      // default values
      jobType = "Software";
      owner = "Serhat SARI";

   }

   /**
    * Constructer with parameters of the Office class
    * 
    * @param newPosition  the new position of the office
    * @param newLength    the new length of the office
    * @param newHeight    the new height of the office
    * @param newSide      the new side of the office
    * @param streetLength length of the street
    * @param newJobType   job type of the office
    * @param newOwner     owner of the office
    * @throws Exception throw an Exception
    */
   public Office(int newPosition, int newLength, int newHeight, String newSide, String newJobType, String newOwner,
         int streetLength) throws Exception {

      super(newPosition, newLength, newHeight, newSide, streetLength);
      // set values
      setJobType(newJobType);
      setOwner(newOwner);

   }

   /**
    * Returns the job type of the office
    * 
    * @return The job type.
    */
   public String getJobType() {
      return jobType;
   }

   /**
    * This function sets the job type of the office
    * 
    * @param newJobType The new job type.
    */
   public void setJobType(String newJobType) {
      jobType = newJobType;
   }

   /**
    * Returns the owner of the office
    * 
    * @return The owner of the office.
    */
   public String getOwner() {
      return owner;
   }

   /**
    * Set the owner of the office
    * 
    * @param newOwner The new owner of the office.
    */
   public void setOwner(String newOwner) {
      owner = newOwner;
   }

   /**
    * This function returns a string representation of the office object details
    * 
    * @return The toString method is overridden and returns a string representation
    *         of the office.
    */
   @Override
   public String toString() {

      StringBuffer officeHeadline = new StringBuffer("");
      StringBuffer officeInfo = new StringBuffer("");

      officeHeadline.append("\nOFFICE INFO: \n");

      officeInfo.append("Job Type: " + jobType + "\n");
      officeInfo.append("Owner: " + owner + "\n");

      // return the office details
      return officeHeadline.toString() + super.toString() + officeInfo.toString();

   }

   /**
    * This function checks if the current office is equal to the other office
    * 
    * @param obj The office object to compare against.
    * @return The boolean value of the equals method.
    */
   @Override
   public boolean equals(Object obj) {

      Office otherOffice = (Office) obj;

      // check whether the other object is null or not
      if (obj == null) {

         return false;

      } else if (getClass() != obj.getClass()) { // check if they are from the same class

         return false;

      } else {

         // if they are from the same playground class, compare them
         return super.equals(obj) && jobType.equals(otherOffice.jobType)
               && owner.equals(otherOffice.owner);

      }

   }

   /**
    * The hashCode method returns a hash code for the office object
    * 
    * @return The hash code of the office object.
    */
   @Override
   public int hashCode() {
      // return a unique hash code
      return super.hashCode() * jobType.hashCode() * owner.hashCode();
   }

   /**
    * Clone the object and return the clone.
    * Deep copy is not needed
    * 
    * @return The Building object that is being cloned.
    */
   @Override
   public Object clone() {

      // make shallow copy
      Office copy = (Office) super.clone();
      return copy;

   }

}
