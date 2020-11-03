package sort

interface ISorter<T> {
	
	List<T> sort(List<T> list);
	List<T> sort(List<T> list, Comparator<T> comp);
	
}
