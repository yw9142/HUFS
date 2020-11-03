package hufs.ces.sort.closure

class FiveCardsComparator implements Comparator<FiveCards> {
	int compare (FiveCards left, FiveCards right) {
		return left.compareTo(right);
	}
}
