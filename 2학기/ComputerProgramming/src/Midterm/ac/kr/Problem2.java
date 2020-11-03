package Midterm.ac.kr;

import java.util.Scanner;

public class Problem2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int Americano = 3000;
        int Cappuccino = 3300;
        int Cafe_Latte = 3500;
        int Einspener = 4000;

        System.out.print("음료수의 종류와 수량을 입력하세요: ");
        String name = scanner.next();
        int amount = scanner.nextInt();
        int price = 0;

        if ("아메리카노".equals(name)) {
            price = amount * Americano;
        } else if ("카푸치노".equals(name)) {
            price = amount * Cappuccino;
        } else if ("카페라떼".equals(name)) {
            price = amount * Cafe_Latte;
        } else if ("아인슈페너".equals(name)) {
            price = amount * Einspener;
        }

        if (price >= 20000)
            price *= 0.9;

        System.out.println("결제할 금액은 " + price + "원입니다.");
        System.out.print("얼마를 지불하시겠습니까? ");
        int pay = scanner.nextInt();

        if ((pay - price) >= 0)
            System.out.println("거스름돈은 " + (pay - price) + "원입니다. 감사합니다.");
        else {
            System.out.println("금액이 부족합니다.");
        }
        scanner.close();
    }
}
