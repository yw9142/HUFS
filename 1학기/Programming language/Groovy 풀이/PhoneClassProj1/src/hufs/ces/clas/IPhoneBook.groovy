package hufs.ces.clas

interface IPhoneBook {
	
	int find(String name);
	String find(int number);
	boolean insert(String name, int number);
	boolean update(String name, int number);
	boolean remove(String name);
	
	void listAll();
}
