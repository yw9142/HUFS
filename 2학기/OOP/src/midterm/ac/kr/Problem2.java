package midterm.ac.kr;

import java.util.Scanner;

public class Problem2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("출력할 줄 수 입력 : ");
        int number = scanner.nextInt();

        for (int i = number; i > 0; i--) {
            for (int j = i; j > 0; j--) {
                System.out.print(i + 1 - j + " ");
            }
            System.out.println();
        }
    }
}
