package sort

class StringCardComparator implements Comparator<Card> {
	public int compare(Card left, Card right) {
		return left.toString().compareTo(right.toString());
	}
}
