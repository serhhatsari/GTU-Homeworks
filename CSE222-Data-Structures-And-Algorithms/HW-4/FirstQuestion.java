/**
 * First Question class implementations.
 * 
 * @author Serhat Sarı
 * @since 1-04-2022
 * 
 */

public class FirstQuestion {

    /**
     * Given a string, find the index of the first occurence of a given substring.
     * If the substring is not found, return - 1.
     * 
     * @param bigStr         The string to search in.
     * @param givenStr       the string to search for
     * @param occurenceCount The number of times the given string is to be found in
     *                       the big string.
     * @param index          The index of the first character of the string that we
     *                       are searching for.
     * @return The index of the first occurence of the given string.
     */
    private static int searchStr(String bigStr, String givenStr, int occurenceCount, int index) {

        if (bigStr == null || givenStr == null)
            return -index - 1;
        else if (bigStr.equals("") || givenStr.equals(""))
            return -index - 1;
        else if (occurenceCount < 0)
            return -index - 1;

        int findInd = bigStr.indexOf(givenStr);

        if (findInd == -1)
            return -index - 1;

        if (occurenceCount == 1)
            return findInd;

        occurenceCount--;
        index = index + findInd + 1;

        return findInd + 1
                + searchStr(bigStr.substring(findInd + 1), givenStr, occurenceCount, index);
    }

    /**
     * Given a string, find the number of occurences of a given substring
     * 
     * @param bigStr         The string in which we are searching for the givenStr.
     * @param givenStr       The string to search for.
     * @param occurenceCount The number of times the given string is expected to
     *                       occur in the big string.
     * @return The index of the first occurence of the given string in the big
     *         string.
     */
    public static int searchOccurences(String bigStr, String givenStr, int occurenceCount) {

        return searchStr(bigStr, givenStr, occurenceCount, 0);

    }

}