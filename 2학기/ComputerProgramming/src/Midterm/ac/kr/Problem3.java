package Midterm.ac.kr;

import java.util.Scanner;

public class Problem3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] word_list_english = {"java", "study", "happy", "array", "project"};
        String[] word_list_korean = {"자바", "공부", "행복한", "배열", "과제"};

        while (true) {
            System.out.print("영어 단어를 입력하세요: ");
            String word = scanner.next();

            for (int i = 0; i < word_list_english.length; i++) {
                if (word.equals(word_list_english[i])) {
                    System.out.println("한글 뜻: " + word_list_korean[i]);
                    break;
                } else if (!(word.equals(word_list_english[i])) && i == word_list_english.length - 1) {
                    System.out.println("해당 단어를 찾을 수 없습니다.");
                }
            }

            if (word.equals("exit")) {
                System.out.println("프로그램을 종료합니다.");
                break;
            }

        }


        scanner.close();
    }
}
