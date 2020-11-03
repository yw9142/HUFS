package hufs.ces.clas

class PhoneBookArray implements IPhoneBook {

	static final int MAX_CONTACT_ENTRY = 100;

	Entry[] arrayPhoneBook = null;
	int lastp = 0;
	
	PhoneBookArray() {
		arrayPhoneBook = new Entry[MAX_CONTACT_ENTRY];
		lastp = 0;
	}

	int findLoc(String name){
		for (int i=0; i<lastp; ++i){
			if (arrayPhoneBook[i].phoneName == name)
				return i;
		}
		return -1; // not found
	}
	
	@Override
	int find(String name){
		int loc = findLoc(name);
		if (loc == -1)
			return null; // not found
		return arrayPhoneBook[loc].phoneNumber;
	}
	
	@Override
	public String find(int number) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	boolean insert(String name, int number){
		int loc = findLoc(name);
		if (loc == -1){ // insert
			if (lastp > MAX_CONTACT_ENTRY){
				println "***Error -- PhoneBook Overflow";
				return false;
			}
			else {
				arrayPhoneBook[lastp] = new Entry(name, number);
				lastp++;
				return true;
			}
		}
		else {
			return false;
		}
	}

	@Override
	boolean remove(String name){
		int loc = findLoc(name);
		if (loc != -1){ // there exist name
			// remove array entry at loc
			for (int i=loc+1; i<lastp; ++i){
				arrayPhoneBook[i-1].phoneName = arrayPhoneBook[i].phoneName;
				arrayPhoneBook[i-1].phoneNumber = arrayPhoneBook[i].phoneNumber;
			}
			lastp--;
			return true;
		}
		else {
			println "***Error -- Name not found";
			return false;
		}
	}
	
	@Override
	boolean update(String name, int number){
		if (remove(name)) {
			if (insert(name, number))
				return true;
		}
		return false;
	}
	
	@Override
	void listAll(){
		println "Name\tNumber";
		for (int i=0; i<lastp; ++i){
			println "${arrayPhoneBook[i].phoneName}\t" +
			"${arrayPhoneBook[i].phoneNumber}"
		}
	}
}


