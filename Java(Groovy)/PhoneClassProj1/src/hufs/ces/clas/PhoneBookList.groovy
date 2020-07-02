package hufs.ces.clas

class PhoneBookList implements IPhoneBook {

    private List<Entry> phoneBookList;

    PhoneBookList() {
        phoneBookList = [];
    }

    private int findLoc(String name) {
        for (int i = 0; i < phoneBookList.size(); ++i) {
            if (phoneBookList[i].phoneName == name)
            // phoneBookList[i].phoneName.equals(name) in Java
                return i;
        }
        return -1; // not found
    }

    private int findLoc2(int num) {
        for (def i = 0; i < phoneBookList.size(); ++i) {
            if (phoneBookList[i].phoneNumber == num)
                return i;
        }
        return -1; // not found
    }

    @Override
    public int find(String name) {
        int loc = findLoc(name);
        if (loc == -1){
            println("Not found");
            return -1; // not found
        }
        return phoneBookList[loc].phoneNumber;
    }

    @Override
    public String find(int number) { /// 번호로 이름 찾기
        int loc = findLoc2(number);
        if (loc == -1) {
            println("Not found");
            return null;
        }
        return phoneBookList[loc].phoneName;
    }

    @Override
    public boolean insert(String name, int number) {
        int loc = findLoc(name);
        if (loc == -1) { //  can insert
            phoneBookList.add(new Entry(name, number));
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean update(String name, int number) {
        def loc = findLoc(name);
        if (loc != -1)
            phoneBookList[loc].phoneNumber = number
        else
            println "***Error -- Name not found";
    }


    @Override
    public boolean remove(String name) {
        int loc = findLoc(name);
        if (loc != -1) { // there exist name
            // remove array entry at loc
            phoneBookList.remove(loc);
            return true;
        } else {
            println "***Error -- Name not found";
            return false;
        }
    }

    @Override
    public void listAll() {
        println "Name\tNumber";
        for (int i = 0; i < phoneBookList.size(); ++i) {
            println "${phoneBookList[i].phoneName}\t${phoneBookList[i].phoneNumber}"
        }
    }

}
