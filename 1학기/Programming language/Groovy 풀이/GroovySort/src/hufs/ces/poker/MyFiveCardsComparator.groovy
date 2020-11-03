package hufs.ces.poker

class MyFiveCardsComparator implements Comparator<FiveCards> {

    public int compare(FiveCards left, FiveCards right) {
        int i;
        for (i = 0; i < 4;) {
            if (left[i].compareTo(right[i]) == 0) {
                i++;
            } else {
                return left[i].compareTo(right[i])
            }
        }
        return left[i].compareTo(right[i])
    }
}
