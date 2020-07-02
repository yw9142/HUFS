package hufs.ces.sort.closure

class SortTest5Cards {

	static main(args) {
		sortTest5Cards()
	}
	
	static SortableList<FiveCards> generate5CardList(int gencount) {

		// Generate List<FiveCards>
		SortableList<FiveCards> p5CardsList = new SortableList<FiveCards>();
		ArrayList<Card> deckCard = new ArrayList<Card>();

		// Make a Card Deck
		for (int s=Card.CLUB; s<=Card.SPADE; s++)
			for (int r=Card.ACE; r<=Card.KING; r++){
				deckCard.add(new Card(s,r));
			}

		for (int i=1; i<=gencount; i++) {

			suffle(deckCard);

			// Make a Card Deck
			int indDeck = 0;

			Card[] fc = new Card[5];
			int ipos = 0;
			while (indDeck < deckCard.size()) {
				fc[ipos] = deckCard.get(indDeck);
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
	static void suffle (ArrayList<Card> list) {
		final int  SUFFLECOUNT = 100;

		//println "List before Suffle"
		//printList(list);
		Random rand = new Random(1234);
		int oneOrzero = 0;
		int lsize = list.size();
		int ind = 0;
		for (int i=1; i <= SUFFLECOUNT*lsize; i++) {
			// random number  0 or 1
			oneOrzero = rand.nextInt(2);
			//println "ind=$ind rand=$oneOrzero card=${list.get(ind)}"
			if (oneOrzero == 0) {
				// move to back
				list.add(list.remove(ind));
			}
			else {
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
		SortableList<FiveCards> list5card = generate5CardList(10);

		// Add more sample data
		
		Card[] fourCards = [new Card(1,1), new Card(2,1), new Card(3,1), new Card(4,1), new Card(1,13)];
		list5card.add(new FiveCards(fourCards));

		Card[] fullhouse = [new Card(1,1), new Card(2,1), new Card(3,1), new Card(4,13), new Card(1,13)];
		list5card.add(new FiveCards(fullhouse));

		Card[] straight = [new Card(1,1), new Card(2,2), new Card(3,3), new Card(4,4), new Card(1,5)];
		list5card.add(new FiveCards(straight));

		Card[] flush = [new Card(1,1), new Card(1,2), new Card(1,3), new Card(1,4), new Card(1,6)];
		list5card.add(new FiveCards(flush));

		Card[] straightflush = [new Card(1,1), new Card(1,2), new Card(1,3), new Card(1,4), new Card(1,5)];
		list5card.add(new FiveCards(straightflush));

		Card[] threeofakind = [new Card(1,1), new Card(2,1), new Card(3,1), new Card(4,10), new Card(1,2)];
		list5card.add(new FiveCards(threeofakind));

				Card[] twopair = [new Card(1,1), new Card(2,1), new Card(3,10), new Card(4,10), new Card(1,2)];
		list5card.add(new FiveCards(twopair));

		Card[] onepair = [new Card(1,1), new Card(2,1), new Card(3,4), new Card(4,5), new Card(1,6)];
		list5card.add(new FiveCards(onepair));

		Card[] nopair = [new Card(1,1), new Card(2,3), new Card(3,5), new Card(4,7), new Card(1,9)];
		list5card.add(new FiveCards(nopair));

		// Display the Deck
		println "FiveCards before Sort";
		printFiveCardsList(list5card);
		// List Test
		list5card.sort(new FiveCardsComparator());

		println "FiveCards after Sort";
		printFiveCardsList(list5card);

	}

}
