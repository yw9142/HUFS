package Midterm.ac.kr;

import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        Scanner scanner = new Scanner(System.in).useDelimiter("\\s|, ");

        System.out.print("(x,y)의 좌표를 입력하세요: ");

        int input_x = scanner.nextInt();
        int input_y = scanner.nextInt();

        if ((input_x >= 100 && input_x <= 200) && (input_y >= 100 && input_y <= 200))
            System.out.println("점(" + input_x + ", " + input_y + ")은 (100, 100)~(200,200) 영역의 사각형 내에 위치해 있습니다.");
        else
            System.out.println("점(" + input_x + ", " + input_y + ")은 (100, 100)~(200,200) 영역의 사각형 밖에 위치해 있습니다.");

        scanner.close();
    }
}
