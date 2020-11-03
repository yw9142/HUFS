package hufs.ces.hasa.list

import java.util.ArrayList
import java.util.Comparator
import java.util.Collection
import java.util.Iterator
import java.util.List
import java.util.ListIterator

class SortableList<E> implements List<E> {

	private ArrayList<E> list = null;
	
	public SortableList() {
		this(new ArrayList<E>());
	}
	public SortableList(ArrayList<E> list) {
		this.list = list;
	}
	public void sort(Comparator<E> c) {
		SortAlgorithms.quickSort(this.list, c);
	}
	public void sort() {
		SortAlgorithms.quickSort(this.list);		
	}
	@Override
	public int size() {
		return this.list.size();
	}

	@Override
	public boolean isEmpty() {
		return this.list.isEmpty();
	}

	@Override
	public boolean contains(Object o) {
		return this.list.contains(o);
	}

	@Override
	public Iterator<E> iterator() {
		return this.list.iterator();
	}

	@Override
	public Object[] toArray() {
		return this.list.toArray();
	}

	@Override
	public <T> T[] toArray(T[] a) {
		return this.list.toArray(a);
	}

	@Override
	public boolean add(E e) {
		return this.list.add(e);
	}

	@Override
	public boolean remove(Object o) {
		return this.list.remove(o);
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		return this.list.containsAll(c);
	}

	@Override
	public boolean addAll(Collection<? extends E> c) {
		return this.list.addAll(c);
	}

	@Override
	public boolean addAll(int index, Collection<? extends E> c) {
		return this.list.addAll(index, c);
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		return this.list.removeAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		return this.list.retainAll(c);
	}

	@Override
	public void clear() {
		this.list.clear();
	}

	@Override
	public E get(int index) {
		return this.list.get(index);
	}

	@Override
	public E set(int index, E element) {
		return this.list.set(index, element);
	}

	@Override
	public void add(int index, E element) {
		this.list.add(index, element);
	}

	@Override
	public E remove(int index) {
		return this.list.remove(index);
	}

	@Override
	public int indexOf(Object o) {
		return this.list.indexOf(o);
	}

	@Override
	public int lastIndexOf(Object o) {
		return this.list.lastIndexOf(o);
	}

	@Override
	public ListIterator<E> listIterator() {
		return this.list.listIterator();
	}

	@Override
	public ListIterator<E> listIterator(int index) {
		return this.list.listIterator(index);
	}

	@Override
	public List<E> subList(int fromIndex, int toIndex) {
		return this.list.subList(fromIndex, toIndex);
	}

}
