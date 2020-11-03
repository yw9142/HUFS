package midterm.ac.kr;

import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("단어 입력 : ");
        String inputString = scanner.nextLine();
        boolean isPalindrome = true;

        int idx1 = 0;
        int idx2 = inputString.length() - 1;

        while (idx1 <= inputString.length() - 1) {
            if (inputString.charAt(idx1) != inputString.charAt(idx2)) {
                isPalindrome = false;
            }
            idx1++;
            idx2--;
        }
        System.out.print(isPalindrome);
    }
}
