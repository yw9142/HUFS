package hufs.ces.closure

class SortTest5Cards {

    static final int CLUB = 1, DIAMOND = 2, HEART = 3, SPADE = 4;

    static List<FiveCards> generate5CardList(int gencount) {

        // Generate List<FiveCards>
        List<FiveCards> p5CardsList = [];
        List<Card> deckCard = [];
        List<Card> lists = [];

        // Make a Card Deck
        for (int s = Card.CLUB; s <= Card.SPADE; s++)
            for (int r = Card.ACE; r <= Card.KING; r++) {
                deckCard.add(new Card(s, r));
            }

        for (int i = 1; i <= gencount; i++) {

            suffle(deckCard);

            // Make a Card Deck
            int indDeck = 0;

            Card[] fc = new Card[5];
            int ipos = 0;
            while (indDeck < deckCard.size()) {
                fc[ipos] = deckCard[indDeck];
                indDeck++;
                ipos++;
                if (ipos == 5) {
                    p5CardsList.add(new FiveCards(fc));
                    ipos = 0;
                }
            }
        }
        return p5CardsList;
    }

    static def map(List<FiveCards> fiveCards, f) {
        if (fiveCards.size() == 0)
            fiveCards
        else
            [f(fiveCards.head())] + map(fiveCards.tail(), f)
    }

    static void suffle(List<Card> list) {
        final int SUFFLECOUNT = 100;

        //println "List before Suffle"
        //printList(list);
        Random rand = new Random(1234);
        int oneOrzero = 0;
        int lsize = list.size();
        int ind = 0;
        for (int i = 1; i <= SUFFLECOUNT * lsize; i++) {
            // random number  0 or 1
            oneOrzero = rand.nextInt(2);
            //println "ind=$ind rand=$oneOrzero card=${list[ind]}"
            if (oneOrzero == 0) {
                // move to back
                list.add(list.remove(ind));
            } else {
                ind++;
                ind %= lsize;
            }
        }
        //println "List after Suffle"
        //printList(list);
    }

    static void printFiveCardsList(List<FiveCards> fcList) {
        int ccount = 0;
        for (FiveCards fc : fcList) {
            println "${++ccount} $fc";
        }
    }

    static void sortTest5Cards() {
        println "Sort Test 5 Cards";
        List<FiveCards> list5card = generate5CardList(10);

        // Add more sample data
        Card[] fourCards = [new Card(CLUB, 1), new Card(DIAMOND, 1), new Card(HEART, 1), new Card(SPADE, 1), new Card(CLUB, 2)];
        list5card.add(new FiveCards(fourCards));

        Card[] fullhouse = [new Card(CLUB, 1), new Card(DIAMOND, 1), new Card(HEART, 1), new Card(SPADE, 13), new Card(CLUB, 13)];
        list5card.add(new FiveCards(fullhouse));

        Card[] straight = [new Card(CLUB, 1), new Card(DIAMOND, 2), new Card(HEART, 3), new Card(SPADE, 4), new Card(CLUB, 5)];
        list5card.add(new FiveCards(straight));

        Card[] flush = [new Card(CLUB, 1), new Card(CLUB, 2), new Card(CLUB, 3), new Card(CLUB, 4), new Card(CLUB, 6)];
        list5card.add(new FiveCards(flush));

        Card[] straightflu = [new Card(CLUB, 1), new Card(CLUB, 2), new Card(CLUB, 3), new Card(CLUB, 4), new Card(CLUB, 5)];
        list5card.add(new FiveCards(straightflu));

        Card[] twopair = [new Card(CLUB, 1), new Card(DIAMOND, 1), new Card(HEART, 10), new Card(SPADE, 10), new Card(CLUB, 2)];
        list5card.add(new FiveCards(twopair));

        Card[] onepair = [new Card(CLUB, 1), new Card(DIAMOND, 1), new Card(HEART, 4), new Card(SPADE, 5), new Card(CLUB, 6)];
        list5card.add(new FiveCards(onepair));

        Card[] nopair = [new Card(CLUB, 1), new Card(DIAMOND, 3), new Card(HEART, 5), new Card(SPADE, 7), new Card(CLUB, 9)];
        list5card.add(new FiveCards(nopair));
        def fnopair = new FiveCards(nopair);
        (0..4).each { i -> println "fnopair[$i] = ${fnopair[i]}" }
        // Display the Deck
        println "FiveCards before Sort";
        printFiveCardsList(list5card);
        // List Test
        //List<FiveCards> list5cardSorted = new SelSort().sort(list5card);
        //List<FiveCards> list5cardSorted = new SelSort().sort(list5card, {left, right->left[0]<=>right[0]});
        //List<FiveCards> list5cardSorted = new QuickSort().sort(list5card);
        //List<FiveCards> list5cardSorted = new QuickSort().sort(list5card, {left, right->left[0]<=>right[0]});
        //List<FiveCards> list5cardSorted = new QuickSort().sort(list5card, {left, right->left.toString()<=>right.toString()});

        Closure comp1 = {left, right->
            int i;
            for (i = 0; i < 4;) {
                if ((left[i] <=> right[i]) == 0) {
                    i++;
                } else {
                    return left[i] <=> right[i]
                }
            }
            return left[i] <=> right[i]
        };


        Closure comp = { head ->
            int count1, count2;
            List<String> lists = new ArrayList<>();
            for (int q = 0; q <= 4; q++) {
                lists.add(head[q])
            }

            int temp;
            String mon;
            count1 = 0
            count2 = 0
            for (int i = 0; i <= 4; i++) {
                for (int j = 0; j <= 4; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (lists[i] <=> lists[j] == 0) {
                        mon = lists[i];
                        count1++;
                    }
                }
                if (count1 > 0){
                    temp = count1;
                    count1 = count2
                    count2 = temp
                }
            }

            int j = 0
            for (int i = 0; i < 3; i++) {
                j = i + 1

                if (lists[i] <=> lists[j] == 0) {
                    lists.remove(j)
                }

            }
            if (lists.size() == 5) {
                if (lists[3] == lists[4]) {
                    lists.remove(3)
                    lists.remove(3)
                }
            }

            if (mon == 'A ') {
                mon = "1"
            } else if (mon == 'J ') {
                mon = "11"
            } else if (mon == 'Q ') {
                mon = "12"
            } else if (mon == 'K ') {
                mon = "13"
            }

            Collections.reverse(lists);

            if (count2 == 0) { // no pair
                lists.add(0, 1)
                return lists
            } else if (count2 == 1) { // one pair
                lists.add(0, mon)
                lists.add(0, 2)
                return lists
            } else if (count2 == 1 && count1 == 1) { // two pair
                lists.add(0, mon)
                lists.add(0, 3)
                return lists
            } else if (count2 == 2) { // triple
                lists.add(0, mon)
                lists.add(0, 4)
                return lists
            } else if ((count2 == 2 && count1 == 1) || (count1 == 1 && count2 == 2)) { // full house
                lists.add(0, mon)
                lists.add(0, 5)
                return lists
            } else if (count2 == 3) { // Four card
                lists.add(0, mon)
                lists.add(0, 6)
                return lists
            }
        };

        List<FiveCards> list5cardSorted = map(list5card, comp)
        println ""
        println ""
        println "FiveCards Rank Poker hands Sort";
        for (int i = 0; i < 109; i++)
            print(i) println(list5cardSorted[i])


    }

    static main(args) {
        sortTest5Cards()
    }
}