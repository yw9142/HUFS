package hufs.ces.clas

class PhoneBookList implements IPhoneBook {

	private List<Entry> phoneBookList;

	PhoneBookList() {
		phoneBookList = [];
	}
	private int findLoc(String name){
		for (int i=0; i<phoneBookList.size(); ++i){
			if (phoneBookList[i].phoneName == name)
				// phoneBookList[i].phoneName.equals(name) in Java
				return i;
		}
		return -1; // not found
	}

	@Override
	public int find(String name) {
		int loc = findLoc(name);
		if (loc == -1)
			return -1; // not found
		return phoneBookList[loc].phoneNumber;
	}

	@Override
	public String find(int number) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean insert(String name, int number) {
		int loc = findLoc(name);
		if (loc == -1){ //  can insert
			phoneBookList.add(new Entry(name, number));
			return true;
		}
		else {
			return false;
		}
	}

	@Override
	public boolean update(String name, int number) {
		if (remove(name)) {
			insert(name, number);
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean remove(String name) {
		int loc = findLoc(name);
		if (loc != -1){ // there exist name
			// remove array entry at loc
			phoneBookList.remove(loc);
			return true;
		}
		else {
			return false;
		}
	}

	@Override
	public void listAll() {
		println "Name\tNumber";
		for (int i=0; i<phoneBookList.size(); ++i){
			println "${phoneBookList[i].phoneName}\t${phoneBookList[i].phoneNumber}"
		}
	}

}
