package hufs.ces.closure;

import java.util.*;

class Poker3 {
    //2017.05.24
    static Scanner sc;
    static Random rn;

    static String[] card = new String[7];
    static String[] cardNum = new String[7];

    static int top = 0, onePair = 0, twoPair = 0, triple = 0, straight = 0, flush = 0, fullHouse = 0, fourCard = 0;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        rn = new Random();

        String[][] cardDeck = new String[4][13];

        int[] shape = new int[4];
        int[] number = new int[13];

        String tmp = "";
        int ranNum = 0, cnge = 0, grade = 0, straightChk = 0, backST = 0;

        cardDeckSet(cardDeck, ranNum,tmp);

        System.out.println("\n==================== Poker Game ====================");
        System.out.println("     카드게임에서 브리지가 지적인 게임인 데 대하여 ");
        System.out.println("    포커는 도박의 색채가 짙은 것으로, 스릴이 있고 또한 ");
        System.out.println("   숙련도가 승패에 영향을 끼치는 재미있는 게임이다.");
        System.out.println("   ¿? 카드 뽑기 <Enter>");

        for(int q = 0 ; q<7 ; q++){
            ranNum = rn.nextInt(4);
            sc.nextLine();

            card[q] = cardDeck[ranNum][q];
            cardNum[q] = cardDeck[ranNum][q];

            cnge = Integer.parseInt(card[q].substring(1, card[q].length()));
            switch(cnge){
                case 11 :
                    card[q] = card[q].replace(card[q].substring(1, 3), "J");
                    break;
                case 12 :
                    card[q] = card[q].replace(card[q].substring(1, 3), "Q");
                    break;
                case 13 :
                    card[q] = card[q].replace(card[q].substring(1, 3), "K");
                    break;
                case 14 :
                    card[q] = card[q].replace(card[q].substring(1, 3), "A");
                    break;
            }
            System.out.println((q+1)+"번째 카드_"+card[q]);
        }//My Card Set

        for(int q = 0 ; q<7 ; q++){
            switch(card[q].substring(0, 1)){
                case "♠" :
                    shape[0] ++;
                    break;
                case "◈" :
                    shape[1] ++;
                    break;
                case "♣" :
                    shape[2] ++;
                    break;
                case "♥" :
                    shape[3] ++;
                    break;
            }
            if(shape[0] >= 5)flush = 4;
            else if(shape[1] >= 5)flush = 3;
            else if(shape[2] >= 5)flush = 2;
            else if(shape[3] >= 5)flush = 1;
            if(flush >= 1 && grade <= 6){
                grade = 6;
            }
        }// flush check

        for(int q = 0 ; q<7 ; q++){
            cnge = Integer.parseInt(cardNum[q].substring(1, cardNum[q].length()));
            number[cnge-2] ++;
        }//number 배열에 카드의 숫자값을 빼서 넣어줌

        for(int q = 0 ; q < 9 ; q++){
            for(int w = q ; w < q + 5 ; w++){
                if(number[w] >= 1){
                    straightChk ++;
                }
                if(q == 0 && w <= 3 && straightChk >= 4 && number[12] >= 1){
                    straight = 14;
                    backST = 1;
                    if(grade <= 5){
                        grade = 5;
                    }
                }//빽 스트레이트 조건
            }//작은 for
            if(straightChk >= 5){
                straight = q + 6;

                if(grade <= 5){
                    grade = 5;
                }
            }
            straightChk = 0;
        }//straight check

        for(int q = 0 ; q<13 ; q++){
            if(number[q] == 4){
                fourCard = q + 2;

                if(grade <= 8)
                    grade = 8;
            }
            else if(triple >= 1 && onePair >= 1){
                fullHouse = triple;
                if(grade <= 7)
                    grade = 7;
            }
            else if(number[q] == 3){
                triple = q + 2;
                if(grade <= 4)
                    grade = 4;
            }
            else if(onePair >= 1 && number[q] == 2 && twoPair == 0){
                twoPair = q + 2;
                if(grade <= 3)
                    grade = 3;
            }
            else if(onePair >= 1 && number[q] == 2 && twoPair >= 1){
                onePair = twoPair;
                twoPair = q + 2;
                if(grade <= 3)
                    grade = 3;
            }// 3페어 방지
            else if(number[q] == 2 && grade != 3){ // 주의!!!!!!! 이 부분이 아주 중요함 && grade < 5
                onePair = q + 2;
                if(grade <= 2)
                    grade = 2;
            }//투페어가 당첨되면 원페어는 그대로 있기위한 조건
            else if(number[q] == 1){
                top = q + 2;
                if(grade <= 1)
                    grade = 1;
            }
        }//원,투페어,트리플,풀하우스,포카드 확인

        System.out.println("\n결과보기 <Enter>");
        sc.nextLine();

        System.out.print("\n당신의 패: ");
        for(int q = 0 ; q<7 ; q++){
            if(q != 0 && q != 7){
                System.out.print("__");
            }
            System.out.print(card[q]);
        }

        System.out.println("\n");
        switch(grade){
            case 1:
                System.out.println("당신은 "+gradeResult(top)+" <Top> 입니다.");
                break;
            case 2:
                System.out.println("당신은 "+gradeResult(onePair)+" <One Pair> 입니다.");
                break;
            case 3:
                System.out.println("당신은 "+gradeResult(twoPair)+gradeResult(onePair)+" <Two Pair> 입니다.");
                break;
            case 4:
                System.out.println("당신은 "+gradeResult(triple)+" <Triple> 입니다.");
                break;
            case 5:
                System.out.print("당신은 "+gradeResult(straight));
                if(straight == 14 && backST == 0){
                    System.out.print("Mountain ");
                }
                else if(backST == 1){
                    System.out.print("Back ");
                }
                System.out.println("<Straight> 입니다.");
                break;
            case 6:
                System.out.print("당신은 ");
                switch(flush){
                    case 4:
                        System.out.print(flush("♠"));
                        break;
                    case 3:
                        System.out.print(flush("◈"));
                        break;
                    case 2:
                        System.out.print(flush("♣"));
                        break;
                    case 1:
                        System.out.print(flush("♥"));
                        break;
                }
                System.out.println(" <Flush> 입니다.");
                break;
            case 7:
                System.out.println("당신은 "+gradeResult(fullHouse)+gradeResult(onePair)+" <FullHouse> 입니다.");
                break;
            case 8:
                System.out.println("당신은 "+gradeResult(fourCard)+" <FourCard> 입니다.");
                break;
        }
        sc.close();
    }//main

    private static String gradeResult(int grade) {
        String tmp = "";
        for(int q = 0; q<7 ; q++){
            if(cardNum[q].substring(1, cardNum[q].length()).equals(""+grade)){
                tmp += card[q]+" ";
            }
        }
        return tmp;
    } //Grade Result

    private static String flush(String shape) {
        String tmp = "";
        for(int q = 0; q<7 ; q++){
            if(cardNum[q].substring(0, 1).equals(shape)){
                tmp += card[q]+" ";
            }
        }
        return tmp;
    } //flush result

    private static void cardDeckSet(String[][] cardDeck, int random, String tmp) {
        for(int q = 0 ; q<13 ; q++){
            cardDeck[0][q] = "♠"+(q+2);
            cardDeck[1][q] = "◈"+(q+2);
            cardDeck[2][q] = "♣"+(q+2);
            cardDeck[3][q] = "♥"+(q+2);
        }//CardDeck set
        for(int q = 0 ; q<4 ; q++){
            for(int w = 0 ; w<100; w++){
                random = rn.nextInt(12)+1;
                tmp = cardDeck[q][random];
                cardDeck[q][random] = cardDeck[q][0];
                cardDeck[q][0] = tmp;
            }
        }//CardDeck Mix
    } //CardDeck set and Mix

}//class
