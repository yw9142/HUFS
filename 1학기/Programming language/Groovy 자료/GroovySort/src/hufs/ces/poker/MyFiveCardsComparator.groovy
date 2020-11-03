package hufs.ces.poker

class MyFiveCardsComparator implements Comparator<FiveCards> {
	
	public int compare(FiveCards left, FiveCards right) {
		// implement this method
		return left.toString().compareTo(right.toString());
		
	}
}
