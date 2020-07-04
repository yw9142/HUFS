package sort

import java.util.ArrayList
import java.util.List

class MergeSort<T> implements ISorter<T> {

	@Override
	public List<T> sort(List<T> list) {
		list = list.collect();
		mergeSort(list);
		return list;
	}
	@Override
	public List<T> sort(List<T> list, Comparator<T> comp) {
		list = list.collect();
		mergeSort(list, comp);
		return list;
	}
	static<T> void mergeSort(List<T> list) {

		int n = list.size();
		if (n < 2)
			return;

		List<T> list1 = [];
		List<T> list2 = [];

		for (int i=0; i<list.size(); ++i) {
			if (i < n/2) {
				list1.add(list[i]);
			}
			else {
				list2.add(list[i]);
			}
		}

		list.clear();
		mergeSort(list1);
		mergeSort(list2);

		merge(list1, list2, list);

	}
	static<T> void mergeSort(List<T> list, Comparator<T> comp) {

		int n = list.size();
		if (n < 2)
			return;

		List<T> list1 = [];
		List<T> list2 = [];

		for (int i=0; i<list.size(); ++i) {
			if (i < n/2) {
				list1.add(list[i]);
			}
			else {
				list2.add(list[i]);
			}
		}

		list.clear();
		mergeSort(list1, comp);
		mergeSort(list2, comp);

		merge(list1, list2, list, comp);

	}
	static<T> void merge (List<T> list1, List<T> list2, List<T> list) {
		int ind1 = 0;
		int ind2 = 0;
		while (ind1<list1.size() && ind2<list2.size()) {
			if (list1[ind1] < list2[ind2]) {
				list.add(list1[ind1]);
				ind1++;
			}
			else {
				list.add(list2[ind2]);
				ind2++;
			}
		}
		while (ind1<list1.size()) {
			list.add(list1[ind1]);
			ind1++;
		}
		while (ind2<list2.size()) {
			list.add(list2[ind2]);
			ind2++;
		}
	}
	static<T> void merge (List<T> list1, List<T> list2, List<T> list, Comparator<T> comp) {
		int ind1 = 0;
		int ind2 = 0;
		while (ind1<list1.size() && ind2<list2.size()) {
			if (comp.compare(list1[ind1], list2[ind2]) < 0) {
				list.add(list1[ind1]);
				ind1++;
			}
			else {
				list.add(list2[ind2]);
				ind2++;
			}
		}
		while (ind1<list1.size()) {
			list.add(list1[ind1]);
			ind1++;
		}
		while (ind2<list2.size()) {
			list.add(list2[ind2]);
			ind2++;
		}
	}
	static<T> void merge1 (List<T> list1, List<T> list2, List<T> list) {
		final Card HIGH_VALUE = new Card(1, 15); // Highest value for toCompare()

		int ind1 = 0;
		int ind2 = 0;
		list1.add(HIGH_VALUE);
		list2.add(HIGH_VALUE);
		while (!(list1[ind1]==HIGH_VALUE && list2[ind2]==HIGH_VALUE)) {
			if (list1[ind1] < list2[ind2]) {
				list.add(list1[ind1]);
				ind1++;
			}
			else {
				list.add(list2[ind2]);
				ind2++;
			}
		}
	}
	static void printList(List list) {
		final int  LINE_MAX = 13;
		int i = 0;
		for (def c:list) {
			print "$c ";
			i++;
			if (i % LINE_MAX == 0) println();
		}
		println();
	}
	static main(args) {

		List<Card> deck = [];
		// Make a Card Deck
		for (int s=Card.CLUB; s<=Card.SPADE; s++) {
			for (int r=Card.ACE; r<=Card.KING; r++){
				deck.add(new Card(s,r));
			}
		}

		ISorter sorter = new MergeSort();
		println "List before ${sorter.class.getName()}";
		printList(deck);
		println "List after ${sorter.class.getName()}"
		printList(sorter.sort(deck));

		println "List before ${sorter.class.getName()}";
		printList(deck);
		println "List after ${sorter.class.getName()} with String comp"
		printList(sorter.sort(deck, new StringCardComparator()));

		def l1 = [3, 2, 7, 6, 8, 4, 5, 100, 90, 11];
		printList(l1);
		printList(sorter.sort(l1));
		printList(sorter.sort(l1, new Comparator<Integer>() {
					public int compare(Integer left, Integer right) {
						//println "|${left.toString()}| |${right.toString()}| ${left.toString().compareTo(right.toString())}"
						return left.toString().compareTo(right.toString());
					}
				}));

	}

}
