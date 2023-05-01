import java.util.*;


class JPM {
    public static void main(String[] args) {
        // Q1
        // Created a character array split into each digits
        // 2020 = [2, 0, 2, 0], length 4
        // Create a hashmap and store the number of times each digit appears
        // Resulting HashMap will be 0 appeared twice, 2 appeared twice
        // Loop through the positions of the character array
        //      int n = arrayAtPos(pos)
        //      look at hashMap to see how many times it pos appeared, if it is not n, I will return 0;
        // If I reach to the end of the string, I will return 1.

        // Q2 - Jumbled Numbers
        //ZERO //ONE //TWO // THREE //FOUR //FIVE //SIX //SEVEN //EIGHT //NINE
        //ZERO -> Z
        //TWO -> W
        //FOUR -> U
        //SIX -> X
        //EIGHT -> G
        //ONE -> num(O) - num(ZERO) - num(TWO) - num(FOUR)
        //THREE -> num(R) - num(ZERO) - num(FOUR)
        //FIVE -> num(F) - num(FOUR)
        //SEVEN -> num(V) - num(FIVE)
        //NINE -> num(I) - num(EIGHT) - num(SIX) - num(FIVE)

        //When I attempted this question, it was more hardcoded, could have modularized it a bit more.
        //Switch case with comments.
    }
}